/** ********************************************************************************
 *  @addtogroup MODULO REDE_SOCIAL
 *  @{
 *  @ingroup MOD_RS
 *
 *  @file Relacionamento.h
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

#ifndef RelacionamentoH
#define RelacionamentoH

/* Inclusão do compilador */
#include <sstream>
#include <iostream>

/* Inclusoes de modulo de definicao */

#include "pessoa.h"

/** ********************************************************************************
 * Classe: Relacionamento
 *
 * Descrição da classe
 *  A classe Relacionamento representa as arestas do grafo da rede social de economia
 *  compartilhada. Representa o relacionamento entre pessoas da rede.
 *
 * Requisitos assegurados pela classe:
 *  ?????
 *
 * Hipóteses assumidas pela classe:
 *  ????
 *
 * REstrições da calsse:
 *  ???
 *
 * ********************************************************************************/
class Relacionamento
{
   /* Atributos da classe */
   private:
	  const Pessoa *origem;
	  const Pessoa *destino;

   /*****  Interface das funções exportadas pela classe  *****/
   public:
      /** ******************************************************************************
      *
      *  Descricao da funcao:
      *      Método construtor da classe, responsável por inicializar os principais atributos.
      *
      *  @param      *_origem      - Ponteiro para a pessoa de origem do relacionamento perten-
      *                            cente a rede social.
      *  @param      *_destino     - Ponteiro para a pessoa de destino do relacionamento per-
      *                            tencente a rede social.

      *
      *  Assertiva de entrada
      *              (*_origem && *_destino) != NULL.
      *
      ** *******************************************************************************/
      Relacionamento(  const Pessoa *_origem,  const Pessoa *_destino);

      /** ******************************************************************************
      *
      *  Descricao da funcao:
      *      Método destrutor da classe, responsável por destruir a classe.
      *
      *
      ** *******************************************************************************/
	  ~Relacionamento();
	  
      /** ******************************************************************************
      *  Funcao: *getOrigem
      *
      *  Descricao da funcao:
      *      Obtem a pessoa de origem do relacionamento.
      *
      * @return   origem - Ponteiro que aponta para a pessoa de origem do relacionamento.
      *
      ** *******************************************************************************/
	  const Pessoa *getOrigem() const;

      /** ******************************************************************************
      *  Funcao: *getDestino
      *
      *  Descricao da funcao:
      *      Obtem a pessoa de destino do relacionamento.
      *
      * @return   destino - Ponteiro que aponta para a pessoa de origem do relacionamento.
      *
      ** *******************************************************************************/
	  const Pessoa *getDestino() const;

          string relacionamentoJson() const;
};

#endif
