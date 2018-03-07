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

#ifndef DESKGUI_CREATEPHYSICAL_H
#define DESKGUI_CREATEPHYSICAL_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "include/function/IFunctionDialog.h"
#include "include/widget/IDataViewer.h"
#include "include/widget/IDataEditor.h"
#include "data/editor/descriptioneditor.h"
#include "data/editor/basedoubleeditor.h"
#include "data/editor/dataphysicaleditor.h"
#include "include/data/DataList.h"

namespace DeskGui {

class CreatePhysicalDialog : public IFunctionDialog
{
    Q_OBJECT
public:
    CreatePhysicalDialog(DeskData::IProject* project, QWidget* parent = 0);
    virtual ~CreatePhysicalDialog();

public slots:
    void runFunction();

private slots:
    void onUpValue();
    void onDownValue();
    void onAddValue();
    void onRemoveValue();
    void onChangeCurrentValue(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void setData(DeskData::IData* data);

private:
    DescriptionEditor* _description;
    QTreeWidget* _values;

    QPushButton* _up;
    QPushButton* _down;
    QPushButton* _add;
    QPushButton* _remove;

    DataPhysicalEditor* _editor;

    QPushButton* _button;

    DeskData::IProject* _project;
    DeskData::ISummation* _value;

};

} // namespace DeskGui

#endif // DESKGUI_CREATEPHYSICAL_H
