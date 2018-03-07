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

#ifndef DIM_H
#define DIM_H

#include <QWidget>
#include "include/data/DataList.h"
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>

class Dim : public QWidget
{
    Q_OBJECT
public:
    explicit Dim(const DeskData::metricUnit& unit, QWidget *parent = 0);

    void setPower(DeskData::Int power);
    void setPrefix(DeskData::Size prefix);

    DeskData::Int getPower();
    DeskData::Size getPrefix();
    void setActive(bool active);

signals:
    void powerChanged(int power);

public slots:
    void onChange(int i);
    void zero();

private:
    QComboBox* _prefixes;
    QLabel* _label;
    QSpinBox* _power;
    QPushButton* _zeroButton;

};

#endif // DIM_H
