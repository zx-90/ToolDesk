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

#ifndef IDATATIMESERIES_H
#define IDATATIMESERIES_H

#include "IData.h"
#include "IDimention.h"

namespace DeskData {

class ITimeSeries : public IData {

protected:
    ITimeSeries() {}
    virtual ~ITimeSeries() {}

public:

    virtual ITimeSeries* clone() const = 0;

    virtual void setSize(Size size) = 0;
    virtual Size getSize() const = 0;

    // X
    virtual void setXDimention(const IDimention* dimention) = 0;
    virtual IDimention* getXDimention() = 0;
    virtual const IDimention* getXDimention() const = 0;
    // x[i] = offset + i * quant
    virtual void setXOffset(const Double xOffset, const Double xQuant) = 0;
    virtual bool isXOffset() const = 0;
    virtual Double getXOffset() const = 0;
    virtual Double getXQuant() const = 0;
    // x[i] = array[i]
    virtual void setArrayX() = 0;
    virtual bool isArrayX() const = 0;
    virtual Double* getArrayX() = 0;
    virtual const Double* getArrayX() const = 0;

    // Y
    virtual void setYDimention(const IDimention* dimention) = 0;
    virtual IDimention* getYDimention() = 0;
    virtual const IDimention* getYDimention() const = 0;
    // y[i] = offset
    virtual void setYOffset(const Double yOffset) = 0;
    virtual bool isYOffset() const = 0;
    virtual Double getYOffset() const = 0;
    // y[i] = array[i]
    virtual void setArrayY() = 0;
    virtual bool isArrayY() const = 0;
    virtual Double* getArrayY() = 0;
    virtual const Double* getArrayY() const = 0;

};

}

#endif // IDATATIMESERIES_H
