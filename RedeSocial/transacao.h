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
 * @author NUR CORREZZI - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
#include <iostream>
using namespace std;

/** ********************************************************************************
 * Classe: Transacao
 *
 * Descrição da classe
 *  A classe transacao representa as transacoes criadas a partir de servicos que podem
 * ser fornecidos ou requisitados na rede. Após escolha de requisição ou oferta uma
 * transação será criada entre dois usuarios.
 *
 * Requisitos assegurados pela classe:
 *  Transação entre dois usuarios, com interesses de ambos e identificador de finalização.
 *
 * Hipóteses assumidas pela classe:
 *  Identificador existe na rede e estara sendo preenchido de forma correta. É necessário
 * que o usuário da classe se sertifique de que os interesses entre fornecedor e consumidor
 * são complementares.
 *
 * Restrições da classe:
 *  Não identifica identificador inválido e não reconhece interesses não relacionados.
 *
 * ********************************************************************************/
class Transacao
{
protected:
    unsigned int id;

    int IdFornecedor;
    int IdConsumidor;
    string intersseFornecedor;
    string interesseSolicitante;

public:
    bool finalizada;
    /** ******************************************************************************
    *
    *  Descricao da funcao:
    *      Método construtor da classe, responsável por inicializar os principais atributos.
    *
    *  Assertiva de entrada:
    *      - _idade, _id e _cep sao representados por inteiros sem sinal.
    *      - Interesses são complementares.
    *      - Identificador da transação existe e é unico na rede, assim como os identificadores
    * dos usuários.
    *
    *  Assertiva de saída:
    *      - Transação corretamente estruturada com valores passados.
    *
    *  @param      _id                  - Identificador único da transacao.
    *  @param      _consumidor          - Identificador único do consumidor.
    *  @param      _fornecedor          - Identificador único do fornecedor.
    *  @param      _inteConsumidor      - String contendo interesse do consumidor.
    *  @param      _inteFornecedor      - String contendo interesse do fornecedor.
    *
    ** *******************************************************************************/
    Transacao(unsigned int _id, int _consumidor, int _fornecedor, string inteConsumidor, string inteFornecedor);

    /** ******************************************************************************
    *  Funcao: getId
    *
    *  Descricao da funcao:
    *      Recupera o valor do identificador da classe Transacao.
    *
    * @return int - Valor de identificação única da classe.
    *
    ** *******************************************************************************/
    unsigned int getId() const;

    /** ******************************************************************************
    *  Funcao: getIdFornecedor
    *
    *  Descricao da funcao:
    *      Recupera o valor do identificador do fornecedor.
    *
    * @return int - Valor de identificação única do fornecedor na rede.
    *
    ** *******************************************************************************/
    int getIdFornecedor() const;

    /** ******************************************************************************
    *  Funcao: getIdConsumidor
    *
    *  Descricao da funcao:
    *      Recupera o valor do identificador do consumidor.
    *
    * @return int - Valor de identificação única do consumidor na rede.
    *
    ** *******************************************************************************/
    int getIdConsumidor() const;

    /** ******************************************************************************
    *  Funcao: setFim
    *
    *  Descricao da funcao:
    *      Atualiza valor do estado da transacao.
    *
    * @param fim    - True : transacao finalizada.
    *               - False : transacao ainda nao finalizada.
    *
    ** *******************************************************************************/
    void setFim(bool fim);
    /** ******************************************************************************
    *  Funcao: getFim
    *
    *  Descricao da funcao:
    *      Retorna valor do estado da transacao.
    *
    * @return fim   - True : transacao finalizada.
    *               - False : transacao ainda nao finalizada.
    *
    ** *******************************************************************************/
    bool getFim();

    /** ******************************************************************************
    *  Funcao: getInteresseFornecedor
    *
    *  Descricao da funcao:
    *      Retorna string contendo interesse do fornecedor
    *
    * @return string - interesse do fornecedor.
    *
    ** *******************************************************************************/
    string getInteresseFornecedor() const;

    /** ******************************************************************************
    *  Funcao: getInteresseConsumidor
    *
    *  Descricao da funcao:
    *      Retorna string contendo interesse do consumidor
    *
    * @return string - interesse do consumidor.
    *
    ** *******************************************************************************/
    string getInteresseConsumidor() const;

    /** ******************************************************************************
    * Funcao: transacaoJson
    *
    * Descricao da funcao:
    *    Transforma os tipos básicos e estruturas do objeto transacao em uma string
    * com a formatação correta para salvar em arquivo do tipo .json.
    *
    * Assertiva de saida:
    *    Objeto transacao convertido corretamente para ser salvo em .json.
    *
    * @return string       - Contém objeto convertido para string em formato .json.
    *
    ** *******************************************************************************/
    string transacaoJson() const;

};

#endif // TRANSACAO_H
