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

#include <QHBoxLayout>

namespace DeskGui {

DescriptionEditor::DescriptionEditor(DeskData::IDescription *description, QWidget *parent) :
    QWidget(parent),
    _description(description)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setMargin(0);

    _descriptionEditor = new ShiftedLineEdit(this);
    layout->addWidget(_descriptionEditor);
    setDescription(description);

    QWidget::connect(
                _descriptionEditor, SIGNAL(textChanged(const QString &)),
                this, SLOT(onTextChanged(const QString &))
                );
}

void DescriptionEditor::setDescription(DeskData::IDescription *description)
{
    _description = description;
    if (description) {
        _descriptionEditor->setEnabled(true);
        _descriptionEditor->setText(description->getDescription());
    } else {
        _descriptionEditor->setEnabled(false);
        _descriptionEditor->setText("");
    }
}

void DescriptionEditor::onTextChanged(const QString &text)
{
    if (_description) {
        _description->setDescription(text);
    }
    emit dataChanged(_description);
}

}
