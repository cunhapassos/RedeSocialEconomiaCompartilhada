#include <string>

#include "pessoa.h"

Pessoa::Pessoa(int _id, int _idade, string _cep, string _nome, char _genero, string _escolaridade)
{
    id = _id;
    idade = _idade;
    cep = _cep;
    nome = _nome;
    genero = _genero;
    escolaridade = _escolaridade;
}

Pessoa::~Pessoa()
{
}
