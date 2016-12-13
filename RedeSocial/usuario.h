#ifndef USUARIO_H
#define USUARIO_H

#include "Rede.h"

class Usuario
{
private:
    Rede *rede;
public:
    Usuario(Rede *_rede);

    void criarPessoa(string nome, unsigned int idade, string genero, unsigned int cep, string escolaridade);
    void inserirRelacionamento(string pessA, string pessB);
    void excluirPessoa(string nome);
    void fazerTransacao();

    void editarPessoa(string nome);
};

#endif // USUARIO_H
