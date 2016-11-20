//---------------------------------------------------------------------------
#include "Rede.h"
#include <queue>
#include <stack>
#define INFINITO 9999999
using namespace std;
//---------------------------------------------------------------------------
Rede::Rede(string _nome,  bool _direcionado )
{
   nome = _nome;
   direcionado = _direcionado;
   identificador = 0;
}
//---------------------------------------------------------------------------
Rede::~Rede()
{
   limpa();
}
//---------------------------------------------------------------------------
string Rede::getNome()
{
    return nome;
}


//---------------------------------------------------------------------------
void Rede::inserePessoa(string nome, unsigned int idade, char genero, unsigned int cep, string escolaridade)
{
   identificador++;
   Pessoa *pessoa = new Pessoa( identificador, nome, idade, genero, cep, escolaridade);
   listaPessoas.push_back( pessoa );
}
//---------------------------------------------------------------------------
void Rede::removePessoaPorId( unsigned int id )
{
   //procura arestas com origem ou destino com valores de nos  e as deleta
   list<Relacionamento *>::iterator posicaoListaRelacionamento = listaRelacionamentos.begin();
   const Pessoa *origem;
   const Pessoa *destino;

   while ( posicaoListaRelacionamento != listaRelacionamentos.end() )
   {
      origem = (*posicaoListaRelacionamento)->getOrigem();
      destino = (*posicaoListaRelacionamento)->getDestino();

      if ( ( origem->getId() == id ) || ( destino->getId() == id )  )
      {
         delete *posicaoListaRelacionamento;
         *posicaoListaRelacionamento = NULL;
         listaRelacionamentos.erase( posicaoListaRelacionamento );
      }
      posicaoListaRelacionamento++;
   }

   origem = NULL;
   destino = NULL;

   //deleta Pessoas com os valores
   list<Pessoa *>::iterator posicaoListaPessoa = listaPessoas.begin();
   while ( posicaoListaPessoa != listaPessoas.end() )
   {
      if ( (*posicaoListaPessoa)->getId() == id )
      {
         delete *posicaoListaPessoa;
         *posicaoListaPessoa = NULL;
         listaPessoas.erase( posicaoListaPessoa );
         break;
      }
      posicaoListaPessoa++;
   }
}
//---------------------------------------------------------------------------
void Rede::removePessoaPorNome( string nome )
{
   //procura arestas com origem ou destino com valores de Pessoas  e as deleta
   list<Relacionamento *>::iterator posicaoListaRelacionamento = listaRelacionamentos.begin();
   const Pessoa *origem;
   const Pessoa *destino;

   while ( posicaoListaRelacionamento != listaRelacionamentos.end() )
   {
      origem = (*posicaoListaRelacionamento)->getOrigem();
      destino = (*posicaoListaRelacionamento)->getDestino();

      if ( ( origem->getNome() == nome ) || ( destino->getNome() == nome )  )
      {
         delete *posicaoListaRelacionamento;
         *posicaoListaRelacionamento = NULL;
         listaRelacionamentos.erase( posicaoListaRelacionamento );
      }
      posicaoListaRelacionamento++;
   }

   origem = NULL;
   destino = NULL;

   //deleta Pessoas com os valores
   list<Pessoa *>::iterator posicaoListaPessoa = listaPessoas.begin();
   while ( posicaoListaPessoa != listaPessoas.end() )
   {
      if ( (*posicaoListaPessoa)->getNome() == nome )
      {
         delete *posicaoListaPessoa;
         *posicaoListaPessoa = NULL;
         listaPessoas.erase( posicaoListaPessoa );
      }
      posicaoListaPessoa++;
   }
}

Pessoa* Rede::procuraPonteiroPessoaNome( string nome )
{
   Pessoa* retorno  = NULL;

   list<Pessoa *>::iterator posicaoListaPessoa = listaPessoas.begin();

   while ( posicaoListaPessoa != listaPessoas.end() )
   {
      if ( (*posicaoListaPessoa)->getNome() == nome )
      {
         retorno = (*posicaoListaPessoa);
         break;
      }
   }

   return retorno;
}

