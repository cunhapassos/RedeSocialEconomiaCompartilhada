/********************************************************************************
** Form generated from reading UI file 'criarperfil.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRIARPERFIL_H
#define UI_CRIARPERFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CriarPerfil
{
public:
    QGroupBox *groupBox;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonM;
    QRadioButton *radioButtonF;
    QLineEdit *lineEditCEP;
    QLabel *label;
    QLineEdit *lineEditNome;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBoxIdade;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QComboBox *comboBoxEscolaridade;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEditInteresse;
    QPushButton *pushButton_2;
    QListWidget *listWidgetInteresses;
    QPushButton *pushButtonAdicionar;
    QPushButton *pushButton_4;

    void setupUi(QDialog *CriarPerfil)
    {
        if (CriarPerfil->objectName().isEmpty())
            CriarPerfil->setObjectName(QStringLiteral("CriarPerfil"));
        CriarPerfil->resize(605, 311);
        groupBox = new QGroupBox(CriarPerfil);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 231, 251));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 70, 59, 16));
        label_5->setMinimumSize(QSize(59, 0));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 160, 101, 81));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 81, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonM = new QRadioButton(layoutWidget);
        radioButtonM->setObjectName(QStringLiteral("radioButtonM"));

        horizontalLayout->addWidget(radioButtonM);

        radioButtonF = new QRadioButton(layoutWidget);
        radioButtonF->setObjectName(QStringLiteral("radioButtonF"));

        horizontalLayout->addWidget(radioButtonF);

        lineEditCEP = new QLineEdit(groupBox);
        lineEditCEP->setObjectName(QStringLiteral("lineEditCEP"));
        lineEditCEP->setGeometry(QRect(70, 70, 151, 21));
        lineEditCEP->setMinimumSize(QSize(113, 0));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 59, 16));
        lineEditNome = new QLineEdit(groupBox);
        lineEditNome->setObjectName(QStringLiteral("lineEditNome"));
        lineEditNome->setGeometry(QRect(70, 40, 151, 21));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(130, 190, 98, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinBoxIdade = new QSpinBox(layoutWidget1);
        spinBoxIdade->setObjectName(QStringLiteral("spinBoxIdade"));

        horizontalLayout_2->addWidget(spinBoxIdade);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 100, 201, 49));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        comboBoxEscolaridade = new QComboBox(layoutWidget2);
        comboBoxEscolaridade->setObjectName(QStringLiteral("comboBoxEscolaridade"));

        verticalLayout->addWidget(comboBoxEscolaridade);

        layoutWidget->raise();
        label_5->raise();
        groupBox_2->raise();
        lineEditCEP->raise();
        label->raise();
        lineEditNome->raise();
        layoutWidget->raise();
        groupBox_3 = new QGroupBox(CriarPerfil);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(260, 10, 331, 251));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 60, 101, 31));
        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 30, 321, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEditInteresse = new QLineEdit(layoutWidget3);
        lineEditInteresse->setObjectName(QStringLiteral("lineEditInteresse"));

        horizontalLayout_3->addWidget(lineEditInteresse);

        pushButton_2 = new QPushButton(layoutWidget3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        listWidgetInteresses = new QListWidget(groupBox_3);
        listWidgetInteresses->setObjectName(QStringLiteral("listWidgetInteresses"));
        listWidgetInteresses->setGeometry(QRect(10, 60, 221, 181));
        pushButtonAdicionar = new QPushButton(CriarPerfil);
        pushButtonAdicionar->setObjectName(QStringLiteral("pushButtonAdicionar"));
        pushButtonAdicionar->setGeometry(QRect(480, 270, 113, 32));
        pushButton_4 = new QPushButton(CriarPerfil);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(370, 270, 113, 32));

        retranslateUi(CriarPerfil);
        QObject::connect(pushButton_4, SIGNAL(clicked()), CriarPerfil, SLOT(close()));

        QMetaObject::connectSlotsByName(CriarPerfil);
    } // setupUi

    void retranslateUi(QDialog *CriarPerfil)
    {
        CriarPerfil->setWindowTitle(QApplication::translate("CriarPerfil", "Criar Perfil do Usu\303\241rio", 0));
        groupBox->setTitle(QApplication::translate("CriarPerfil", "Dados Pessoais", 0));
        label_5->setText(QApplication::translate("CriarPerfil", "CEP:", 0));
        groupBox_2->setTitle(QApplication::translate("CriarPerfil", "G\303\252nero:", 0));
        radioButtonM->setText(QApplication::translate("CriarPerfil", "M", 0));
        radioButtonF->setText(QApplication::translate("CriarPerfil", "F", 0));
        label->setText(QApplication::translate("CriarPerfil", "Nome:", 0));
        label_3->setText(QApplication::translate("CriarPerfil", "Idade:", 0));
        label_4->setText(QApplication::translate("CriarPerfil", "Escolaridade:", 0));
        groupBox_3->setTitle(QApplication::translate("CriarPerfil", "Interesses", 0));
        pushButton_3->setText(QApplication::translate("CriarPerfil", "Remover", 0));
        pushButton_2->setText(QApplication::translate("CriarPerfil", "Adicionar", 0));
        pushButtonAdicionar->setText(QApplication::translate("CriarPerfil", "Adicionar", 0));
        pushButton_4->setText(QApplication::translate("CriarPerfil", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class CriarPerfil: public Ui_CriarPerfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRIARPERFIL_H
