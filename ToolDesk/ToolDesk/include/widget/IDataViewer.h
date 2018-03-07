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

#ifndef IVIEWWIDGET
#define IVIEWWIDGET

#include <QWidget>
#include "include/data/DataList.h"

namespace DeskGui {

class IDataViewer : public QWidget {
    Q_OBJECT
public:
    IDataViewer(const DeskData::IData* data, QWidget* parent = 0);
    virtual ~IDataViewer();

public slots:
    virtual void onChangeData(const DeskData::IData* = NULL);

protected:
    const DeskData::IData* _data;

};

}

#endif // IVIEWWIDGET