//---------------------------------------------------------------------------
Pessoa* Rede::procuraPonteiroPessoaId( unsigned int id )
{
   Pessoa* retorno  = NULL;

   list<Pessoa *>::iterator posicaoListaPessoa = listaPessoas.begin();

   while ( posicaoListaPessoa != listaPessoas.end() )
   {
      if ( (*posicaoListaPessoa)->getId() == id )
      {
         retorno = (*posicaoListaPessoa);
         break;
      }
      posicaoListaPessoa++;
   }

   return retorno;
}
//---------------------------------------------------------------------------
bool Rede::procuraPessoaNome( string nome )
{
   bool retorno  = false;

   list<Pessoa *>::iterator posicaoListaPessoa = listaPessoas.begin();

   while ( posicaoListaPessoa != listaPessoas.end() )
   {
      if ( (*posicaoListaPessoa)->getNome() == nome )
      {
         retorno = true;
         break;
      }
      posicaoListaPessoa++;
   }

   return retorno;
}

//---------------------------------------------------------------------------
void Rede::insereRelacionamentoPorNome(string nomeOrigem, string nomeDestino)
{
   const Pessoa* pessoaOrigem = procuraPonteiroPessoaNome( nomeOrigem );
   const Pessoa* pessoaDestino = procuraPonteiroPessoaNome( nomeDestino );

   if ( ( pessoaOrigem != NULL ) && ( pessoaDestino != NULL ) )
   {
      Relacionamento *relacionamento = new Relacionamento( pessoaOrigem, pessoaDestino);
      listaRelacionamentos.push_back( relacionamento );
   }
}
//---------------------------------------------------------------------------
void Rede::insereRelacionamentoPorId(int idOrigem, int idDestino)
{
   const Pessoa* pessoaOrigem = procuraPonteiroPessoaId( idOrigem );
   const Pessoa* pessoaDestino = procuraPonteiroPessoaId( idDestino );

   if ( ( pessoaOrigem != NULL ) && ( pessoaDestino != NULL ) )
   {
      Relacionamento *relacionamento = new Relacionamento( pessoaOrigem, pessoaDestino);
      listaRelacionamentos.push_back( relacionamento );
   }
}

void Rede::removeRelacionamentoPorCaminhoNome( string nomeOrigem, string nomeDestino )
{
   const Pessoa *origem;
   const Pessoa *destino;
   list<Relacionamento *>::iterator posicaoListaRelacionamento = listaRelacionamentos.begin();

   while ( posicaoListaRelacionamento != listaRelacionamentos.end() )
   {
      origem = (*posicaoListaRelacionamento)->getOrigem();
      destino = (*posicaoListaRelacionamento)->getDestino();

      if ( ( origem->getNome() == nomeOrigem ) || ( destino->getNome() == nomeDestino )  )
      {
         delete *posicaoListaRelacionamento;
         *posicaoListaRelacionamento = NULL;
         listaRelacionamentos.erase( posicaoListaRelacionamento );
      }

      posicaoListaRelacionamento++;
   }
}
//---------------------------------------------------------------------------
void Rede::removeRelacionamentoPorCaminhoId( unsigned int idOrigem, unsigned int idDestino )
{
   const Pessoa *origem;
   const Pessoa *destino;
   list<Relacionamento *>::iterator posicaoListaRelacionamento = listaRelacionamentos.begin();

   while ( posicaoListaRelacionamento != listaRelacionamentos.end() )
   {
      origem = (*posicaoListaRelacionamento)->getOrigem();
      destino = (*posicaoListaRelacionamento)->getDestino();

      if ( ( origem->getId() == idOrigem ) && ( destino->getId() == idDestino )  )
      {
         delete *posicaoListaRelacionamento;
         *posicaoListaRelacionamento = NULL;
         listaRelacionamentos.erase( posicaoListaRelacionamento );
         break;
      }

      posicaoListaRelacionamento++;
   }
}
//---------------------------------------------------------------------------
unsigned int Rede::numeroRelacionamentos()
{
   return listaRelacionamentos.size();
}
//---------------------------------------------------------------------------
unsigned int Rede::numeroPessoas()
{
   return listaPessoas.size();
}
//---------------------------------------------------------------------------
bool Rede::vazia()
{
   return listaPessoas.empty();
}
//---------------------------------------------------------------------------
void Rede::limpa()
{
//deleta arestas
   list<Relacionamento *>::iterator posicaoListaRelacionamento = listaRelacionamentos.begin();

   while ( posicaoListaRelacionamento != listaRelacionamentos.end() )
   {
      delete *posicaoListaRelacionamento;
      *posicaoListaRelacionamento = NULL;
      posicaoListaRelacionamento++;
   }

   listaRelacionamentos.clear();

//deleta Pessoas
   list<Pessoa *>::iterator posicaoListaPessoa = listaPessoas.begin();

   while ( posicaoListaPessoa != listaPessoas.end() )
   {
      delete *posicaoListaPessoa;
      *posicaoListaPessoa = NULL;
      posicaoListaPessoa++;
   }

   listaPessoas.clear();
}

