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

#include "createtimeseriesdialog.h"
#include <limits>

CreateTimeSeriesDialog::CreateTimeSeriesDialog(DeskData::IProject *project, QWidget *parent) :
    IFunctionDialog(project, parent),
    _layout(new QVBoxLayout(this)),
    _description(new DeskGui::DescriptionEditor(nullptr, this)),
    _size(new QSpinBox(this)),

    _dimentionX(new DeskGui::DimentionEditor(nullptr, this)),
    _typeX(new QGroupBox(this)),
    _isOffsetX(new QRadioButton(_typeX)),
    _isArrayX(new QRadioButton(_typeX)),
    _offsetX(new DeskGui::BaseDoubleEditor(this)),
    _quantX(new DeskGui::BaseDoubleEditor(this)),

    _dimentionY(new DeskGui::DimentionEditor(nullptr, this)),
    _typeY(new QGroupBox(this)),
    _isOffsetY(new QRadioButton(_typeY)),
    _isArrayY(new QRadioButton(_typeY)),
    _offsetY(new DeskGui::BaseDoubleEditor(this)),

    _chart(new TimeSeriesViewer(nullptr, this))

{
    _layout->addWidget(_description);
    _layout->addWidget(new QLabel("Points: ", this));
    _size->setMinimum(2);
    _size->setMaximum(INT_MAX);
    _size->setValue(1000);
    _layout->addWidget(_size);

    _layout->addWidget(_dimentionX);
    _layout->addWidget(_typeX);
    _layout->addWidget(_offsetX);
    _layout->addWidget(_quantX);

    _layout->addWidget(_dimentionY);
    _layout->addWidget(_typeY);
    _layout->addWidget(_offsetY);

    _layout->addWidget(_chart);

    resize(400, 400);
}

CreateTimeSeriesDialog::~CreateTimeSeriesDialog()
{

}

void CreateTimeSeriesDialog::runFunction()
{

}
