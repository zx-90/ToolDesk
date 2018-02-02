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
    virtual const Char* getDescription() const;
    virtual void setDescription(const Char* description);

    virtual ITimeSeries* clone() const;

    virtual void setXDimention(const IDimention* dimention);
    virtual IDimention *getXDimention();
    virtual const IDimention *getXDimention() const;
    virtual void setXOffset(const Double xOffset);
    virtual Double getXOffset() const;
    virtual void setXQuant(const Double xQuant);
    virtual Double getXQuant() const;

    virtual void setYDimention(const IDimention* dimention);
    virtual IDimention *getYDimention();
    virtual const IDimention *getYDimention() const;
    virtual void setYOffset(const Double yOffset);
    virtual Double getYOffset() const;
    virtual void setYQuant(const Double yQuant);
    virtual Double getYQuant() const;

    virtual void setSize(Size size);
    virtual Size getSize() const;
    virtual Double* getArrayY();
    virtual const Double* getArrayY() const;

private:
    Size _id;
    std::wstring _description;

    IDimention* _xDimention;
    Double _xOffset;
    Double _xQuant;
    IDimention* _yDimention;
    Double _yOffset;
    Double _yQuant;

    Size _size;
    Double* _array;
};

} // namespace ToolDeskData

#endif // TOOLDESKDATA_DATATIMESERIES_H
