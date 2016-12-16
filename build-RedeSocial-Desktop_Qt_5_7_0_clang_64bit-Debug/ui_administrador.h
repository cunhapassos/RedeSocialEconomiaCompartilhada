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

QT_BEGIN_NAMESPACE

class Ui_Administrador
{
public:

    void setupUi(QDialog *Administrador)
    {
        if (Administrador->objectName().isEmpty())
            Administrador->setObjectName(QStringLiteral("Administrador"));
        Administrador->resize(400, 300);

        retranslateUi(Administrador);

        QMetaObject::connectSlotsByName(Administrador);
    } // setupUi

    void retranslateUi(QDialog *Administrador)
    {
        Administrador->setWindowTitle(QApplication::translate("Administrador", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Administrador: public Ui_Administrador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRADOR_H
