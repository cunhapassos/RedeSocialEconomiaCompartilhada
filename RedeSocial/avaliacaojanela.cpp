#include "avaliacaojanela.h"
#include "ui_avaliacaojanela.h"

AvaliacaoJanela::AvaliacaoJanela(QWidget *parent, Rede *_rede, Pessoa *_pes, Transacao *_tr) :
    QDialog(parent),
    ui(new Ui::AvaliacaoJanela)
{
    ui->setupUi(this);
    rede = _rede;
    pes = _pes;
    tr = _tr;
}

AvaliacaoJanela::~AvaliacaoJanela()
{
    delete ui;
}

void AvaliacaoJanela::on_pushButton_clicked()
{
    pes->inserirAvaliacao(ui->spinBox->value(), tr);
    hide();
}
