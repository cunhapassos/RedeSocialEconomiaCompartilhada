/** ********************************************************************************
 *  @addtogroup MODULO REDE_SOCIAL
 *  @{
 *  @ingroup MOD_RS
 *
 *  @file Rede.h
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

#ifndef RedeH
#define RedeH

/* Inclusão do compilador */

#include <list>

/* inclusão do módulo de definição */

#include "Pessoa.h"
#include "Relacionamento.h"


/** ********************************************************************************
 * Classe: Rede
 *
 * Descrição da classe
 *  A classe Rede implementa o grafo da da rede social de economia compartilhada e
 * contem os vertices e arestas da rede, que no caso são respectivamente as pessoas
 * e os seus relacionamentos.
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
class Rede
{
    /* Atributos da classe */
    protected:
      string nome;
      bool direcionado; // VERIFICAR SE CONVÉM RETIRAR????
      unsigned int identificador;
      /* Lista de pessoas da rede social */
      list<Pessoa *> listaPessoas;

      /* Lista de relacionamentos entre pessoas da rede social */
      list<Relacionamento *> listaRelacionamentos;

      /* Lista de relacionamentos existente de uma  pessoas ate outra na rede social */
      list<Relacionamento *> caminhoRelacionamentos;

      /*****  Interface das funções internas da classe  *****/

      /** ******************************************************************************
      *  Funcao: *procuraPonteiroPessoaNome
      *
      *  Descricao da funcao:
      *      Procura uma pessoa, na lista de pessoas da rede social, por meio de seu nome
      * e retorna um ponteiro para essa pessoa.
      *
      * @param    nome      - Nome que deseja encontrar na listas de pessoas da rede social.
      *
      * @return   retorno   - Ponteiro para a pessoa que possui o nome procurado.
      * @return   NULL      - Caso nao encontre o nome procurado na lista de pessoas da
      *                     rede social.
      *
      ** *******************************************************************************/
      Pessoa *procuraPonteiroPessoaNome( string nome );

      /** ******************************************************************************
      *  Funcao: *procuraPonteiroPessoaId
      *
      *  Descricao da funcao:
      *      Procura uma pessoa, na lista de pessoas da rede social, por meio de seu id
      * e retorna um ponteiro para essa pessoa.
      *
      * @param    id      - Id da pessoa que deseja encontrar na listas de pessoas da
      *                   rede social.
      *
      * @return   retorno   - Ponteiro para a pessoa que possui o id procurado.
      * @return   NULL      - Caso nao encontre o nome procurado na lista de pessoas da
      *                     rede social.
      *
      * Assertiva de entrada
      *               _id deve ser representado por um inteiro sem sinal.
      *
      ** *******************************************************************************/
      Pessoa *procuraPonteiroPessoaId( unsigned int id );

      /** ******************************************************************************
      *  Funcao: *procuraRelacionamentoPorCaminhoId
      *
      *  Descricao da funcao:
      *      Verifica se existe um relacionamento entre duas pessoas por meio do id das
      *  pessoas que estariam envolvidas no relacionamento.
      *
      * @param    idOrigem  - Id da pessoa de origem do relacionamento.
      * @param    idDestino - Id da pessoa de destino do relacionamento.
      *
      * @return   retorno   - Ponteiro para o relacionamento entre entre a pessoa que
      *                     possua idOrigem e a que possua idDestino.
      * @return   NULL      - Caso nao exista relacionamento entre as duas pessos.
      *
      * Assertiva de entrada
      *               idOrigem && idDestino devem ser unsigned.
      *
      ** *******************************************************************************/
      Relacionamento* procuraRelacionamentoPorCaminhoId( unsigned int idOrigem, unsigned int idDestino );

      Pessoa* getPessoaAdjacenteNaoVisitada( unsigned int id ); // VERIFICAR SE CONVÉM RETIRAR????


   /*****  Interface das funções exportadas pela classe  *****/
   public:
      /** ******************************************************************************
      *
      *  Descricao da funcao:
      *      Método construtor da classe, responsável por inicializar os principais atributos.
      *
      *  @param      _nome         - Nome da rede social.
      *  @param      _direcionado  - Indica se o grafo da rede é direcionado ou nao.
      *
      ** *******************************************************************************/
      Rede( string _nome, bool _direcionado = false );

      /** ******************************************************************************
      *
      *  Descricao da funcao:
      *      Método destrutor da classe, responsável por destruir a classe.
      *
      ** *******************************************************************************/
      ~Rede();

      /** ******************************************************************************
      *  Funcao: getNome
      *
      *  Descricao da funcao:
      *      Recupera o nome da rede social.
      *
      * @return  nome  - Nome da rede social.
      *
      ** *******************************************************************************/
      string getNome();

      /** ******************************************************************************
      *  Funcao: inserePessoa
      *  Descricao da funcao:
      *      Insere uma pessoa na rede social.
      *
      *  @param      _nome         - Nome da pessoa.
      *  @param      _idade        - Idade da pessoa.
      *  @param      _genero       - Genero da pessoa. Deve ser M para masculino ou F para
      *                            feminino.
      *  @param      _cep          - CEP residencial da pessoa. Deve ser um número inteiro.
      *  @param      _escolaridade - Representa a escolaridade da pessoa. Deve ser uma das
      *                            seguintes opcoes: primeiro grau incompleto, primeiro
      *                            grau completo, segundo grau incompleto, segundo grau
      *                            completo, superior incompleto, superior completo ou
      *                            pós-graduação.
      *
      *  Assertiva de entrada
      *              _idade, _id e _cep devem ser inteiros sem sinal.
      *
      ** *******************************************************************************/
      void inserePessoa(string nome, unsigned int idade, char genero, unsigned int cep, string escolaridade);

      /** ******************************************************************************
      *  Funcao: removePessoaPorId
      *
      *  Descricao da funcao:
      *      Remove pessoa da rede social que tenha identificação igual a id.
      *
      * @param   id - Identificador da pessoa a ser excluida da rede social.
      *
      * Assertiva de entrada
      *           _id deve ser representado por um inteiro sem sinal.
      *
      ** *******************************************************************************/
      void removePessoaPorId( unsigned int id );

      /** ******************************************************************************
      *  Funcao: removePessoaPorNome
      *
      *  Descricao da funcao:
      *      Remove pessoa da rede social que tenha o nome passado como argumento.
      *
      * @param   nome - Nome da pessoa a ser excluida da rede social.
      *
      ** *******************************************************************************/
      void removePessoaPorNome( string nome );

      /** ******************************************************************************
      *  Funcao: procuraPessoaNome
      *
      *  Descricao da funcao:
      *      Verifica se a pessao que possue o nome passado como argumento da função
      * peretence a rede social.
      *
      * @param   nome   - Nome da pessoa a ser verificada.
      *
      * @return true    - Caso a pessoa pertença a rede social.
      * @return false   - Caso a pessoa não pertença a rede social
      *
      ** *******************************************************************************/
      bool procuraPessoaNome( string nome );

      /** ******************************************************************************
      *  Funcao: insereRelacionamentoPorNome
      *
      *  Descricao da funcao:
      *      Insere um relacionamento entre duas pessoas da rede social por meio de seus
      * nomes.
      *
      * @param   nomeOrigem   - Nome da pessoa de origem do relacionamento.
      * @param   nomeDestino  - Nome da pessoa de destino do relacionamento.
      *
      *  Assertiva de entrada
      *         As pessoas que possuem nomeOrigem e nomeDestino devem pertencer a rede
      * social.
      *
      ** *******************************************************************************/
      void insereRelacionamentoPorNome( string nomeOrigem, string nomeDestino);

      /** ******************************************************************************
      *  Funcao: insereRelacionamentoPorId
      *
      *  Descricao da funcao:
      *      Insere um relacionamento entre duas pessoas da rede social por meio de seus
      * ids.
      *
      * @param   idOrigem   - Identificador da pessoa de origem do relacionamento.
      * @param   idDestino  - Identificador da pessoa de destino do relacionamento.
      *
      *  Assertiva de entrada
      *         As pessoas que possuem idOrigem e idDestino devem pertencer a rede social.
      *
      ** *******************************************************************************/
      void insereRelacionamentoPorId( int idOrigem, int idDestino);

      /** ******************************************************************************
      *  Funcao: removeRelacionamentoPorCaminhoNome
      *
      *  Descricao da funcao:
      *      Remove relacionamento da rede social entre duas pessoas que tenham o nome
      * passado como argumento.
      *
      * @param   nome - Nome da pessoa a ser excluida da rede social.
      *
      ** *******************************************************************************/
      void removeRelacionamentoPorCaminhoNome( string nomeOrigem, string nomeDestino );

      /** ******************************************************************************
      *  Funcao: removeRelacionamentoPorCaminhoId
      *
      *  Descricao da funcao:
      *      Remove relacionamento entre duas pessoas da rede social que tenha identificação
      * igual a idOrigem e idDestino.
      *
      * @param   idOrigem - Identificador da pessoa de origem do relacionamento.
      * @param   idDestino  - Identificador da pessoa de destino do relacionamento.
      *
      * Assertiva de entrada
      *           O relacionamento entre as pessoas de idOrigem e idDestino deve pertencer
      * a rede social.
      *
      ** *******************************************************************************/
      void removeRelacionamentoPorCaminhoId( unsigned int idOrigem, unsigned int idDestino );

      /** ******************************************************************************
      *  Funcao: numeroRelacionamentos
      *
      *  Descricao da funcao:
      *      Informa o numero de relacionamentos existentes na rede social.
      *
      * @return     - Numero de relacionamentos que existentes na rede social.
      *
      ** *******************************************************************************/
      unsigned int numeroRelacionamentos();

      /** ******************************************************************************
      *  Funcao: numeroPessoas
      *
      *  Descricao da funcao:
      *      Informa numero de pessoas pertencentes a rede social.
      *
      * @return     - Numero de pessoas pertencentes a rede social.
      *
      ** *******************************************************************************/
      unsigned int numeroPessoas();
      bool vazia();
      void limpa();

      bool menorCaminho( unsigned int idOrigem, unsigned int idDestino );
      bool arvoreGeradoraMinima( unsigned int idOrigem );
};

#endif

