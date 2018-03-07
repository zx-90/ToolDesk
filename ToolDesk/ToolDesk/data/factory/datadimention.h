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

#ifndef DATADIMENTION_H
#define DATADIMENTION_H

#include <string>
#include "include/data/IDimention.h"
#include "data.h"

namespace DeskData {

class DataDimention : public IDimention
{
public:
    DataDimention();
    virtual ~DataDimention();

    virtual void release();

    virtual IDimention* clone() const;

    virtual void clear();

    virtual Size getSize() const;
    virtual Size getDimentionType(Size number) const;
    virtual Int getDimentionPower(Size number) const;
    virtual Size getDimentionPrefix(Size number) const;
    virtual bool addDimention(Size dimention, Int power,Int prefix = 0);
    virtual bool eraseDimention(Size number);

private:
    struct DimentionUnit {
        Int MetricPrefix;
        Size DimentionType;
        Int DimentionPower;
    };

    Size _id;

    Size _size;
    DimentionUnit _units[DIMENTION_MAX_SIZE];
};

}

#endif // DATADIMENTION_H
