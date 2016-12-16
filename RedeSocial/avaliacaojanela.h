#ifndef AVALIACAOJANELA_H
#define AVALIACAOJANELA_H

#include <QDialog>
#include "Rede.h"
namespace Ui {
class AvaliacaoJanela;
}

class AvaliacaoJanela : public QDialog
{
    Q_OBJECT

public:
    explicit AvaliacaoJanela(QWidget *parent = 0, Rede *_rede = 0, Pessoa *_pes = 0, Transacao *_tr = 0);
    ~AvaliacaoJanela();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AvaliacaoJanela *ui;
    Rede *rede;
    Pessoa *pes;
    Transacao *tr;
};

#endif // AVALIACAOJANELA_H
