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
    Relacionamento *rel;
    Pessoa *p1, *p2;
    Transacao *t;
    const Pessoa*p3;

    Rede rede("Compartilhada");
    EXPECT_EQ("Compartilhada", rede.getNome());

    rede.inserePessoa("Paulo", 32, "M", 71065904, "Superior Completo");
    rede.inserePessoa("Pedro", 20, "M", 71065905, "Primeiro Grau incompleto");

    EXPECT_TRUE(rede.procuraPessoaNome("Paulo"));
    EXPECT_TRUE(rede.procuraPessoaNome("Pedro"));

    p1 = rede.procuraPonteiroPessoaNome("Paulo");

    for(int i = 0; i < 23; i++){
        p1->inserirInteresse("Comprar Carro");
    }

    EXPECT_EQ( 32, p1->getIdade() );
    EXPECT_EQ( "M", p1->getGenero());
    EXPECT_EQ( 71065904, p1->getCep());
    EXPECT_EQ( "Superior Completo", p1->getEscolaridade());
    EXPECT_EQ( 20, p1->interesses.size() );
    EXPECT_EQ(p1, rede.procuraPonteiroPessoaNome("Paulo"));
    EXPECT_EQ(NULL, rede.procuraPonteiroPessoaNome("Leo"));

    EXPECT_EQ(p1, rede.procuraPonteiroPessoaId(1));
    EXPECT_EQ(NULL, rede.procuraPonteiroPessoaId(10));

    p2 = rede.procuraPonteiroPessoaNome("Pedro");

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

    rede.inserePessoa("Patricia", 32, "F", 71065904, "Superior Completo");
    rede.inserePessoa("Ana", 20, "M", 71065905, "Primeiro Grau incompleto");

    rede.iniciarRelacionamentoPorId(3, 4);

    EXPECT_TRUE(rede.relacionamentoExiste("Paulo", "Pedro"));
    EXPECT_TRUE(rede.relacionamentoExiste("Pedro", "Paulo"));
    EXPECT_TRUE(rede.relacionamentoExiste("Patricia", "Ana"));
    EXPECT_TRUE(rede.relacionamentoExiste("Ana", "Patricia"));
    EXPECT_FALSE(rede.arvoreGeradoraMinima(2));
    EXPECT_FALSE(rede.menorCaminho(1,4));
    EXPECT_TRUE(rede.menorCaminho(1,2));

    rede.removeRelacionamentoPorCaminhoId(3,4);
    EXPECT_FALSE(rede.relacionamentoExiste("Patricia", "Ana"));
    EXPECT_FALSE(rede.relacionamentoExiste("Ana", "Patricia"));

    rede.iniciarRelacionamentoPorId(3, 4);
    EXPECT_EQ(2, rede.numeroRelacionamentos());

    rede.removeRelacionamentoPorCaminhoNome("Ana", "Patricia");
    EXPECT_FALSE(rede.relacionamentoExiste("Patricia", "Ana"));
    EXPECT_FALSE(rede.relacionamentoExiste("Ana", "Patricia"));
    EXPECT_EQ(1, rede.numeroRelacionamentos());

    EXPECT_EQ(4, rede.numeroPessoas());

    p3 = rede.procuraRelacionamentoPorCaminhoId(1, 2)->getOrigem();
    EXPECT_EQ(p1, p3);

    rede.editaPessoa(p1, "Rafael", 31, "M", 710659010, "Superior");
    EXPECT_EQ("Rafael", p1->getNome());
    EXPECT_EQ( 31, p1->getIdade() );
    EXPECT_EQ( "M", p1->getGenero());
    EXPECT_EQ( 710659010, p1->getCep());
    EXPECT_EQ( "Superior", p1->getEscolaridade());
    EXPECT_EQ( 20, p1->interesses.size() );

    rede.removePessoaPorId(1);
    EXPECT_FALSE(rede.procuraPessoaNome("Paulo"));
    rede.removePessoaPorNome("Pedro");
    EXPECT_FALSE(rede.procuraPessoaNome("Pedro"));
    EXPECT_EQ(2, rede.numeroPessoas());

    EXPECT_FALSE(rede.vazia());

    t = rede.iniciarTransacao(p1, p2, "Comprar Carro", "Comprar Carro");
    EXPECT_EQ( 2, t->getIdFornecedor());
    EXPECT_EQ( 1, t->getIdConsumidor());
    t->setFim(true);
    EXPECT_TRUE(t->getFim());
    EXPECT_EQ("Comprar Carro", t->getInteresseFornecedor());
    EXPECT_EQ("Comprar Carro", t->getInteresseConsumidor());

    rede.inserirTransacao(7, p1, p2, "Vender Carro", "Comprar Carro", true);
    t = rede.retornaTransacao(7);
    EXPECT_EQ( 7, t->getId());
    EXPECT_EQ( 2, t->getIdFornecedor());
    EXPECT_EQ( 1, t->getIdConsumidor());
    EXPECT_TRUE(t->getFim());

    rede.limpa();
    EXPECT_TRUE(rede.vazia());

}
TEST_F(RedeTeste, Teste_Pessoa){
    string json;
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

    json = "{\"id\":1,\"cep\":71065905,\"nome\":\"Pedro\",\"idade\":20,\"genero\":\"M\",\"escolaridade\":\"Primeiro Grau incompleto\",\"interesses\":[\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\",\"Comprar Carro\"],\"transacoes\":[],\"avaliacoes\":[]}";
    EXPECT_EQ(json, p.pessoaJson());
}
TEST_F(RedeTeste, Teste_Transacao){
    string json;
    Transacao t(1, 2, 3, "Comprar Carro", "Vender Carro");

    EXPECT_EQ( 1, t.getId());
    EXPECT_EQ( 3, t.getIdFornecedor());
    EXPECT_EQ( 2, t.getIdConsumidor());
    t.setFim(true);
    EXPECT_TRUE(t.getFim());
    EXPECT_EQ("Vender Carro", t.getInteresseFornecedor());
    EXPECT_EQ("Comprar Carro", t.getInteresseConsumidor());

    json = "{\"id\":1,\"IdFornecedor\":3,\"IdConsumidor\":2,\"intersseFornecedor\":\"Vender Carro\",\"interesseSolicitante\":\"Comprar Carro\",\"finalizada\":1}";
    EXPECT_EQ(json, t.transacaoJson());

}

TEST_F(RedeTeste, Teste_Avaliacao){
    Transacao *t1;

    t1 = new Transacao(1, 2, 3, "Comprar Carro", "Vender Carro");

    Avaliacao a(10, t1);

    EXPECT_EQ( 10, a.getNota());
    EXPECT_EQ(t1, a.getTransacao());
}

