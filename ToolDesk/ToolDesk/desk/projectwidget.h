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

#ifndef PROJECTWIDGET_H
#define PROJECTWIDGET_H

#include <QWidget>
#include <QTreeWidget>
#include <QVBoxLayout>

#include "project/project.h"

class ProjectWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProjectWidget(DeskData::IProject* project, QWidget* view, QWidget *parent = 0);

    void setProject(DeskData::IProject* project);

signals:

public slots:
    void onChange();
    void onClick(QTreeWidgetItem * current, QTreeWidgetItem *previous);

private:
    DeskData::IProject* _project;
    QTreeWidget* _tree;
    QWidget* _view;
    QVBoxLayout* _viewLayout;
    QWidget* _viewer;
};

#endif // PROJECTWIDGET_H
