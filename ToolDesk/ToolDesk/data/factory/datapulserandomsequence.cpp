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

#include "datapulserandomsequence.h"

#include <string.h>
#include "datadimention.h"

namespace DeskData {

DataPulseRandomSequence::DataPulseRandomSequence()
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

DataPulseRandomSequence::~DataPulseRandomSequence()
{
    _xDimention->release();
    _yDimention->release();
    delete _array;
}

void DataPulseRandomSequence::release()
{
    delete this;
}

Size DataPulseRandomSequence::getType() const
{
    return DATATYPE_PULSE_RANDOM_SEQUENCE;

}

void DataPulseRandomSequence::setId(Size id)
{
    _id = id;
}

Size DataPulseRandomSequence::getId() const
{
    return _id;
}

const Char *DataPulseRandomSequence::getDescription() const
{
    return _description.c_str();
}

void DataPulseRandomSequence::setDescription(const Char *description)
{
    _description = description;
}

IPulseRandomSequence *DataPulseRandomSequence::clone() const
{
    DataPulseRandomSequence* result = new DataPulseRandomSequence();
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

void DataPulseRandomSequence::setXDimention(const IDimention *dimention)
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

IDimention *DataPulseRandomSequence::getXDimention()
{
    return _xDimention;
}

const IDimention *DataPulseRandomSequence::getXDimention() const
{
    return _xDimention;
}

void DataPulseRandomSequence::setXOffset(const Double xOffset)
{
    _xOffset = xOffset;
}

Double DataPulseRandomSequence::getXOffset() const
{
    return _xOffset;
}

void DataPulseRandomSequence::setXQuant(const Double xQuant)
{
    _xQuant = xQuant;
}

Double DataPulseRandomSequence::getXQuant() const
{
    return _xQuant;
}

void DataPulseRandomSequence::setYDimention(const IDimention *dimention)
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

IDimention *DataPulseRandomSequence::getYDimention()
{
    return _yDimention;
}

const IDimention *DataPulseRandomSequence::getYDimention() const
{
    return _yDimention;
}

void DataPulseRandomSequence::setYOffset(const Double yOffset)
{
    _yOffset = yOffset;
}

Double DataPulseRandomSequence::getYOffset() const
{
    return _yOffset;
}

void DataPulseRandomSequence::setYQuant(const Double yQuant)
{
    _yQuant = yQuant;
}

Double DataPulseRandomSequence::getYQuant() const
{
    return _yQuant;
}

void DataPulseRandomSequence::setSize(Size size)
{
    _size = size;
    delete _array;
    _array = new Double[size];
}

Size DataPulseRandomSequence::getSize() const
{
    return _size;
}

Double *DataPulseRandomSequence::getArrayX()
{
    return _array;
}

const Double *DataPulseRandomSequence::getArrayX() const
{
    return _array;
}

} // namespace DeskData

