#include "usuario.h"
#include "ui_usuario.h"
#include "usuarioperfil.h"

Usuario::Usuario(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Usuario)
{
    ui->setupUi(this);
}

Usuario::~Usuario()
{
    delete ui;
}

void Usuario::on_actionCriar_Perfil_triggered()
{
    uPerfil = new UsuarioPerfil(this);
    uPerfil->show();
}
