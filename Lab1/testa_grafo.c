/**
 *  @addtogroup TESTA_GRAFO
 *  @{
 *  @ingroup testa_grafo.c
 *  @author Paulo da Cunha Passos - 10/0118577
 *  @since 24/08/16.
 *
 *  @file testa_grafo.c
 *  @brief Definicao
 *      Modulo de testes da biblioteca de criação e manipulação de Grafos.
 *
 */

/* Inclusoes do compilador */
#include "CUnit/CUnit.h"

/* Inclusoes de modulo de definicao */

#include "grafo.h"
#include "testa_grafo.h"

/* PARA QUE TODOS OS TESTES FUNCIONEM OS PONTEIROS PARA 
 * AS ESTRUTURAS GRAFO, NO E ARESTAS DEVEM ESTAR INICIALIZADOS 
 *
 *
 * O grafo contido no arquivo t1.txt utilizado em varios testes possui 
 * a seguinte estrutura:
 * 
 *      1:a->2-20->4-30;
 *      2:b->3-10->1-25->5-20->4-10;
 *      3:c->1-30->5-45;
 *      4:d->3-15->2-65->1-10;
 *      5:f->1-10;
 */

 void testaCriaGrafo(void){
    Grafo *grafoT;
    
    /* Cria o Grafo de nome  GrafoTeste e passa para um ponteiro seu endereço */
    grafoT = criaGrafo("GrafoTeste");
    
    CU_ASSERT_PTR_NOT_NULL(grafoT);         /* Testa se a estrutura Grafo foi criada    */
    CU_ASSERT_EQUAL(grafoT->ordem, 0);      /* Testa se a ordem inicial do Grafo é 0    */
    CU_ASSERT_EQUAL(grafoT->tamanho, 0);    /* Testa se o tamanho inicial do grafo é 0  */
    CU_ASSERT_PTR_NULL(grafoT->noInicio);   /* Testa se o noInicio é NULL               */
    CU_ASSERT_STRING_EQUAL(grafoT->nome, "GrafoTeste"); /* Testa se o nome do Grafo é  GrafoTeste */
     destroiGrafo(grafoT);
}

void testaConstroiGrafo(void){
    Grafo *grafoT;
    
    /* Cria o Grafo de nome  GrafoTeste e passa para um ponteiro seu endereço */
    grafoT = criaGrafo("GrafoTeste");
    
    CU_ASSERT_FALSE(constroiGrafo(grafoT, "")); /* Passa nome de arquivo que nao existe */
    zeraGrafo(grafoT);
    CU_ASSERT_FALSE(constroiGrafo(grafoT, "t2.txt")); /* Passa nome de arquivo que nao existe */
    zeraGrafo(grafoT);

    CU_ASSERT_TRUE(constroiGrafo(grafoT, "t1.txt"));
    
    zeraGrafo(grafoT);
    constroiGrafo(grafoT, "t1.txt");
    
    CU_ASSERT_EQUAL(grafoT->ordem, 5);
    CU_ASSERT_EQUAL(grafoT->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT->noInicio);
    
    destroiGrafo(grafoT);
}

void testaRetornaNomeGrafo(void){
    Grafo *grafoT1, *grafoT2;
    
    /* Cria o Grafo de nome  GrafoTeste e passa para um ponteiro seu endereço */
    grafoT1 = criaGrafo("GrafoTeste");
    grafoT2 = NULL;
    
    CU_ASSERT_STRING_EQUAL(retornaNomeGrafo(grafoT1), "GrafoTeste");
    CU_ASSERT_PTR_NULL(retornaNomeGrafo(grafoT2));
    
    destroiGrafo(grafoT1);
}

void testaDestroiGrafo(void){
    Grafo *grafoT1, *grafoT2;
    
    /* Cria o Grafo de nome  GrafoTeste e passa para um ponteiro seu endereço */
    grafoT1 = criaGrafo("GrafoTeste");
    grafoT2 = NULL;

    CU_ASSERT_EQUAL(destroiGrafo(grafoT1), 1);
    CU_ASSERT_EQUAL(destroiGrafo(grafoT2), 0);
}

