#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T11:43:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = QWebServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    qwebservercontrol.cpp \
    requestrouter.cpp \
    logincontroler.cpp \
    cookiecontroller.cpp

include(./QtWebApp/QtWebApp/httpserver/httpserver.pri)
include(./QtWebApp/QtWebApp/logging/logging.pri)

OTHER_FILES += etc/webapp.ini

HEADERS += \
    qwebservercontrol.h \
    requestrouter.h \
    logincontroler.h \
    cookiecontroller.h
