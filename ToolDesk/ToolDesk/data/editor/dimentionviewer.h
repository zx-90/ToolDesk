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

#ifndef DESKGUI_DIMENTIONVIEWER_H
#define DESKGUI_DIMENTIONVIEWER_H

#include "include/widget/idataviewer.h"
#include <QLabel>

namespace DeskGui {

class DimentionViewer : public DeskGui::IDataViewer
{
    Q_OBJECT

public:
    DimentionViewer(const DeskData::IData* data, QWidget* parent = 0);
    virtual ~DimentionViewer();

public slots:
    virtual void onChangeData(const DeskData::IData* data = NULL);

private:
    QLabel* _label;

    //QString toPower(DeskData::Int num);
};

} // namespace DeskGui

#endif // DESKGUI_DIMENTIONVIEWER_H
