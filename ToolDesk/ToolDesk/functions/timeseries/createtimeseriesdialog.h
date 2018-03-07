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

#ifndef CREATETIMESERIESDIALOG_H
#define CREATETIMESERIESDIALOG_H

#include "include/function/IFunctionDialog.h"

#include <QVBoxLayout>
#include <QSpinBox>
#include <QGroupBox>
#include <QRadioButton>
#include "data/editor/descriptioneditor.h"
#include "data/editor/dimentioneditor.h"
#include "data/editor/basedoubleeditor.h"
#include "data/editor/timeseriesviewer.h"

class CreateTimeSeriesDialog : public DeskGui::IFunctionDialog
{
public:
    CreateTimeSeriesDialog(DeskData::IProject* project, QWidget* parent = 0);
    virtual ~CreateTimeSeriesDialog();

public slots:
    void runFunction();

private:
    QVBoxLayout* _layout;

    DeskGui::DescriptionEditor* _description;

    QSpinBox* _size;

    DeskGui::DimentionEditor* _dimentionX;
    QGroupBox* _typeX;
    QRadioButton* _isOffsetX;
    QRadioButton* _isArrayX;
    DeskGui::BaseDoubleEditor* _offsetX;
    DeskGui::BaseDoubleEditor* _quantX;

    DeskGui::DimentionEditor* _dimentionY;
    QGroupBox* _typeY;
    QRadioButton* _isOffsetY;
    QRadioButton* _isArrayY;
    DeskGui::BaseDoubleEditor* _offsetY;

    TimeSeriesViewer* _chart;

};

#endif // CREATETIMESERIESDIALOG_H
