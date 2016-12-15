#include "usuarioperfil.h"
#include "ui_usuarioperfil.h"

UsuarioPerfil::UsuarioPerfil(QWidget *parent, Rede *_rede) :
    QDialog(parent),
    ui(new Ui::UsuarioPerfil)
{
    ui->setupUi(this);
    rede = _rede;
    ui->comboBoxEscolaridade->addItem("primeiro grau incompleto");
    ui->comboBoxEscolaridade->addItem("primeiro grau completo");
    ui->comboBoxEscolaridade->addItem("segundo grau incompleto");
    ui->comboBoxEscolaridade->addItem("segundo grau completo");
    ui->comboBoxEscolaridade->addItem("superior incompleto");
    ui->comboBoxEscolaridade->addItem("superior completo");
    ui->comboBoxEscolaridade->addItem("pós-graduação");
    ui->radioButtonM->setChecked(true);
}

UsuarioPerfil::~UsuarioPerfil()
{
    delete ui;
}


void UsuarioPerfil::on_pushButtonAdicionar_clicked()
{
    nome = (ui->lineEditNome->text()).toStdString();
    cep  = (ui->lineEditCEP->text()).toInt();
    idade = ui->spinBoxIdade->value();
    if(ui->radioButtonM->isChecked()){
        genero = "M";
    }
    else{
        genero = "F";
    }
    escolaridade = (ui->comboBoxEscolaridade->currentText()).toStdString();

    rede->inserePessoa(nome, idade, genero, cep, escolaridade);
    hide();
}
