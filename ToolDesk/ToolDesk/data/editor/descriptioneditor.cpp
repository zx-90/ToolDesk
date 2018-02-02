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

#include "descriptioneditor.h"

#include <QVBoxLayout>
#include <QLabel>

namespace DeskGui {

DescriptionEditor::DescriptionEditor(DeskData::IData *data, QWidget *parent) :
    IDataEditor(data, parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* label = new QLabel(tr("Description:"), this);
    layout->addWidget(label);
    _descriptionEditor = new QLineEdit(this);
    layout->addWidget(_descriptionEditor);

    connect(
                _descriptionEditor, SIGNAL(textChanged(const QString &)),
                this, SLOT(onTextChanged(const QString &))
                                           );
}

void DescriptionEditor::onTextChanged(const QString &text)
{
    _data->setDescription(text.toStdWString().c_str());
    emit dataChanged(_data);
}

}
