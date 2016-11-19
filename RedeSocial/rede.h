/** ********************************************************************************
 *  @defgroup MODULO REDE
 *  @{
 *  @ingroup MOD_REDE
 *  @brief
 *  O módulo permite a criação e manipulação da Rede Social de Economia compartilhada
 *  por meio da estrutura de dados de um Grafo.
 *
 *  @file rede.h
 *  @brief Módulo de definição: Módulo Rede

 * @author NUR CORREIA - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

#ifndef REDE_H
#define REDE_H

//---------------------------------------------------------------------------
#include <list>
#include <string>

#include "Pessoa.h"
#include "Relacionamento.h"
//---------------------------------------------------------------------------
class Rede
{
    protected:
        int ordem;
        int tamanho;
        string nome;

        Pessoa* pessoaInicio; // no inicial da lista de pessoas


    public:
        Rede(string nomeRede);

    string getNome();
    void destroiRede()
};

#endif // REDE_H