void testaZeraGrafo(void){
    Grafo *grafoT1, *grafoT2;
    
    /* Cria o Grafo de nome  GrafoTeste e passa para um ponteiro seu endereço */
    grafoT1 = criaGrafo("GrafoTeste");
    grafoT2 = NULL;
    constroiGrafo(grafoT1, "t1.txt");
    
    CU_ASSERT_EQUAL(zeraGrafo(grafoT1), 1);
    CU_ASSERT_EQUAL(zeraGrafo(grafoT2), 0);
    
    destroiGrafo(grafoT1);
}

void testaRetornaNo(void){
    Grafo *grafoT1, *grafoT2;
    
    /* Cria o Grafo de nome  GrafoTeste e passa para um ponteiro seu endereço */
    grafoT1 = criaGrafo("GrafoTeste");
    constroiGrafo(grafoT1, "t1.txt");
    grafoT2 = NULL;
    
    /* testa se retorna o primeiro No */
    CU_ASSERT_PTR_NOT_NULL(retornaNo(grafoT1, 1));
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 1)->id, 1);
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 1)->dado, 'a');
    
    /* Testa se retorna um No no meio do grafo */
    CU_ASSERT_PTR_NOT_NULL(retornaNo(grafoT1, 4));
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 4)->id, 4);
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 4)->dado, 'd');
    
    
    /* Testa se retorna o ultimo No */
    CU_ASSERT_PTR_NOT_NULL(retornaNo(grafoT1, 5));
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 5)->id, 5);
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 5)->dado, 'f');
    
    /* Testa o retorno da procura por um No que nao existe no grafo */
    CU_ASSERT_PTR_NULL(retornaNo(grafoT1, 0));
    
    /* Testa o retorno quendo se passa um Grafo que nao existe */
    CU_ASSERT_PTR_NULL(retornaNo(grafoT2, 0));
    
    destroiGrafo(grafoT1);
    
}

void testaAdicionaVertice(void){
    Grafo *grafoT1, *grafoT2;
    
    grafoT1 = NULL;
    CU_ASSERT_EQUAL(adicionaVertice(grafoT1, 'a'), 0);
    
    /* Testa adicionar um No em um Grafo vazio */
    grafoT1 = criaGrafo("GrafoTeste");
    CU_ASSERT_EQUAL(adicionaVertice(grafoT1, 'a'), 1);
    CU_ASSERT_EQUAL(grafoT1->contId, 1);
    CU_ASSERT_EQUAL(grafoT1->ordem, 1);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 0);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    

    /* Testa adicionar um No em um grafo que ja possui 5 Nos */
    grafoT2 = criaGrafo("GrafoTeste2");
    constroiGrafo(grafoT2, "t1.txt");
    CU_ASSERT_EQUAL(adicionaVertice(grafoT2, 't'), 1);
    CU_ASSERT_EQUAL(grafoT2->ordem, 6);
    CU_ASSERT_EQUAL(grafoT2->contId, 6);
    CU_ASSERT_EQUAL(grafoT2->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT2->noInicio);
    
    destroiGrafo(grafoT1);
    destroiGrafo(grafoT2);
}

