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

#ifndef DATAPHYSICAL_H
#define DATAPHYSICAL_H

#include <string>
#include "data/IDataPhysical.h"
#include "data.h"

namespace DeskData {

class DataPhysical : public IPhysical
{
public:
    DataPhysical();
    virtual ~DataPhysical();

    virtual void release();
    virtual Size getType() const;
    virtual void setId(Size id);
    virtual Size getId() const;
    virtual const QString getDescription() const;
    virtual void setDescription(const QString description);

    virtual IPhysical* clone() const;

    virtual void clear();

    virtual void setValue(Double value);
    virtual Double getValue() const;
    virtual void setDimention(const IDimention* dimention);
    virtual IDimention* getDimention();
    virtual const IDimention *getDimention() const;

private:
    Size _id;
    QString _description;

    Double _value;
    IDimention* _dimention;
};

}

#endif // DATAPHYSICAL_H
