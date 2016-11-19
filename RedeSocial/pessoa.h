/** ********************************************************************************
 *  @defgroup MODULO PESSOA
 *  @{
 *  @ingroup MOD_PESS
 *  @brief
 *  O módulo permite a manipulação das pessoas que pertencerão a rede social de
 *  economia compartilhada. Essas pessoas representam vertices de um grafo.
 *
 *  @file pessoa.h
 *  @brief Módulo de definição: Módulo Pessoa

 * @author NUR CORREIA - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa
{
    private:
        int id;
        int idade;
        string cep;
        string nome;
        char genero;
        string escolaridade;
        string interesses[20];
        // transacoes
        // avaliacoes

    public:
        Pessoa(int _id, int _idade, string _cep, string _nome, char _genero, string _escolaridade);
        ~Pessoa();

};

#endif // PESSOA_H
