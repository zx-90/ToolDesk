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

#include "saver.h"
#include <QFile>
#include <QDir>

#include "include/data/DataList.h"

namespace DeskData {

const Size VERSION = 1;

Saver::Saver()
{

}

Saver::~Saver()
{

}

void Saver::save(const IProject *project, QString dir)
{
    QFile projectFile(dir + "/proj.td");
    projectFile.open(QIODevice::WriteOnly);
    save(projectFile, VERSION);
    save(projectFile, project->getId());
    projectFile.close();

    Size dataSize = project->getDataCount();
    for (Size i = 0; i < dataSize; i++) {
        const IData* data = project->getData(i);
        QFile dataFile(dir + "/" + QString::number(data->getId()) + ".data");
        dataFile.open(QIODevice::WriteOnly);
        saveData(dataFile,data);
        dataFile.close();
    }

    Size functionSize = project->getFunctionCount();
    for (Size i = 0; i < functionSize; i++) {
        const ISummation* summation = project->getFunctionResult(i);
        QFile funcFile(dir + "/" + QString::number(i) + ".func");
        funcFile.open(QIODevice::WriteOnly);
        save(funcFile, summation->getDescription());
        saveContainer(funcFile, summation->getInContainer());
        saveContainer(funcFile, summation->getOutContainer());
        funcFile.close();
    }
}

Project *Saver::load(QString dir)
{
    QFile file(dir + "/proj.td");
    file.open(QIODevice::ReadOnly);
    Size version = loadSize(file);
    if (version != VERSION) {
        return nullptr;
    }
    Size id = loadSize(file);
    Project* project = new Project(id);
    file.close();

    const IFactory* factory = project->getFactory();
    QDir dataDir;
    dataDir.setCurrent(dir);
    dataDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dataDir.setSorting(QDir::Size | QDir::Reversed);
    QFileInfoList dataList = dataDir.entryInfoList(QStringList("*.data"));
    for (int i = 0; i < dataList.size(); ++i) {
        QFileInfo fileInfo = dataList.at(i);
        QFile fileData(fileInfo.fileName());
        fileData.open(QIODevice::ReadOnly);
        IData* data = loadData(factory, fileData);
        project->setData(data);

        fileData.close();
    }

    QFileInfoList funcList = dataDir.entryInfoList(QStringList("*.func"));
    for (int i = 0; i < funcList.size(); ++i) {
        QFileInfo fileInfo = funcList.at(i);
        QFile fileFunc(fileInfo.fileName());
        fileFunc.open(QIODevice::ReadOnly);
        ISummation* func = loadFunc(project, factory, fileFunc);
        project->setFunctionResult(func);

        fileFunc.close();
    }

    return project;
}

void Saver::saveData(QFile& file, const IData* data)
{
    save(file, data->getType());
    save(file, data->getId());
    save(file, data->getDescription());

    switch (data->getType()) {
    case DATATYPE_PHYSICAL: {
        IPhysical* dataPhysical = (IPhysical*) data;
        save(file, dataPhysical->getDimention());
        save(file, dataPhysical->getValue());
        break;
    }
    case DATATYPE_TIMESERIES: {
        ITimeSeries* dataTimeSeries = (ITimeSeries*) data;

        Size size = dataTimeSeries->getSize();
        save(file, size);

        save(file, dataTimeSeries->getXDimention());
        save(file, dataTimeSeries->isXOffset());
        save(file, dataTimeSeries->getXOffset());
        save(file, dataTimeSeries->getXQuant());
        bool isArrayX = dataTimeSeries->isArrayX();
        save(file, isArrayX);
        if (isArrayX) {
            save(file, dataTimeSeries->getArrayX(), size);
        }

        save(file, dataTimeSeries->getYDimention());
        save(file, dataTimeSeries->isYOffset());
        save(file, dataTimeSeries->getYOffset());
        bool isArrayY = dataTimeSeries->isArrayY();
        save(file, isArrayY);
        if (isArrayY) {
            save(file, dataTimeSeries->getArrayY(), size);
        }

        break;
    }
    default: {
        // TODO: Check for errors.
    }
    }
}

void Saver::saveContainer(QFile &file, const IContainer *container)
{
    save(file, container->getSize());
    for (Size j = 0; j < container->getSize(); j++) {
        save(file, container->getData(j)->getId());
        //save(file, container->getDescription(j));
    }
}

void Saver::save(QFile &file, bool data)
{
    save(file, (Int)data);
}

void Saver::save(QFile &file, Int data)
{
    file.write((char*) &data, sizeof(data));
}

void Saver::save(QFile &file, Size data)
{
    file.write((char*) &data, sizeof(data));
}

void Saver::save(QFile &file, Double data)
{
    file.write((char*) &data, sizeof(data));
}

void Saver::save(QFile &file, const QString data)
{
    QByteArray array = data.toUtf8();
    Size len = array.length();
    file.write((char*) &len, sizeof(len));
    file.write(array);
}

void Saver::save(QFile &file, const Double *data, Size size)
{
    file.write((char*) data, sizeof(*data) * size);
}

void Saver::save(QFile &file, const IDimention* data)
{
    save(file, data->getSize());
    for (Size i = 0; i < data->getSize(); i++) {
        save(file, data->getDimentionPrefix(i));
        save(file, data->getDimentionType(i));
        save(file, data->getDimentionPower(i));
    }
}

IData* Saver::loadData(const IFactory* factory, QFile &file)
{
    Size type = loadSize(file);
    switch(type) {
    case DATATYPE_PHYSICAL: {
        IPhysical* data = (IPhysical*)factory->createData(DATATYPE_PHYSICAL);
        loadDataHeader(file, data);
        IDimention* dimention = loadDataDimention(file, factory);
        data->setDimention(dimention);
        dimention->release();
        data->setValue(loadDouble(file));
        return data;
    }
    case DATATYPE_TIMESERIES: {
        ITimeSeries* data = (ITimeSeries*)factory->createData(DATATYPE_TIMESERIES);
        loadDataHeader(file, data);

        Size size = loadSize(file);
        data->setSize(size);

        IDimention* dimentionX = loadDataDimention(file, factory);
        data->setXDimention(dimentionX);
        dimentionX->release();
        loadBool(file); // isXOffset
        data->setXOffset(loadDouble(file), loadDouble(file));
        bool isArrayX = loadBool(file);
        if (isArrayX) {
            loadDoubleArray(file, data->getArrayX(), size);
        }

        IDimention* dimentionY = loadDataDimention(file, factory);
        data->setYDimention(dimentionY);
        dimentionY->release();
        loadBool(file); // isYOffset
        data->setYOffset(loadDouble(file));
        bool isArrayY = loadBool(file);
        if (isArrayY) {
            loadDoubleArray(file, data->getArrayY(), size);
        }

        return data;
    }
    default: return nullptr;
    }
}

bool Saver::loadBool(QFile &file)
{
    return loadInt(file);
}

Size Saver::loadSize(QFile &file)
{
    Size data;
    file.read((char*) &data, sizeof(data));
    return data;
}

Int Saver::loadInt(QFile &file)
{
    Int data;
    file.read((char*) &data, sizeof(data));
    return data;
}

Double Saver::loadDouble(QFile &file)
{
    Double data;
    file.read((char*) &data, sizeof(data));
    return data;
}

QString Saver::loadString(QFile &file, Size len)
{
    char data[len + 1];
    file.read((char*) data, sizeof(*data) * len);
    data[len] = 0;
    return QString::fromUtf8(data);
}

void Saver::loadDoubleArray(QFile &file, Double *data, Size len)
{
    file.read((char*) data, sizeof(*data) * len);
}

void Saver::loadDataHeader(QFile &file, IData *data)
{
    Size id = loadSize(file);
    data->setId(id);
    Size descSize = loadSize(file);
    QString desc = loadString(file, descSize);
    data->setDescription(desc);
}

IDimention* Saver::loadDataDimention(QFile &file, const IFactory* factory)
{
    IDimention* data = factory->createDimention();
    Size size = loadSize(file);
    for (Size i = 0; i < size; i++) {
        data->addDimention(loadSize(file),loadInt(file),loadInt(file));
    }
    return data;
}

ISummation *Saver::loadFunc(Project *project, const IFactory *factory, QFile &file)
{
    ISummation* result = factory->createSummation();
    Size descSize = loadSize(file);
    QString desc = loadString(file, descSize);
    result->setDescription(desc);
    loadContainer(project, (IContainer*)result->getInContainer(), file);
    loadContainer(project, (IContainer*)result->getOutContainer(), file);

    return result;
}

void Saver::loadContainer(Project *project, IContainer *container, QFile &file)
{
    Size size = loadSize(file);
    for (Size i = 0; i < size; i++) {
        Size id = loadSize(file);
        IData* data = (IData*)project->getData(id - 1);
        container->addData(data);
    }
}

} // namespace DeskData