void testaRemoveVertice(void){
    Grafo *grafoT1, *grafoT2;
    
    /* Testa a tentativa de remover um No de um Grafo que nao existe */
    grafoT1 = NULL;
    CU_ASSERT_EQUAL(removeVertice(grafoT1, 1), 0);
    
    /* Testa a tentativa de remover um No de um Grafo vazio */
    grafoT1 = criaGrafo("GrafoTeste");
    CU_ASSERT_EQUAL(removeVertice(grafoT1, 1), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 0);
    CU_ASSERT_EQUAL(grafoT1->contId, 0);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 0);
    CU_ASSERT_PTR_NULL(grafoT1->noInicio);
    
    /* Testa a tentativa de remover um No que nao existe no Grafo */
    constroiGrafo(grafoT1, "t1.txt");
    CU_ASSERT_EQUAL(removeVertice(grafoT1, 8), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    /* Testa a tentativa de remover um No que existe no inicio da lista de Nos do Grafo */
    CU_ASSERT_EQUAL(removeVertice(grafoT1, 1), 1);
    CU_ASSERT_EQUAL(grafoT1->ordem, 4);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 6);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    /* Testa se ao remover o No 1, também sao removidas as arestas 
     * que tem como destino o No 1 
     */
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 2)->numVizinhos, 3);
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 5)->numVizinhos, 0);
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 4)->numVizinhos, 2);
    
    /* Testa a tentativa de remover um No que existe no meio da 
     * lista de Nos do Grafo 
     */
    CU_ASSERT_EQUAL(removeVertice(grafoT1, 3), 1);
    CU_ASSERT_EQUAL(grafoT1->ordem, 3);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 3);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    /* Testa a tentativa de remover um No que existe no fim da 
     * lista de Nos do Grafo 
     */
    CU_ASSERT_EQUAL(removeVertice(grafoT1, 5), 1);
    CU_ASSERT_EQUAL(grafoT1->ordem, 2);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 2);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    /* Testa a tentativa de remover o unico No do Grafo */
    grafoT2 = criaGrafo("GrafoTeste1");
    adicionaVertice(grafoT2, 't');
    CU_ASSERT_EQUAL(removeVertice(grafoT2, 1), 1);
    CU_ASSERT_EQUAL(grafoT2->ordem, 0);
    CU_ASSERT_EQUAL(grafoT2->contId, 1);
    CU_ASSERT_EQUAL(grafoT2->tamanho, 0);
    CU_ASSERT_PTR_NULL(grafoT2->noInicio);
    
    destroiGrafo(grafoT1);
    destroiGrafo(grafoT2);
}
void testaRetornaAresta(void){
    Grafo *grafoT1;
    No *x, *y;
    
    grafoT1 = criaGrafo("GrafoTeste");
    constroiGrafo(grafoT1, "t1.txt");
    
    /* Testa a tentativa de encontra uma aresta, tal que
     * um dos Nos ou ambos nao pertence no Grafo
     */
    x = retornaNo(grafoT1, 8);
    y = retornaNo(grafoT1, 10);
    CU_ASSERT_PTR_NULL(retornaAresta(x, y));
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    x = retornaNo(grafoT1, 1);
    y = retornaNo(grafoT1, 10);
    CU_ASSERT_PTR_NULL(retornaAresta(x, y));
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    x = retornaNo(grafoT1, 10);
    y = retornaNo(grafoT1, 2);
    CU_ASSERT_PTR_NULL(retornaAresta(x, y));
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    
    /* Testa a tentativa de encontra uma aresta entre dois Nos 
     * do Grafo, sendo que tal aresta nao existe no Grafo
     */
    x = retornaNo(grafoT1, 1);
    y = retornaNo(grafoT1, 5);
    CU_ASSERT_PTR_NULL(retornaAresta(x, y));
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    /* Testa a tentativa de encontra uma aresta entre dois Nos
     * do Grafo, sendo que tal aresta existe no Grafo
     */
    x = retornaNo(grafoT1, 2);
    y = retornaNo(grafoT1, 1);
    CU_ASSERT_PTR_NOT_NULL(retornaAresta(x, y));
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    destroiGrafo(grafoT1);
}

