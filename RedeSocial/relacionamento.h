/** ********************************************************************************
 *  @defgroup MODULO RELACIONAMENTO
 *  @{
 *  @ingroup MOD_RELA
 *  @brief
 *  O módulo permite a manipulação dos relacionamentos entre pessoas que pertencerão
 *  a rede social de economia compartilhada. Esses relacionamentos representam
 *  arestas de um grafo.
 *
 *  @file relacionamento.h
 *  @brief Módulo de definição: Módulo Relacionamento

 * @author NUR CORREIA - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

#ifndef RELACIONAMENTO_H
#define RELACIONAMENTO_H

#include "Pessoa.h"

class Relacionamento
{
private:
    const Pessoa *origem;
    const Pessoa *destino;

public:
    Relacionamento(const Pessoa *_origem, const Pessoa *_destino);
    ~Relacionamento();

    const Pessoa *getOrigem() const;
    const Pessoa *getDestino() const;
};

#endif // RELACIONAMENTO_H
