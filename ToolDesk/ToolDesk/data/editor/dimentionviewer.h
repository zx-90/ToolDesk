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

#include "include/widget/IDataViewer.h"
#include <QLabel>

namespace DeskGui {

class DimentionViewer : public QWidget//: public DeskGui::IDataViewer
{
    Q_OBJECT

public:
    DimentionViewer(const DeskData::IDimention *data, QWidget* parent = 0);
    virtual ~DimentionViewer();

public slots:
    virtual void onDataChanged(DeskData::IDimention *data = NULL);

private:
    QLabel* _label;
    const DeskData::IDimention* _data;

};

} // namespace DeskGui

#endif // DESKGUI_DIMENTIONVIEWER_H
