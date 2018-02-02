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

#include "summation.h"
#include "container.h"

namespace DeskData {

Summation::Summation()
{
    _inContainer = new Container();
    _outContainer = new Container();
    _registerContainer = new Container();
}

Summation::~Summation()
{
    _inContainer->release();
    _outContainer->release();
    _registerContainer->release();
}

void Summation::release()
{
    delete this;
}

void Summation::setDescription(const Char *description)
{
    _description = description;
}

const Char *Summation::getDescription() const
{
    return _description.c_str();
}

void Summation::setInData(const IData *data)
{
    _inContainer->addData((IData*) data);
}

void Summation::registerInData(IData *data)
{
    _inContainer->addData(data);
    _registerContainer->addData(data);
}

void Summation::registerOutData(IData *data)
{
    _outContainer->addData(data);
    _registerContainer->addData(data);
}

const IContainer *Summation::getInContainer() const
{
    return _inContainer;
}

const IContainer *Summation::getOutContainer() const
{
    return _outContainer;
}

IContainer *Summation::getRegisterContainer() const
{
    return _registerContainer;
}

} // namespace DeskData

