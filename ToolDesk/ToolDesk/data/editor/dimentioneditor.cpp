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

#include "dimentioneditor.h"
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include "desk/core/borderlayout.h"

namespace DeskGui {

DimentionEditor::DimentionEditor(DeskData::IDimention *data, QWidget *parent) :
    QWidget(parent),
    _data(data),
    _dialog(nullptr)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setMargin(0);

    _button = new QPushButton(this);
    setDimention(data);
    layout->addWidget(_button);
    QWidget::connect(
                _button, SIGNAL(clicked()),
                this, SLOT(onClick())
                );
}

DimentionEditor::~DimentionEditor()
{

}

void DimentionEditor::setDimention(DeskData::IDimention *data)
{
    _data = data;
    if (data) {
        _button->setEnabled(true);
        _button->setText("[" + DeskData::dimentionToString(data) + "]");
    } else {
        _button->setEnabled(false);
        _button->setText("[]");
    }
}

void DimentionEditor::onClick()
{
    if (_dialog) {
        _dialog->close();
    }
    _dims.clear();

    _dialog = new QDialog(this);
    BorderLayout* layout = new BorderLayout(_dialog);
    _dialog->setLayout(layout);

    QWidget* okWidget = new QWidget(_dialog);
    QHBoxLayout* okLayout = new QHBoxLayout(okWidget);
    okWidget->setLayout(okLayout);
    layout->addWidget(okWidget, BorderLayout::South);

    QPushButton* okButton = new QPushButton("Set", okWidget);
    okButton->setMaximumWidth(100);
    okLayout->addWidget(okButton);

    QWidget* dims = new QWidget(_dialog);
    QGridLayout* dimsLayout = new QGridLayout(dims);
    dims->setLayout(dimsLayout);
    layout->addWidget(dims, BorderLayout::Center);

    for (DeskData::Size i = 1; i < DeskData::METRIX_UNITS_SIZE; ++i) {
        const DeskData::metricUnit unit = DeskData::METRIX_UNITS[i];
        Dim* dim = new Dim(unit, dims);
        if (_data) {
            DeskData::Size size = _data->getSize();
            for (DeskData::Size j = 0; j < size; j++) {
                if (_data->getDimentionType(j) == i) {
                    dim->setPower(_data->getDimentionPower(j));
                    dim->setPrefix(_data->getDimentionPrefix(j));
                }
            }
        }
        QWidget::connect(
                    dim, SIGNAL(powerChanged(int)),
                    this, SLOT(onChangeDimStatus())
                    );


        const DeskData::Size ROWS = 15;
        dimsLayout->addWidget(dim, (i-1) % ROWS, (i-1) / ROWS, 1, 1);
        _dims.push_back(dim);
    }
    onChangeDimStatus();

    QWidget::connect(
                okButton, SIGNAL(clicked(bool)),
                this, SLOT(onSetClick())
                );
    QWidget::connect(
                _dialog, SIGNAL(destroyed(QObject*)),
                this, SLOT(onCloseDialog())
                );

    _dialog->setModal(true);
    _dialog->show();
}

void DimentionEditor::onCloseDialog()
{
    _dialog = nullptr;
    _dims.clear();
}

void DimentionEditor::onSetClick()
{
    if (_data) {
        _data->clear();
        for (DeskData::Size i = 0; i < _dims.size(); ++i) {
            Dim* dim = _dims.at(i);
            if (dim->getPower() != 0) {
                _data->addDimention(i+1, dim->getPower(), dim->getPrefix());
            }
        }
    }

    if (_dialog) {
        _dialog->close();
    }

    _button->setText("[" + DeskData::dimentionToString(_data) + "]");
    emit dataChanged(_data);
}

void DimentionEditor::onChangeDimStatus()
{
    DeskData::Size activeDims = 0;
    for (DeskData::Size i = 0; i < _dims.size(); ++i) {
        Dim* dim = _dims.at(i);
        if (dim->getPower() != 0) {
            activeDims++;
        }
    }
    for (DeskData::Size i = 0; i < _dims.size(); ++i) {
        Dim* dim = _dims.at(i);
        if (activeDims >= DeskData::DIMENTION_MAX_SIZE) {
            dim->setActive(dim->getPower() != 0);
        } else {
            dim->setActive(true);
        }
    }
}

} // namespace DeskGui

