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

/* Controle de escopo do arquivo de definição */

#ifndef AVALIACAOJANELA_H
#define AVALIACAOJANELA_H

/* Inclusão do compilador */
#include <QDialog>

/* inclusão do módulo de definição */
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
    Transacao *tr1;
};

#endif // AVALIACAOJANELA_H
