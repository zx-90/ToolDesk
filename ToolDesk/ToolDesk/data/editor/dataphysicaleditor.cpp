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

#include <QVBoxLayout>
#include <QHBoxLayout>
#include "include/data/IDataDimention.h"
#include "dimentionviewer.h"
#include "dimentioneditor.h"
#include "float.h"

namespace DeskGui {

DataPhysicalEditor::DataPhysicalEditor(DeskData::IData *data, QWidget *parent) :
    IDataEditor(data, parent)
{
    _physicalValue = (DeskData::IPhysical*)data;

    setWindowTitle("Create physical value");

    QVBoxLayout* layout = new QVBoxLayout(this);

    _descriptionEditor = new DescriptionEditor(data, this);
    layout->addWidget(_descriptionEditor);

    QWidget* viewWidget = new QWidget(this);
    layout->addWidget(viewWidget);
    QHBoxLayout* viewLayout = new QHBoxLayout(viewWidget);
    _doubleViewer = new QLabel(viewWidget);
    _doubleViewer->setAlignment(Qt::AlignCenter);
    viewLayout->addWidget(_doubleViewer);
    _dimentionViewer = new DimentionViewer(_physicalValue->getDimention(),viewWidget);
    viewLayout->addWidget(_dimentionViewer);

    _doubleEditor = new BaseDoubleEditor(this);
    layout->addWidget(_doubleEditor);

    _dimentionEditor = new DimentionEditor(_physicalValue->getDimention(),this);
    layout->addWidget(_dimentionEditor);

    QWidget::connect(
                _doubleEditor, SIGNAL(dataChanged(QString)),
                _doubleViewer, SLOT(setText(QString)));
    QWidget::connect(
                _dimentionEditor, SIGNAL(dataChanged(DeskData::IData*)),
                _dimentionViewer, SLOT(onChangeData(DeskData::IData*)));

    connect( _doubleEditor, SIGNAL(dataChangedDouble(double)),
             this, SLOT(setDouble(double)));
    connect( _dimentionEditor, SIGNAL(dataChanged(DeskData::IData*)),
             this, SLOT(setDimention(DeskData::IData*)));

    _doubleEditor->redraw();
}

DataPhysicalEditor::~DataPhysicalEditor()
{
}

void DataPhysicalEditor::release()
{
    delete this;
}

void DataPhysicalEditor::setDouble(double data)
{
    _physicalValue->setValue(data);
}

void DataPhysicalEditor::setDimention(DeskData::IData *data)
{
    _physicalValue->setDimention((DeskData::IDimention*)data);
}

} // namespace DeskDataWidget
