#include "rede.h"

Rede::Rede(string nomeRede)
{
    nome = nomeRede;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Retorna o nome do grafo
 *
 *
 *  @return  nome - Nome do grafo g.
 *
 ** **********************************************************************************/
string Rede::getNome()
{
    return nome;
}

/** **********************************************************************************
 *
 *  Descricao da funcao:
 *      Destroi um grafo, liberando toda a memoria por ele usada
 *
 *  @return     0     - Se nao destruiu o Grafo.
 *              1     - Se destruiu o Grafo
 *
 *
 *  Assertiva de saída
 *          Se *g == NULL
 *              Entao returno = 0
 *          Senao
 *              Destroi grafo e retorno = 1
 *          FimSe
 *
 ** **********************************************************************************/

void Rede::destroiRede(){
    Pessoa *pes1;
    Relacionamento *rel1;

    while(pessoaInicio){
        while (pessoaInicio->pAcessoRela) {
            rel1 = pessoaInicio->pAcessoRela;
            pessoaInicio->pAcessoRela = rel1->prox;
            free(rel1);
            tamanho--; //
        }
        pes1 = pessoaInicio;
        pessoaInicio = pessoaInicio->prox;
        free(pes1);
        ordem--;
    }
}
