#include "transacao.h"
#include "pessoa.h"

Transacao::Transacao(unsigned int _id, int _consumidor, int _fornecedor, string inteConsumidor, string inteFornecedor)
{
    id = _id;
    IdFornecedor = _fornecedor;
    IdConsumidor = _consumidor;
    intersseFornecedor = inteFornecedor;
    interesseSolicitante = inteConsumidor;
    finalizada = false;
}
unsigned int Transacao::getId() const
{
    return id;
}

int Transacao::getIdFornecedor() const {
    return IdFornecedor;
}

int Transacao::getIdConsumidor() const {
    return IdConsumidor;
}

void Transacao::setFim(bool fim)
{
    finalizada = fim;
}
bool  Transacao::getFim()
{
    return finalizada;
}
string Transacao::getInteresseFornecedor() const
{
    return intersseFornecedor;
}

string Transacao::getInteresseConsumidor() const
{
    return interesseSolicitante;
}

string Transacao::transacaoJson() const
{
    string json;

    stringstream idTransacaoString;
    stringstream idFornecedorString;
    stringstream idConsumidorString;

    idTransacaoString << getId();
    idFornecedorString << getIdFornecedor();
    idConsumidorString << getIdConsumidor();

     json = "{\"id\":" + idTransacaoString.str() + "," +
             "\"IdFornecedor\":" + idFornecedorString.str() + "," +
             "\"IdConsumidor\":" + idConsumidorString.str() + "," +
             "\"intersseFornecedor\":\"" + getInteresseFornecedor() + "\"," +
             "\"interesseSolicitante\":\"" + getInteresseConsumidor() + "\"}";
     return json;
}


