#include "usuario.h"

Usuario::Usuario(Rede *_rede)
{
    rede = _rede;
}
void Usuario::criarPessoa(string nome, unsigned int idade, string genero, unsigned int cep, string escolaridade)
{
    rede->inserePessoa(nome, idade, genero, cep, escolaridade);
}

void Usuario::inserirRelacionamento(string pessA, string pessB)
{
    /**
     * Para que exista amizade entre duas pessoas A e B, deve-se
     * exixtir uma aresta de A para B e uma de B para A
     **/
    rede->iniciarRelacionamentoPorNome(pessA, pessB);
    rede->iniciarRelacionamentoPorNome(pessB, pessA);
}

void Usuario::excluirPessoa(string nome){
    rede->removePessoaPorNome(nome);
}
