#include "criarperfil.h"
#include "ui_criarperfil.h"



CriarPerfil::CriarPerfil(QWidget *parent, Rede *_rede) :
    QDialog(parent),
    ui(new Ui::CriarPerfil)
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
    rede = _rede;
}

CriarPerfil::~CriarPerfil()
{
    delete ui;
}


void CriarPerfil::on_pushButtonAdicionar_clicked()
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

    /* Insere Pessoa na Rede */
    rede->inserePessoa(nome, idade, genero, cep, escolaridade);
     usuarioPerfil= rede->procuraPonteiroPessoaNome(nome);

    //Insere interesses da Pessoa em sua lista de interesses
    for (int i = 0; i < (ui->listWidgetInteresses->count()); i++) {
        usuarioPerfil->inserirInteresse(ui->listWidgetInteresses->item(i)->text().toStdString());
    }

    usuarioJanela = new Usuario(this, rede, usuarioPerfil);
    usuarioJanela->main = main;
    usuarioJanela->show();
    hide();


}

void CriarPerfil::on_pushButton_2_clicked()
{
    if((ui->lineEditInteresse->text().length() < 201) && (contInteresses < 21)){
        if(!(ui->lineEditInteresse->text().isEmpty())){ // Não insere string vazia
            ui->listWidgetInteresses->addItem(ui->lineEditInteresse->text());
            contInteresses++;
        }
    }
    else{
        QMessageBox::information(this, "Erro", "Não foi possivel inserir interesse! Isera uma frase com ao menos um carcter e no maximo 200 caracteres, ou jverifique se já possui 20 interesses inseridos!");
    }
    ui->lineEditInteresse->clear();
}

void CriarPerfil::on_pushButton_3_clicked()
{
    delete ui->listWidgetInteresses->currentItem();
    contInteresses--;
}

