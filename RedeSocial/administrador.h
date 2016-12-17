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
 * @author NUR CORREZZI - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <QDialog>

namespace Ui {
class Administrador;
}

/** ********************************************************************************
 * Classe: Administrador
 *
 * Descrição da classe
 *  A classe Administrador é responsavel por armazenar uma pessoa a qual será o 
 * administrador da rede e fazer a integração com a interface gráfica.
 *
 * Requisitos assegurados pela classe:
 *  Armazenagem de dados pessoais assim como os protocolos necessários para a 
 * comunicação com a interface gráfica.
 *
 * Hipóteses assumidas pela classe:
 *  A classe ainda não faz exigencias quanto a seu uso.
 *
 * Restrições da classe:
 *  A classe ainda não possui restrições.  
 *
 * ********************************************************************************/
class Administrador : public QDialog
{
    Q_OBJECT

public:
    explicit Administrador(QWidget *parent = 0);
    ~Administrador();

private:
    Ui::Administrador *ui;
};

#endif // ADMINISTRADOR_H
