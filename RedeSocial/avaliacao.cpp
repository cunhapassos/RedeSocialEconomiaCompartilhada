#include "avaliacao.h"

Avaliacao::Avaliacao(unsigned int nota, Transacao *_transacao)
{
    notaAvaliacao = nota;
    transacao = _transacao;
}

void Avaliacao::setNota(unsigned int nota){
    notaAvaliacao = nota;
}
unsigned int Avaliacao::getNota(){
    return notaAvaliacao;
}

Transacao* Avaliacao::getTransacao()
{
    return transacao;
}
