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

#ifndef TIMESERIESVIEWER_H
#define TIMESERIESVIEWER_H

#include <QVBoxLayout>
#include <QLabel>
#include <QtCharts/QChartView>

#include "include/widget/IDataViewer.h"

class TimeSeriesViewer : public DeskGui::IDataViewer
{
    Q_OBJECT

public:
    TimeSeriesViewer(const DeskData::IData* data, QWidget* parent = 0);
    ~TimeSeriesViewer();

public slots:
    virtual void onChangeData(const DeskData::IData* data = NULL);

private:
    QVBoxLayout* _layout;
    QLabel* _label;
    QtCharts::QChartView* _chart;

};

#endif // TIMESERIESVIEWER_H
