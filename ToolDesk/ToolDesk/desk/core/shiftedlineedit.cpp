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

#include "shiftedlineedit.h"

#include <QKeyEvent>
#include <QFocusEvent>

ShiftedLineEdit::ShiftedLineEdit(QWidget* parent, bool shiftLeft, bool shiftRight) :
    QLineEdit(parent),
    _shiftLeft(shiftLeft),
    _shiftRight(shiftRight)
{

}

void ShiftedLineEdit::keyPressEvent(QKeyEvent *event)
{
    if ((_shiftLeft) &&
            (cursorPosition() == 0) &&
            (!hasSelectedText()) &&
            (event->key() == Qt::Key_Left)) {

        focusPreviousChild();

    } if ((_shiftRight) &&
            (cursorPosition() == text().length()) &&
            (!hasSelectedText()) &&
            (event->key() == Qt::Key_Right)) {

        focusNextChild();

    } else {
        QLineEdit::keyPressEvent(event);
    }
}

void ShiftedLineEdit::focusInEvent(QFocusEvent *event)
{
    QLineEdit::focusInEvent(event);
    if ((event->gotFocus()) && (event->reason() == Qt::TabFocusReason)) {
        setCursorPosition(0);
    } else if ((event->gotFocus()) && (event->reason() == Qt::BacktabFocusReason)) {
        setCursorPosition(text().length());
    }
}
