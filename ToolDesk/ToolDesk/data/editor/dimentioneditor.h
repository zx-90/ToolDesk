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

namespace DeskGui {

class DimentionEditor : public IDataEditor
{
    Q_OBJECT

public:
    DimentionEditor(DeskData::IData* data,QWidget* parent = 0);
    ~DimentionEditor();

signals:
    void dataChanged(DeskData::IData* data);

public slots:
    void onAddDimention();
    void onDeleteDimention();
    void onMoveUpDimention();
    void onMoveDownDimention();
    void redraw();

private:
    QTreeWidget* _dimentionUnitTree;

    QWidget* _dimentionActions;
    QPushButton* _dimentionUnitDelete;
    QPushButton* _dimentionUnitUp;
    QPushButton* _dimentionUnitDown;

    QWidget* _dimentionAdd;
    QComboBox* _dimentionPrefixList;
    QComboBox* _dimentionUnitList;
    QComboBox* _dimentionPowerList;
    QPushButton* _dimentionUnitAdd;


};

} // namespace DeskGui

#endif // DESKGUI_DIMENTIONEDITOR_H
