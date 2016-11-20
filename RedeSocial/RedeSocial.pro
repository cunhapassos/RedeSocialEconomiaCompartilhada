QT += core
QT -= gui

CONFIG += c++11

TARGET = RedeSocial
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Pessoa.cpp \
    Rede.cpp \
    Relacionamento.cpp

HEADERS += \
    Pessoa.h \
    Rede.h \
    Relacionamento.h
