/*
 * Copyright © 2018 Evgenii Zaitcev.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license.
 *
 * BSD License Usage
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     (1) Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *     (2) Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *     (3)The name of the author may not be used to
 *     endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "DataList.h"

#include <math.h>

namespace DeskData {

void Normalize(Double &base, Int &power, bool &ok)
{
    Double tempBase = base * exp10(Double(power));
    Double tempSign = (0 < tempBase) - (tempBase < 0);
    tempBase = fabs(tempBase);
    Int tempPower = 0;

    if ((tempBase >= DBL_MAX) || (tempBase <= -DBL_MAX)) {
        base = 0;
        power = 0;
        ok = false;
        return;
    }
    if (fabs(tempBase) <= DBL_MIN) {
        base = 0;
        power = 0;
        ok = true;
        return;
    }

    if (tempBase >= 1000.0) {
        while (tempBase >= 10.0) {
            tempBase /= 10.0;
            tempPower += 1;
        }
    }
    if (tempBase < 0.001) {
        while (tempBase < 1.0) {
           tempBase *= 10;
            tempPower -= 1;
        }
    }
    base = tempSign * tempBase;
    power = tempPower;
    ok = true;
}

QString toPower(Int num)
{
    QString res = QString::number(num);
    res = res.replace('-',"⁻");
    res = res.replace('0',"⁰");
    res = res.replace('1',"¹");
    res = res.replace('2',"²");
    res = res.replace('3',"³");
    res = res.replace('4',"⁴");
    res = res.replace('5',"⁵");
    res = res.replace('6',"⁶");
    res = res.replace('7',"⁷");
    res = res.replace('8',"⁸");
    res = res.replace('9',"⁹");
    return res;
}

QString doubleToString(Double d)
{
    Double base = d;
    Int power = 0;
    bool normalizeOk;
    Normalize(base, power, normalizeOk);
    if (!normalizeOk) {
        return "";
    }
    QString result = QString::number(base);
    if (power != 0) {
        result += TEN_POWER + toPower(power);
    }
    return result;
}

QString dimentionToString(const IDimention* dimention)
{
    if (!dimention) {
        return "";
    }
    if (dimention->getSize() == 0) {
        return "";
    }
    if (dimention->getSize() == 1) {
        QString res;
        int prefixIndex = dimention->getDimentionPrefix(0);
        int valueIndex = dimention->getDimentionType(0);
        int power = dimention->getDimentionPower(0);
        res += METRIC_PREFIXES[prefixIndex].prefix;
        res += METRIX_UNITS[valueIndex].symbol;
        if (power != 1) {
            res += toPower(power);
        }
        return res;
    }

    QString num = "";
    QString den = "";
    for (Size i = 0; i < dimention->getSize(); i++) {
        int prefixIndex = dimention->getDimentionPrefix(i);
        int valueIndex = dimention->getDimentionType(i);
        int power = dimention->getDimentionPower(i);

        if (power > 0) {
            if (num != "") {
                num += "·";
            }
            num += METRIC_PREFIXES[prefixIndex].prefix;
            num += METRIX_UNITS[valueIndex].symbol;
            if (power != 1) {
                num += toPower(power);
            }
        } else {
            if (den != "") {
                den += "·";
            }
            den += METRIC_PREFIXES[prefixIndex].prefix;
            den += METRIX_UNITS[valueIndex].symbol;
            if (power != -1) {
                den += toPower(-power);
            }
        }
    }
    if (num == "") {
        num = "1";
    }
    if (den != "") {
        num += "/" + den;
    }
    return num;
}

}

