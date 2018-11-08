QT += core
QT += xml
QT -= gui

CONFIG += c++11

TARGET = KoAgrXML
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    koagrxml.cpp

HEADERS += \
    koagrxml.h
