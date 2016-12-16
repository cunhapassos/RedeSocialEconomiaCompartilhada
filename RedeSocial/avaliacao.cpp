#include "avaliacao.h"

Avaliacao::Avaliacao(unsigned int nota, Transacao *_transacao)
{
    notaAvaliacao = nota;
    transacao = _transacao;
}

void Avaliacao::setNota(unsigned int nota){
    notaAvaliacao = nota;
}
int Avaliacao::getNota(){
    return notaAvaliacao;
}

Transacao* Avaliacao::getTransacao()
{
    return transacao;
}
string Avaliacao::avaliacaoJson()
{
    string json;

    stringstream notaString;
    stringstream idTransação;


    notaString << getNota();
    idTransação << getTransacao()->getId();

     json = "{\"nota\":" + notaString.str() + "," +
             "\"IdTransacao\":" + idTransação.str() +"}";
     return json;
}
