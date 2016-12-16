/********************************************************************************
** Form generated from reading UI file 'administrador.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRADOR_H
#define UI_ADMINISTRADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Administrador
{
public:
    QLabel *label;

    void setupUi(QDialog *Administrador)
    {
        if (Administrador->objectName().isEmpty())
            Administrador->setObjectName(QStringLiteral("Administrador"));
        Administrador->resize(400, 300);
        label = new QLabel(Administrador);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 110, 191, 16));

        retranslateUi(Administrador);

        QMetaObject::connectSlotsByName(Administrador);
    } // setupUi

    void retranslateUi(QDialog *Administrador)
    {
        Administrador->setWindowTitle(QApplication::translate("Administrador", "Dialog", 0));
        label->setText(QApplication::translate("Administrador", "Aguardando Implementa\303\247\303\243o!!!", 0));
    } // retranslateUi

};

namespace Ui {
    class Administrador: public Ui_Administrador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRADOR_H
