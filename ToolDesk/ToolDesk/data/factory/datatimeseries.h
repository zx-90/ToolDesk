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

#ifndef TOOLDESKDATA_DATATIMESERIES_H
#define TOOLDESKDATA_DATATIMESERIES_H

#include <string>
#include "data/IDataTimeSeries.h"
#include "data.h"

namespace DeskData {

class DataTimeSeries : public ITimeSeries
{
public:
    DataTimeSeries();
    virtual ~DataTimeSeries();

    virtual void release();
    virtual Size getType() const;
    virtual void setId(Size id);
    virtual Size getId() const;
    virtual const QString getDescription() const;
    virtual void setDescription(const QString description);

    virtual ITimeSeries* clone() const;

    virtual void setSize(Size size);
    virtual Size getSize() const;

    // X
    virtual void setXDimention(const IDimention* dimention);
    virtual IDimention *getXDimention();
    virtual const IDimention *getXDimention() const;
    // x[i] = offset + i * quant
    virtual void setXOffset(const Double xOffset, const Double xQuant);
    virtual bool isXOffset() const;
    virtual Double getXOffset() const;
    virtual Double getXQuant() const;
    // x[i] = array[i]
    virtual void setArrayX();
    virtual bool isArrayX() const;
    virtual Double *getArrayX();
    virtual const Double *getArrayX() const;

    // Y
    virtual void setYDimention(const IDimention* dimention);
    virtual IDimention *getYDimention();
    virtual const IDimention *getYDimention() const;
    // y[i] = offset
    virtual void setYOffset(const Double yOffset);
    virtual bool isYOffset() const;
    virtual Double getYOffset() const;
    // y[i] = array[i]
    virtual void setArrayY();
    virtual bool isArrayY() const;
    virtual Double* getArrayY();
    virtual const Double* getArrayY() const;

private:
    Size _id;
    QString _description;

    Size _size;

    IDimention* _xDimention;
    bool _isXOffset;
    Double _xOffset;
    Double _xQuant;
    Double* _arrayX;

    IDimention* _yDimention;
    bool _isYOffset;
    Double _yOffset;
    Double* _arrayY;

};

} // namespace ToolDeskData

#endif // TOOLDESKDATA_DATATIMESERIES_H
