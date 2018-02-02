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

#ifndef DESKDATAWIDGET_DATAPHYSICALWIDGET_H
#define DESKDATAWIDGET_DATAPHYSICALWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTreeWidget>
#include <QComboBox>
#include <QPushButton>
#include <QString>

#include "include/widget/IDataEditor.h"
#include "include/widget/idataviewer.h"
#include "include/project/IProject.h"
#include "include/data/IDataPhysical.h"
#include "basedoubleeditor.h"
#include "descriptioneditor.h"

namespace DeskGui {

class DataPhysicalEditor : public IDataEditor
{
    Q_OBJECT
public:
    DataPhysicalEditor(DeskData::IData* data, QWidget *parent = 0);
    ~DataPhysicalEditor();

    virtual void release();

signals:

private slots:
    void setDouble(double data);
    void setDimention(DeskData::IData* data);

private:
    DescriptionEditor* _descriptionEditor;
    QLabel* _doubleViewer;
    BaseDoubleEditor* _doubleEditor;
    IDataViewer* _dimentionViewer;
    IDataEditor* _dimentionEditor;

    DeskData::IPhysical* _physicalValue;


/*
public slots:
    DeskData::IData* createData(QString& error);

private slots:
    void redraw();
    void onAddDimention();
    void onDeleteDimention();
    void onMoveUpDimention();
    void onMoveDownDimention();
    void redrawDimentionButton();

private:
    QLabel* _result;

    QLineEdit* _base;
    QLabel* _tenBase;
    QLineEdit* _power;

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

    DeskData::Double getDouble(QString string,bool& isOk);
    void Normalize(DeskData::Double& base, DeskData::Int& power, bool &ok);
    QString toPower(DeskData::Int num);*/

};

} // namespace DeskDataWidget

#endif // DESKDATAWIDGET_DATAPHYSICALWIDGET_H
