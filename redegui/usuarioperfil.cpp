#include "usuarioperfil.h"
#include "ui_usuarioperfil.h"

UsuarioPerfil::UsuarioPerfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsuarioPerfil)
{
    ui->setupUi(this);
}

UsuarioPerfil::~UsuarioPerfil()
{
    delete ui;
}

