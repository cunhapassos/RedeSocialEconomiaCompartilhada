#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T21:42:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = redegui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    usuario.cpp \
    administrador.cpp \
    usuarioperfil.cpp

HEADERS  += mainwindow.h \
    usuario.h \
    administrador.h \
    usuarioperfil.h

FORMS    += mainwindow.ui \
    usuario.ui \
    administrador.ui \
    usuarioperfil.ui