//---------------------------------------------------------------------------
bool Rede::arvoreGeradoraMinima( unsigned int idOrigem )
{
    bool retorno = false;
    unsigned int numeroPessoasChecados = 0;
    list<Relacionamento *> arvore;

    Pessoa* pessoa = procuraPonteiroPessoaId( idOrigem );
    Relacionamento* relacionamento = NULL;
    std::stack<unsigned int> *pilhaPessoas = new std::stack<unsigned int>;

    pilhaPessoas->push( pessoa->getId() );
    numeroPessoasChecados++;

    pessoa->setVisitado(true);

    while ( !(pilhaPessoas->empty()) )
    {


       unsigned int idPessoaAtual = pilhaPessoas->top();
       //pega proximo Pessoa adjacente nao visitado
       pessoa = getPessoaAdjacenteNaoVisitada( idPessoaAtual );

       if ( pessoa == NULL) // sem mais pessoas adjacentes
       {
          pilhaPessoas->pop();
       }
       else
       {
          pessoa->setVisitado( true ); //marca como visitado
          pilhaPessoas->push( pessoa->getId() ); //coloca na pilha
          numeroPessoasChecados++; //contagem de Pessoas checados
          relacionamento = procuraRelacionamentoPorCaminhoId( idPessoaAtual, pessoa->getId() );
          if ( ( relacionamento == NULL ) && ( direcionado == false ) )
          {
             relacionamento = procuraRelacionamentoPorCaminhoId( pessoa->getId() , idPessoaAtual );
          }

          if ( relacionamento != NULL )
          {
             arvore.push_back(relacionamento);
             relacionamento = NULL;
          }

       }
    }

    //limpa Pessoas visitados
    list<Pessoa *>::iterator posicaoListaPessoa = listaPessoas.begin();

    while ( posicaoListaPessoa != listaPessoas.end() )
    {
       (*posicaoListaPessoa)->setVisitado(false);
       posicaoListaPessoa++;
    }

    caminhoRelacionamentos.clear();
    if ( numeroPessoasChecados == numeroPessoas() )
    {
       retorno = true;
       caminhoRelacionamentos = arvore;
    }

    return retorno;
}
//---------------------------------------------------------------------------
Pessoa* Rede::getPessoaAdjacenteNaoVisitada( unsigned int id )
{
   Pessoa* idAdjacente = NULL;
   list<Relacionamento *>::iterator posicaoListaRelacionamento = listaRelacionamentos.begin();

   while ( posicaoListaRelacionamento != listaRelacionamentos.end() )
   {
      if ( ( (*posicaoListaRelacionamento)->getOrigem()->getId() == id )  &&
           ( (*posicaoListaRelacionamento)->getDestino()->getVisitado() == false )
         )
      {
         idAdjacente = procuraPonteiroPessoaId( (*posicaoListaRelacionamento)->getDestino()->getId() );
         break;
      }

      if ( !direcionado )
      {
          if ( ( (*posicaoListaRelacionamento)->getDestino()->getId() == id )  &&
               ( (*posicaoListaRelacionamento)->getOrigem()->getVisitado() == false )
            )
          {
              idAdjacente = procuraPonteiroPessoaId( (*posicaoListaRelacionamento)->getOrigem()->getId() );
              break;
          }
      }

      posicaoListaRelacionamento++;
   }

   return idAdjacente;
}
//---------------------------------------------------------------------------
Relacionamento* Rede::procuraRelacionamentoPorCaminhoId( unsigned int idOrigem, unsigned int idDestino )
{
   Relacionamento* relacionamento = NULL;
   const Pessoa *origem;
   const Pessoa *destino;
   list<Relacionamento *>::iterator posicaoListaRelacionamento = listaRelacionamentos.begin();

   while ( posicaoListaRelacionamento != listaRelacionamentos.end() )
   {
      origem = (*posicaoListaRelacionamento)->getOrigem();
      destino = (*posicaoListaRelacionamento)->getDestino();

      if ( ( origem->getId() == idOrigem ) && ( destino->getId() == idDestino )  )
      {
         relacionamento = *posicaoListaRelacionamento;
         break;
      }

      posicaoListaRelacionamento++;
   }

   return relacionamento;

}
//---------------------------------------------------------------------------
 bool Rede::menorCaminho( unsigned int idOrigem, unsigned int idDestino )
{
// ARRUMAR PARA TRABALHAR COM NAO DIRECIONADO
   bool retorno = false;
   Pessoa* origemCaminho =  procuraPonteiroPessoaId( idOrigem );
   Pessoa* destinoCaminho = procuraPonteiroPessoaId( idDestino );

   if ( ( origemCaminho !=  NULL ) && ( destinoCaminho != NULL ) )
   {
      //define que existe um menor caminho (previamente)
      retorno  = true;

      //variaveis para auxiliar calculo
      unsigned int numeroPessoas = identificador; //considera o numero de nos como o numero de ids criados
      unsigned int atual, auxiliarTroca; //caminha pela matriz de adjancencia para calculcar caminho
      double novaDistancia, distanciaAtual, menorDistancia; //variaveis auxiliares calculo de distancia
     //  int  anterior, aux_troca, percurso;

      // Alocacao dinamica de matrizes e vetores.
      double **matrizAdjacencia = new double*[numeroPessoas]; //cria caminho e distancias em matriz para facilitar calculo menor caminho
      double *distancia = new double[numeroPessoas]; //armazena distancia calculcados entre caminhos
      bool *veriricados =  new bool[numeroPessoas]; //lista de nos verificados
      unsigned int *caminho = new unsigned int[numeroPessoas]; //armzena o caminho encontrado  ????

      // Cria a segunda dimensao da matriz de adjacencias
      for(unsigned int i = 0; i < numeroPessoas; i++)
      {
         matrizAdjacencia[i] = new double[numeroPessoas];
      }
      //inicilia matriz de adjancencias com todos caminhos inifitos
      for(unsigned int i = 0; i < numeroPessoas; i++)
      {
          for(unsigned int j = 0; j < numeroPessoas; j++)
          {
             matrizAdjacencia[i][j] = INFINITO;
          }
      }

      // traz valores dos caminhos reais para matriz de adjacencias (transfere de lista para matriz)
      list<Relacionamento *>::iterator posicaoListaRelacionamento = listaRelacionamentos.begin();
      unsigned int idOrigemAux, idDestinoAux;
      while ( posicaoListaRelacionamento != listaRelacionamentos.end() )
      {
         idOrigemAux = (*posicaoListaRelacionamento)->getOrigem()->getId();
         idDestinoAux = (*posicaoListaRelacionamento)->getDestino()->getId();

         matrizAdjacencia[idOrigemAux-1][idDestinoAux-1] = 1;

         if ( !direcionado )
         {
            matrizAdjacencia[idDestinoAux-1][idOrigemAux-1] = 1;
         }

         posicaoListaRelacionamento++;
      }


      // Inicializa todos os elementos do vetor conjunto com NAOMEMBRO, os
      // do vetor distancia com INFINITO, e os do vetor caminho com zero.
      for(unsigned int i = 0; i < numeroPessoas; i++)
      {
         veriricados[i]  = false;
         distancia[i] = INFINITO;
         caminho[i]   = 0;
      }

      //iniciliza valores de origem como verificado e distancia de si mesmo 0
      idOrigem--;
      idDestino--;
      veriricados[idOrigem]  = true;
      distancia[idOrigem] = 0;

      // Define a origem como o inicio da busca
      atual = idOrigem;
      auxiliarTroca = atual;

      //calcula distancia  e encontra caminho
      while( atual != idDestino )
      {
         menorDistancia = INFINITO;
         distanciaAtual = distancia[atual];

         for(unsigned int i = 0; i < numeroPessoas; i++)
         {
            // Verifica se o elemento NAO esta no vetor conjunto.
            if( veriricados[i] == false )
            {
               // Calcula a distancia a partir do vertice atual ate vertice adjacente i.
               novaDistancia = distanciaAtual + matrizAdjacencia[atual][i];

               // Se a distancia, partindo do vertice atual, for menor,
               // atualiza o vetor de distancia e de precedencia.
               if( novaDistancia < distancia[i] )
               {
                  distancia[i] = novaDistancia;
                  caminho[i]   = atual;
               }

               // Determina o vertice (dentre todos os nao pertencentes ao
               // vetor conjunto) com a menor distancia.
               if( distancia[i] < menorDistancia )
               {
                  menorDistancia = distancia[i];
                  auxiliarTroca = i;
               }
            }
         }

         // Embora estejamos assumindo grafos ponderados e conexos, esta
         // verificacao garante que, em caso da nao existencia de um caminho,
         // o programa nao entre em loop infinito.
         if( atual == auxiliarTroca )
         {
            retorno = false;     // O caminho nao existe.
            break;
         }

         atual = auxiliarTroca;
         veriricados[atual] = true;
      }

       //se caminho encontrado marca para desenho
      if(retorno)
      {

        // Percorre o vetor dos menores caminhos para encontrar os vertices
        // e arestas que fazem parte do percurso.
        //AlteraPessoaSelecao(destino+1, true);
     unsigned int percurso = idDestino;
     unsigned int anterior = idDestino+1;
     Relacionamento *aresta;
     caminhoRelacionamentos.clear();
     while(percurso != idOrigem)
     {
        aresta = procuraRelacionamentoPorCaminhoId( caminho[percurso]+1, anterior);
        if ( !direcionado && ( aresta == NULL ) )
        {
           aresta = procuraRelacionamentoPorCaminhoId( anterior, caminho[percurso]+1 );
        }

        if ( aresta != NULL )
        {
           caminhoRelacionamentos.push_back( aresta );
        }

        anterior = (caminho[percurso] + 1);
        percurso = caminho[percurso];
      }

      }

     //limpa memoria
     for( unsigned int i = 0; i < numeroPessoas; i++ )
     {
        delete[] matrizAdjacencia[i];
     }
     delete[] matrizAdjacencia;
     delete[] caminho;
     delete[] veriricados;
     delete[] distancia;
   }
   return retorno;
}


