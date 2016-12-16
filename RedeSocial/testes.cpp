/** ********************************************************************************
 * @addtogroup MOD_TEST
 * @{
 * @ingroup MOD_TEST
 * @brief
 * O módulo teste possui funções responsáveis por realizar a massa de teste sobre o
 * módulo ???????????????????????????????????.
 *
 * @file teste.cpp
 * @brief Módulo de Implementação: Módulo Tete
 *
 * @author NUR CORREIA - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 18/09/2016
 *
 @}********************************************************************************/

/* Inclusões do Compilador */
#ifndef TESTE_GTEST
    #define TESTE_GTEST
#endif


/* Inclusões do Gtest */
#include "gtest/gtest.h"

/* Inclusões do respectivo módulo de definição */
#include "rede.h"
#include "pessoa.h"

using namespace std;

class RedeTeste : public::testing::Test{
    void SetUp(){}
    virtual void TearDown(){}
};


TEST_F(RedeTeste, Teste_Rede){

    Rede rede("Compartilhada");
    EXPECT_EQ("Compartilhada", rede.getNome());

    rede.inserePessoa("Paulo", 32, "M", 71065904, "Superior Completo");
    rede.inserePessoa("Pedro", 20, "M", 71065905, "Primeiro Grau incompleto");

    EXPECT_TRUE(rede.procuraPessoaNome("Paulo"));
    EXPECT_TRUE(rede.procuraPessoaNome("Pedro"));

    Pessoa *p1 = rede.procuraPonteiroPessoaNome("Paulo");

    for(int i = 0; i < 23; i++){
        p1->inserirInteresse("Comprar Carro");
    }
    EXPECT_EQ( 32, p1->getIdade() );
    EXPECT_EQ( "M", p1->getGenero());
    EXPECT_EQ( 71065904, p1->getCep());
    EXPECT_EQ( "Superior Completo", p1->getEscolaridade());
    EXPECT_EQ( 20, p1->interesses.size() );

    Pessoa *p2 = rede.procuraPonteiroPessoaNome("Pedro");

    for(int i = 0; i < 23; i++){
        p2->inserirInteresse("Vender Carro");
    }
    EXPECT_EQ( 20, p2->getIdade() );
    EXPECT_EQ( "M", p2->getGenero());
    EXPECT_EQ( 71065905, p2->getCep());
    EXPECT_EQ( "Primeiro Grau incompleto", p2->getEscolaridade());
    EXPECT_EQ( 20, p2->interesses.size() );

    rede.iniciarRelacionamentoPorNome("Paulo", "Pedro");
    rede.iniciarTransacao(p1, p2, p1->getInteresse(1), p2->getInteresse(2));


}
TEST_F(RedeTeste, Teste_Pessoa){

    Pessoa p( 1, "Pedro", 20, "M", 71065905, "Primeiro Grau incompleto" );

    EXPECT_EQ( 1, p.getId() );
    EXPECT_EQ( 20, p.getIdade() );
    EXPECT_EQ( "M", p.getGenero() );
    EXPECT_EQ( "Pedro", p.getNome() );
    EXPECT_EQ( 71065905, p.getCep() );
    EXPECT_EQ( "Primeiro Grau incompleto", p.getEscolaridade() );

    for(int i = 0; i < 23; i++){
        p.inserirInteresse("Comprar Carro");
    }

    EXPECT_EQ( 20, p.interesses.size() );

    vector<string>::iterator it = p.interesses.begin();
    EXPECT_EQ("Comprar Carro", *it);

    //cout << p.pessoaJson(); // imprime json da pessoa
}
TEST_F(RedeTeste, Teste_Transacao){

}
