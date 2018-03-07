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

#include "project.h"

#include "data/factory/factory.h"

namespace DeskData {

Project::Project(Size id) : _id(id)
{
    _factory = new Factory();
    _id = 1;
}

Project::~Project()
{
    _factory->release();
}

void Project::release()
{
    delete this;
}

void Project::setId(Size id)
{
    _id = id;
}

Size Project::getId() const
{
    return _id;
}

const IFactory *Project::getFactory() const
{
    return _factory;
}

void Project::setFunctionResult(ISummation *result)
{
    _functionResults.push_back(result);
    IContainer* container = result->getRegisterContainer();
    for (Size i = 0; i < container->getSize(); i++) {
        IData* data = container->getData(i);
        data->setId(_id);
        _id++;
        _data.push_back(data);
        IContainer* container = _dataByTypes[data->getType()];
        if (!container) {
            container = _factory->createContainer();
            _dataByTypes.insert(std::pair<Size, IContainer*>(data->getType(), container));
        }
        container->addData(data);
    }
}

Size Project::getDataCount() const
{
    return _data.size();
}

const IData *Project::getData(Size number) const
{
    if (number >= _data.size()) {
        return nullptr;
    }
    return _data.at(number);
}

const IData *Project::getDataById(Size id) const
{
    for (Size i = 0; i < _data.size(); i++) {
        DeskData::IData* data = _data.at(i);
        if (data->getId() == id) {
            return data;
        }
    }
    return nullptr;
}

void Project::setData(IData *data)
{
    if (!data) {
        return;
    }
    _data.push_back(data);
}

Size Project::getFunctionCount() const
{
    return _functionResults.size();
}

const ISummation *Project::getFunctionResult(Size id) const
{
    if (id >= _functionResults.size()) {
        return nullptr;
    }
    return _functionResults.at(id);
}

const IContainer *Project::getContainerByType(Size dataType) const
{
    return _dataByTypes.find(dataType)->second;
}

} // namespace DeskData

