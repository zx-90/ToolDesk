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

#include "basedoubleeditor.h"

#include <QVBoxLayout>
#include <math.h>

namespace DeskGui {

const QString BASE_ERROR = "<font color=\"red\">***</font>";
const QString POWER_ERROR = "<font color=\"red\">***</font>";

BaseDoubleEditor::BaseDoubleEditor(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* numberLayout = new QHBoxLayout(this);
    _base = new QLineEdit(this);
    _base->setText("0");
    _base->setAlignment(Qt::AlignRight);
    QWidget::connect(_base,SIGNAL(textChanged(const QString&)),this,SLOT(redraw()));
    numberLayout->addWidget(_base);
    _tenBase = new QLabel(this);
    _tenBase->setText(DeskData::TEN_POWER);
    numberLayout->addWidget(_tenBase);
    _power = new QLineEdit(this);
    QFont font = _power->font();
    font.setPointSize(font.pointSize() * 3 / 4);
    _power->setFont(font);
    _power->setAlignment(Qt::AlignTop);
    _power->setText("0");
    QWidget::connect(_power,SIGNAL(textChanged(const QString&)),this,SLOT(redraw()));
    numberLayout->addWidget(_power);
}

BaseDoubleEditor::~BaseDoubleEditor()
{

}

void BaseDoubleEditor::redraw()
{
    QString res = "";

    bool baseOk;
    DeskData::Double base = getDouble(_base->text(), baseOk);
    bool powerOk;
    DeskData::Int power = _power->text().toInt(&powerOk);
    if (baseOk && powerOk) {
        bool normalizeOk;
        DeskData::Normalize(base, power, normalizeOk);
        if (!normalizeOk) {
            res += BASE_ERROR;
            emit dataChanged(res);
            return;
        }
    }


    if (baseOk) {
        res += QString::number(base);
    } else {
        res += BASE_ERROR;
    }
    if (powerOk) {
        if (power != 0) {
            res += DeskData::TEN_POWER + " " + DeskData::toPower(power);
        }
    } else {
        res += DeskData::TEN_POWER + " " + POWER_ERROR;
    }
    res += " ";

    if (baseOk && powerOk) {
        emit dataChangedDouble(base * pow(10, power));
    }

    emit dataChanged(res);
}

DeskData::Double BaseDoubleEditor::getDouble(QString string, bool &isOk)
{
    QString res = string.replace(",", ".");
    return res.toDouble(&isOk);
}

} // namespace DeskGui

