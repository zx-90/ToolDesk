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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

#include "include/project/IFactory.h"
#include "desk/core/borderlayout.h"
#include "desk/projectwidget.h"
#include "desk/functionwidget.h"
#include "include/project/IProject.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void newProject();
    void openProject();
    void saveProject();
    void quit();
    void help();

private:
    QMenuBar* _menuBar;

    DeskData::IProject* _project;

    ProjectWidget* _projectWidget;
    QWidget* _view;
    FunctionWidget* _functions;

    void menuInit();
    void mainWindowInit();
};

#endif // MAINWINDOW_H
