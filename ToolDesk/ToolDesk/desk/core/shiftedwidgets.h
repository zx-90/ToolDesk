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

#include "shiftedwidgettemplate.h"

#include <QLineEdit>
typedef ShiftedEditedWidgetTemplate<QLineEdit> ShiftedLineEdit;

#include <QTreeWidget>
typedef ShiftedWidgetTemplate<QTreeWidget> ShiftedTreeWidget;

#include <QComboBox>
typedef ShiftedWidgetTemplate<QComboBox> ShiftedComboBox;

#include <QSpinBox>
typedef ShiftedWidgetTemplate<QSpinBox> ShiftedSpinBox;

#endif // SHIFTEDLINEEDIT_H
