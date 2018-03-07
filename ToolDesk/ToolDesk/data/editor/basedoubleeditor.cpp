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

#include "desk/core/borderlayout.h"
#include "QDoubleValidator"
#include <math.h>
#include <QKeyEvent>

namespace DeskGui {

const QString BASE_ERROR = "<font color=\"red\">***</font>";
const QString POWER_ERROR = "<font color=\"red\">***</font>";

BaseDoubleEditor::BaseDoubleEditor(QWidget *parent) :
    QWidget(parent),
    _base(nullptr),
    _tenBase(nullptr),
    _power(nullptr)
{
    BorderLayout* numberLayout = new BorderLayout(this);
    numberLayout->setMargin(0);
    numberLayout->setContentsMargins(0, 0, 0, 0);
    numberLayout->setSpacing(0);

    _base = new ShiftedLineEdit(this);
    _base->setText("0");
    _base->setAlignment(Qt::AlignRight);
    _base->setMaxLength(17);
    _base->setValidator(new QDoubleValidator(_base));
    QWidget::connect(
                _base, SIGNAL(textChanged(const QString&)),
                this, SLOT(resizeToContent())
                );
    QWidget::connect(
                _base, SIGNAL(returnPressed()),
                this, SLOT(onBaseReturnPressed())
                );
    numberLayout->addWidget(_base, BorderLayout::West);

    _tenBase = new QLabel(this);
    _tenBase->setText(DeskData::TEN_POWER);
    _tenBase->setMargin(0);
    _tenBase->setIndent(0);
    _tenBase->setContentsMargins(0,0,0,0);
    numberLayout->addWidget(_tenBase, BorderLayout::West);

    _power = new ShiftedLineEdit(this);
    QFont font = _power->font();
    font.setPointSize(font.pointSize() * 3 / 4);
    _power->setFont(font);
    _power->setAlignment(Qt::AlignTop);
    _power->setText("0");
    _power->setTextMargins(0,0,0,0);
    _power->setMaxLength(3);
    _power->setValidator(new QIntValidator(_power));
    QWidget::connect(
                _power, SIGNAL(textChanged(const QString&)),
                this, SLOT(resizeToContent())
                );
    QWidget::connect(
                _power, SIGNAL(returnPressed()),
                this, SLOT(onPowerReturnPressed())
                );
    numberLayout->addWidget(_power, BorderLayout::West);

    QWidget* widget = new QWidget(this);
    QFontMetrics fm(_base->font());
    widget->setMinimumHeight(fm.height() + 7);
    widget->setMinimumWidth(1);
    numberLayout->addWidget(widget, BorderLayout::Center);

    setContentsMargins(0, 0, 0, 0);
    setMinimumWidth(265);
    resizeToContent();
}

BaseDoubleEditor::~BaseDoubleEditor()
{

}

void BaseDoubleEditor::setDouble(DeskData::Double d)
{
    DeskData::Double base = d;
    DeskData::Int power = 0;
    bool normalizeOk;
    DeskData::Normalize(base, power, normalizeOk);
    if (normalizeOk) {
        _base->setText(QString::number(base));
        _power->setText(QString::number(power));
    } else {
        _base->setText("");
        _power->setText("");
    }
}

void BaseDoubleEditor::redraw()
{
    QString res = "";

    bool baseOk;
    DeskData::Double base = getDouble(_base->text(), baseOk);
    if (_base->text() == "") {
        base = 0;
        baseOk = true;
    }

    bool powerOk;
    DeskData::Int power = _power->text().toInt(&powerOk);
    if (_power->text() == "") {
        power = 0;
        powerOk = true;
    }

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
            res += DeskData::TEN_POWER + DeskData::toPower(power);
        }
    } else {
        res += DeskData::TEN_POWER + POWER_ERROR;
    }
    res += " ";

    if (baseOk && powerOk) {
        emit dataChangedDouble(base * pow(10, power));
    }

    emit dataChanged(res);
}

void BaseDoubleEditor::resizeToContent()
{
    if (_base) {
        QFont font(_base->font());
        QFontMetrics fm(font);

        // TODO: how to calculate MARGINS from QEditLine properties.
        const int MARGINS = 7;
        int pixelsWide = fm.width(_base->text()) + MARGINS;

        _base->setFixedWidth(pixelsWide);
    }
    if (_tenBase) {
        QFont fontTen(_tenBase->font());
        QFontMetrics fm(fontTen);

        int pixelsWide = fm.width(_tenBase->text());

        _tenBase->setFixedWidth(pixelsWide);
    }
    if (_power) {
        QString text = _power->text();

        QFont font(_power->font());
        QFontMetrics fm(font);

        // TODO: how to calculate MARGINS from QEditLine properties.
        const int MARGINS = 7;
        int pixelsWide = fm.width(text) + MARGINS;

        _power->setFixedWidth(pixelsWide);
    }
    redraw();
}

void BaseDoubleEditor::onBaseReturnPressed()
{
    _power->setFocus();
}

void BaseDoubleEditor::onPowerReturnPressed()
{
    _base->setFocus();
}

DeskData::Double BaseDoubleEditor::getDouble(QString string, bool &isOk)
{
    QString res = string.replace(",", ".");
    return res.toDouble(&isOk);
}

} // namespace DeskGui

