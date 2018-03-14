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

#ifndef SHIFTEDWIDGETTEMPLATE_H
#define SHIFTEDWIDGETTEMPLATE_H

#include <QWidget>

//*********************************************************************
// ShiftedEditedWidgetTemplate
//*********************************************************************

template<class T> class ShiftedEditedWidgetTemplate : public T
{
    //Q_OBJECT
public:
    ShiftedEditedWidgetTemplate(QWidget* parent = nullptr, bool shiftLeft = true, bool shiftRight = true);

protected:
    bool _shiftLeft;
    bool _shiftRight;

    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void focusInEvent(QFocusEvent *event) override;
};

#include <QKeyEvent>
#include <QFocusEvent>

template <typename T> ShiftedEditedWidgetTemplate<T>::ShiftedEditedWidgetTemplate(QWidget *parent, bool shiftLeft, bool shiftRight) :
    T(parent),
    _shiftLeft(shiftLeft),
    _shiftRight(shiftRight)
{

}

template <typename T> void ShiftedEditedWidgetTemplate<T>::keyPressEvent(QKeyEvent *event)
{
    if ((_shiftLeft) &&
            (T::cursorPosition() == 0) &&
            (!T::hasSelectedText()) &&
            (event->key() == Qt::Key_Left)) {

        T::focusPreviousChild();

    } else if ((_shiftRight) &&
            (T::cursorPosition() == T::text().length()) &&
            (!T::hasSelectedText()) &&
            (event->key() == Qt::Key_Right)) {

        T::focusNextChild();

    } else {
        T::keyPressEvent(event);
    }
}

template <typename T> void ShiftedEditedWidgetTemplate<T>::focusInEvent(QFocusEvent *event)
{
    T::focusInEvent(event);
    if ((event->gotFocus()) && (event->reason() == Qt::TabFocusReason)) {
        T::setCursorPosition(0);
    } else if ((event->gotFocus()) && (event->reason() == Qt::BacktabFocusReason)) {
        T::setCursorPosition(T::text().length());
    }
}

//*********************************************************************
// ShiftedWidgetTemplate
//*********************************************************************

template<class T> class ShiftedWidgetTemplate : public T
{
    //Q_OBJECT
public:
    ShiftedWidgetTemplate(QWidget* parent = nullptr, bool shiftLeft = true, bool shiftRight = true);

protected:
    bool _shiftLeft;
    bool _shiftRight;

    virtual void keyPressEvent(QKeyEvent *event) override;
};

#include <QKeyEvent>
#include <QFocusEvent>

template <typename T> ShiftedWidgetTemplate<T>::ShiftedWidgetTemplate(QWidget *parent, bool shiftLeft, bool shiftRight) :
    T(parent),
    _shiftLeft(shiftLeft),
    _shiftRight(shiftRight)
{

}

template <typename T> void ShiftedWidgetTemplate<T>::keyPressEvent(QKeyEvent *event)
{
    if ((_shiftLeft) &&
        (event->key() == Qt::Key_Left)) {

        T::focusPreviousChild();

    } else if ((_shiftRight)  &&
        (event->key() == Qt::Key_Right)) {

        T::focusNextChild();

    } else {
        T::keyPressEvent(event);
    }
}

#endif // SHIFTEDWIDGETTEMPLATE_H
