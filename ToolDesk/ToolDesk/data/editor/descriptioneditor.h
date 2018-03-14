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

#ifndef DESCRIPTIONEDITOR_H
#define DESCRIPTIONEDITOR_H

#include "desk/core/shiftedwidgets.h"
#include "include/widget/IDataEditor.h"

namespace DeskGui {

class DescriptionEditor : public QWidget
{
    Q_OBJECT

public:
    DescriptionEditor(DeskData::IDescription* description, QWidget* parent = 0);

    void setDescription(DeskData::IDescription* description);

signals:
    void dataChanged(DeskData::IDescription* description);

private slots:
    void onTextChanged(const QString &text);

private:
    DeskData::IDescription* _description;

    ShiftedLineEdit* _descriptionEditor;


};

}

#endif // DESCRIPTIONEDITOR_H
