#include "usuario.h"
#include "ui_usuario.h"

Usuario::Usuario(QWidget *parent, Rede *_rede) :
    QMainWindow(parent),
    ui(new Ui::Usuario)
{
    ui->setupUi(this);
    rede = _rede;
}

Usuario::~Usuario()
{
    delete ui;
}

void Usuario::on_actionCriar_Perfil_triggered()
{
    uPerfil = new UsuarioPerfil(this, rede);
    uPerfil->show();
}

