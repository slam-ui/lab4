QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    datedialog.cpp

HEADERS += \
    mainwindow.h \
    datedialog.h

FORMS += \
    mainwindow.ui

RESOURCES += data.qrc
