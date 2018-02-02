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

#include "mainwindow.h"
#include "data/editor/dataphysicaleditor.h"
#include "project/project.h"
#include <QFileDialog>
#include <QSplitter>
#include <QMessageBox>
#include <QApplication>
#include "project/saver.h"
#include "functions/physical/createphysicaldialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QIcon icon = QIcon(":/main/resource/icon.png");
    QApplication::setWindowIcon(icon);
    _project = new DeskData::Project(0);
    menuInit();
    mainWindowInit();

    connect(
                _functions, SIGNAL(changed(void)),
                _projectWidget, SLOT(onChange(void)));
}

MainWindow::~MainWindow()
{
    if (_project) {
        _project->release();
    }
}

void MainWindow::newProject()
{
    if (_project) {
        _project->release();
    }
    _project = new DeskData::Project(0);
    _projectWidget->setProject(_project);
    _functions->setProject(_project);
    _projectWidget->onChange();
}

void MainWindow::openProject()
{
    QString dir = QFileDialog::getExistingDirectory(this);
    DeskData::Saver* saver = new DeskData::Saver();
    DeskData::Project* project = saver->load(dir);
    delete saver;
    if (_project) {
        _project->release();
    }
    _project = project;
    _projectWidget->setProject(_project);
    _functions->setProject(_project);
    _projectWidget->onChange();
}

void MainWindow::saveProject()
{
    QString dir = QFileDialog::getExistingDirectory(this);
    if (dir == "") {
        return;
    }
    DeskData::Saver* saver = new DeskData::Saver();
    saver->save(_project,dir);
    delete saver;
}

void MainWindow::quit()
{
    exit(0);
}

void MainWindow::help()
{
    QMessageBox::about(
                this,
                "About ToolDesk",
                "ToolDesk version 0.1\n"
                "\n"
                "© 2018 Evgenii Zaitcev. All rights reserved.\n"
                "\n"
                "The program is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.");
}

void MainWindow::menuInit()
{
    _menuBar = this->menuBar();

    QMenu* fileMenu = new QMenu("File");
    fileMenu->addAction("New",this,SLOT(newProject()),Qt::CTRL + Qt::Key_N);
    fileMenu->addAction("Open",this,SLOT(openProject()),Qt::CTRL + Qt::Key_O);
    fileMenu->addAction("Save",this,SLOT(saveProject()),Qt::CTRL + Qt::Key_S);
    fileMenu->addSeparator();
    fileMenu->addAction("Quit", this, SLOT(quit()),Qt::CTRL + Qt::Key_Q);
    _menuBar->addMenu(fileMenu);

    QMenu* helpMenu = new QMenu("Help");
    helpMenu->addAction("About...", this, SLOT(help()));
    _menuBar->addMenu(helpMenu);
}

void MainWindow::mainWindowInit()
{

    QSplitter* splitter = new QSplitter(this);
    _view = new QWidget(this);
    // #b8b5b2 is a border color for QTreeWidget.
    // ??? Is there any constant for this color?
    _view->setObjectName("dataViewer");
    _view->setStyleSheet("QWidget#dataViewer {margin: 2px; border: 1px solid #b8b5b2;}");
    _projectWidget = new ProjectWidget(_project, _view, this);
    _functions = new FunctionWidget(_project, this);
    splitter->addWidget(_projectWidget);
    splitter->addWidget(_view);
    splitter->addWidget(_functions);
    splitter->setStretchFactor(0,1);
    splitter->setStretchFactor(1,50);
    splitter->setStretchFactor(2,1);

    QVBoxLayout* boxLayout = new QVBoxLayout(this);
    setLayout(boxLayout);
    boxLayout->addWidget(splitter);

    this->setCentralWidget(splitter);

    this->setGeometry(0,0,600,400);
    this->showMaximized();

}
