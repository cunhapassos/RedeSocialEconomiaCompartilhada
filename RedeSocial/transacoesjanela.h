/** ********************************************************************************
 *  @addtogroup MODULO REDE_SOCIAL
 *  @{
 *  @ingroup MOD_RS
 *
 *  @file Pessoa.h
 *  @brief Módulo de definição: Módulo Rede Social:
 *         Implementa a Rede Social de Economia Compartilhada por meio da estrutura
 *         de dados de umm grafo. Os pessoas da rede são representadas pelos vertices do gra-
 *         fo e os relacionamentos são representados pelas arestas.
 *         O grafo é implementado por meio de lista duplamente encadeada.
 *
 * @author NUR CORREIA - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

#ifndef TRANSACOESJANELA_H
#define TRANSACOESJANELA_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "rede.h"
#include "avaliacaojanela.h"

namespace Ui {
class TransacoesJanela;
}

/** ********************************************************************************
 * Classe: TransacoesJanela
 *
 * Descrição da classe
 *  A classe é responsavel pela interface de apresentação das transações da rede.
 *
 * Requisitos assegurados pela classe:
 *  Informar e atualizar transações da rede.
 *
 * Hipóteses assumidas pela classe:
 *  Transações inseridas estão corretamente formatadas.
 *
 * Restrições da classe:
 *  Classe não faz verificação da formatação das transações e nem sua validade.
 *
 * ********************************************************************************/
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

    void on_pushButtonConcluir_clicked();

private:
    Ui::TransacoesJanela *ui;
    Rede *rede;
    Pessoa *pes;
    AvaliacaoJanela *aval;
};

#endif // TRANSACOESJANELA_H
