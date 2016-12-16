/********************************************************************************
** Form generated from reading UI file 'transacoesjanela.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACOESJANELA_H
#define UI_TRANSACOESJANELA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransacoesJanela
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton_2;
    QListWidget *listWidgetInteresses;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_3;
    QListWidget *listWidgetTransacoes;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_3;
    QListWidget *listWidgetTransacoesFinalizadas;
    QPushButton *pushButton_5;
    QPushButton *pushButtonConcluir;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TransacoesJanela)
    {
        if (TransacoesJanela->objectName().isEmpty())
            TransacoesJanela->setObjectName(QStringLiteral("TransacoesJanela"));
        TransacoesJanela->resize(1038, 600);
        centralwidget = new QWidget(TransacoesJanela);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 30, 311, 471));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 420, 141, 32));
        listWidgetInteresses = new QListWidget(groupBox);
        listWidgetInteresses->setObjectName(QStringLiteral("listWidgetInteresses"));
        listWidgetInteresses->setGeometry(QRect(15, 91, 281, 321));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 288, 38));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);


        horizontalLayout_2->addLayout(horizontalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(360, 30, 311, 461));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 420, 151, 32));
        listWidgetTransacoes = new QListWidget(groupBox_2);
        listWidgetTransacoes->setObjectName(QStringLiteral("listWidgetTransacoes"));
        listWidgetTransacoes->setGeometry(QRect(10, 90, 291, 321));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 420, 141, 32));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(690, 30, 321, 461));
        listWidgetTransacoesFinalizadas = new QListWidget(groupBox_3);
        listWidgetTransacoesFinalizadas->setObjectName(QStringLiteral("listWidgetTransacoesFinalizadas"));
        listWidgetTransacoesFinalizadas->setGeometry(QRect(10, 90, 301, 321));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 420, 181, 32));
        pushButtonConcluir = new QPushButton(centralwidget);
        pushButtonConcluir->setObjectName(QStringLiteral("pushButtonConcluir"));
        pushButtonConcluir->setGeometry(QRect(900, 510, 113, 32));
        TransacoesJanela->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TransacoesJanela);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TransacoesJanela->setStatusBar(statusbar);

        retranslateUi(TransacoesJanela);

        QMetaObject::connectSlotsByName(TransacoesJanela);
    } // setupUi

    void retranslateUi(QMainWindow *TransacoesJanela)
    {
        TransacoesJanela->setWindowTitle(QApplication::translate("TransacoesJanela", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("TransacoesJanela", "Servi\303\247os e Produtos Dispon\303\255veis:", 0));
        pushButton_2->setText(QApplication::translate("TransacoesJanela", "Iniciar Transa\303\247\303\243o", 0));
        label->setText(QApplication::translate("TransacoesJanela", "Profundidade da Busca:", 0));
        pushButton->setText(QApplication::translate("TransacoesJanela", "Listar", 0));
        groupBox_2->setTitle(QApplication::translate("TransacoesJanela", "Transa\303\247\303\265es em Andamento:", 0));
        pushButton_3->setText(QApplication::translate("TransacoesJanela", "Finalizar Transa\303\247\303\243o", 0));
        pushButton_4->setText(QApplication::translate("TransacoesJanela", "Atualizar", 0));
        groupBox_3->setTitle(QApplication::translate("TransacoesJanela", "Transa\303\247\303\265es Finalizadas:", 0));
        pushButton_5->setText(QApplication::translate("TransacoesJanela", "Atualizar", 0));
        pushButtonConcluir->setText(QApplication::translate("TransacoesJanela", "Concluir", 0));
    } // retranslateUi

};

namespace Ui {
    class TransacoesJanela: public Ui_TransacoesJanela {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACOESJANELA_H
