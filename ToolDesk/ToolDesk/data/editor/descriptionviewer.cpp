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

#include "descriptionviewer.h"

#include <QMessageBox>

namespace DeskGui {

DescriptionViewer::DescriptionViewer(const DeskData::IData *data, QWidget *parent) :
    DeskGui::IDataViewer(data, parent)
{
    _label = new QLabel(this);
    onChangeData(_data);
}

DescriptionViewer::~DescriptionViewer()
{

}

void DescriptionViewer::onChangeData(const DeskData::IData *data)
{
    _data = data;
    if (_data) {
        _label->setText(QString::fromWCharArray(_data->getDescription()));
    }
}

}
