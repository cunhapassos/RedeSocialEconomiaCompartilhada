#ifndef AVALIACAO_H
#define AVALIACAO_H

#include "transacao.h"

class Avaliacao
{
protected:
    unsigned int id;
    unsigned int notaAvaliacao;
    Transacao* transacao;
public:
    Avaliacao(unsigned int _id, unsigned int nota, Transacao *_transacao);
    unsigned int getId();
    unsigned int getNota();
    void setNota(unsigned int nota);
    Transacao* getTransacao();
};

#endif // AVALIACAO_H
