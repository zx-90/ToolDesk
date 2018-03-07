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

#include "dim.h"

#include "desk/core/borderlayout.h"

Dim::Dim(const DeskData::metricUnit &unit, QWidget *parent) :
    QWidget(parent),
    _prefixes(nullptr),
    _label(nullptr),
    _power(nullptr),
    _zeroButton(nullptr)
{
    setToolTip(unit.name);
    setMinimumWidth(150);
    BorderLayout* dimLayout = new BorderLayout(this);
    setLayout(dimLayout);

    const int MIN_SYMBOL_WIDTH = 70;
    if (unit.isPrefixesAllowed) {
        _prefixes = new QComboBox(this);
        _prefixes->setMinimumWidth(MIN_SYMBOL_WIDTH);
        for (DeskData::Size j = 0; j < DeskData::METRIC_PREFIXES_SIZE; ++j) {
            const DeskData::metrixPrefix prefix = DeskData::METRIC_PREFIXES[j];
            QString text = prefix.prefix + unit.symbol;
            _prefixes->addItem(text);
            if (unit.koefficient == 0.001) {
                if (prefix.factorPower == 3) {
                    _prefixes->setCurrentText(text);
                }
            } else {
                if (prefix.factorPower == 0) {
                    _prefixes->setCurrentText(text);
                }
            }
        }
        dimLayout->addWidget(_prefixes, BorderLayout::West);

    } else {
        _label = new QLabel(this);
        _label->setMinimumWidth(MIN_SYMBOL_WIDTH);
        _label->setMargin(5);
        _label->setText(unit.symbol);
        dimLayout->addWidget(_label, BorderLayout::West);
    }

    _power = new QSpinBox(this);
    _power->setMaximum(4);
    _power->setMinimum(-4);
    _power->setMinimumHeight(20);
    dimLayout->addWidget(_power, BorderLayout::West);

    _zeroButton = new QPushButton("X", this);
    _zeroButton->setMinimumWidth(20);
    _zeroButton->setMaximumWidth(20);
    dimLayout->addWidget(_zeroButton, BorderLayout::Center);
    dimLayout->setAlignment(_zeroButton, Qt::AlignVCenter);

    QWidget::connect(
                _power, SIGNAL(valueChanged(int)),
                this, SLOT(onChange(int))
                );
    QWidget::connect(
                _zeroButton, SIGNAL(clicked(bool)),
                this, SLOT(zero())
                );

}

void Dim::setPower(DeskData::Int power)
{
    _power->setValue(power);
}

void Dim::setPrefix(DeskData::Size prefix)
{
    if (!_prefixes) {
        return;
    }
    _prefixes->setCurrentIndex(prefix);
}

DeskData::Int Dim::getPower()
{
    return _power->value();
}

DeskData::Size Dim::getPrefix()
{
    if (_prefixes) {
        return _prefixes->currentIndex();
    } else {
        return DeskData::PREFIX_NONE;
    }
}

void Dim::setActive(bool active)
{
    if (active) {
        _power->setEnabled(true);
        _zeroButton->setEnabled(true);
    } else {
        _power->setValue(0);
        _power->setEnabled(false);
        _power->setEnabled(false);
    }
}

void Dim::onChange(int i)
{
    if (i) {
        QPalette pal(palette());
        pal.setColor(QPalette::Background, Qt::darkCyan);
        setAutoFillBackground(true);
        setPalette(pal);
        if (_prefixes) {
            _prefixes->setStyleSheet("QComboBox { background-color: darkCyan; }");
        }
    } else {
        setAutoFillBackground(false);
        if (_prefixes) {
            _prefixes->setStyleSheet("");
        }
    }
    emit powerChanged(i);
}

void Dim::zero()
{
    _power->setValue(0);
}
