QT += core
QT += xml
QT += gui
QT += widgets

CONFIG += c++11

TARGET = KoAgrXML
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    koagrxml.cpp

HEADERS += \
    koagrxml.h
