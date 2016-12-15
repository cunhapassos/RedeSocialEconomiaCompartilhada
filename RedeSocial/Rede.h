<<<<<<< HEAD
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
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <fstream>
#include <iostream>

/* inclusão do módulo de definição */

#include "pessoa.h"
#include "transacao.h"
#include "relacionamento.h"

#include "json.hpp"

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
      unsigned int idPessoa;
      unsigned int idTransacao;
      unsigned int idColaboracao;


      /** ******************************************************************************
      *  Funcao: *getRelacionamentoAdjacenteNaoVisitado
      *
      *  Descricao da funcao:
      *      Procura uma pessoa, na lista de pessoas da rede social, que ainda nao foi
      * visitada.
      *
      * @param    id      - ID da pessoa a ser procurada.
      *
      *
      ** *******************************************************************************/
      Pessoa* getRelacionamentoAdjacenteNaoVisitado( unsigned int id );

      /*****  Interface das funções exportadas pela classe  *****/
      public:

      /* Lista de pessoas da rede social */
      list<Pessoa *> listaPessoas;

      /* Lista de relacionamentos entre pessoas da rede social */
      list<Relacionamento *> listaRelacionamentos;

      /* Lista de relacionamentos existente de uma  pessoas ate outra na rede social */
      list<Relacionamento *> caminhoRelacionamentos;

      /* Lista de Transacoes */
      list<Transacao *> transacoes;

      /** ******************************************************************************
      *  Funcao: relacionamentoExiste
      *
      *  Descricao da funcao:
      *      Verifica se um relacionamento existe na rede
      * visitada.
      *
      * @param    pes1      - Nome da pessoa a ser procurada no relacionamento.
      * @param    pes2      - Nome da pessoa a ser procurada no relacionamento.
      *
      ** *******************************************************************************/
      bool relacionamentoExiste(string pes1, string pes2);

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
      void inserePessoa(string nome, unsigned int idade, string genero, unsigned int cep, string escolaridade);

      /** ******************************************************************************
      *  Funcao: editaPessoa
      *  Descricao da funcao:
      *      Edita os atributos de uma pessoa da rede social.
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
      void editaPessoa(Pessoa *p, string nome, unsigned int idade, string genero, unsigned int cep, string escolaridade);

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
      void iniciarRelacionamentoPorNome( string nomeOrigem, string nomeDestino);

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
      void iniciarRelacionamentoPorId( int idOrigem, int idDestino);

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

      /** ******************************************************************************
      *  Funcao: vazia
      *
      *  Descricao da funcao:
      *      Informa se rede social está vazia ou nao
      *
      * @return     true   - Indica que a rede social está vazia.
      * @return     false  - Indica que a rede social não está vazia.
      *
      ** *******************************************************************************/
      bool vazia();

      /** ******************************************************************************
      *  Funcao: limpa
      *
      *  Descricao da funcao:
      *      Limpa a rede social, apagando relacionamentos e pessoas que existiam na rede
      * social.
      *
      *
      ** *******************************************************************************/
      void limpa();

      /** ******************************************************************************
      *  Funcao: arvoreGeradoraMinima
      *
      *  Descricao da funcao:
      *      Cria a arvore geradora minima a partir do id de uma Pessoa de origem
      *
      * @param idOrigem - Identificador da pessoa de origem
      *
      *
      ** *******************************************************************************/
      bool arvoreGeradoraMinima( unsigned int idOrigem );

      /** ******************************************************************************
      *  Funcao: imprimirCaminhoRelacionamentos
      *
      *  Descricao da funcao:
      *      Imprime a arvore geradora minima já gerada na rede
      *
      ** *******************************************************************************/
      void imprimirCaminhoRelacionamentos();

      /** ******************************************************************************
      *  Funcao: menorCaminho
      *
      *  Descricao da funcao:
      *      Retorna a distancia minima entre duas Pessoas na rede
      *
      * @param idOrigem     - Identificador da pessoa de origem
      * @param idDestino    - Identificador da pessoa de destino
      *
      *
      ** *******************************************************************************/
      bool menorCaminho( unsigned int idOrigem, unsigned int idDestino );


      void iniciarTransacao(Pessoa *solicitante, Pessoa *fornecedor, string inteSoliciatante, string inteFornecedor);

      void inserirTransacao(unsigned int id, Pessoa *solicitante, Pessoa *fornecedor, string inteSoliciatante, string inteFornecedor, bool finalizada);

      void guardarRedeJson(string arquivo);

      string redeJson();

      bool criarRedeJson(string arquivo);
      bool inserirPessoasJson(json js);
      bool inserirTransacaoJson(json js);
      bool inserirRelacionamentoJson(json js);
};

#endif

=======
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
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <fstream>
#include <iostream>

/* inclusão do módulo de definição */

#include "pessoa.h"
#include "transacao.h"
#include "relacionamento.h"

#include "json.hpp"

