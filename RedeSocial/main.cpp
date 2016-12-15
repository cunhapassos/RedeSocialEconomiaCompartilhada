
#include <stdio.h>
#include <iostream>

#include <QApplication>

#include "rede.h"
#include "usuario.h"
#include "gtest/gtest.h"
#include "json.cpp"
#include "mainwindow.h"

int main(int argc, char *argv[])
{

    Rede *rede = new Rede("Economia");
    rede->criarRedeJson("rede.json");
    cout << rede->procuraPessoaNome("Thais") << "\n";

    QApplication a(argc, argv);
    MainWindow w;
    w.addRede(rede);
    w.show();

     a.exec();
    cout << rede->procuraPessoaNome("Leandro") << "\n";
    cout << rede->procuraPessoaNome("Ze") << "\n";
    return 0;
 /*
    cout << "olá mundo!" << endl;
 //     TESTES JSON
 //====================================================================
    std::ifstream i("rede.json");
    json j;
    i >> j;

     //cout << j << endl << endl;


    for(json::iterator it = j.begin(); it != j.end(); ++it){
        //cout << it.key() << " : " << it.value() << "\n\n";
    }

\
    Rede *rede = new Rede("Economia");

    rede->criarRedeJson("rede.json");

    cout << rede->procuraPonteiroPessoaNome("Paulo")->getInteresse(1) << "\n";
    cout << rede->procuraPessoaNome("Paulo") << "\n";
    cout << rede->procuraPessoaNome("Pedro") << "\n";
    cout << rede->procuraPessoaNome("Tavares") << "\n";
    cout << rede->procuraPessoaNome("Thais") << "\n";


    cout << "Numero de Pessoas na rede: " << rede->numeroPessoas() << "\n";


    // TESTA MENOR CAMINHO
    cout << "Imprime Caminho de Relacionamentos \n";
    rede->arvoreGeradoraMinima(5); // Primeiro deve criar a arvore geradora
    rede->imprimirCaminhoRelacionamentos(); // VER SE DEVE MODIFICAR< ele considera (A, B) = (B, A)

    cout << "Imprime menor Caminho de de uma origem ate um destino \n";


    // CUIDADO NA DEVE-SE VER O CASO DE NÃO EXISTIR O CAMINHO
    if(rede->menorCaminho(1, 3)){
        rede->imprimirCaminhoRelacionamentos();
        cout << "Disantancia de 1 a 3: " << rede->caminhoRelacionamentos.size() << "\n"; // verifica a distancia de 1 a 3;
    }
    //rede->inserirPessoasJson(j); */
 //====================================================================

/*
    Rede *rede = new Rede("Economia");
    cout << rede->getNome() << "\n";
    //cout << rede->vazia() << "\n";
    rede->inserePessoa("Paulo", 32, "M", 71065904, "Superior");
    rede->inserePessoa("Pedro", 20, "M", 71065905, "Primeiro Grau incompleto");
    rede->inserePessoa("Renan", 25, "M", 71065906, "Medio completo");
    rede->inserePessoa("Camila", 22, "F", 71065907, "Medio completo");
    rede->inserePessoa("Thais", 27, "F", 71065908, "Superior completo");
    //cout << rede->vazia() << "\n";

    Pessoa *p1 = rede->procuraPonteiroPessoaNome("Paulo");
    Pessoa *p2 = rede->procuraPonteiroPessoaNome("Pedro");
    Pessoa *p3 = rede->procuraPonteiroPessoaNome("Renan");
    Pessoa *p4 = rede->procuraPonteiroPessoaNome("Camila");
    Pessoa *p5 = rede->procuraPonteiroPessoaNome("Thais");

    for(int i = 0; i < 23; i++){
        p1->inserirInteresse("Comprar Carro");
        p2->inserirInteresse("Vender Carro");
        p3->inserirInteresse("Dar Carona");
        p4->inserirInteresse("Pegar Carona");
        p5->inserirInteresse("Alugar Casa");
    }
    rede->iniciarRelacionamentoPorNome("Paulo", "Pedro");
    rede->iniciarRelacionamentoPorNome("Pedro", "Renan");
    rede->iniciarRelacionamentoPorNome("Renan", "Camila");
    rede->iniciarRelacionamentoPorNome("Thais", "Pedro");
    rede->iniciarTransacao(p1, p2, p1->getInteresse(1), p2->getInteresse(2));

    cout << "Numero de Pessoas na rede: " << rede->numeroPessoas() << "\n";

    //Usuario usuario(rede);
    //usuario.criarPessoa("Pedro", 22, 'M', 71065805, "Medio");

    //cout << "Numero de Pessoas na rede: " << rede->numeroPessoas() << "\n";
    cout << "Gravando rede no arquivo... \n";
    rede->guardarRedeJson("rede.json");
    cout << "Rede guardada no arquivo! \n";
    //cout << rede->redeJson();
    //usuario.inserirRelacionamento("Paulo", "Pedro");
*/
/*
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); */
}
