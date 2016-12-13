QT += core
QT -= gui

CONFIG += c++11

TARGET = RedeSocial
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    testes.cpp \
    avaliacao.cpp \
    pessoa.cpp \
    rede.cpp \
    relacionamento.cpp \
    transacao.cpp \
    usuario.cpp \
    json.cpp

HEADERS += \
    avaliacao.h \
    pessoa.h \
    rede.h \
    relacionamento.h \
    transacao.h \
    usuario.h

unix: LIBS += -L$$PWD/./ -lgtest

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix: PRE_TARGETDEPS += $$PWD/./libgtest.a

DISTFILES += \
    JSON.json \
    rede.json
