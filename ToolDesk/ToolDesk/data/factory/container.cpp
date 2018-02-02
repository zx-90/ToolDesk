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

#include "container.h"

namespace DeskData {

Container::Container()
{

}

Container::~Container()
{

}

void Container::release()
{
    delete this;
}

Size Container::getSize() const
{
    return _container.size();
}

void Container::addData(IData *data)
{
    _container.push_back(data);
}

void Container::eraseData(Size number)
{
    if (number >= _container.size()) {
        return;
    }
    _container.erase(_container.begin() + number);
}

IData *Container::getData(Size number)
{
    if (number >= _container.size()) {
        return NULL;
    }
    return _container.at(number);
}

const IData *Container::getData(Size number) const
{
    if (number >= _container.size()) {
        return NULL;
    }
    return _container.at(number);
}

} // namespace DeskData

