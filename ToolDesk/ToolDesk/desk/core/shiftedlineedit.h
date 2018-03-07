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

#ifndef SHIFTEDLINEEDIT_H
#define SHIFTEDLINEEDIT_H

#include <QLineEdit>

class ShiftedLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    ShiftedLineEdit(QWidget* parent = nullptr, bool shiftLeft = true, bool shiftRight = true);

protected:
    bool _shiftLeft;
    bool _shiftRight;

    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void focusInEvent(QFocusEvent *event) override;
};

#endif // SHIFTEDLINEEDIT_H
