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

#include "dimentionviewer.h"
#include "include/data/DataList.h"
#include <QVBoxLayout>

namespace DeskGui {

DimentionViewer::DimentionViewer(const DeskData::IDimention *data, QWidget *parent) :
    QWidget(parent),
    _data(data)
{
    setContentsMargins(0, 0, 0, 0);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setContentsMargins(0, 0, 0, 0);

    _label = new QLabel(this);
    _label->setMargin(0);
    _label->setContentsMargins(0,0,0,0);
    _label->setIndent(0);
    _label->setText(DeskData::dimentionToString(data));
    layout->addWidget(_label);
}

DimentionViewer::~DimentionViewer()
{

}

void DimentionViewer::onDataChanged(DeskData::IDimention *data)
{
    _data = data;
    if (_data) {
        QString res = dimentionToString(_data);
        _label->setText(res);
    }
}

} // namespace DeskGui

