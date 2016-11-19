#include "relacionamento.h"


Relacionamento::Relacionamento(const Pessoa *_origem, const Pessoa *_destino)
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