void testaAdicionaAresta(void){
    Grafo *grafoT1;
    
    grafoT1 = criaGrafo("GrafoTeste");
    constroiGrafo(grafoT1, "t1.txt");
    
    /* Testa a tentativa de adicionar uma Aresta entre Nos
     * tal que um dos Nos ou ambos não pertencem ao Grafo
     */

    CU_ASSERT_EQUAL(adicionaAresta(grafoT1, 8, 10, 10), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    CU_ASSERT_EQUAL(adicionaAresta(grafoT1, 1, 10, 10), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    CU_ASSERT_EQUAL(adicionaAresta(grafoT1, 10, 3, 10), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    /* Testa a tentativa de adicionar uma Aresta entre Nos do 
     * Grafo, tal que ja exista uma aresta entre tais Nos
     */
    CU_ASSERT_EQUAL(adicionaAresta(grafoT1, 3, 1, 10), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    /* Testa a tentativa de adicionar uma Aresta entre Nos do
     * Grafo, tal que nao exista uma aresta entre tais Nos
     */
    CU_ASSERT_EQUAL(adicionaAresta(grafoT1, 4, 5, 10), 1);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 13);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    destroiGrafo(grafoT1);
}

void testaRemoveAresta(void){
    Grafo *grafoT1;
    
    grafoT1 = criaGrafo("GrafoTeste");
    constroiGrafo(grafoT1, "t1.txt");
    
    /* Testa a tentativa de remover uma Aresta entre Nos
     * tal que um dos Nos ou ambos não pertencem ao Grafo
     */
    CU_ASSERT_EQUAL(removeAresta(grafoT1, 8, 10), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    CU_ASSERT_EQUAL(removeAresta(grafoT1, 1, 10), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    CU_ASSERT_EQUAL(removeAresta(grafoT1, 10, 3), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 12);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    /* Testa a tentativa de remover uma Aresta entre Nos do
     * Grafo, tal que ja exista uma aresta entre tais Nos
     */
    CU_ASSERT_EQUAL(removeAresta(grafoT1, 4, 3), 1);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 11);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    CU_ASSERT_EQUAL(removeAresta(grafoT1, 3, 1), 1);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 10);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    /* Testa a tentativa de remover uma Aresta entre Nos do
     * Grafo, tal que nao exista uma aresta entre tais Nos
     */
    CU_ASSERT_EQUAL(removeAresta(grafoT1, 5, 4), 0);
    CU_ASSERT_EQUAL(grafoT1->ordem, 5);
    CU_ASSERT_EQUAL(grafoT1->contId, 5);
    CU_ASSERT_EQUAL(grafoT1->tamanho, 10);
    CU_ASSERT_PTR_NOT_NULL(grafoT1->noInicio);
    
    destroiGrafo(grafoT1);

}

void testaRetornaValorVertice(void){
    Grafo *grafoT1;
    
    grafoT1 = NULL;
    /* Testa a tentativa de retorna o valor de um verice
     * de um Grafo que nao exite 
     */
    CU_ASSERT_EQUAL(retornaValorVertice(grafoT1, 1), 0);
    
    grafoT1 = criaGrafo("GrafoTeste");
   
    /* Testa a tentativa de retorna o valor de um verice que
    * nao exite no Grafo g 
    */
    CU_ASSERT_EQUAL(retornaValorVertice(grafoT1, 10), 0);
    constroiGrafo(grafoT1, "t1.txt");
    CU_ASSERT_EQUAL(retornaValorVertice(grafoT1, 10), 0);
    
    /* Testa a tentativa de retorna o valor de um verice que
     *  exite no Grafo g
     */
    CU_ASSERT_EQUAL(retornaValorVertice(grafoT1, 2), 'b');
    destroiGrafo(grafoT1);
}

void testaMudaValorVertice(void){
    Grafo *grafoT1;
    
    grafoT1 = NULL;
    /* Testa a tentativa de mudar o valor de um veritice
     * de um Grafo que nao exite
     */
    CU_ASSERT_FALSE(mudaValorVertice(grafoT1, 10, 'a'));
    
    grafoT1 = criaGrafo("GrafoTeste");
    
    /* Testa a tentativa de mudar o valor de um verice que
     * nao exite no Grafo g
     */
    CU_ASSERT_FALSE(mudaValorVertice(grafoT1, 10, 'a'));
    
    constroiGrafo(grafoT1, "t1.txt");
    CU_ASSERT_FALSE(mudaValorVertice(grafoT1, 10, 'a'));
    
    /* Testa a tentativa de mudar o valor de um verice que
     *  exite no Grafo g
     */
    CU_ASSERT_TRUE(mudaValorVertice(grafoT1, 1, 'f'));
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 1)->dado, 'f');
    CU_ASSERT_TRUE(mudaValorVertice(grafoT1, 5, 'a'));
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 5)->dado, 'a');
    CU_ASSERT_TRUE(mudaValorVertice(grafoT1, 3, 't'));
    CU_ASSERT_EQUAL(retornaNo(grafoT1, 3)->dado, 't');
    
    destroiGrafo(grafoT1);
}

