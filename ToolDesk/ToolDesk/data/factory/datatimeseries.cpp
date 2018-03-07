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

DataTimeSeries::DataTimeSeries() :
    _id(0),
    _description(""),
    _size(0),
    _xDimention(new DataDimention()),
    _isXOffset(true),
    _xOffset(0),
    _xQuant(1),
    _arrayX(nullptr),
    _yDimention(new DataDimention()),
    _isYOffset(true),
    _yOffset(1),
    _arrayY(nullptr)
{
}

DataTimeSeries::~DataTimeSeries()
{
    _xDimention->release();
    _yDimention->release();
    delete _arrayX;
    _arrayX = nullptr;
    delete _arrayY;
    _arrayY = nullptr;
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

const QString DataTimeSeries::getDescription() const
{
    return _description;
}

void DataTimeSeries::setDescription(const QString description)
{
    _description = description;
}

ITimeSeries *DataTimeSeries::clone() const
{
    DataTimeSeries* result = new DataTimeSeries();
    result->setDescription(getDescription());

    result->setSize(getSize());

    result->setXDimention(getXDimention());
    if (isXOffset()) {
        result->setXOffset(getXOffset(), getXQuant());
    } else if (isArrayX()) {
        result->setArrayX();
        memcpy(result->_arrayX, _arrayX, _size * sizeof(Double));
    }

    result->setYDimention(getYDimention());
    if (isYOffset()) {
        result->setYOffset(getYOffset());
    } else if (isArrayY()) {
        result->setArrayY();
        memcpy(result->_arrayY, _arrayY, _size * sizeof(Double));
    }

    return result;
}

void DataTimeSeries::setSize(Size size)
{
    _size = size;
    delete _arrayX;
    _arrayX = new Double[size];
    delete _arrayY;
    _arrayY = new Double[size];
}

Size DataTimeSeries::getSize() const
{
    return _size;
}

void DataTimeSeries::setXDimention(const IDimention *dimention)
{
    if (!dimention) {
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

void DataTimeSeries::setXOffset(const Double xOffset, const Double xQuant)
{
    _isXOffset = true;
    _xOffset = xOffset;
    _xQuant = xQuant;
    delete _arrayX;
    _arrayX = nullptr;
}

bool DataTimeSeries::isXOffset() const
{
    return _xOffset;
}

Double DataTimeSeries::getXOffset() const
{
    return _xOffset;
}

Double DataTimeSeries::getXQuant() const
{
    return _xQuant;
}

void DataTimeSeries::setArrayX()
{
    if (isArrayX()) {
        return;
    }
    _isXOffset = false;
    _arrayX = new Double[_size];
}

bool DataTimeSeries::isArrayX() const
{
    return !_xOffset;
}

Double *DataTimeSeries::getArrayX()
{
    return _arrayX;
}

const Double *DataTimeSeries::getArrayX() const
{
    return _arrayX;
}

void DataTimeSeries::setYDimention(const IDimention *dimention)
{
    if (!dimention) {
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

bool DataTimeSeries::isYOffset() const
{
    return _isYOffset;
}

Double DataTimeSeries::getYOffset() const
{
    return _yOffset;
}

void DataTimeSeries::setArrayY()
{
    if (isArrayY()) {
        return;
    }
    _isYOffset = false;
    _arrayY = new Double[_size];
}

bool DataTimeSeries::isArrayY() const
{
    return !_isYOffset;
}

Double *DataTimeSeries::getArrayY()
{
    return _arrayY;
}

const Double *DataTimeSeries::getArrayY() const
{
    return _arrayY;
}

} // namespace ToolDeskData
