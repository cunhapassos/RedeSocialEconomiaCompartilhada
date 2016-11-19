QT += core
QT -= gui

CONFIG += c++11

TARGET = RedeSocial
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    rede.cpp \
    pessoa.cpp \
    relacionamento.cpp

HEADERS += \
    rede.h \
    pessoa.h \
    relacionamento.h
