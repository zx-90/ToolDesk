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

#ifndef DESKDATA_DATAFACTORY_H
#define DESKDATA_DATAFACTORY_H

#include "include/project/IFactory.h"

namespace DeskData {

class Factory : public IFactory
{
public:
    Factory();
    virtual ~Factory();

    virtual void release();

    virtual IData* createData(Size type) const;
    virtual IContainer* createContainer() const;
    virtual ISummation* createSummation() const;
};

} // namespace DeskData

#endif // DESKDATA_DATAFACTORY_H
