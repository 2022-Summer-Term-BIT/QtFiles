#-------------------------------------------------
#
# Project created by QtCreator 2022-08-12T09:24:23
#
#-------------------------------------------------

QT       += core gui network sql core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = liaotian
TEMPLATE = app


SOURCES += main.cpp\
    MainWindow.cpp \
    chatwindow.cpp \
        login.cpp \
    database.cpp \
    register.cpp \
    modify.cpp

HEADERS  += login.h \
    MainWindow.h \
    chatwindow.h \
    database.h \
    register.h \
    modify.h

FORMS    += login.ui \
    MainWindow.ui \
    chatwindow.ui \
    register.ui \
    modify.ui

RESOURCES += res.qrc



