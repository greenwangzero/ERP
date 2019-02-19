#-------------------------------------------------
#
# Project created by QtCreator 2019-01-25T16:15:41
#
#-------------------------------------------------

QT       += core gui network
QT +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = new
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    purchase.cpp \
    transform.cpp \
    connection.cpp \
    hetong.cpp \
    rmb.cpp \
    api.cpp

HEADERS  += mainwindow.h \
    purchase.h \
    transform.h \
    hetong.h \
    rmb.h \
    helper.h \
    api.h

FORMS    += mainwindow.ui \
    purchase.ui \
    transform.ui \
    hetong.ui \
    rmb.ui

    caigou/rmb.ui

RESOURCES += \
    layout.qrc

DISTFILES += \
    database/purchase.accdb \
    database/transform.accdb \
    purchase.accdb \
    Doll.java
