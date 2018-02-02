#-------------------------------------------------
#
# Project created by QtCreator 2016-08-24T23:20:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToolDesk
TEMPLATE = app

INCLUDEPATH += $$PWD/include

SOURCES += main.cpp\
        mainwindow.cpp \
    data/factory/data.cpp \
    data/factory/datadimention.cpp \
    data/factory/datanonequdistanttimeseries.cpp \
    data/factory/dataphysical.cpp \
    data/factory/datapulserandomsequence.cpp \
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
    desk/functionitem.cpp \
    desk/functionwidget.cpp \
    desk/projectwidget.cpp \
    include/function/IFunctionDialog.cpp \
    include/function/ifunctionregistrator.cpp \
    include/function/ifunction.cpp \
    desk/projectitem.cpp \
    data/editor/descriptionviewer.cpp \
    data/editor/descriptioneditor.cpp \
    data/editor/dataphysicaleditor.cpp \
    data/editor/dataphysicalviewer.cpp \
    include/data/DataList.cpp \
    include/widget/idataviewer.cpp \
    functions/physical/createphysicaldialog.cpp \
    functions/timeseries/createtimeseriesregistrator.cpp \
    functions/timeseries/createtimeseriesdialog.cpp

HEADERS  += mainwindow.h \
    include/data/DataBase.h \
    include/data/IData.h \
    include/data/IDataPhysical.h \
    include/data/IDataTimeSeries.h \
    include/data/IDataDimention.h \
    include/data/DataTypes.h \
    include/data/IDataNonEqudistantTimeSeries.h \
    include/data/IDataPulseRandomSequence.h \
    include/project/IFactory.h \
    include/data/DataList.h \
    include/project/IProject.h \
    include/widget/IDataEditor.h \
    data/factory/data.h \
    data/factory/datadimention.h \
    data/factory/datanonequdistanttimeseries.h \
    data/factory/dataphysical.h \
    data/factory/datapulserandomsequence.h \
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
    desk/functionitem.h \
    desk/functionwidget.h \
    desk/projectwidget.h \
    include/data/IContainer.h \
    include/data/ISummation.h \
    include/function/IFunctionDialog.h \
    include/function/ifunctionregistrator.h \
    include/function/ifunction.h \
    desk/projectitem.h \
    data/editor/descriptionviewer.h \
    data/editor/descriptioneditor.h \
    data/editor/dataphysicaleditor.h \
    data/editor/dataphysicalviewer.h \
    include/widget/idataviewer.h \
    functions/physical/createphysicaldialog.h \
    functions/timeseries/createtimeseriesregistrator.h \
    functions/timeseries/createtimeseriesdialog.h

DISTFILES += \
    resource/test/Clear.png \
    resource/test/Collapse.png \
    resource/test/Exception.png \
    resource/test/Expand.png \
    resource/test/Failed.png \
    resource/test/filesave.png \
    resource/test/NoTested.png \
    resource/test/Stop.png \
    resource/test/Stress.png \
    resource/test/Succeed.png \
    resource/test/Testing.png \
    resource/test/test.ico

RESOURCES += \
    Images.qrc
