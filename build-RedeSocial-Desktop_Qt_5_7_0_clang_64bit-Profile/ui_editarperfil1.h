/********************************************************************************
** Form generated from reading UI file 'editarperfil1.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITARPERFIL1_H
#define UI_EDITARPERFIL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_EditarPerfil
{
public:

    void setupUi(QDialog *EditarPerfil)
    {
        if (EditarPerfil->objectName().isEmpty())
            EditarPerfil->setObjectName(QStringLiteral("EditarPerfil"));
        EditarPerfil->resize(400, 300);

        retranslateUi(EditarPerfil);

        QMetaObject::connectSlotsByName(EditarPerfil);
    } // setupUi

    void retranslateUi(QDialog *EditarPerfil)
    {
        EditarPerfil->setWindowTitle(QApplication::translate("EditarPerfil", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class EditarPerfil: public Ui_EditarPerfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITARPERFIL1_H
