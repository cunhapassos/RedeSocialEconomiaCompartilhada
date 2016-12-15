#ifndef USUARIO_H
#define USUARIO_H

#include <QMainWindow>
#include "usuarioperfil.h"
#include "Rede.h"

namespace Ui {
class Usuario;
}

class Usuario : public QMainWindow
{
    Q_OBJECT

public:
    explicit Usuario(QWidget *parent = 0, Rede *_rede = 0);
    ~Usuario();

private slots:
    void on_actionCriar_Perfil_triggered();

private:
    Rede *rede;
    Ui::Usuario *ui;
    UsuarioPerfil * uPerfil;
};

#endif // USUARIO_H
