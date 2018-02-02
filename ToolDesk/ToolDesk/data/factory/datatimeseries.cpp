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

#include "datatimeseries.h"

#include <string.h>
#include "datadimention.h"

namespace DeskData {

DataTimeSeries::DataTimeSeries()
{
    _xDimention = new DataDimention();
    _xOffset = 0.0;
    _xQuant = 1.0;
    _yDimention = new DataDimention();
    _yOffset = 0.0;
    _yQuant = 1.0;

    _size = 0;
    _array = new Double[_size];
}

DataTimeSeries::~DataTimeSeries()
{
    _xDimention->release();
    _yDimention->release();
    delete _array;
}

void DataTimeSeries::release()
{
    delete this;
}

Size DataTimeSeries::getType() const
{
    return DATATYPE_TIMESERIES;
}

void DataTimeSeries::setId(Size id)
{
    _id = id;
}

Size DataTimeSeries::getId() const
{
    return _id;
}

const Char *DataTimeSeries::getDescription() const
{
    return _description.c_str();
}

void DataTimeSeries::setDescription(const Char *description)
{
    _description = description;
}

ITimeSeries *DataTimeSeries::clone() const
{
    DataTimeSeries* result = new DataTimeSeries();
    result->setDescription(getDescription());
    result->setXDimention(getXDimention());
    result->setXOffset(getXOffset());
    result->setXQuant(getXQuant());
    result->setYDimention(getYDimention());
    result->setYOffset(getYOffset());
    result->setYQuant(getYQuant());
    result->setSize(getSize());
    memcpy(result->_array, _array, _size * sizeof(Double));
    return result;
}

void DataTimeSeries::setXDimention(const IDimention *dimention)
{
    if (dimention == NULL) {
        return;
    }
    if (dimention == _xDimention) {
        return;
    }
    _xDimention->release();
    _xDimention = dimention->clone();
}

IDimention *DataTimeSeries::getXDimention()
{
    return _xDimention;
}

const IDimention *DataTimeSeries::getXDimention() const
{
    return _xDimention;
}

void DataTimeSeries::setXOffset(const Double xOffset)
{
    _xOffset = xOffset;
}

Double DataTimeSeries::getXOffset() const
{
    return _xOffset;
}

void DataTimeSeries::setXQuant(const Double xQuant)
{
    _xQuant = xQuant;
}

Double DataTimeSeries::getXQuant() const
{
    return _xQuant;
}

void DataTimeSeries::setYDimention(const IDimention *dimention)
{
    if (dimention == NULL) {
        return;
    }
    if (dimention == _yDimention) {
        return;
    }
    _yDimention->release();
    _yDimention = dimention->clone();
}

IDimention *DataTimeSeries::getYDimention()
{
    return _yDimention;
}

const IDimention *DataTimeSeries::getYDimention() const
{
    return _yDimention;
}

void DataTimeSeries::setYOffset(const Double yOffset)
{
    _yOffset = yOffset;
}

Double DataTimeSeries::getYOffset() const
{
    return _yOffset;
}

void DataTimeSeries::setYQuant(const Double yQuant)
{
    _yQuant = yQuant;
}

Double DataTimeSeries::getYQuant() const
{
    return _yQuant;
}

void DataTimeSeries::setSize(Size size)
{
    _size = size;
    delete _array;
    _array = new Double[size];
}

Size DataTimeSeries::getSize() const
{
    return _size;
}

Double *DataTimeSeries::getArrayY()
{
    return _array;
}

const Double *DataTimeSeries::getArrayY() const
{
    return _array;
}

} // namespace ToolDeskData
