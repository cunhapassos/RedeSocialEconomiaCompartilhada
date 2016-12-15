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

#ifndef AVALIACAO_H
#define AVALIACAO_H

#include "transacao.h"

/** ********************************************************************************
 * Classe: Avaliacao
 *
 * Descrição da classe
 *  A classe Avaliacao contem valores atribuidos a uma transacao. Todas as avaliações
 * serão salvas na rede e irão possuir um identificador único que estara diretamente
 * relacionado com umatransacao.
 *
 * Requisitos assegurados pela classe:
 *  Armazenamento de identificador de avaliacao e valor de nota relacionado a uma
 * transacao.
 *
 * Hipóteses assumidas pela classe:
 *  Identificador de avaliacao é unico e esta alinhado com identificador de transacoes
 * da rede.
 *
 * Restrições da classe:
 *  Não faz identificação da unicidade de seu identificador e nem verifica se transacao
 * a qual esta relacionada esta de fato inserida na rede.
 *
 * ********************************************************************************/
class Avaliacao
{
protected:
    unsigned int id;
    unsigned int notaAvaliacao;
    Transacao* transacao;

public:

    /** ******************************************************************************
    *
    *  Descricao da funcao:
    *      - Método construtor da classe, responsável por inicializar os principais atributos.
    *
    *  Assertiva de entrada:
    *      - _id é um identificador único da avaliação na rede.
    *      - nota, possui um valor não negativo.
    *      - *_transacao existe e esta inserido na lista de transacoes da rede.
    *
    *  Assertiva de saída:
    *      - Avaliação criada com sucesso.
    *
    *  @param      _id          - Identificador único que será atribuido a avaliacao.
    *  @param      nota         - Nota que sera atribuida a transacao.
    *  @param      *_transacao  - Ponteiro para transacao a qual nota diz respeito.
    *
    *
    ** *******************************************************************************/
    Avaliacao(unsigned int _id, unsigned int nota, Transacao *_transacao);

    /** ******************************************************************************
    *  Funcao: getId
    *
    *  Descricao da funcao:
    *      Informa qual é o identificador unico atribuido a transacao.
    *
    * @return unsigned int - retorna identificador unico da avaliacao.
    *
    ** *******************************************************************************/
    unsigned int getId();

    /** ******************************************************************************
    *  Funcao: getNota
    *
    *  Descricao da funcao:
    *      Informa qual é a nota aramazenada na avaliacao atribuida a transacao.
    *
    * @return  unsigned int - retorna o valor da nota atribuida.
    *
    ** *******************************************************************************/
    unsigned int getNota();

    /** ******************************************************************************
    *  Funcao: setNota
    *
    *  Descricao da funcao:
    *      Modifica nota atribuida a avaliação.
    *
    * @param  nota - valor para o qual nota será atualizada.
    *
    ** *******************************************************************************/
    void setNota(unsigned int nota);

    /** ******************************************************************************
    *  Funcao: getTransacao
    *
    *  Descricao da funcao:
    *      Retorna transacao a qual avaliação se refere.
    *
    * @return Transacao* - ponteiro para transacao armazenado pela avaliacao.
    *
    ** *******************************************************************************/
    Transacao* getTransacao();
};

#endif // AVALIACAO_H
