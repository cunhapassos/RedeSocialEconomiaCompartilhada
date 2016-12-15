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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Usuario
{
public:
    QAction *actionEditar_Perfil;
    QAction *actionExcluir_Perfil;
    QAction *actionListar_Pessoas;
    QWidget *centralwidget;
    QListWidget *listWidgetAmigos;
    QListWidget *listWidgetPessoas;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButtonIniAmizade;
    QPushButton *pushButtonExcAmizade;
    QTableWidget *tableWidgetInteresses;
    QPushButton *pushButtonIniTransacao;
    QMenuBar *menubar;
    QMenu *menuPerfil;
    QMenu *menuAmigos;
    QMenu *menuTransa_es;
    QMenu *menuRede;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Usuario)
    {
        if (Usuario->objectName().isEmpty())
            Usuario->setObjectName(QStringLiteral("Usuario"));
        Usuario->resize(800, 600);
        actionEditar_Perfil = new QAction(Usuario);
        actionEditar_Perfil->setObjectName(QStringLiteral("actionEditar_Perfil"));
        actionExcluir_Perfil = new QAction(Usuario);
        actionExcluir_Perfil->setObjectName(QStringLiteral("actionExcluir_Perfil"));
        actionListar_Pessoas = new QAction(Usuario);
        actionListar_Pessoas->setObjectName(QStringLiteral("actionListar_Pessoas"));
        centralwidget = new QWidget(Usuario);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidgetAmigos = new QListWidget(centralwidget);
        listWidgetAmigos->setObjectName(QStringLiteral("listWidgetAmigos"));
        listWidgetAmigos->setGeometry(QRect(240, 30, 211, 321));
        listWidgetPessoas = new QListWidget(centralwidget);
        listWidgetPessoas->setObjectName(QStringLiteral("listWidgetPessoas"));
        listWidgetPessoas->setGeometry(QRect(10, 30, 221, 321));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 121, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 10, 59, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(460, 10, 181, 16));
        pushButtonIniAmizade = new QPushButton(centralwidget);
        pushButtonIniAmizade->setObjectName(QStringLiteral("pushButtonIniAmizade"));
        pushButtonIniAmizade->setGeometry(QRect(10, 350, 221, 32));
        pushButtonExcAmizade = new QPushButton(centralwidget);
        pushButtonExcAmizade->setObjectName(QStringLiteral("pushButtonExcAmizade"));
        pushButtonExcAmizade->setGeometry(QRect(240, 350, 211, 32));
        tableWidgetInteresses = new QTableWidget(centralwidget);
        tableWidgetInteresses->setObjectName(QStringLiteral("tableWidgetInteresses"));
        tableWidgetInteresses->setGeometry(QRect(460, 30, 256, 321));
        pushButtonIniTransacao = new QPushButton(centralwidget);
        pushButtonIniTransacao->setObjectName(QStringLiteral("pushButtonIniTransacao"));
        pushButtonIniTransacao->setGeometry(QRect(470, 350, 151, 32));
        Usuario->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Usuario);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuPerfil = new QMenu(menubar);
        menuPerfil->setObjectName(QStringLiteral("menuPerfil"));
        menuAmigos = new QMenu(menubar);
        menuAmigos->setObjectName(QStringLiteral("menuAmigos"));
        menuTransa_es = new QMenu(menubar);
        menuTransa_es->setObjectName(QStringLiteral("menuTransa_es"));
        menuRede = new QMenu(menubar);
        menuRede->setObjectName(QStringLiteral("menuRede"));
        Usuario->setMenuBar(menubar);
        statusbar = new QStatusBar(Usuario);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Usuario->setStatusBar(statusbar);

        menubar->addAction(menuPerfil->menuAction());
        menubar->addAction(menuAmigos->menuAction());
        menubar->addAction(menuRede->menuAction());
        menubar->addAction(menuTransa_es->menuAction());
        menuPerfil->addAction(actionEditar_Perfil);
        menuPerfil->addAction(actionExcluir_Perfil);
        menuRede->addAction(actionListar_Pessoas);

        retranslateUi(Usuario);

        QMetaObject::connectSlotsByName(Usuario);
    } // setupUi

    void retranslateUi(QMainWindow *Usuario)
    {
        Usuario->setWindowTitle(QApplication::translate("Usuario", "MainWindow", 0));
        actionEditar_Perfil->setText(QApplication::translate("Usuario", "Editar Perfil", 0));
        actionExcluir_Perfil->setText(QApplication::translate("Usuario", "Excluir Perfil", 0));
        actionListar_Pessoas->setText(QApplication::translate("Usuario", "Listar Pessoas", 0));
        label->setText(QApplication::translate("Usuario", "Pessoas da Rede:", 0));
        label_2->setText(QApplication::translate("Usuario", "Amigos:", 0));
        label_3->setText(QApplication::translate("Usuario", "Op\303\247\303\265es para transa\303\247\303\243o:", 0));
        pushButtonIniAmizade->setText(QApplication::translate("Usuario", "Iniciar amizade", 0));
        pushButtonExcAmizade->setText(QApplication::translate("Usuario", "Excluir amizade", 0));
        pushButtonIniTransacao->setText(QApplication::translate("Usuario", "Inciciar transa\303\247\303\243o", 0));
        menuPerfil->setTitle(QApplication::translate("Usuario", "Perfil", 0));
        menuAmigos->setTitle(QApplication::translate("Usuario", "Amigos", 0));
        menuTransa_es->setTitle(QApplication::translate("Usuario", "Transa\303\247\303\265es", 0));
        menuRede->setTitle(QApplication::translate("Usuario", "Rede", 0));
    } // retranslateUi

};

namespace Ui {
    class Usuario: public Ui_Usuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USUARIO_H
