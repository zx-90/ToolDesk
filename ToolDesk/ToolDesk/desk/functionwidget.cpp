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

#include "functionwidget.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include "desk/core/treewidgetitemtemplate.h"
#include "functions/physical/createphysicalregistrator.h"
#include "functions/timeseries/createtimeseriesregistrator.h"

typedef TreeWidgetItemTemplate<DeskGui::IFunctionRegistrator> FunctionItem;

FunctionWidget::FunctionWidget(DeskData::IProject *project, QWidget *parent) :
    QWidget(parent),
    _project(project)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    setLayout(layout);
    layout->setContentsMargins(2, 2, 2, 2);
    _tree = new QTreeWidget(this);
    _tree->setIndentation(0);
    _tree->setHeaderLabels(QStringList() << "Function");
    layout->addWidget(_tree);

    createTreeItem(new DeskGui::CreatePhysicalRegistrator());
    createTreeItem(new CreateTimeSeriesRegistrator());

    connect( _tree, SIGNAL(itemClicked(QTreeWidgetItem*, int)),
             this, SLOT(onClick(QTreeWidgetItem*, int)));
}

void FunctionWidget::setProject(DeskData::IProject *project)
{
    _project = project;
}

void FunctionWidget::onClick(QTreeWidgetItem *item, int)
{
    DeskGui::IFunctionRegistrator* registrator = FunctionItem::getData(item);
    DeskGui::IFunctionDialog* dialog = registrator->getDialog(_project, this);
    dialog->setModal(true);
    connect(
                dialog, SIGNAL(createSummation(DeskData::ISummation*)),
                this, SLOT(onCreateSummation(DeskData::ISummation*)));
    dialog->show();
}

void FunctionWidget::onCreateSummation(DeskData::ISummation *summation)
{
    _project->setFunctionResult(summation);
    emit changed();
}

void FunctionWidget::createTreeItem(DeskGui::IFunctionRegistrator *registrator)
{
    FunctionItem *topLevelItem = new FunctionItem(registrator);
    topLevelItem->setText(0, registrator->getName());
    _tree->addTopLevelItem(topLevelItem);
}

