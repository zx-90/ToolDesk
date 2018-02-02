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

#include "dimentioneditor.h"
#include <QVBoxLayout>

namespace DeskGui {

DimentionEditor::DimentionEditor(DeskData::IData *data, QWidget *parent) :
    IDataEditor(data, parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    _dimentionUnitTree = new QTreeWidget(this);
    QWidget::connect(
                _dimentionUnitTree,SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)),
                this,SLOT(redraw()));
    QWidget::connect(
                _dimentionUnitTree,SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)),
                this,SLOT(redraw()));
    QStringList headerLabels;
    headerLabels.push_back("prefix");
    headerLabels.push_back("dimention");
    headerLabels.push_back("pow");
    _dimentionUnitTree->setHeaderLabels(headerLabels);
    layout->addWidget(_dimentionUnitTree);

    _dimentionActions = new QWidget(this);
    layout->addWidget(_dimentionActions);
    QHBoxLayout* dimentionActionsLayout = new QHBoxLayout(_dimentionActions);
    _dimentionUnitDelete = new QPushButton("-",_dimentionActions);
    _dimentionUnitDelete->setEnabled(false);
    QWidget::connect(_dimentionUnitDelete,SIGNAL(clicked()),this,SLOT(onDeleteDimention()));
    dimentionActionsLayout->addWidget(_dimentionUnitDelete);
    _dimentionUnitUp = new QPushButton("Up",_dimentionActions);
    _dimentionUnitUp->setEnabled(false);
    QWidget::connect(_dimentionUnitUp,SIGNAL(clicked()),this,SLOT(onMoveUpDimention()));
    dimentionActionsLayout->addWidget(_dimentionUnitUp);
    _dimentionUnitDown = new QPushButton("Down",_dimentionActions);
    _dimentionUnitDown->setEnabled(false);
    QWidget::connect(_dimentionUnitDown,SIGNAL(clicked()),this,SLOT(onMoveDownDimention()));
    dimentionActionsLayout->addWidget(_dimentionUnitDown);

    _dimentionAdd = new QWidget(this);
    layout->addWidget(_dimentionAdd);
    QHBoxLayout* dimentionLayout = new QHBoxLayout(_dimentionAdd);
    _dimentionPrefixList = new QComboBox(_dimentionAdd);
    dimentionLayout->addWidget(_dimentionPrefixList);
    for (DeskData::Size i = 0; i < DeskData::METRIC_PREFIXES_SIZE; i++) {
        _dimentionPrefixList->addItem(QString::fromWCharArray(DeskData::METRIC_PREFIXES[i].name));
    }
    _dimentionUnitList = new QComboBox(_dimentionAdd);
    dimentionLayout->addWidget(_dimentionUnitList);
    for (DeskData::Size i = 0; i < DeskData::METRIX_UNITS_SIZE; i++) {
        _dimentionUnitList->addItem(
                    QString::fromWCharArray(DeskData::METRIX_UNITS[i].name) + "\t" +
                    QString::fromWCharArray(DeskData::METRIX_UNITS[i].symbol));
    }
    _dimentionPowerList = new QComboBox(_dimentionAdd);
    dimentionLayout->addWidget(_dimentionPowerList);
    _dimentionPowerList->addItem("4");
    _dimentionPowerList->addItem("3");
    _dimentionPowerList->addItem("2");
    _dimentionPowerList->addItem("1");
    _dimentionPowerList->addItem("-1");
    _dimentionPowerList->addItem("-2");
    _dimentionPowerList->addItem("-3");
    _dimentionPowerList->addItem("-4");
    _dimentionPowerList->setCurrentIndex(3);
    _dimentionUnitAdd = new QPushButton("+",_dimentionActions);
    dimentionLayout->addWidget(_dimentionUnitAdd);
    QWidget::connect(_dimentionUnitAdd,SIGNAL(clicked()),this,SLOT(onAddDimention()));

    redraw();
}

DimentionEditor::~DimentionEditor()
{

}

void DimentionEditor::onAddDimention()
{
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setData(0,Qt::UserRole,QVariant(_dimentionPrefixList->currentIndex()));
    item->setText(0,_dimentionPrefixList->currentText());
    item->setData(1,Qt::UserRole,QVariant(_dimentionUnitList->currentIndex()));
    item->setText(1,_dimentionUnitList->currentText());
    int power = 4 - _dimentionPowerList->currentIndex();
    if (power < 1) power--;
    item->setData(2,Qt::UserRole,QVariant(power));
    item->setText(2,_dimentionPowerList->currentText());
    _dimentionUnitTree->addTopLevelItem(item);
    _dimentionUnitTree->setCurrentItem(item);
    redraw();
}

void DimentionEditor::onDeleteDimention()
{
    QTreeWidgetItem* item = _dimentionUnitTree->currentItem();
    if (item == NULL) {
        return;
    }
    delete item;
    redraw();
    redraw();
}

void DimentionEditor::onMoveUpDimention()
{
    QTreeWidgetItem* current = _dimentionUnitTree->currentItem();
    int itemIndex = _dimentionUnitTree->indexOfTopLevelItem(current);
    if (itemIndex <= 0) {
        redraw();
        return;
    }
    _dimentionUnitTree->takeTopLevelItem(itemIndex);
    _dimentionUnitTree->insertTopLevelItem(itemIndex - 1, current);
    _dimentionUnitTree->setCurrentItem(current);
    redraw();
}

void DimentionEditor::onMoveDownDimention()
{
    QTreeWidgetItem* current = _dimentionUnitTree->currentItem();
    int itemIndex = _dimentionUnitTree->indexOfTopLevelItem(current);
    if (itemIndex >= _dimentionUnitTree->topLevelItemCount() - 1) {
        redraw();
        return;
    }
    _dimentionUnitTree->takeTopLevelItem(itemIndex);
    _dimentionUnitTree->insertTopLevelItem(itemIndex + 1, current);
    _dimentionUnitTree->setCurrentItem(current);
    redraw();
}

void DimentionEditor::redraw()
{
    if (_dimentionUnitTree->currentItem() == NULL) {
        _dimentionUnitDelete->setEnabled(false);
        _dimentionUnitUp->setEnabled(false);
        _dimentionUnitDown->setEnabled(false);
    } else {
        _dimentionUnitDelete->setEnabled(true);
        int row = _dimentionUnitTree->currentIndex().row();
        if (row == 0) {
            _dimentionUnitUp->setEnabled(false);
        } else {
            _dimentionUnitUp->setEnabled(true);
        }
        if (row < _dimentionUnitTree->model()->rowCount() - 1) {
            _dimentionUnitDown->setEnabled(true);
        } else {
            _dimentionUnitDown->setEnabled(false);
        }
    }
    if (_dimentionUnitTree->topLevelItemCount() < (int)DeskData::DIMENTION_MAX_SIZE) {
        _dimentionUnitAdd->setEnabled(true);
    } else {
        _dimentionUnitAdd->setEnabled(false);
    }

    DeskData::IDimention* dimention =
            (DeskData::IDimention*)_data;
    dimention->clear();
    for (int i = 0; i < _dimentionUnitTree->topLevelItemCount(); i++) {
        QTreeWidgetItem* item = _dimentionUnitTree->topLevelItem(i);
        int prefixIndex = item->data(0,Qt::UserRole).toInt();
        int valueIndex = item->data(1,Qt::UserRole).toInt();
        int power = item->data(2,Qt::UserRole).toInt();
        dimention->addDimention(valueIndex,power,prefixIndex);
    }

    emit dataChanged(_data);
}

} // namespace DeskGui

