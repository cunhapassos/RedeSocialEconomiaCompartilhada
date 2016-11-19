/** ********************************************************************************
 *  @defgroup MODULO GRAFO
 *  @{
 *  @ingroup MOD_GRAFO
 *  @brief
 *  O módulo permite a criação e manipulação de Grafos.
 *
 *  @file grafo.h
 *  @brief Módulo de definição: Módulo Grafo
 
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 18/09/2016
 *
 @}********************************************************************************/

#ifndef GRAFO
#define GRAFO

/**
 * 
 * @brief Tipo de dado Aresta
 *
 * Registro:
 *
 * - valoraresta  - Recebe um int como valor/peso da aresta.
 * - usado        - Recebe um valor 0 ou 1 para indicar se foi usaso ou nao.
 * - *proxaresta  - Ponteiro para a próxima aresta.
 * - *padj        - Ponteiro para o no adjacente.
 *
 */

typedef struct elementoaresta {
    int usado;
    int valoraresta;
    struct elementoaresta *proxaresta;
    struct elementono *padj;
}Aresta;

/**
* @brief Tipo de dado No
*
* Registro:
*
* - id             - Recebe um int como identificador do No.
* - dado           - Recebe um char como conteudo do No.
* - *proxno        - Ponteiro para o próximo No.
* - *pacessoaresta - Ponteiro para a aresta de acesso.
*
*/

typedef struct elementono{
    int id;
    char dado;
    int usado;
    int numVizinhos;
    struct elementono *proxno;
    struct elementoaresta *pacessoaresta;
}No;

/**
 * @brief Tipo de dado Grafo
 *
 * Registro:
 *
 * - *nome          - Recebe o nome do grafo.
 * - contId         - Contador de Id, para fornecer ids distintos para o nos.
 * - ordem          - Recebe o numero de Nos que o grafo possui.
 * - tamanho        - Recebe o numero de arestas que o grafo possui.
 * - *noInicio      - Ponteiro para o no de entrada do grafo.
 *
 */

typedef struct elementografo{
    int ordem;
    int contId;
    char *nome;
    int tamanho;
    struct elementono *noInicio;
}Grafo;


/*
 * @brief Cria um grafo e lhe da um nome.
 */

Grafo *criaGrafo(char *nome);

/*
 * @brief Constroi um grafo a partir dos dados de um arquivo.
 */

int constroiGrafo(Grafo *g, char *arquivo);

/*
 * @brief Le um grafo e imprime seus valores na tela.
 */

void LeGrafo(Grafo *g);

/*
 * @brief Retorna o nome de um grafo G.
 */

char *retornaNomeGrafo(Grafo *g);

/*
 * @brief Destroi um grafo G.
 */

int destroiGrafo(Grafo *g);

/*
 * @brief Limpa um grafo deixando-o sem nenhum No ou Aresta.
 */

int zeraGrafo(Grafo *g);

/*
 * @brief Adiciona vertice em um grafo G.
 */

int adicionaVertice(Grafo *g, char dado);

/*
 * @brief Remove um vertice de um grafo G.
 */
int removeVertice(Grafo *g, int noId);

/*
 * @brief Funcao auxiliar para remover um No de um grafo.
 */

No *removeVerticeAux(No *inicio, int noId);


/*
 * @brief Destroi um lista de aresta.
 */

void destroiListaArestas(Aresta *inicio);


/*
 * @brief Retorna um ponteiro para o no procurado.
 */

No *retornaNo(Grafo *g, int noId);

/*
 * @brief Retorna um ponteiro para a Aresta procurada.
 */

Aresta *retornaAresta(No *x, No *y);

/*
 * @brief Adiciona aresta ao grafo G
 */

int adicionaAresta(Grafo *g, int noId1, int noId2, int valorAresta);

/*
 * @brief Remove aresta que tem origem o No x e destino o No y.
 */
int removeAresta(Grafo *g, int noId1, int noId2);

/*
 * @brief Remove aresta (de uma lista de aresta0 que tem como No de destino y.
 */

Aresta *removerArestaAux(No *x, Aresta *xInicio, No *y);

/*
 * @brief Verifica se dois nos sao adjacentes.
 */

int adjacente(Grafo *g, int noId1, int noId2);

/*
 * @brief Retorna lista de todos os vértices que podem ser visitados a partir de x.
 */

int *vizinhos(Grafo *g, int noId);

/*
 * @brief Retorna o valor associado com o vertice x.
 */

char retornaValorVertice(Grafo *g, int noId);

/*
 * @brief Muda o valor de um vertice x.
 */

int mudaValorVertice(Grafo *g, int noId, char valor);

/*
 * @brief Retorna o valor associado a uma aresta x, y em G.
 */

int retornaValorAresta(Grafo *g, int noId1, int noId2);

/*
 * @brief Muda o valor de uma aresta x->y no grafo G.
 */

int mudaValorAresta(Grafo *g, int noId1, int noId2, int valor);

#endif /** @} */
