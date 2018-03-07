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

#ifndef TREEWIDGETITEMTEMPLATE_H
#define TREEWIDGETITEMTEMPLATE_H

#include <QTreeWidgetItem>

template<class T> class TreeWidgetItemTemplate : public QTreeWidgetItem {
protected:
    T* _t;
public:
    TreeWidgetItemTemplate(T* t = nullptr) : _t(t) {}
    ~TreeWidgetItemTemplate() {}

    void setData(T* t) { _t = t; }
    T* getData() { return _t; }

    static T* getData(QTreeWidgetItem* item) {
        TreeWidgetItemTemplate<T>* it =
                static_cast<TreeWidgetItemTemplate<T> *>(item);
        if (it) {
            return it->getData();
        } else {
            return nullptr;
        }
    }

};

#endif // TREEWIDGETITEMTEMPLATE_H
