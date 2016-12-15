#include "editarperfil.h"
#include "ui_editarperfil.h"

EditarPerfil::EditarPerfil(QWidget *parent, Rede *_rede, Pessoa *_pes) :
    QDialog(parent),
    ui(new Ui::EditarPerfil)
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
    pes = _pes;

    cep = QString::number(pes->getCep());
    nome = QString::fromStdString(pes->getNome());
    idade = pes->getIdade();
    genero = QString::fromStdString(pes->getGenero());

    ui->lineEditNome->setText(nome);
    ui->lineEditCEP->setText(cep);
    ui->spinBoxIdade->setValue(idade);
    if(genero == "F"){
        ui->radioButtonF->setChecked(true);
    }
    else{
        ui->radioButtonM->setChecked(true);
    }
    for(vector<string>::iterator i = pes->interesses.begin() ; i != pes->interesses.end() ; i++ ){
        ui->listWidgetInteresses->addItem( QString::fromStdString(*i));
    }

}

EditarPerfil::~EditarPerfil()
{
    delete ui;
}



void EditarPerfil::on_pushButton_2_clicked()
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

void EditarPerfil::on_pushButton_3_clicked()
{
        delete ui->listWidgetInteresses->currentItem();
        contInteresses--;
}

void EditarPerfil::on_pushButtonAdicionar_clicked()
{
    nomeEd = (ui->lineEditNome->text()).toStdString();
    cepEd  = (ui->lineEditCEP->text()).toInt();
    idadeEd = ui->spinBoxIdade->value();
    if(ui->radioButtonM->isChecked()){
        generoEd = "M";
    }
    else{
        generoEd = "F";
    }
    escolaridadeEd = (ui->comboBoxEscolaridade->currentText()).toStdString();

    /* Insere Pessoa na Rede */
    rede->editaPessoa(pes, nomeEd, idadeEd, generoEd, cepEd, escolaridadeEd);

    //Insere interesses da Pessoa em sua lista de interesses
    pes->interesses.clear();
    for (int i = 0; i < (ui->listWidgetInteresses->count()); i++) {
        pes->inserirInteresse(ui->listWidgetInteresses->item(i)->text().toStdString());
    }
    hide();
}
