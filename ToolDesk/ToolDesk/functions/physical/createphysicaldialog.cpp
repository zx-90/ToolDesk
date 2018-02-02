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

#include "createphysicaldialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <math.h>
#include "data/editor/dataphysicaleditor.h"

namespace DeskGui {

CreatePhysicalDialog::CreatePhysicalDialog(DeskData::IProject *project, QWidget *parent) :
    IFunctionDialog(project, parent),
    _project(project)
{
    _physicalValue =
            (DeskData::IPhysical*)
            project->getFactory()->createData(DeskData::DATATYPE_PHYSICAL);

    setWindowTitle("Create physical value");

    QVBoxLayout* layout = new QVBoxLayout(this);

    _editor = new DataPhysicalEditor(_physicalValue, this);
    layout->addWidget(_editor);

    _button = new QPushButton("Add", this);
    layout->addWidget(_button);

    QWidget::connect(
                _editor, SIGNAL(dataChanged(DeskData::IData*)),
                this, SLOT(setData(DeskData::IData*)));
    QWidget::connect(
                _button, SIGNAL(pressed()),
                this, SLOT(runFunction()));

}

CreatePhysicalDialog::~CreatePhysicalDialog()
{

}

void CreatePhysicalDialog::runFunction()
{
    // TODO: Don't close dialog on add summation.
    //       Add posibility add some values.
    DeskData::ISummation* result = _project->getFactory()->createSummation();
    result->setDescription(_physicalValue->getDescription());
    result->registerOutData(_physicalValue);
    _physicalValue = (DeskData::IPhysical*)
            _project->getFactory()->createData(DeskData::DATATYPE_PHYSICAL);
    emit createSummation(result);
    close();
}

} // namespace DeskGui

