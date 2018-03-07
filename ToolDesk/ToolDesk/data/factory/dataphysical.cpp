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

#include "dataphysical.h"
#include "datadimention.h"

namespace DeskData {

DataPhysical::DataPhysical() :
    _id(-1),
    _description(""),
    _value(0.0),
    _dimention(new DataDimention())
{
}

DataPhysical::~DataPhysical()
{
    _dimention->release();
}

void DataPhysical::release()
{
    delete this;
}

Size DataPhysical::getType() const
{
    return DATATYPE_PHYSICAL;
}

void DataPhysical::setId(Size id)
{
    _id = id;
}

Size DataPhysical::getId() const
{
    return _id;
}

const QString DataPhysical::getDescription() const
{
    return _description;
}

void DataPhysical::setDescription(const QString description)
{
    _description = description;
}

IPhysical *DataPhysical::clone() const
{
    DataPhysical* result = new DataPhysical();
    result->setDescription(getDescription());
    result->setValue(getValue());
    result->setDimention(getDimention());
    return result;
}

void DataPhysical::clear()
{
    _value = 0.0;
    _dimention->clear();
}

void DataPhysical::setValue(Double value)
{
    _value = value;
}

Double DataPhysical::getValue() const
{
    return _value;
}

void DataPhysical::setDimention(const IDimention *dimention)
{
    if (!dimention) {
        return;
    }
    if (dimention == _dimention) {
        return;
    }
    _dimention->clear();
    _dimention = dimention->clone();
}

IDimention *DataPhysical::getDimention()
{
    return _dimention;
}

const IDimention *DataPhysical::getDimention() const
{
    return _dimention;
}

}
