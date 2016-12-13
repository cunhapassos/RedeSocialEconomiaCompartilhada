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

#ifndef PessoaH
#define PessoaH

/* Inclusão do compilador */


#include <vector>
#include <sstream>
#include <iostream>

#include "json.cpp"
#include "transacao.h"
#include "avaliacao.h"

using namespace std;

/** ********************************************************************************
 * Classe: Pessoa
 *
 * Descrição da classe
 *  A classe Pessoa é um vertice do grafo da rede social de economia compartilhada
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
class Pessoa
{
    /* Atributos da classe */
   private:
      string nome;
      string genero;
      bool visitado;
      unsigned int id;
      unsigned int cep;
      unsigned int idade;
      string escolaridade;

   /*****  Interface das funções exportadas pela classe  *****/
   public:
      vector<string> interesses;
      vector<int> transacoes; // Lista de id das transacoes que a passoa participou
      vector<int> avaliacoes; // Lista de id das avaliacoes da pessoa

      /** ******************************************************************************
      *
      *  Descricao da funcao:
      *      Método construtor da classe, responsável por inicializar os principais atributos.
      *
      *  @param      _id           - Identificador único da pessoa.
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
      *              _idade, _id e _cep sao representados por inteiros sem sinal.
      *
      ** *******************************************************************************/
      Pessoa(unsigned int _id, string _nome, unsigned int _idade, string _genero,  unsigned int _cep, string _escolaridade);

      /** ******************************************************************************
      *
      *  Descricao da funcao:
      *      Método destrutor da classe, responsável por destruir a classe.
      *
      ** *******************************************************************************/
	  ~Pessoa();
	  
      /** ******************************************************************************
      *  Funcao: getVisitado
      *
      *  Descricao da funcao:
      *      Recupera o valor visitado da classe para saber se o vertice que reperesenta
      *      a pessoa na rede social já foi visitado.
      *
      * @return   False - que indica de o vertice não foi visitado.
      * @return   True  - que indica que o vertice foi vistitado.
      *
      ** *******************************************************************************/
	  bool getVisitado() const;

      /** ******************************************************************************
      *  Funcao: setVisitado
      *
      *  Descricao da funcao:
      *      Altera o valor referente ao contorle de visita da classe pessoa.
      *
      * @param   valor - Valor booleano: False que indica de o vertice não foi visitado;
      *                                   True que indica que o vertice foi vistitado.
      *
      * Assertiva de entrada
      *           _id deve ser representado por um inteiro sem sinal.
      *
      ** *******************************************************************************/
      void setVisitado( bool valor );

      /** ******************************************************************************
      *  Funcao: getId
      *
      *  Descricao da funcao:
      *      Recupera o valor do identificador da classe Pessoa.
      *
      * @return id - Valor de identifiucação única da classe.
      *
      ** *******************************************************************************/
	  unsigned int getId() const;

      /** ******************************************************************************
      *  Funcao: setId
      *
      *  Descricao da funcao:
      *      Insere o valor do identificador da classe Pessoa.
      *
      * @param id - Valor de identifiucação única da classe.
      *
      ** *******************************************************************************/
      void setId(unsigned int id);

      /** ******************************************************************************
      *  Funcao: setNome
      *
      *  Descricao da funcao:
      *      Isere o valor referente ao nome da classe pessoa no atributo nome.
      *
      * @param  _nome - Nome da pessoa.
      *
      ** *******************************************************************************/
      void setNome(string _nome);

      /** ******************************************************************************
      *  Funcao: getNome
      *
      *  Descricao da funcao:
      *      Recupera o nome da classe Pessoa.
      *
      * @return  nome  - Nome da pessoa.
      *
      ** *******************************************************************************/
      string getNome() const;

      /** ******************************************************************************
      *  Funcao: setCep
      *
      *  Descricao da funcao:
      *      Isere o valor referente ao cep da classe pessoa no atributo cep.
      *
      * @param  _cep - CEP da pessoa.
      *
      * Assertiva de entrada
      *         _cep deve ser representado por um inteiro sem sinal.
      *
      ** *******************************************************************************/
      void setCep(unsigned int _cep );

      /** ******************************************************************************
      *  Funcao: getCep
      *
      *  Descricao da funcao:
      *      Recupera o cep da classe Pessoa.
      *
      * @return  cep  - CEP residencial da pessoa.
      *
      ** *******************************************************************************/
      unsigned int getCep() const;

      /** ******************************************************************************
      *  Funcao: setGenero
      *
      *  Descricao da funcao:
      *      Isere o valor referente ao genero da classe pessoa no atributo genero.
      *
      * @param  _genero - Genero da pessoa. Deve ser M para masculino ou F para feminino.
      *
      ** *******************************************************************************/
      void setGenero(string _genero );

      /** ******************************************************************************
      *  Funcao: getGenero
      *
      *  Descricao da funcao:
      *      Recupera o genero da classe Pessoa.
      *
      * @return  genero  - Genero da pessoa.
      *
      ** *******************************************************************************/
      string getGenero() const;

      /** ******************************************************************************
      *  Funcao: setGenero
      *
      *  Descricao da funcao:
      *      Isere o valor referente a idade da classe pessoa no atributo idade.
      *
      * @param  _idade - Idade da pessoa. Deve ser um número inteiro sem sinal.
      *
      * Assertiva de entrada
      *         _idade deve ser representado por um inteiro sem sinal.
      *
      ** *******************************************************************************/
      void setIdade(unsigned int _idade );

      /** ******************************************************************************
      *  Funcao: getIdade
      *
      *  Descricao da funcao:
      *      Recupera a idade da Pessoa.
      *
      * @return  idade  - Idade da pessoa.
      *
      ** *******************************************************************************/
      unsigned int getIdade() const;

      /** ******************************************************************************
      *  Funcao: setEscolaridade
      *
      *  Descricao da funcao:
      *      Isere o valor referente a escolarida da pessoa no atributo escolaridade.
      *
      * @param  _escolaridade - Escolaridade da pessoa. Deve ser uma das seguintes opcoes:
      *                         primeiro grau incompleto,
      *                         primeiro grau completo,
      *                         segundo grau incompleto,
      *                         segundo grau completo,
      *                         superior incompleto,
      *                         superior completo ou
      *                         pós-graduação
      *
      ** *******************************************************************************/
      void setEscolaridade(string _escolaridade );

      /** ******************************************************************************
      *  Funcao: getEscolaridade
      *
      *  Descricao da funcao:
      *      Recupera a escolaridade da Pessoa.
      *
      * @return  escolaridade  - Escolaridade da pessoa. Deve ser uma das seguintes opcoes:
      *                         primeiro grau incompleto,
      *                         primeiro grau completo,
      *                         segundo grau incompleto,
      *                         segundo grau completo,
      *                         superior incompleto,
      *                         superior completo ou
      *                         pós-graduação
      *
      ** *******************************************************************************/
      string getEscolaridade() const;

      bool inserirInteresse(string interesse);
      void inserirTransacao(int idTransacao);
      void inserirAvaliacao(int idAvaliacao);

      string getInteresse(int ordemInteresse);

      string pessoaJson() const;
};

#endif
