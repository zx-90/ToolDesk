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

#include "dataphysicaleditor.h"

#include <QFormLayout>
#include <QHBoxLayout>
#include "desk/core/borderlayout.h"
#include "include/data/IDimention.h"
#include "dimentionviewer.h"
#include "dimentioneditor.h"
#include "float.h"

namespace DeskGui {

DataPhysicalEditor::DataPhysicalEditor(DeskData::IData *data, QWidget *parent) :
    IDataEditor(data, parent)
{
    _physicalValue = (DeskData::IPhysical*)data;

    QFormLayout* layout = new QFormLayout(this);
    layout->setMargin(0);
    layout->setSpacing(10);

    _descriptionEditor = new DescriptionEditor(data, this);
    layout->addRow("Description:", _descriptionEditor);

    QWidget* viewWidget = new QWidget(this);
    //viewWidget->setStyleSheet("border-radius: 3px; border: 1px solid #000000;");
    QFormLayout* viewLayout = new QFormLayout(viewWidget);
    viewLayout->setMargin(0);
    viewLayout->setContentsMargins(0, 0, 0, 0);
    viewLayout->setHorizontalSpacing(0);
    _doubleViewer = new QLabel(viewWidget);
    _doubleViewer->setAlignment(Qt::AlignLeft | Qt::AlignBaseline);
    _doubleViewer->setMargin(0);
    _doubleViewer->setContentsMargins(0,0,0,0);
    _doubleViewer->setIndent(0);
    if (_physicalValue) {
        _dimentionViewer = new DimentionViewer(_physicalValue->getDimention(), viewWidget);
    } else {
        _dimentionViewer = new DimentionViewer(nullptr, viewWidget);
    }
    viewLayout->addRow(_doubleViewer, _dimentionViewer);
    layout->addRow("Value:", viewWidget);

    QWidget* editors = new QWidget(this);
    BorderLayout* editorsLayout = new BorderLayout(editors);
    layout->addWidget(editors);

    _doubleEditor = new BaseDoubleEditor(editors);
    _doubleEditor->setEnabled(false);
    editorsLayout->addWidget(_doubleEditor, BorderLayout::Center);

    if (_physicalValue) {
        _dimentionEditor = new DimentionEditor(_physicalValue->getDimention(), editors);
    } else {
        _dimentionEditor = new DimentionEditor(nullptr, editors);
    }
    editorsLayout->addWidget(_dimentionEditor, BorderLayout::East);

    QWidget::connect(
                _doubleEditor, SIGNAL(dataChanged(QString)),
                _doubleViewer, SLOT(setText(QString)));
    QWidget::connect(
                _dimentionEditor, SIGNAL(dataChanged(DeskData::IDimention*)),
                _dimentionViewer, SLOT(onDataChanged(DeskData::IDimention*)));

    QWidget::connect(
                _doubleEditor, SIGNAL(dataChangedDouble(double)),
                this, SLOT(setDouble(double)));
    QWidget::connect(
                _dimentionEditor, SIGNAL(dataChanged(DeskData::IData*)),
                this, SLOT(setDimention(DeskData::IData*)));

    QWidget::connect(
                _descriptionEditor, SIGNAL(dataChanged(DeskData::IDescription*)),
                this, SLOT(onDataChanged()));
    QWidget::connect(
                _doubleEditor, SIGNAL(dataChangedDouble(double)),
                this, SLOT(onDataChanged()));
    QWidget::connect(
                _dimentionEditor, SIGNAL(dataChanged(DeskData::IDimention*)),
                this, SLOT(onDataChanged()));

    _doubleEditor->redraw();
}

DataPhysicalEditor::~DataPhysicalEditor()
{
}

void DataPhysicalEditor::release()
{
    delete this;
}

void DataPhysicalEditor::setData(DeskData::IData *data)
{
    _data = data;
    _physicalValue = (DeskData::IPhysical*)data;

    if (_physicalValue) {
        _descriptionEditor->setDescription(_physicalValue);
        _doubleEditor->setEnabled(true);
        _doubleEditor->setDouble(_physicalValue->getValue());
        _dimentionEditor->setDimention(_physicalValue->getDimention());
    } else {
        _descriptionEditor->setDescription(nullptr);
        _doubleEditor->setEnabled(false);
        _doubleEditor->setDouble(0);
        _dimentionEditor->setDimention(nullptr);
    }
}

void DataPhysicalEditor::setDouble(double data)
{
    if (_physicalValue) {
        _physicalValue->setValue(data);
    }
}

void DataPhysicalEditor::setDimention(DeskData::IData *data)
{
    if (_physicalValue) {
        _physicalValue->setDimention((DeskData::IDimention*)data);
    }
}

void DataPhysicalEditor::onDataChanged()
{
    emit dataChanged(_physicalValue);
}

} // namespace DeskDataWidget
