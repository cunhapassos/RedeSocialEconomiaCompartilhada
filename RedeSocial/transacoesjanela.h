#ifndef TRANSACOESJANELA_H
#define TRANSACOESJANELA_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "rede.h"
#include "avaliacaojanela.h"

namespace Ui {
class TransacoesJanela;
}

class TransacoesJanela : public QMainWindow
{
    Q_OBJECT

public:
    explicit TransacoesJanela(QWidget *parent = 0, Rede *_rede = 0, Pessoa *_pes = 0);
    ~TransacoesJanela();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::TransacoesJanela *ui;
    Rede *rede;
    Pessoa *pes;
    AvaliacaoJanela *aval;
};

#endif // TRANSACOESJANELA_H
