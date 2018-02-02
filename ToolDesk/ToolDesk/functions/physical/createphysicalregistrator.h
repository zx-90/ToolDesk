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

#ifndef DESKGUI_CREATEPHYSICALREGISTRATOR_H
#define DESKGUI_CREATEPHYSICALREGISTRATOR_H

#include "include/function/ifunctionregistrator.h"

namespace DeskGui {

class CreatePhysicalRegistrator : public IFunctionRegistrator
{
public:
    CreatePhysicalRegistrator();
    virtual ~CreatePhysicalRegistrator();

    virtual QString getName() const;
    virtual IFunctionDialog* getDialog(DeskData::IProject* project, QWidget* parent = 0) const;

};

} // namespace DeskGui

#endif // DESKGUI_CREATEPHYSICALREGISTRATOR_H
