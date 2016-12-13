#include "avaliacao.h"

Avaliacao::Avaliacao(unsigned int _id, unsigned int nota, Transacao *_transacao)
{
    id = _id;
    notaAvaliacao = nota;
    transacao = _transacao;
}

void Avaliacao::setNota(unsigned int nota){
    notaAvaliacao = nota;
}
unsigned int Avaliacao::getNota(){
    return notaAvaliacao;
}

unsigned int Avaliacao::getId()
{
    return id;
}

Transacao* Avaliacao::getTransacao()
{
    return transacao;
}
