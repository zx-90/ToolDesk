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

#ifndef DESKGUI_BASEDOUBLEEDITOR_H
#define DESKGUI_BASEDOUBLEEDITOR_H

#include <QWidget>
#include <QLabel>
#include "desk/core/shiftedwidgets.h"
#include "include/data/DataList.h"

namespace DeskGui {

class BaseDoubleEditor : public QWidget
{
    Q_OBJECT

public:
    BaseDoubleEditor(QWidget* parent = 0);
    ~BaseDoubleEditor();

    void setDouble(DeskData::Double d);

signals:
    void dataChanged(QString value);
    void dataChangedDouble(double value);

public slots:
    void redraw();

private slots:
    void resizeToContent();
    void onBaseReturnPressed();
    void onPowerReturnPressed();

private:
    ShiftedLineEdit* _base;
    QLabel* _tenBase;
    ShiftedLineEdit* _power;

    DeskData::Double getDouble(QString string, bool& isOk);

};

} // namespace DeskGui

#endif // DESKGUI_BASEDOUBLEEDITOR_H
