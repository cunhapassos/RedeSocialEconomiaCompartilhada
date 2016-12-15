QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += c++11

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
    json.cpp \
    administrador.cpp \
    usuarioperfil.cpp \
    usuario.cpp \
    mainwindow.cpp

HEADERS += \
    avaliacao.h \
    pessoa.h \
    rede.h \
    relacionamento.h \
    transacao.h \
    administrador.h \
    usuarioperfil.h \
    usuario.h \
    mainwindow.h

FORMS    += mainwindow.ui \
    usuario.ui \
    administrador.ui \
    usuarioperfil.ui

unix: LIBS += -L$$PWD/./ -lgtest

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix: PRE_TARGETDEPS += $$PWD/./libgtest.a

DISTFILES += \
    JSON.json \
    rede.json


