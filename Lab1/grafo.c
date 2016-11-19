/** ********************************************************************************
 *  @addtogroup MODULO GRAFO
 *  @{
 *  @ingroup MOD_GRAFO
 *
 *  @file grafo.c
 *  @brief Módulo de implementação: Módulo Grafo
 *
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 18/09/2016
 *
 @}********************************************************************************/

/* Inclusoes do compilador */

#include <stdio.h>
#include <stdlib.h>

/* Inclusoes de modulo de definicao */

#include "grafo.h"

/** ******************************************************************************
 *
 *  Descricao da funcao:
 *      Cria uma estrutura grafo e lhe da um nome.
 *
 *  @param      *nome - Nome do grafo
 *
 *  @return     g - estrutura de dados do tipo Grafo
 *  
 *  Assertiva de entrada
 *              *nome != NULL
 *
 *********************************************************************************/
Grafo *criaGrafo(char *nome){
    Grafo *g;
    /* Aloca espaço na memoria para a estrutura do grafo e atribui valores iniciais para os
       atributos do grado */
    g = malloc(sizeof(Grafo));
    g->nome = nome;
    g->ordem = 0;
    g->contId = 0;
    g->tamanho = 0;
    g->noInicio = NULL;
    
    return g;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Controi um grafo a partir de um arquivo contido no diretorio com os dados dos 
 *      Nos e Arestas
 *
 *  @param   *g       - Ponteiro para a estrutura do grafo.
 *  @param   *arquivo - String com o nome do arquivo de onde se buscara os dados dos 
 *                      Nos e Arestas.
 *
 *  Assertiva de entrada
 *           *g != NULL
 *           *arquivo != NULL
 *          Os dados contidos no arquivo de entrada apontados por *arquivo devem estar na 
 *          formatacao adequada. Sendo que cada linha deve conter o id do no seguido de
 *          dois pontos mais o valor do no, seguido do id do no para o qual tenha aresta, mais 
 *          o peso da aresta e a linha deve ser finalizado com ponto e virgula. Um exemplo 
 *          de linha do arquivo seria: 1:a->2-20->4-30;
 *
 *  Assertiva de saída
 *          Se arq == NULL || g == NULL
 *              Entao returno = 0
 *          Senao
 *              Constroi grafo a partir do arquivo e retorno = 1
 *          FimSe
 *
 ** **********************************************************************************/

int constroiGrafo(Grafo *g, char *arquivo){
    FILE *arq;
    No *pno1, *pno2;
    Aresta *pare1, *pare2;
    int id, no, valor;
    char dado, resto[50];
				
    
    pno1 = NULL;
    pno2 = NULL;
    
    arq = fopen(arquivo, "r");
    
    /* Se o ponteiro arq ou ponterio g for NULL return 0 */
    if(!arq || !g) return 0;
    
    /* Le estrutura do grafo a partir do arquivop de entrada */
    while (fscanf(arq, "%d:%c->%s", &id, &dado, resto) != EOF) {
        
        /* Aloca espaço na memoria para os nos e inicializa os atributos destes nos */
        pno1 = malloc(sizeof(No));
        pno1->id = ++g->contId;
        pno1->usado = 0;
        pno1->dado = dado;
        pno1->proxno = NULL;
        pno1->numVizinhos = 0;
        pno1->pacessoaresta = NULL;
        g->ordem++; /* Incrementa a ordem do grafo */
        
        /* Se o grafo estiver vazio atribui a noInicio o no recem carregado do arquivo */
        if(g->noInicio == NULL){
            g->noInicio = pno1;
            
        }
        /* Caso contrario liga o no carregado ao ultimo no da lista de nos */
        else{
            pno2->proxno = pno1;
        }
        pno2 = pno1;
    }
    rewind(arq);
    pno1 = g->noInicio;
    pare2 = NULL;
    
    /* Constroi a lista de arestas de cada no a partir do arquivo de entrada */
    while (fscanf(arq, "%d:%c", &id, &dado) != EOF) {
        while ((fscanf(arq, "->%d-%d", &no, &valor)) == 2) {
            /* Aloca espaço na memoria para as arestas e inicializa os atributos destas arestas */
            pare1 = malloc(sizeof(Aresta));
            pare1->usado = 0;
            pare1->proxaresta = NULL;
            pare1->valoraresta = valor;
            
            pare1->padj = retornaNo(g, no);
            
            /* Se a lista de arestas do no estiver vazia, atribui a pacessoaresta a aresta recem 
             * carregada do arquivo 
             */
            if(pno1->pacessoaresta == NULL){
                pno1->pacessoaresta = pare1;
            }
            /* Caso contrario liga essa aresta a ultima aresta da lista de arestas */
            else{
                pare2->proxaresta = pare1;
            }
            
            g->tamanho++; /* Incrementa tamanho do grafo */
            pno1->numVizinhos++; /* Incrementa numero de vizinhos do no */
            pare2 = pare1;
        }
        getc(arq);
        pno1 = pno1->proxno;
    }
    return 1;
}
/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Le um grafo e imprime sua estrutura na tela.
 *
 *  @param   *g - Ponteiro para a estrutura grafo que sera lida e impressa.
 *
 *  Assertiva de entrada
 *           *g != NULL
 *
 ** **********************************************************************************/

void LeGrafo(Grafo *g) {
    No *pno1;
    Aresta *pare1;
    
    /* Verifica se o grafo nao eh vazio */
    if (g->noInicio == NULL)
        printf ("grafo vazio \n");
    else {
        pno1 = g->noInicio;
        /* Percorre o grafo a partir do inicio imprimindo cada no na tela */
        while (pno1 != NULL) {
            printf("\n %d:%c", pno1->id, pno1->dado);
            pare1 = pno1->pacessoaresta;
            /* Percorre cada aresta de um no e a imprime na tela */
            while(pare1 != NULL){
                printf("->%d-%d", pare1->padj->id,pare1->valoraresta);
                pare1 = pare1->proxaresta;
            }
            printf(";\n");
            pno1 = pno1->proxno;
        }
    }
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Retorna o nome de um grafo
 *
 *  @param   *g - Ponteiro para a estrutura grafo a qual deve retornar o nome.
 *
 *  @return  nome - Nome do grafo g.
 *           NULL - Retorno se o Grafo g nao existe.
 *
 *  Assertiva de entrada
 *           *g != NULL
 *
 *  Assertiva de saída
 *          Se *g != NULL
 *              Entao retorna nome do grafo
 *          Senao
 *              retorno = NULL
 *          FimSe
 *
 ** **********************************************************************************/

char *retornaNomeGrafo(Grafo *g){
    if(g) return g->nome; /* retorna o conteudo contido no atributo nome do grafo */
    return NULL;    
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Destroi um grafo, liberando toda a memoria por ele usada
 *
 *  @param      Grafo - Estrutura grafo a ser destruido. 
 *
 *  @return     0     - Se nao destruiu o Grafo.
 *              1     - Se destruiu o Grafo
 *
 *  Assertiva de entrada
 *           *g != NULL
 *
 *  Assertiva de saída
 *          Se *g == NULL
 *              Entao returno = 0
 *          Senao
 *              Destroi grafo e retorno = 1
 *          FimSe
 *
 ** **********************************************************************************/

int destroiGrafo(Grafo *g){
    
    /* Verifica se o grafo esta vazio */
    if(!g) return 0;
    
    zeraGrafo(g);
    free(g); /* Libera espaço da memoria ocupada pela estrutura do Grafo*/
    return 1;
}

/** **********************************************************************************
 *  Descricao da funcao:
 *      Limpa um grafo deixando-o sem nenhum No ou Aresta.
 *
 *  @param      Grafo - Estrutura grafo a ser destruido.
 *
 *  @return     0     - Se nao zerou o Grafo
 *  @return     1     - Se zerou o Grafo
 *
 *  Assertiva de entrada
 *           *g != NULL
 *
 *  Assertiva de saída
 *          Se *g == NULL
 *              Entao returno = 0
 *          Senao
 *              Limpa a lista de nos e de arestas da memoria e retorno = 1
 *          FimSe
 *
 ** **********************************************************************************/

int zeraGrafo(Grafo *g){
    No *no1;
    Aresta *are1;

    /* Verifica se o grafo esta vazio */
    if(!g) return 0;
    
    /* Loops que percorrem no e arestas do grafo */
    while(g->noInicio){                         /* Loop que libera espaços ocupado pelos Nos na memoria */
        while (g->noInicio->pacessoaresta) {    /* Loop que libera espaços ocupado pelas Arestas na memoria */
            are1 = g->noInicio->pacessoaresta;
            g->noInicio->pacessoaresta = are1->proxaresta;
            free(are1);
        }
        no1 = g->noInicio;
        g->noInicio = g->noInicio->proxno;
        free(no1);
    }
    g->ordem = 0;   /* Zera a ordem do grafo */
    g->tamanho = 0; /* Zera o tamanho do grafo */
    return 1;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Percorre o grafo G em procura de um no que tenha id == noId e retorna um 
 *      ponteiro para esse no.
 *
 *  @param      G - Grafo.
 *  @param      noId - Identificador do no procurado.
 *
 *  @return     no1 - Ponteiro para o no procurado.
 *              NULL -Retorno caso o ponteiro n seja encontrado.
 *
 *  Assertiva de entrada
 *           *g != NULL
 *
 *  Assertiva de saída
 *          Se *g == NULL
 *              Entao returno = 0
 *          SeNao
 *              Procura no com id == noId
 *              Se id == noId
 *                  retorna no que id == noId
 *              FimSe
 *          FimSe
 *          retorno = NULL
 *
 **  **********************************************************************************/

No *retornaNo(Grafo *g, int noId){
    No *no1;
    /* Se ponteiro para grafo for NULL retorna NULL */
    if(!g) return NULL;
    
    /* Percorre grafo a partir do noInicio */
    no1 = g->noInicio;
    while(no1 != NULL){
        if(no1->id == noId){ /* Caso o no tenha id igual a noId retorna esse no */
            return no1;
        }
        no1 = no1->proxno;
    }
    return NULL;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Adiciona um no/vertice ao Grafo G.
 *
 *  @param      *g   - Ponteiro para uma estrutura grafo a qual recebera o no.
 *  @param     dado  - Valor do No que sera adicionado ao grafo G.
 *
 *  @return     0    - Se nao adicionou o vertice.
 *              1    - Se adicionou o vertice.
 *
 *  Assertiva de entrada
 *           *g != NULL
 *
 *  Assertiva de saída
 *          Se *g == NULL
 *              Entao returno = 0
 *          Senao
 *              Cria no de valor dado e insere esse no  no grafo g e retorno = 1
 *          FimSe
 *          
 *  Assertiva de saída
 *          g->ordem == Entrada.g->ordem + 1
 *
 **  **********************************************************************************/

int adicionaVertice(Grafo *g, char dado){
    No *pn1, *no;
    
    if(!g) return 0;
    
    no = malloc(sizeof(No));
    no->id = ++g->contId;
    no->usado = 0;
    no->dado= dado;
    no->proxno = NULL;
    no->numVizinhos = 0;
    no->pacessoaresta = NULL;
    
    if (g->noInicio == NULL){ /* Se o grafo estiver vazio adiciona o no no inicio do grafo */
        g->noInicio = no;
        g->ordem++;
    }
    else{
        pn1 = g->noInicio;  /* Se o grafo nao estiver vazio coloca o no topo da lista de nos */
        no->proxno = pn1;
        g->noInicio = no;
        pn1 = NULL;
        g->ordem++; /* Incrementa a ordem do grafo */
    }
    return 1;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Remove um no/vertice do Grafo G.
 *
 *  @param      G     - Estrutura grafo doqual sera removido o no.
 *  @param      noId1 - Identificador do No que sera removido.
 *
 *  @return     0     - Se nao removeu o vertice por nao existir o Grafo ou o No.
 *              1     - Se removeuo vertice.
 *
 *  Assertiva de entrada
 *           *g != NULL
 *           noId pertence ao grafo g
 *
 *  Assertiva de saída
 *          Se *g == NULL
 *              Entao returno = 0
 *          
 *          Se nao existe no grafo um no de id == noId
 *              Então retorno = 0
 *          Senao
 *              remove o no de id == noId do grafo g, remove as arestas ligadas ao no 
 *              e retorno = 1
 *          FimSe
 *
 *  Assertiva de saída
 *          g->ordem == Entrada.g->ordem - 1
 *          g->tamanho == Entrada.g->tamanho - noId->numVizinhos
 *
 ** **********************************************************************************/

int removeVertice(Grafo *g, int noId){
    No *pn1, *pn2;
    int aux, viz;
    
    if (!g) return 0;
    
    pn1 = g->noInicio;
    pn2 = retornaNo(g, noId);
    
    if (!pn2) return 0;
    
    viz = pn2->numVizinhos;
    /* Remove arestas que tem como destino o No que sera removido */
    while(pn1) {
        if(pn1 != pn2){
            aux = pn1->numVizinhos;
            pn1->pacessoaresta = removerArestaAux(pn1, pn1->pacessoaresta, pn2);
            aux = aux - pn1->numVizinhos;
            g->tamanho = g->tamanho - aux; /* Subtrai o numero de arestas que vai de outros Nos para noId */
        }
        pn1 = pn1->proxno;
    }
    
    g->noInicio = removeVerticeAux(g->noInicio, noId);
    g->ordem--; /* Decrementa ordem do grafo */
    g->tamanho = g->tamanho - viz; /* Subtrai o numero de arestas que vai de noId para outros Nos */
    return 1;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Funcao auxiliar para remover um No de um grafo.
 *
 *  @param      *inicio - Ponteiro para a lista de Nos.
 *  @param      noId1   - Identificador do No que sera removido.
 *
 *  @return     inicio/temp  - retorna um ponteiro para o incio da lista de nos.
 *              NULL         - retorna NULL se o panteiro passado é NULL.
 *
 *  Assertiva de entrada
 *           *inicio != NULL
 * 
 *  Assertiva de saída
 *          Se *inicio == NULL
 *              Entao returno = NULL
 *          Senao
 *              remove lista de arestas ligadas ao no de id == noId e retorna um ponteiro
 *              para o inicio da lista
 *          FimSe
 *
 *  Assertiva de saída
 *          g->tamanho == Entrada.g->tamanho - noId->numVizinhos
 *
 ** **********************************************************************************/

No *removeVerticeAux(No *inicio, int noId){
    No *temp;
    
    if(!inicio) return NULL;
    /* Remove no da lista de Nos */
    if(inicio->id == noId){
        destroiListaArestas(inicio->pacessoaresta);
        temp = inicio->proxno;
        free(inicio);
        return temp;
    }
    inicio->proxno = removeVerticeAux(inicio->proxno, noId);
    return inicio;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Destroi um lista de aresta.
 *
 *  @param      *inicio - Ponteiro para o inicio da lista de Arestas.
 *
 *  Assertiva de entrada
 *           *inicio != NULL
 *
 ** **********************************************************************************/

void destroiListaArestas(Aresta *inicio){
    Aresta *temp;
    while(inicio){
        temp = inicio->proxaresta;
        free(inicio);
        inicio = temp;
    }
}

/** **********************************************************************************
 *  Descricao da funcao:
 *      Retorna uma aresta que tem como origem o No x e destino o No y.
 *
 *  @param      *x - Ponteiro para o No de origem.
 *  @param      *y - Ponteiro para o No de destino.
 *
 *  @return     NULL - Se nao existir aresta entre x e y.
 *              NULL - Se algum dos Nos nao existe.
 *              pare - Ponteiro para a aresta de x para y.
 *
 *  Assertiva de entrada
 *           *x != NULL && *y != NULL
 *
 *  Assertiva de saída
 *          Se *x == NULL || *y == NULL
 *              Entao returno = NULL
 *          Senao
 *              retorna aresta de x para y
 *          FimSe
 *          retuorno = NULL
 *
 **  **********************************************************************************/

Aresta *retornaAresta(No *x, No *y){
    Aresta *pare;
    
    if(!x || !y ) return NULL;
    
    pare = x->pacessoaresta;
    while(pare){ /* Percorre aresta de um No x e caso alguma esteja ligada ao No y, 
                  * retorna-a*/
        if(pare->padj == y) return pare;
        pare = pare->proxaresta;
    }
    
    return NULL;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Adiciona uma aresta que tenha como origem o noId1 e destino o noId2.
 *
 *  @param      *x - Ponteiro que aponta para o No de origem da aresta.
 *  @param      *y - Poneteiro que aponta para o No de destino da Aresta.
 *  @param      valorAresta - Valor/peso da aresta que liga os dois nos. 
 *
 *  @return     0  - Se nao foi possivel adicionar a aresta.
 *  @return             1  - Se a Aresta foi adicionada com sucesso.
 *
 *  Assertiva de entrada
 *           *inicio != NULL
 *           Existe no grafo os nos cujos id sao noId1 e noId2 mas nao existe uma aresta 
 *           de noId1 para noId2
 *
 *  Assertiva de saída
 *          Se *g == NULL || noId1 == NULL || noId2 == NULL || existe aresta de noId1 
 *          para noID2
 *              Entao returno = 0
 *          Senao
 *              adiciona aresta de noId1 para noId2 e retorno = 1
 *          FimSe
 *
 *  Assertiva de saída
 *          g->tamanho == Entrada.g->tamanho + 1
 *
 ** **********************************************************************************/

int adicionaAresta(Grafo *g, int noId1, int noId2, int valorAresta){
    Aresta *pa1;
    No *pn1, *pn2;
    
    pn1 = retornaNo(g, noId1);
    pn2 = retornaNo(g, noId2);
    
    /* Verifica se o Nos x e y nao sao NULL e se ja existe aresta entre eles */
    if(!g || !pn1 || !pn2 || retornaAresta(pn1, pn2)) return 0;
    
    pa1 = malloc(sizeof(Aresta));
    
    pa1->padj = pn2;
    pa1->usado = 0;
    pa1->valoraresta = valorAresta;
    pa1->proxaresta = pn1->pacessoaresta;
    pn1->pacessoaresta = pa1;
    pn1->numVizinhos++;
    g->tamanho++;
    
    return 1;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Remove uma aresta que liga No noId1 de origem a seu adjacente No noId2.
 *      Essa funcao parte do presuposto que existe somente uma aresta de noId1 para noId2.
 *
 *  @param      noId1 - Identificador do No de origem.
 *  @param      noId2 - Identificador do No de destino da Aresta.
 *
 *  @return     0     - Se nao foi possivel remover a Aresta.
 *              1     - Se a Aresta foi removida com sucesso.
 *
 *  Assertiva de entrada
 *           *inicio != NULL
 *           Existe no grafo os nos cujos id sao noId1 e noId2 e existe uma aresta de noId1
 *           para noId2
 *
 *  Assertiva de saída
 *          Se *g == NULL || noId1 == NULL || noId2 == NULL || existe aresta de noId1 para noID2
 *              Entao returno = 0
 *          Senao
 *              remove aresta de noId1 para noId2 e retorno = 1
 *          FimSe
 *
 *  Assertiva de saída
 *          g->tamanho == Entrada.g->tamanho - 1
 *
 ** **********************************************************************************/

int removeAresta(Grafo *g, int noId1, int noId2){
    No *pn1, *pn2;
    int aux;
    
    pn1 = retornaNo(g, noId1);
    pn2 = retornaNo(g, noId2);
    /* verifica se o grafo nao eh vazio, se os nos n1 e n2 exisistem, e se existe uma
     * aresta entre os dois nos, caso contrario retorna 0
     */
    if(!g || !pn1 || !pn2 || !retornaAresta(pn1, pn2)) return 0;
    
    aux = pn1->numVizinhos;
    pn1->pacessoaresta = removerArestaAux(pn1, pn1->pacessoaresta, pn2);
    
    aux = aux - pn1->numVizinhos;
    g->tamanho = g->tamanho - aux;
    
    return 1;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Recebe uma lista de aresta e remove a aresta que tem como destino o No y.
 *
 *  @param      *x       - Ponteiro para o No de origem.
 *  @param      *xInicio - Ponteiro para o inicio de uma lista de arestas de um dado No.
 *  @param      *y       - Ponteiro para o No de destino.
 *
 *  @return     NULL - Se o No n nao foi encontrado como adjacente.
 *              l    - Ponteiro para a nova cabeca da lista de arestas.
 *
 *  Assertiva de entrada
 *           *x != NULL
 *
 *  Assertiva de saída
 *          Se *xInicio == NULL
 *              Entao returno = NULL
 *          FimSe
 *          Se existe uma aresta de x para y
 *              remove aresta e retorna proxima aresta de adjacencia de x
 *          FimSe
 *          retorno = xInicio
 *
 ** **********************************************************************************/

Aresta *removerArestaAux(No *x, Aresta *xInicio, No *y){
    if(!xInicio) return NULL;
    
    if(xInicio->padj == y){
        Aresta *temp = xInicio->proxaresta;
        x->numVizinhos--;
        free(xInicio);
        return temp;
    }
    xInicio->proxaresta = removerArestaAux(x, xInicio->proxaresta, y);
    return xInicio;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Retorna o valor associado com o vertice x..
 *
 *  @param      G - Grafo.
 *  @param      noId - Identificador do No ao qual deseja-se saber o valor.
 *
 *  @return     - um char com o valor/dado do No.
 *
 *  Assertiva de entrada
 *           *g != NULL
 *           Existe no grafo g um no de id == noId
 *
 *  Assertiva de saída
 *          Se *g == NULL || noId1 == NULL 
 *              Entao returno = 0
 *          Senao
 *              retorno = noId->dado
 *          FimSe
 *
 ** **********************************************************************************/

char retornaValorVertice(Grafo *g, int noId){
    No *pn1;
    
    /* caso *g == NULL entao pn1 também sera NULL*/
    pn1 = retornaNo(g, noId);
    
    if(!g || !pn1) return 0;
    return pn1->dado;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Muda o valor da variavel dado de um vertice x.
 *
 *  @param      G     - Grafo.
 *  @param      noId  - Identificador do No ao qual deseja-se aterar o valor.
 *  @param      valor - Novo valor
 *
 *  Assertiva de entrada
 *           *g != NULL && noId != NULL
 *
 *  Assertiva de saída
 *          Se *g == NULL || noId1 == NULL
 *              Entao returno = 0
 *          Senao
 *              altera valor do no e retorno = 1
 *          FimSe
 *
 ** **********************************************************************************/

int mudaValorVertice(Grafo *g, int noId, char valor){
    No *pn1;
    
    /* caso *g == NULL entao pn1 também sera NULL*/
    pn1 = retornaNo(g, noId);
    if(pn1){
        pn1->dado = valor;
        return 1;
    }
    else{
        return 0;
    }
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Retorna o valor associado a uma aresta x->y em G.
 *
 *  @param      G     - Grafo.
 *  @param      noId1 - Identificador do No x de origem da aresta.
 *  @param      noId2 - Identificador do No y de destino da aresta.
 *
 *  @return           - valor/peso da aresta.
 *
 *  Assertiva de entrada
 *           *g != NULL && noId1 != NULL && noId2 != NULL
 *
 *  Assertiva de saída
 *          Se *g == NULL || noId1 == NULL || noId2 == NULL
 *              Entao returno = 0
 *          Senao
 *              retorno = valor da aresta de noId1 para noId2
 *          FimSe
 *
 ** **********************************************************************************/

int retornaValorAresta(Grafo *g, int noId1, int noId2){
    No *pn1, *pn2;
    Aresta *pa1;
    
    /* caso *g == NULL entao pn1, pn2 e pa1 também serao NULL*/
    pn1 = retornaNo(g, noId1);
    pn2 = retornaNo(g, noId2);
    pa1 = retornaAresta(pn1, pn2);
    
    if(!pa1) return 0;
    else{
        return pa1->valoraresta;
    }
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Muda o valor da variavel valoraresta de uma aresta x->y.
 *
 *  @param      G     - Grafo.
 *  @param      noId1 - Identificador do No x de origem da aresta.
 *  @param      noId2 - Identificador do No y de destino da aresta.
 *  @param      valor - Novo valor da variavel valoraresta.
 *
 *  Assertiva de entrada
 *           *g != NULL && noId1 != NULL && noId2 != NULL
 *           existe uma areesta de noId1 para noId2
 *
 *  Assertiva de saída
 *          Se *g == NULL || noId1 == NULL || noId2 == NULL
 *              Entao returno = 0
 *          Senao
 *              altera o valor da aresta de noId1 para noId2 e retorno = 1
 *          FimSe
 *
 ** **********************************************************************************/

int mudaValorAresta(Grafo *g, int noId1, int noId2, int valor){
    No *pn1, *pn2;
    Aresta *pa1;
    
    /* caso *g == NULL entao pn1, pn2 e pa1 também serao NULL*/
    pn1 = retornaNo(g, noId1);
    pn2 = retornaNo(g, noId2);
    
    pa1 = retornaAresta(pn1, pn2);
    if(!pa1) return 0;
    else{
        pa1->valoraresta = valor;
        return 1;
    }
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Retorna a lista de todos os vértices que podem ser visitados a partir do de 
 *      identificador noId.
 *
 *  @param      *g    - Ponteiro para o grafo g.
 *  @param      noId - Identificador do No procurado.
 *
 *  @return     viz	 - Vetor com todos os nós adjacentes a noId.
 *
 *  Assertiva de entrada
 *           *g != NULL && noId != NULL
 *
 *  Assertiva de saída
 *          Se *g == NULL || noId == NULL || noId->numVizinhos == 0
 *              Entao returno = NULL
 *          Senao
 *              retorna um vetor com os ids dos nos vizinhos de noId
 *          FimSe
 *
 ** **********************************************************************************/

int *vizinhos(Grafo *g, int noId){
    int i;
    No *pn1;
    Aresta *pare;
    
    /* caso *g == NULL entao pn1 também sera NULL*/
    pn1 = retornaNo(g, noId);
    if(!pn1) return NULL;
    
    /* se pn1 nao possui vizinho return = NULL */
    if(!pn1->numVizinhos) return NULL;
    
    int viz[pn1->numVizinhos];
    pare = pn1->pacessoaresta;
    /* percorre lista de aresta de n1 e acrescenta o id de seus vizinhos ao vetor viz */
    for (i = 0; i < pn1->numVizinhos; i++) {
        viz[i] = pare->padj->id;
        pare = pare->proxaresta;
    }
    return viz;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Verifica se dois Nos de um grafo G sao adjacentes.
 *
 *  @param      *g    - Ponteiro para o Grafo G.
 *  @param      noId1 - Identificador de um No.
 *  @param      noId2 - Identificador de um No.
 *
 *  @return     1 - Se os dois Nos sao adjacentes.
 *              0 - Se os dois Nos nao sao adjacentes.
 *
 *  Assertiva de entrada
 *           *g != NULL && noId1 != NULL && noId2 != NULL
 *
 *  Assertiva de saída
 *          Se *g == NULL || noId1 == NULL || noId2 == NULL || nao existe aresta de noId1 para noId2
 *              Entao returno = 0
 *          Senao
 *              retorno = 1
 *          FimSe
 *
 ** **********************************************************************************/

int adjacente(Grafo *g, int noId1, int noId2){
    No *pn1, *pn2;
    Aresta *pa1;
    
    /* caso *g == NULL entao pn1, pn2 e pa1 também serao NULL*/
    pn1 = retornaNo(g, noId1);
    pn2 = retornaNo(g, noId2);
    pa1 = retornaAresta(pn1, pn2);
    if(pa1){
        return 1;
    }
    else{
        return 0; /* Zero representa falso em C, e qualquer outro valor significa verdadeiro */
    }
}