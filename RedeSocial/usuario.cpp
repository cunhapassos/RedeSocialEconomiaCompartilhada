#include "usuario.h"
#include "ui_usuario.h"


Usuario::Usuario(QWidget *parent, Rede *_rede, Pessoa *_pes) :
    QMainWindow(parent),
    ui(new Ui::Usuario)
{
    ui->setupUi(this);
    rede = _rede;
    pes = _pes;
    listarPessoasDaRede();
    listarAmigos();

}

Usuario::~Usuario()
{
    delete ui;
}

void Usuario::setUsuario(Pessoa *usuario)
{
    pes = usuario;
}
void Usuario::on_actionEditar_Perfil_triggered()
{
    edPerfil = new EditarPerfil(this, rede, pes);
    edPerfil->show();
}

void Usuario::on_actionExcluir_Perfil_triggered()
{
    rede->removePessoaPorNome(pes->getNome());
    hide();
    this->main->show();
}

void Usuario::listarPessoasDaRede()
{
    for(list<Pessoa *>::iterator i = rede->listaPessoas.begin() ; i != rede->listaPessoas.end() ; i++ ){
        ui->listWidgetPessoas->addItem(QString::fromStdString((*i)->getNome()));
    }
}
void Usuario::listarAmigos()
{
    for(list<Relacionamento *>::iterator i = rede->listaRelacionamentos.begin() ; i != rede->listaRelacionamentos.end() ; i++ ){
        if((*i)->getOrigem() == pes){
            ui->listWidgetAmigos->addItem(QString::fromStdString((*i)->getDestino()->getNome()));
        }
        if((*i)->getDestino() == pes){
            ui->listWidgetAmigos->addItem(QString::fromStdString((*i)->getOrigem()->getNome()));
        }
    }
}

void Usuario::listarInteresses()
{
    for(list<Pessoa *>::iterator i = rede->listaPessoas.begin() ; i != rede->listaPessoas.end() ; i++ ){
        if((*i) != pes){
            for(vector<string>::iterator j = (*i)->interesses.begin() ; j != (*i)->interesses.end() ; j++ ){
                //Parei aqui
                //ui->tableWidgetInteresses->addItem( QString::fromStdString(*j));
            }
        }

    }
}

void Usuario::on_pushButtonIniAmizade_clicked()
{
    string pes1, pes2;

    pes2 = ui->listWidgetPessoas->currentItem()->text().toStdString();
    pes1 = pes->getNome();

    if(!(rede->relacionamentoExiste(pes1, pes2)) && (pes1 != pes2)){
        rede->iniciarRelacionamentoPorNome(pes1, pes2);
        ui->listWidgetAmigos->addItem(QString::fromStdString(pes2));
    }
}

void Usuario::on_pushButtonExcAmizade_clicked()
{
    string pes2;
    pes2 = ui->listWidgetAmigos->currentItem()->text().toStdString();
    rede->removeRelacionamentoPorCaminhoNome(pes->getNome(), pes2);
    delete ui->listWidgetAmigos->currentItem();
}
