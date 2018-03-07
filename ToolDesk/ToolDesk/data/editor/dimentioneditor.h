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

#ifndef DESKGUI_DIMENTIONEDITOR_H
#define DESKGUI_DIMENTIONEDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QTreeWidget>
#include <QComboBox>
#include "include/widget/IDataEditor.h"
#include "include/data/DataList.h"
#include "dim.h"

namespace DeskGui {

class DimentionEditor : public QWidget
{
    Q_OBJECT

public:
    DimentionEditor(DeskData::IDimention* data,QWidget* parent = 0);
    ~DimentionEditor();

    void setDimention(DeskData::IDimention* data);

signals:
    void dataChanged(DeskData::IDimention* data);

private slots:
    void onClick();
    void onCloseDialog();
    void onSetClick();
    void onChangeDimStatus();

private:
    QPushButton* _button;

    DeskData::IDimention* _data;

    QDialog* _dialog;
    std::vector<Dim*> _dims;
};

} // namespace DeskGui

#endif // DESKGUI_DIMENTIONEDITOR_H
