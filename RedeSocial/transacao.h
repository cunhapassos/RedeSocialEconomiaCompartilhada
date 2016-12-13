#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

using namespace std;

class Transacao
{
protected:
    unsigned int id;
    bool finalizada;
    int IdFornecedor;
    int IdConsumidor;
    string intersseFornecedor;
    string interesseSolicitante;

public:
    Transacao(unsigned int _id, int _consumidor, int _fornecedor, string inteConsumidor, string inteFornecedor);

    unsigned int getId() const;
    int getIdFornecedor() const;
    int getIdConsumidor() const;
    void setFim(bool fim);
    string getInteresseFornecedor() const;
    string getInteresseConsumidor() const;

    string transacaoJson() const;

};

#endif // TRANSACAO_H