void testaRetornaValorAresta(void){
    Grafo *grafoT1;
    
    grafoT1 = NULL;
    /* Testa a tentativa de retorna o valor de uma Areta
     * de um Grafo que nao exite
     */
    CU_ASSERT_EQUAL(retornaValorAresta(grafoT1, 1, 2), 0);
    
    grafoT1 = criaGrafo("GrafoTeste");
    
    /* Testa a tentativa de retorna o valor de uma Aresta que
     * nao exite no Grafo g
     */
    CU_ASSERT_EQUAL(retornaValorAresta(grafoT1, 5, 4), 0);
    constroiGrafo(grafoT1, "t1.txt");
    CU_ASSERT_EQUAL(retornaValorAresta(grafoT1, 5, 4), 0);
    
    /* Testa a tentativa de retorna o valor de uma Aresta que
     *  exite no Grafo g
     */
    CU_ASSERT_EQUAL(retornaValorAresta(grafoT1, 3, 5), 45);
    CU_ASSERT_EQUAL(retornaValorAresta(grafoT1, 4, 3), 15);
    CU_ASSERT_EQUAL(retornaValorAresta(grafoT1, 5, 1), 10);
    CU_ASSERT_EQUAL(retornaValorAresta(grafoT1, 1, 4), 30);
    
}

void testaMudaValorAresta(void){
    Grafo *grafoT1;
    No *x, *y;
    
    grafoT1 = NULL;
    /* Testa a tentativa de mudar o valor de uma aresta
     * de um Grafo que nao exite
     */
    CU_ASSERT_FALSE(mudaValorAresta(grafoT1, 10, 1, 10));
    
    grafoT1 = criaGrafo("GrafoTeste");
    
    /* Testa a tentativa de mudar o valor de uma aresta que
     * nao exite no Grafo g
     */
    CU_ASSERT_FALSE(mudaValorAresta(grafoT1, 10, 1, 10));
    
    constroiGrafo(grafoT1, "t1.txt");
    CU_ASSERT_FALSE(mudaValorAresta(grafoT1, 10, 1, 10));
    
    /* Testa a tentativa de mudar o valor de uma aresta que
     *  exite no Grafo g
     */
    CU_ASSERT_TRUE(mudaValorAresta(grafoT1, 1, 2, 70));
    x = retornaNo(grafoT1, 1);
    y = retornaNo(grafoT1, 2);
    CU_ASSERT_EQUAL(retornaAresta(x, y)->valoraresta, 70);

    CU_ASSERT_TRUE(mudaValorAresta(grafoT1, 3, 1, 100));
    x = retornaNo(grafoT1, 3);
    y = retornaNo(grafoT1, 1);
    CU_ASSERT_EQUAL(retornaAresta(x, y)->valoraresta, 100);
    
    destroiGrafo(grafoT1);
}

void testaVizinhos(void){
    int *p;
    Grafo *grafoT1, *grafoT2;
    
    grafoT2 = NULL;
    grafoT1 = criaGrafo("GrafoTeste");
    constroiGrafo(grafoT1, "t1.txt");
    
    /* Testa o retorno da funcao para um grafo que nao existe */
    CU_ASSERT_PTR_NULL(vizinhos(grafoT2, 1));
    
    /* Testa o retorno da funcao para um grafo que existe */
    CU_ASSERT_PTR_NOT_NULL(vizinhos(grafoT1, 2));
    
    p = vizinhos(grafoT1, 2);
    
    /* Testa os valores da lista de nos vizinhos ao No 2 */
    CU_ASSERT_EQUAL(p[0], 3);
    CU_ASSERT_EQUAL(p[1], 1);
    CU_ASSERT_EQUAL(p[2], 5);
    CU_ASSERT_EQUAL(p[3], 4);
    
    p = vizinhos(grafoT1, 5);
    /* Testa os valores da lista de nos vizinhos ao No 5 */
    CU_ASSERT_EQUAL(p[0], 1);
    
    adicionaVertice(grafoT1, 's');
    /* Testa se quando um No nao tem vizinhos */
    CU_ASSERT_PTR_NULL(vizinhos(grafoT2, 6));
    
    destroiGrafo(grafoT1);
}

void testaAdjacente(void){
    Grafo *grafoT1, *grafoT2;
    
    grafoT2 = NULL;
    grafoT1 = criaGrafo("GrafoTeste");
    constroiGrafo(grafoT1, "t1.txt");
    
    /* Testa o retorno da funcao para um grafo que nao existe */
    CU_ASSERT_FALSE(adjacente(grafoT2, 1, 2));
    
    /* Testa se existe adjancencia entre dois Nos */
    CU_ASSERT_TRUE(adjacente(grafoT1, 1, 2));
    CU_ASSERT_FALSE(adjacente(grafoT1, 3, 4));
    
    
}