#include "transacoesjanela.h"
#include "ui_transacoesjanela.h"
#include <QMessageBox>

TransacoesJanela::TransacoesJanela(QWidget *parent, Rede *_rede, Pessoa *_pes) :
    QMainWindow(parent),
    ui(new Ui::TransacoesJanela)
{
    ui->setupUi(this);
    rede = _rede;
    pes = _pes;
    on_pushButton_5_clicked();
}

TransacoesJanela::~TransacoesJanela()
{
    delete ui;
}

void TransacoesJanela::on_pushButton_clicked()
{
    int id1, id2;
    QString pes1, intere;

    ui->listWidgetInteresses->clear();
    for (list<Pessoa *>::iterator i = rede->listaPessoas.begin(); i != rede->listaPessoas.end(); i++)
    {
        id1 = pes->getId();
        id2 = (*i)->getId();

        if(rede->menorCaminho(id1, id2) && (rede->caminhoRelacionamentos.size() < (ui->spinBox->value() + 1)) && (pes != (*i))){

            for (vector<string>::iterator j = (*i)->interesses.begin(); j != (*i)->interesses.end(); j++)
            {
                pes1 = QString::fromStdString((*i)->getNome());
                intere = QString::fromStdString((*j));
                ui->listWidgetInteresses->addItem(pes1 + " -> " + intere);
            }
        }
        // Se profundidade igual a 1 lista todos os interesses da rede
        if( 0 == ui->spinBox->value() && (pes != (*i))){
            for (vector<string>::iterator j = (*i)->interesses.begin(); j != (*i)->interesses.end(); j++)
            {
                pes1 = QString::fromStdString((*i)->getNome());
                intere = QString::fromStdString((*j));
                ui->listWidgetInteresses->addItem(pes1 + " -> " + intere);
            }
        }

    }

}
/* Iniciar Transação */
void TransacoesJanela::on_pushButton_2_clicked()
{
    int id;
    string str, str2;
    string pes1, aux, intere, intere1;
    Pessoa *p;
    Transacao *tr;

    str = (ui->listWidgetInteresses->currentItem()->text()).toStdString();
    istringstream iss(str);
    iss >> pes1;
    iss >> aux;
    while(iss){
        intere1 = intere1 + " " + intere;
        iss >> intere;
    }

    p = rede->procuraPonteiroPessoaNome(pes1);
    tr = rede->iniciarTransacao(pes, p, "", intere1);
    id = tr->getId();

    ui->listWidgetTransacoes->addItem(QString::fromStdString(str));
    on_pushButton_4_clicked();
}

/* Atualizar Transação */
void TransacoesJanela::on_pushButton_4_clicked()
{
    QString p1, intere;
    ui->listWidgetTransacoes->clear();
    for(list<Transacao *>::iterator i = rede->transacoes.begin(); i != rede->transacoes.end(); i++)
    {
        if((*i)->getIdConsumidor() == pes->getId() && !(*i)->getFim()){
            p1 = QString::fromStdString((rede->procuraPonteiroPessoaId((*i)->getIdFornecedor()))->getNome());
            intere = QString::fromStdString((*i)->getInteresseFornecedor());
            ui->listWidgetTransacoes->addItem(p1 + " -> " + intere);
        }
    }
}

/* Finalizar Transação */
void TransacoesJanela::on_pushButton_3_clicked()
{

    string str, pes1;
    Pessoa *p1, *p2;
    Transacao *tr;

    str = (ui->listWidgetInteresses->currentItem()->text()).toStdString();
    istringstream iss(str);
    iss >> pes1;

    for(list<Transacao *>::iterator i = rede->transacoes.begin(); i != rede->transacoes.end(); i++)
    {
        p1 = rede->procuraPonteiroPessoaId((*i)->getIdFornecedor());
        p2 = rede->procuraPonteiroPessoaId((*i)->getIdConsumidor());
        if(p1->getNome() == pes1 && p2->getNome() == pes->getNome())
        {
            (*i)->setFim(true);
            tr = (*i);
        }
    }
    aval = new AvaliacaoJanela(this, rede, p1, tr);
    aval->show();

    delete ui->listWidgetTransacoes->currentItem();
    on_pushButton_5_clicked();
}
/* Atualizar transações finalizadas */
void TransacoesJanela::on_pushButton_5_clicked()
{
    QString p1, intere;
    ui->listWidgetTransacoesFinalizadas->clear();
    for(list<Transacao *>::iterator i = rede->transacoes.begin(); i != rede->transacoes.end(); i++)
    {
        if((*i)->getIdConsumidor() == pes->getId() && (*i)->getFim()){
            p1 = QString::fromStdString((rede->procuraPonteiroPessoaId((*i)->getIdFornecedor()))->getNome());
            intere = QString::fromStdString((*i)->getInteresseFornecedor());
            ui->listWidgetTransacoesFinalizadas->addItem(p1 + " -> " + intere);
        }
    }
}

void TransacoesJanela::on_pushButtonConcluir_clicked()
{
    hide();
}
