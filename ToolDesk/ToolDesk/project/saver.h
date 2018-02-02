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

#ifndef DESKDATA_SAVER_H
#define DESKDATA_SAVER_H

#include "project.h"
#include <QString>
#include <QFile>

namespace DeskData {

class Saver
{
public:
    Saver();
    ~Saver();

    void save(const IProject* project, QString dir);
    Project* load(QString dir);

private:
    void saveData(QFile& file, const IData* data);
    void saveContainer(QFile& file, const IContainer* container);
    void save(QFile& file, Int data);
    void save(QFile& file, Size data);
    void save(QFile& file, Double data);
    void save(QFile& file, const Char* data);
    void save(QFile& file, const Double* data, Size size);

    IData *loadData(const IFactory* factory, QFile& file);
    Size loadSize(QFile& file);
    Int loadInt(QFile& file);
    Double loadDouble(QFile& file);
    void loadString(QFile& file, Char* data, Size len);
    void loadDoubleArray(QFile& file, Double* data, Size len);
    void loadDataHeader(QFile& file, IData* data);
    ISummation* loadFunc(Project* project, const IFactory* factory, QFile& file);
    void loadContainer(Project *project, IContainer *container, QFile& file);
};

} // namespace DeskData

#endif // DESKDATA_SAVER_H
