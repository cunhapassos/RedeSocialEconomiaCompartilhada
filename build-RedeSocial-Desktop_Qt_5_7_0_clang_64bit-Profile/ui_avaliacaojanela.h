/********************************************************************************
** Form generated from reading UI file 'avaliacaojanela.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVALIACAOJANELA_H
#define UI_AVALIACAOJANELA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AvaliacaoJanela
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton;

    void setupUi(QDialog *AvaliacaoJanela)
    {
        if (AvaliacaoJanela->objectName().isEmpty())
            AvaliacaoJanela->setObjectName(QStringLiteral("AvaliacaoJanela"));
        AvaliacaoJanela->resize(400, 120);
        label = new QLabel(AvaliacaoJanela);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 371, 20));
        widget = new QWidget(AvaliacaoJanela);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 60, 301, 38));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);


        horizontalLayout_2->addLayout(horizontalLayout);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        retranslateUi(AvaliacaoJanela);

        QMetaObject::connectSlotsByName(AvaliacaoJanela);
    } // setupUi

    void retranslateUi(QDialog *AvaliacaoJanela)
    {
        AvaliacaoJanela->setWindowTitle(QApplication::translate("AvaliacaoJanela", "Avalia\303\247\303\243o", 0));
        label->setText(QApplication::translate("AvaliacaoJanela", "Qual a nota que voc\303\252 da para o fornecedor nessa transa\303\247\303\243o?", 0));
        label_2->setText(QApplication::translate("AvaliacaoJanela", "Nota:", 0));
        pushButton->setText(QApplication::translate("AvaliacaoJanela", "Avaliar", 0));
    } // retranslateUi

};

namespace Ui {
    class AvaliacaoJanela: public Ui_AvaliacaoJanela {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVALIACAOJANELA_H
