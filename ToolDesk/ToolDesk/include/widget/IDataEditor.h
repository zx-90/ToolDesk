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

#ifndef ICREATEWIDGET
#define ICREATEWIDGET

#include <QWidget>
#include "include/data/IData.h"

namespace DeskGui {

class IDataEditor : public QWidget {
public:
    IDataEditor(DeskData::IData* data, QWidget* parent = 0) :
        QWidget(parent), _data(data) {}
    virtual ~IDataEditor() {}

signals:
    void dataChanged(DeskData::IData* data);

protected:
    DeskData::IData* _data;

};

}

#endif // ICREATEWIDGET

