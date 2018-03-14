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

#include "createphysicaldialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <math.h>
#include "data/editor/dataphysicaleditor.h"
#include "desk/core/borderlayout.h"
#include "desk/core/treewidgetitemtemplate.h"

typedef TreeWidgetItemTemplate<DeskData::IPhysical> PhysicalItem;

namespace DeskGui {

CreatePhysicalDialog::CreatePhysicalDialog(DeskData::IProject *project, QWidget *parent) :
    IFunctionDialog(project, parent),
    _project(project)
{
    _value = _project->getFactory()->createSummation();
    _value->setDescription("Values");

    setWindowTitle("Create physical value");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(10);

    _description = new DescriptionEditor(_value, this);
    layout->addWidget(_description);

    QWidget* valuesWidget = new QWidget(this);
    QHBoxLayout* valuesLayout = new QHBoxLayout(valuesWidget);
    valuesWidget->setLayout(valuesLayout);
    valuesLayout->setMargin(0);
    layout->addWidget(valuesWidget);

    _values = new ShiftedTreeWidget(valuesWidget);
    _values->setHeaderLabels(QStringList() << "Value" << "Description");
    _values->setIndentation(0);
    valuesLayout->addWidget(_values);

    QWidget* buttonsWidget = new QWidget(valuesWidget);
    buttonsWidget->setMaximumWidth(20);
    BorderLayout* buttonsLayout = new BorderLayout(buttonsWidget);
    buttonsWidget->setLayout(buttonsLayout);
    buttonsLayout->setMargin(0);
    valuesLayout->addWidget(buttonsWidget);

    _up = new QPushButton("↑", buttonsWidget);
    _up->setMaximumWidth(20);
    buttonsLayout->addWidget(_up, BorderLayout::North);
    _down = new QPushButton("↓", buttonsWidget);
    _down->setMaximumWidth(20);
    buttonsLayout->addWidget(_down, BorderLayout::North);
    _add = new QPushButton("+", buttonsWidget);
    _add->setMaximumWidth(20);
    buttonsLayout->addWidget(_add, BorderLayout::North);
    _remove = new QPushButton("0", buttonsWidget);
    _remove->setMaximumWidth(20);
    buttonsLayout->addWidget(_remove, BorderLayout::North);

    _editor = new DataPhysicalEditor(nullptr, this);
    layout->addWidget(_editor);

    _button = new QPushButton("Set", this);
    layout->addWidget(_button);

    QWidget::connect(
                _up, SIGNAL(pressed()),
                this, SLOT(onUpValue())
                );
    QWidget::connect(
                _down, SIGNAL(pressed()),
                this, SLOT(onDownValue())
                );
    QWidget::connect(
                _add, SIGNAL(pressed()),
                this, SLOT(onAddValue())
                );
    QWidget::connect(
                _remove, SIGNAL(pressed()),
                this, SLOT(onRemoveValue())
                );
    QWidget::connect(
                _values, SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)),
                this, SLOT(onChangeCurrentValue(QTreeWidgetItem *, QTreeWidgetItem *))
                );
    QWidget::connect(
                _editor, SIGNAL(dataChanged(DeskData::IData*)),
                this, SLOT(setData(DeskData::IData*)));
    QWidget::connect(
                _button, SIGNAL(pressed()),
                this, SLOT(runFunction()));

    onChangeCurrentValue(nullptr, nullptr);
}

CreatePhysicalDialog::~CreatePhysicalDialog()
{
    if (!_value) {
        return;
    }
    _value->release();
    for (int i = 0; i < _values->topLevelItemCount(); i++) {
        QTreeWidgetItem* item = _values->topLevelItem(i);
        DeskData::IPhysical* data = PhysicalItem::getData(item);
        data->release();
    }
}

void CreatePhysicalDialog::runFunction()
{
    if (!_value) {
        return;
    }
    for (int i = 0; i < _values->topLevelItemCount(); i++) {
        QTreeWidgetItem* item = _values->topLevelItem(i);
        DeskData::IPhysical* data = PhysicalItem::getData(item);
        _value->registerOutData(data);
    }
    emit createSummation(_value);
    _value = nullptr;
    close();
}

void CreatePhysicalDialog::onUpValue()
{
    QTreeWidgetItem* item = _values->currentItem();
    if (!item) {
        return;
    }
    int index = _values->indexOfTopLevelItem(item);
    if (index > 0) {
        _values->takeTopLevelItem(index);
        _values->insertTopLevelItem(index - 1, item);
        _values->setCurrentItem(item);
    }
}

void CreatePhysicalDialog::onDownValue()
{
    QTreeWidgetItem* item = _values->currentItem();
    if (!item) {
        return;
    }
    int index = _values->indexOfTopLevelItem(item);
    if (index < _values->topLevelItemCount() - 1) {
        _values->takeTopLevelItem(index);
        _values->insertTopLevelItem(index + 1, item);
        _values->setCurrentItem(item);
    }
}

void CreatePhysicalDialog::onAddValue()
{
    DeskData::IPhysical* value =
            (DeskData::IPhysical*)
            _project->getFactory()->createData(DeskData::DATATYPE_PHYSICAL);
    PhysicalItem* item = new PhysicalItem(value);
    _values->addTopLevelItem(item);
    _values->setCurrentItem(item);
    setData(value);
}

void CreatePhysicalDialog::onRemoveValue()
{
    QTreeWidgetItem* item = _values->currentItem();
    if (!item) {
        return;
    }
    int index = _values->indexOfTopLevelItem(item);
    _values->takeTopLevelItem(index);
    DeskData::IPhysical* val = PhysicalItem::getData(item);
    val->release();
    delete item;
    onChangeCurrentValue(_values->topLevelItem(index), nullptr);
}

void CreatePhysicalDialog::onChangeCurrentValue(QTreeWidgetItem *current, QTreeWidgetItem *)
{
    if (current) {
        int index = _values->indexOfTopLevelItem(current);
        if (index > 0) {
            _up->setEnabled(true);
        } else {
            _up->setEnabled(false);
        }
        if ((index < _values->topLevelItemCount() - 1) &&
                (index >= 0)) {
            _down->setEnabled(true);
        } else {
            _down->setEnabled(false);
        }
        _remove->setEnabled(true);
    } else {
        _up->setEnabled(false);
        _down->setEnabled(false);
        _remove->setEnabled(false);
    }
    _editor->setData(PhysicalItem::getData(current));
}

void CreatePhysicalDialog::setData(DeskData::IData *data)
{
    DeskData::IPhysical* physical = (DeskData::IPhysical*)data;
    if (!physical) {
        return;
    }
    QTreeWidgetItem* current = _values->currentItem();
    current->setText(0,
                     DeskData::doubleToString(physical->getValue()) +
                     " " +
                     DeskData::dimentionToString(physical->getDimention()));
    current->setText(1, physical->getDescription());
}

} // namespace DeskGui

