#ifndef USUARIOPERFIL_H
#define USUARIOPERFIL_H

#include <QDialog>

namespace Ui {
class UsuarioPerfil;
}

class UsuarioPerfil : public QDialog
{
    Q_OBJECT

public:
    explicit UsuarioPerfil(QWidget *parent = 0);
    ~UsuarioPerfil();

private slots:


private:
    Ui::UsuarioPerfil *ui;
};

#endif // USUARIOPERFIL_H
