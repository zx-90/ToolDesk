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

#ifndef DESKDATA_PROJECT_H
#define DESKDATA_PROJECT_H

#include "include/project/IProject.h"
#include "include/data/IData.h"
#include "include/project/IFactory.h"
#include "include/data/ISummation.h"
#include <vector>
#include <map>

namespace DeskData {

class Project : public IProject
{
public:
    Project(Size id = 1);
    ~Project();

    virtual void release();

    virtual void setId(Size id);
    virtual Size getId() const;

    virtual const IFactory* getFactory() const;

    virtual void setFunctionResult(ISummation* result);

    virtual Size getDataCount() const;
    virtual const IData* getData(Size number) const;
    virtual const IData *getDataById(Size id) const;
    virtual void setData(IData* data);

    virtual Size getFunctionCount() const;
    virtual const ISummation* getFunctionResult(Size id) const;

    virtual const IContainer* getContainerByType(Size dataType) const;

private:
    IFactory* _factory;

    Size _id;
    std::vector<IData*> _data;
    std::map<Size, IContainer*> _dataByTypes;
    std::vector<ISummation*> _functionResults;

};

} // namespace DeskData

#endif // DESKDATA_PROJECT_H
