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

#ifndef CREATETIMESERIES_H
#define CREATETIMESERIES_H

#include "include/function/IFunctionRegistrator.h"
#include "createtimeseriesdialog.h"

class CreateTimeSeriesRegistrator : public DeskGui::IFunctionRegistrator
{
public:
    CreateTimeSeriesRegistrator();
    virtual ~CreateTimeSeriesRegistrator();

    virtual QString getName() const;
    virtual DeskGui::IFunctionDialog *getDialog(DeskData::IProject* project, QWidget* parent = 0) const;

};

#endif // CREATETIMESERIES_H
