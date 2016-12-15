/********************************************************************************
** Form generated from reading UI file 'usuario.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USUARIO_H
#define UI_USUARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Usuario
{
public:
    QAction *actionCriar_Perfil;
    QAction *actionEditar_Perfil;
    QAction *actionExcluir_Perfil;
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuPerfil;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Usuario)
    {
        if (Usuario->objectName().isEmpty())
            Usuario->setObjectName(QStringLiteral("Usuario"));
        Usuario->resize(800, 600);
        actionCriar_Perfil = new QAction(Usuario);
        actionCriar_Perfil->setObjectName(QStringLiteral("actionCriar_Perfil"));
        actionEditar_Perfil = new QAction(Usuario);
        actionEditar_Perfil->setObjectName(QStringLiteral("actionEditar_Perfil"));
        actionExcluir_Perfil = new QAction(Usuario);
        actionExcluir_Perfil->setObjectName(QStringLiteral("actionExcluir_Perfil"));
        centralwidget = new QWidget(Usuario);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 90, 291, 16));
        Usuario->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Usuario);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuPerfil = new QMenu(menubar);
        menuPerfil->setObjectName(QStringLiteral("menuPerfil"));
        Usuario->setMenuBar(menubar);
        statusbar = new QStatusBar(Usuario);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Usuario->setStatusBar(statusbar);

        menubar->addAction(menuPerfil->menuAction());
        menuPerfil->addAction(actionCriar_Perfil);
        menuPerfil->addAction(actionEditar_Perfil);
        menuPerfil->addAction(actionExcluir_Perfil);

        retranslateUi(Usuario);

        QMetaObject::connectSlotsByName(Usuario);
    } // setupUi

    void retranslateUi(QMainWindow *Usuario)
    {
        Usuario->setWindowTitle(QApplication::translate("Usuario", "MainWindow", 0));
        actionCriar_Perfil->setText(QApplication::translate("Usuario", "Criar Perfil", 0));
        actionEditar_Perfil->setText(QApplication::translate("Usuario", "Editar Perfil", 0));
        actionExcluir_Perfil->setText(QApplication::translate("Usuario", "Excluir Perfil", 0));
        label->setText(QApplication::translate("Usuario", "Clique no menu Perfil-> Criar Perfil", 0));
        menuPerfil->setTitle(QApplication::translate("Usuario", "Perfil", 0));
    } // retranslateUi

};

namespace Ui {
    class Usuario: public Ui_Usuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USUARIO_H
