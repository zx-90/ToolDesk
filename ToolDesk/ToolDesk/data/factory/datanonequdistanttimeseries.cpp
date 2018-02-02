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

#include "datanonequdistanttimeseries.h"

#include <string.h>
#include "datadimention.h"

namespace DeskData {

DataNonEqudistantTimeSeries::DataNonEqudistantTimeSeries()
{
    _xDimention = new DataDimention();
    _xOffset = 0.0;
    _xQuant = 1.0;
    _yDimention = new DataDimention();
    _yOffset = 0.0;
    _yQuant = 1.0;

    _size = 0;
    _arrayX = new Double[_size];
    _arrayY = new Double[_size];
}

DataNonEqudistantTimeSeries::~DataNonEqudistantTimeSeries()
{
    _xDimention->release();
    _yDimention->release();
    delete _arrayX;
    delete _arrayY;
}

void DataNonEqudistantTimeSeries::release()
{
    delete this;
}

Size DataNonEqudistantTimeSeries::getType() const
{
    return DATATYPE_NON_EQUDISTANT_TIMESERIES;
}

void DataNonEqudistantTimeSeries::setId(Size id)
{
    _id = id;
}

Size DataNonEqudistantTimeSeries::getId() const
{
    return _id;
}

const Char *DataNonEqudistantTimeSeries::getDescription() const
{
    return _description.c_str();
}

void DataNonEqudistantTimeSeries::setDescription(const Char *description)
{
    _description = description;
}

INonEqudistantTimeSeries *DataNonEqudistantTimeSeries::clone() const
{
    DataNonEqudistantTimeSeries* result = new DataNonEqudistantTimeSeries();
    result->setDescription(getDescription());
    result->setXDimention(getXDimention());
    result->setXOffset(getXOffset());
    result->setXQuant(getXQuant());
    result->setYDimention(getYDimention());
    result->setYOffset(getYOffset());
    result->setYQuant(getYQuant());
    result->setSize(getSize());
    memcpy(result->_arrayX, _arrayX, _size * sizeof(Double));
    memcpy(result->_arrayY, _arrayY, _size * sizeof(Double));
    return result;
}

void DataNonEqudistantTimeSeries::setXDimention(const IDimention *dimention)
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

IDimention *DataNonEqudistantTimeSeries::getXDimention()
{
    return _xDimention;
}

const IDimention *DataNonEqudistantTimeSeries::getXDimention() const
{
    return _xDimention;
}

void DataNonEqudistantTimeSeries::setXOffset(const Double xOffset)
{
    _xOffset = xOffset;
}

Double DataNonEqudistantTimeSeries::getXOffset() const
{
    return _xOffset;
}

void DataNonEqudistantTimeSeries::setXQuant(const Double xQuant)
{
    _xQuant = xQuant;
}

Double DataNonEqudistantTimeSeries::getXQuant() const
{
    return _xQuant;
}

void DataNonEqudistantTimeSeries::setYDimention(const IDimention *dimention)
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

IDimention *DataNonEqudistantTimeSeries::getYDimention()
{
    return _yDimention;
}

const IDimention *DataNonEqudistantTimeSeries::getYDimention() const
{
    return _yDimention;
}

void DataNonEqudistantTimeSeries::setYOffset(const Double yOffset)
{
    _yOffset = yOffset;
}

Double DataNonEqudistantTimeSeries::getYOffset() const
{
    return _yOffset;
}

void DataNonEqudistantTimeSeries::setYQuant(const Double yQuant)
{
    _yQuant = yQuant;
}

Double DataNonEqudistantTimeSeries::getYQuant() const
{
    return _yQuant;
}

void DataNonEqudistantTimeSeries::setSize(Size size)
{
    _size = size;
    delete _arrayX;
    _arrayX = new Double[size];
    delete _arrayY;
    _arrayY = new Double[size];
}

Size DataNonEqudistantTimeSeries::getSize() const
{
    return _size;
}

Double *DataNonEqudistantTimeSeries::getArrayX()
{
    return _arrayX;
}

const Double *DataNonEqudistantTimeSeries::getArrayX() const
{
    return _arrayX;
}

Double *DataNonEqudistantTimeSeries::getArrayY()
{
    return _arrayY;
}

const Double *DataNonEqudistantTimeSeries::getArrayY() const
{
    return _arrayY;
}

} // namespace DeskData

