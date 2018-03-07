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

#include "datadimention.h"

namespace DeskData {

DataDimention::DataDimention() :
    _id(-1),
    _size(0)
{
}

DataDimention::~DataDimention()
{
}

void DataDimention::release()
{
    delete this;
}

IDimention *DataDimention::clone() const
{
    DataDimention* result = new DataDimention();
    result->_size = _size;
    for (Size i = 0; i < _size; i++) {
        result->_units[i].MetricPrefix = _units[i].MetricPrefix;
        result->_units[i].DimentionType = _units[i].DimentionType;
        result->_units[i].DimentionPower = _units[i].DimentionPower;
    }
    return result;
}

void DataDimention::clear()
{
    _size = 0;
}

Size DataDimention::getSize() const
{
    return _size;
}

Size DataDimention::getDimentionType(Size number) const
{
    if (number >= _size) {
        return 0;
    }
    return _units[number].DimentionType;
}

Int DataDimention::getDimentionPower(Size number) const
{
    if (number >= _size) {
        return 0;
    }
    return _units[number].DimentionPower;
}

Size DataDimention::getDimentionPrefix(Size number) const
{
    if (number >= _size) {
        return 0;
    }
    return _units[number].MetricPrefix;
}

bool DataDimention::addDimention(Size dimention, Int power, Int prefix)
{
    if (_size >= DIMENTION_MAX_SIZE) {
        return false;
    }
    _units[_size].DimentionType = dimention;
    _units[_size].DimentionPower = power;
    _units[_size].MetricPrefix = prefix;
    _size++;
    return true;
}

bool DataDimention::eraseDimention(Size number)
{
    if (number >= _size) {
        return false;
    }
    for (Size i = number; i < _size-1; i++) {
        _units[i].DimentionType = _units[i + 1].DimentionType;
        _units[i].DimentionPower = _units[i + 1].DimentionPower;
        _units[i].MetricPrefix = _units[i + 1].MetricPrefix;
    }
    _size--;
    return true;
}

}
