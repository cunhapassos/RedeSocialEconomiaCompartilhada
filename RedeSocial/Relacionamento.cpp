/** ********************************************************************************
 *  @addtogroup MODULO REDE_SOCIAL
 *  @{
 *  @ingroup MOD_RS
 *
 *  @file Relacionamento.cpp
 *  @brief Módulo de implementação: Módulo Rede Social
 *
 *
 * @author NUR CORREIA - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

/* inclusão do módulo de definição */

#include "relacionamento.h"

/*****  Código das funções exportadas pela classe  *****/
Relacionamento::Relacionamento(const Pessoa *_origem,  const Pessoa *_destino)
{
   origem = _origem;
   destino = _destino;
}

Relacionamento::~Relacionamento()
{
}

const Pessoa* Relacionamento::getOrigem() const
{
   return origem;
}

const Pessoa* Relacionamento::getDestino() const
{
    return destino;
}

string Relacionamento::relacionamentoJson() const
{
    string json;
    stringstream idOriString;
    stringstream idDesString;

    int idO = getOrigem()->getId();
    int idD = getDestino()->getId();

    idOriString << idO;
    idDesString << idD;

    json = "{\"idOrigem\":" + idOriString.str() + "," + "\"idDestino\":" + idDesString.str() + "}";
    return json;
}