/** ********************************************************************************
 * Classe: Rede
 *
 * Descrição da classe
 *  A classe Rede implementa o grafo da da rede social de economia compartilhada e
 * contem os vertices e arestas da rede, que no caso são respectivamente as pessoas
 * e os seus relacionamentos.
 *
 * Requisitos assegurados pela classe:
 *  Criação, execução e persistência da estrutura rede criado por suas funções,
 * contendo estas dados válidos ou inválidos de usuários.
 *
 * Hipóteses assumidas pela classe:
 *  Execução e requisição de serviços conforme protocolado. É esperado que o usuário
 * informe valores válidos para entidades simples como especificadas em pessoa.h,
 * usuário.h, requisitos.h, administrador.h, relacionamento.h e transacao.h.
 *
 * Restrições da classe:
 *  Vértices e arestas são operados como classes customizadas identificadas por tipos
 * especificados em pessoa.h e relacionamento.h, portanto grafo não trabalho com
 * tipos quaisquer.
 *
 * ********************************************************************************/
class Rede
{
    /* Atributos da classe */
    protected:
      string nome;
      bool direcionado; // VERIFICAR SE CONVÉM RETIRAR????
      unsigned int idPessoa;
      unsigned int idTransacao;
      unsigned int idColaboracao;

      /** ******************************************************************************
      *  Funcao: *getRelacionamentoAdjacenteNaoVisitado
      *
      *  Descricao da funcao:
      *      Procura uma pessoa, na lista de pessoas da rede social, que ainda nao foi
      * visitada.
      *
      * @param    id      - ID da pessoa a ser procurada.
      *
      *
      ** *******************************************************************************/
      Pessoa* getRelacionamentoAdjacenteNaoVisitado( unsigned int id );

      /*****  Interface das funções exportadas pela classe  *****/
      public:

      /* Lista de pessoas da rede social */
      list<Pessoa *> listaPessoas;

      /* Lista de relacionamentos entre pessoas da rede social */
      list<Relacionamento *> listaRelacionamentos;

      /* Lista de relacionamentos existente de uma  pessoas ate outra na rede social */
      list<Relacionamento *> caminhoRelacionamentos;

      /* Lista de Transacoes */
      list<Transacao *> transacoes;


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
      void inserePessoa(string nome, unsigned int idade, string genero, unsigned int cep, string escolaridade);

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
      void iniciarRelacionamentoPorNome( string nomeOrigem, string nomeDestino);

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
      void iniciarRelacionamentoPorId( int idOrigem, int idDestino);

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

      /** ******************************************************************************
      *  Funcao: vazia
      *
      *  Descricao da funcao:
      *      Informa se rede social está vazia ou nao
      *
      * @return     true   - Indica que a rede social está vazia.
      * @return     false  - Indica que a rede social não está vazia.
      *
      ** *******************************************************************************/
      bool vazia();

      /** ******************************************************************************
      *  Funcao: limpa
      *
      *  Descricao da funcao:
      *      Limpa a rede social, apagando relacionamentos e pessoas que existiam na rede
      * social.
      *
      *
      ** *******************************************************************************/
      void limpa();

      /** ******************************************************************************
      *  Funcao: arvoreGeradoraMinima
      *
      *  Descricao da funcao:
      *      Cria a arvore geradora minima a partir do id de uma Pessoa de origem
      *
      * @param idOrigem - Identificador da pessoa de origem
      *
      *
      ** *******************************************************************************/
      bool arvoreGeradoraMinima( unsigned int idOrigem );

      /** ******************************************************************************
      *  Funcao: imprimirCaminhoRelacionamentos
      *
      *  Descricao da funcao:
      *      Imprime a arvore geradora minima já gerada na rede
      *
      ** *******************************************************************************/
      void imprimirCaminhoRelacionamentos();

      /** ******************************************************************************
      *  Funcao: menorCaminho
      *
      *  Descricao da funcao:
      *      Retorna a distancia minima entre duas Pessoas na rede
      *
      * @param idOrigem     - Identificador da pessoa de origem
      * @param idDestino    - Identificador da pessoa de destino
      *
      *
      ** *******************************************************************************/
      bool menorCaminho( unsigned int idOrigem, unsigned int idDestino );

      /** ******************************************************************************
      *  Funcao: iniciarTransacao
      *
      *  Descricao da funcao:
      *      Inicia transacao entre usuários e atualiza lista de transações da rede.
      *
      * @param *solicitante          - Ponteiro para usuario que requisitou um servico.
      * @param *fornecedor           - Ponteiro para usuario que ira fornecer servico.
      * @param inteSoliciatante      - Especificacao em string do servico solicitado por
      * solicitante.
      * @param inteFornecedor        - Especificacao em string do servico ofertado por
      * fornecedor.
      *
      ** *******************************************************************************/
      void iniciarTransacao(Pessoa *solicitante, Pessoa *fornecedor, string inteSoliciatante, string inteFornecedor);

