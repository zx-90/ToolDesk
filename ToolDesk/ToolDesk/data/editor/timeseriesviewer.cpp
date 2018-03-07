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

#include "timeseriesviewer.h"

#include <QtCharts/QSplineSeries>
#include <QtCharts/QChart>

TimeSeriesViewer::TimeSeriesViewer(const DeskData::IData *data, QWidget *parent) :
    IDataViewer(data, parent),
    _layout(new QVBoxLayout(this)),
    _label(new QLabel("Time Series Label", this)),
    _chart(new QtCharts::QChartView(this))
{
    QtCharts::QSplineSeries *series = new QtCharts::QSplineSeries();
    series->setName("spline");

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Simple spline chart example");
    chart->createDefaultAxes();
    chart->axisY()->setRange(0, 10);
    chart->axisX()->setRange(0, 10);

    _chart->setChart(chart);

    _layout->addWidget(_label);
    _layout->addWidget(_chart);

    onChangeData(data);
}

TimeSeriesViewer::~TimeSeriesViewer()
{

}

void TimeSeriesViewer::onChangeData(const DeskData::IData *data)
{
    _data = data;

    QtCharts::QSplineSeries *series = (QtCharts::QSplineSeries*)_chart->chart()->series().at(0);
    series->clear();

    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
}
