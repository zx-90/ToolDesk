#ifndef FUNCTIONTREE_H
#define FUNCTIONTREE_H

#include <QTreeWidget>

class FunctionTree : public QTreeWidget
{
public:
    FunctionTree(QWidget* parent = NULL);
    ~FunctionTree();
};

#endif // FUNCTIONTREE_H
