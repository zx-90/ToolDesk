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

#include "data.h"

#include <wchar.h>

namespace DeskData {

DataCore::DataCore() :
    _id(0),
    _description("")
{
}

DataCore::~DataCore()
{
}

void DataCore::setId(Size id)
{
    _id = id;
}

Size DataCore::getId() const
{
    return _id;
}

void DataCore::release()
{
    delete this;
}

QString DataCore::getDescription()
{
    return _description;
}

const QString DataCore::getDescription() const
{
    return _description;
}

void DataCore::setDescription(const QString description)
{
    _description = description;
}

}
