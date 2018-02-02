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

#include "dataphysicalviewer.h"

namespace DeskGui {

DataPhysicalViewer::DataPhysicalViewer(const DeskData::IData *data, QWidget* parent) :
    IDataViewer(data, parent)
{

    _layout = new QVBoxLayout(this);
    _description = NULL;
    _number = NULL;
    _dimention = NULL;

    _description = new DescriptionViewer(data, this);
    _layout->addWidget(_description);

    DeskData::IPhysical* physical = (DeskData::IPhysical*)data;
    _number = new QLabel(DeskData::doubleToString(physical->getValue()), this);
    _layout->addWidget(_number);

    _dimention = new DimentionViewer(physical->getDimention(), this);
    _layout->addWidget(_dimention);
}

DataPhysicalViewer::~DataPhysicalViewer()
{

}

void DataPhysicalViewer::onChangeData(const DeskData::IData *data)
{
    _data = data;
    _description->onChangeData(data);
    DeskData::IPhysical* physical = (DeskData::IPhysical*)data;
    _number->setText(DeskData::doubleToString(physical->getValue()));
    _dimention->onChangeData(data);
}

}
