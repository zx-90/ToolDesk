/*
 * This file is part of ToolDesk.
 * Copyright © 2018 Evgenii Zaitcev.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "projectwidget.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include "include/data/DataList.h"
#include "projectitem.h"
#include "data/editor/dataphysicalviewer.h"

ProjectWidget::ProjectWidget(DeskData::IProject *project, QWidget *view, QWidget *parent) :
    QWidget(parent),
    _project(project),
    _view(view),
    _viewer(NULL)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    setLayout(layout);
    layout->setContentsMargins(2, 2, 2, 2);
    _tree = new QTreeWidget(this);
    _tree->setColumnCount(2);
    layout->addWidget(_tree);

    _viewLayout = new QVBoxLayout(_view);

    connect(_tree, SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)),
            this, SLOT(onClick(QTreeWidgetItem *, QTreeWidgetItem *)));
}

void ProjectWidget::setProject(DeskData::IProject *project)
{
    _project = project;
}

void ProjectWidget::onChange()
{
    //QMessageBox::information(this, "title", "text");
    _tree->clear();
    for (DeskData::Size i = 0; i < _project->getFunctionCount(); i++) {

        const DeskData::ISummation* summation = _project->getFunctionResult(i);
        const DeskData::IContainer* container = summation->getOutContainer();
        QStringList list;
        list.push_back(QString::fromWCharArray(summation->getDescription()));
        ProjectItem* summationItem = new ProjectItem(container, list);
        _tree->addTopLevelItem(summationItem);
        summationItem->setFirstColumnSpanned(true);

        for (DeskData::Size j = 0; j < container->getSize(); j++) {
            const DeskData::IData* data = container->getData(j);
            if (!data) {
                continue;
            }
            QString valueStr = "";
            if (data->getType() == DeskData::DATATYPE_PHYSICAL) {
                const DeskData::IPhysical* physical = (const DeskData::IPhysical*)data;
                valueStr =
                        DeskData::doubleToString(physical->getValue()) +
                        " " +
                        DeskData::dimentionToString(physical->getDimention());
            }
            QStringList list;
            list.push_back(valueStr);
            list.push_back(QString::fromWCharArray(data->getDescription()));
            ProjectItem* dataItem = new ProjectItem(data, list);
            summationItem->addChild(dataItem);
        }

    }
}

void ProjectWidget::onClick(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    //QMessageBox::information(this, "title", "text");
    if (_viewer) {
        delete _viewer;
        _viewer = NULL;
    }
    if (!current) {
        return;
    }
    if (current == previous) {
        return;
    }

    ProjectItem* cur = (ProjectItem*)current;
    const DeskData::IData* data = cur->getData();
    if (data == NULL) {
        return;
    }
    if (data->getType() == DeskData::DATATYPE_PHYSICAL) {
        _viewer = new DeskGui::DataPhysicalViewer(data, _view);
        _viewLayout->addWidget(_viewer);
    }
}