      /** ******************************************************************************
      *  Funcao: iniciarTransacao
      *
      *  Descricao da funcao:
      *      Inicia transacao entre usuários e atualiza lista de transações da rede.
      *
      * @param *solicitante          - Ponteiro para usuario que requisitou um servico.
      * @param *fornecedor           - Ponteiro para usuario que ira fornecer servico.
      * @param inteSoliciatante      - Especificacao em string do servico solicitado por
      * solicitante.
      * @param inteFornecedor        - Especificacao em string do servico ofertado por
      * fornecedor.
      * @param finalizada            - Valor boleano que indica se transação foi finalizada.
      *
      ** *******************************************************************************/
      void inserirTransacao(unsigned int id, Pessoa *solicitante, Pessoa *fornecedor, string inteSoliciatante, string inteFornecedor, bool finalizada);

      /** ******************************************************************************
      * Funcao: iniciarTransacao
      *
      * Descricao da funcao:
      *     Inicia transacao entre usuários e atualiza lista de transações da rede.
      *
      * Assertiva de entrada:
      *     string informada possui formato válido para armazenagem em .json.
      *
      * Assertiva de ssaida:
      *     Arquivo .json gerado com rede salva.
      *
      * @param arquivo          - string com todos os parametros da rede corretamente
      * formatados, tipos básicos da rede e estruturas.
      *
      ** *******************************************************************************/
      void guardarRedeJson(string arquivo);

      /** ******************************************************************************
      * Funcao: redeJson
      *
      * Descricao da funcao:
      *     Constroi string de todas as variaveis e tipos básicos da rede para formato
      * json.
      *
      * Assertiva de saida:
      *     String contendo rede em formato json.
      *
      * @return string      - Rede convertida para formato json em string.
      *
      ** *******************************************************************************/
      string redeJson();

      /** ******************************************************************************
      * Funcao: criarRedeJson
      *
      * Descricao da funcao:
      *     Faz a leitura de um arquivo em formato json e popula o objeto rede no qual a
      * funcao foi chamada.
      *
      * Assertiva de entrada:
      *     O arquivo deve existir e estar corretamente formatado como json, construido a
      * partir da funcao guardarRedeJson.
      *
      * Assertiva de saida:
      *     Objeto do tipo rede populado com todos os valores da rede salva em arquivo json.
      *
      * @param  arquivo   - Nome do arquivo .json que será utilizado para leitura.
      * @return bool      - True : Caso arquivo exista e esteja corretamente formatado.
      *                   - False : Caso arquivo não exista ou esteja incorretamente formatado.
      *
      ** *******************************************************************************/
      bool criarRedeJson(string arquivo);

      /** ******************************************************************************
      * Funcao: inserirPessoasJson
      *
      * Descricao da funcao:
      *     Insere pessoas lidas de um arquivo json no objeto rede. Função é auxiliar a
      * função @sa criarRedeJson
      *
      * Assertiva de entrada:
      *     Formato da pessoa lida em arquivo deve estar corretamente estruturado.
      *
      * Assertiva de saida:
      *     Pessoa inserida corretamete na rede com todos valores corretos.
      *
      * @param  js        - tipo básico json no qual será carregado o arquivo de leitura.
      * @return bool      - True : Caso arquivo esteja corretamente formatado.
      *                   - False : Caso arquivo não esteja corretamente formatado.
      *
      ** *******************************************************************************/
      bool inserirPessoasJson(json js);

      /** ******************************************************************************
      * Funcao: inserirTransacaoJson
      *
      * Descricao da funcao:
      *     Insere transacoes lidas de um arquivo json no objeto rede. Função é auxiliar a
      * função @sa criarRedeJson
      *
      * Assertiva de entrada:
      *     Formato da transacao lida em arquivo deve estar corretamente estruturado.
      *
      * Assertiva de saida:
      *     Transacao inserida corretamete na rede com todos valores corretos.
      *
      * @param  js        - tipo básico json no qual será carregado o arquivo de leitura.
      * @return bool      - True : Caso arquivo esteja corretamente formatado.
      *                   - False : Caso arquivo não esteja corretamente formatado.
      *
      ** *******************************************************************************/
      bool inserirTransacaoJson(json js);

      /** ******************************************************************************
      * Funcao: inserirRelacionamentoJson
      *
      * Descricao da funcao:
      *     Insere relacionamentos lidos de um arquivo json no objeto rede. Função é auxiliar a
      * função @sa criarRedeJson
      *
      * Assertiva de entrada:
      *     Formato do relacionamento lido em arquivo deve estar corretamente estruturado.
      *
      * Assertiva de saida:
      *     Relacionamento inserido corretamete na rede com todos valores corretos.
      *
      * @param  js        - tipo básico json no qual será carregado o arquivo de leitura.
      * @return bool      - True : Caso arquivo esteja corretamente formatado.
      *                   - False : Caso arquivo não esteja corretamente formatado.
      *
      ** *******************************************************************************/
      bool inserirRelacionamentoJson(json js);
};

#endif

>>>>>>> origin/master
