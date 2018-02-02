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

#ifndef DESKDATA_CONTAINER_H
#define DESKDATA_CONTAINER_H

#include "include/data/IContainer.h"
#include <vector>
#include <string>

namespace DeskData {

class Container : public IContainer
{
public:
    Container();
    virtual ~Container();

    virtual void release();

    virtual Size getSize() const;

    virtual void addData(IData* data);
    virtual void eraseData(Size number);
    virtual IData* getData(Size number);
    virtual const IData* getData(Size number) const;

private:
    std::vector<IData*> _container;

};

} // namespace DeskData

#endif // DESKDATA_CONTAINER_H
