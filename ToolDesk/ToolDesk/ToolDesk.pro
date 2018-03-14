#-------------------------------------------------
#
# Project created by QtCreator 2016-08-24T23:20:19
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToolDesk
TEMPLATE = app

INCLUDEPATH += $$PWD/include

SOURCES += main.cpp\
        mainwindow.cpp \
    data/factory/data.cpp \
    data/factory/datadimention.cpp \
    data/factory/dataphysical.cpp \
    data/factory/datatimeseries.cpp \
    data/editor/basedoubleeditor.cpp \
    data/editor/dimentioneditor.cpp \
    data/editor/dimentionviewer.cpp \
    desk/core/borderlayout.cpp \
    functions/physical/createphysicalregistrator.cpp \
    data/factory/factory.cpp \
    data/factory/summation.cpp \
    data/factory/container.cpp \
    project/project.cpp \
    project/saver.cpp \
    desk/functionwidget.cpp \
    desk/projectwidget.cpp \
    include/function/IFunctionDialog.cpp \
    desk/projectitem.cpp \
    data/editor/descriptionviewer.cpp \
    data/editor/descriptioneditor.cpp \
    data/editor/dataphysicaleditor.cpp \
    data/editor/dataphysicalviewer.cpp \
    include/data/DataList.cpp \
    functions/physical/createphysicaldialog.cpp \
    functions/timeseries/createtimeseriesregistrator.cpp \
    functions/timeseries/createtimeseriesdialog.cpp \
    include/function/IFunction.cpp \
    include/function/IFunctionRegistrator.cpp \
    include/widget/IDataViewer.cpp \
    data/editor/timeseriesviewer.cpp \
    data/editor/timeserieseditor.cpp \
    data/editor/dim.cpp

HEADERS  += mainwindow.h \
    include/data/DataBase.h \
    include/data/IData.h \
    include/data/IDataPhysical.h \
    include/data/IDataTimeSeries.h \
    include/data/DataTypes.h \
    include/project/IFactory.h \
    include/data/DataList.h \
    include/project/IProject.h \
    include/widget/IDataEditor.h \
    data/factory/data.h \
    data/factory/datadimention.h \
    data/factory/dataphysical.h \
    data/factory/datatimeseries.h \
    data/editor/basedoubleeditor.h \
    data/editor/dimentioneditor.h \
    data/editor/dimentionviewer.h \
    desk/core/borderlayout.h \
    functions/physical/createphysicalregistrator.h \
    data/factory/factory.h \
    data/factory/summation.h \
    data/factory/container.h \
    project/project.h \
    project/saver.h \
    desk/functionwidget.h \
    desk/projectwidget.h \
    include/data/IContainer.h \
    include/data/ISummation.h \
    include/function/IFunctionDialog.h \
    desk/projectitem.h \
    data/editor/descriptionviewer.h \
    data/editor/descriptioneditor.h \
    data/editor/dataphysicaleditor.h \
    data/editor/dataphysicalviewer.h \
    functions/physical/createphysicaldialog.h \
    functions/timeseries/createtimeseriesregistrator.h \
    functions/timeseries/createtimeseriesdialog.h \
    include/data/IDimention.h \
    include/data/IDescription.h \
    include/function/IFunction.h \
    include/function/IFunctionRegistrator.h \
    include/widget/IDataViewer.h \
    data/editor/timeseriesviewer.h \
    data/editor/timeserieseditor.h \
    data/editor/dim.h \
    desk/core/treewidgetitemtemplate.h \
    desk/core/shiftedwidgettemplate.h \
    desk/core/shiftedwidgets.h

RESOURCES += \
    Images.qrc
