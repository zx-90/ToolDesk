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

#ifndef DESKDATA_SUMMATION_H
#define DESKDATA_SUMMATION_H

#include "include/data/ISummation.h"
#include <string>

namespace DeskData {

class Summation : public ISummation
{
public:
    Summation();
    virtual ~Summation();

    virtual void release();

    virtual void setDescription(const Char* description);
    virtual const Char* getDescription() const;

    virtual void setInData(const IData* data);
    virtual void registerInData(IData* data);
    virtual void registerOutData(IData* data);

    virtual const IContainer* getInContainer() const;
    virtual const IContainer* getOutContainer() const;
    virtual IContainer* getRegisterContainer() const;

private:
    std::wstring _description;
    IContainer* _inContainer;
    IContainer* _outContainer;
    IContainer* _registerContainer;
};

} // namespace DeskData

#endif // DESKDATA_SUMMATION_H
