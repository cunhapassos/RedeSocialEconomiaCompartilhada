//---------------------------------------------------------------------------
#include "Grafo.h"
#include <queue>
#include <stack>
#define INFINITO 9999999
using namespace std;
//---------------------------------------------------------------------------
Grafo::Grafo( bool _direcionado )
{
   direcionado = _direcionado;
   identificador = 0;
}
//---------------------------------------------------------------------------
Grafo::~Grafo()
{
   limpa();
}
//---------------------------------------------------------------------------
void Grafo::insereNo( int valor,  int posisaoX, int posicaoY, int posicaoZ )
{
   identificador++;
   NoGrafo *no = new NoGrafo( identificador, valor, posisaoX, posicaoY, posicaoZ );
   listaNos.push_back( no );
}
//---------------------------------------------------------------------------
void Grafo::removeNoPorId( unsigned int id )
{
   //procura arestas com origem ou destino com valores de nos  e as deleta
   list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();
   const NoGrafo *origem;
   const NoGrafo *destino;

   while ( posicaoListaAresta != listaArestas.end() )
   {
	  origem = (*posicaoListaAresta)->getOrigem();
	  destino = (*posicaoListaAresta)->getDestino();

	  if ( ( origem->getId() == id ) || ( destino->getId() == id )  )
	  {
		 delete *posicaoListaAresta;
		 *posicaoListaAresta = NULL;
		 listaArestas.erase( posicaoListaAresta );
	  }
	  posicaoListaAresta++;
   }

   origem = NULL;
   destino = NULL;

   //deleta nos com os valores
   list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();
   while ( posicaoListaNo != listaNos.end() )
   {
	  if ( (*posicaoListaNo)->getId() == id )
	  {
		 delete *posicaoListaNo;
		 *posicaoListaNo = NULL;
		 listaNos.erase( posicaoListaNo );
		 break;
	  }
	  posicaoListaNo++;
   }
}
//---------------------------------------------------------------------------
void Grafo::removeNoPorValor( int valor )
{
   //procura arestas com origem ou destino com valores de nos  e as deleta
   list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();
   const NoGrafo *origem;
   const NoGrafo *destino;

   while ( posicaoListaAresta != listaArestas.end() )
   {
	  origem = (*posicaoListaAresta)->getOrigem();
	  destino = (*posicaoListaAresta)->getDestino();

	  if ( ( origem->getValor() == valor ) || ( destino->getValor() == valor )  )
	  {
		 delete *posicaoListaAresta;
		 *posicaoListaAresta = NULL;
		 listaArestas.erase( posicaoListaAresta );
	  }
	  posicaoListaAresta++;
   }

   origem = NULL;
   destino = NULL;

   //deleta nos com os valores
   list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();
   while ( posicaoListaNo != listaNos.end() )
   {
	  if ( (*posicaoListaNo)->getValor() == valor )
	  {
		 delete *posicaoListaNo;
		 *posicaoListaNo = NULL;
 		 listaNos.erase( posicaoListaNo );
	  }
	  posicaoListaNo++;
   }
}
//---------------------------------------------------------------------------
void Grafo::removeNoMenorValor()
{
   if ( !vazio() )
   {
	  int menorValor;
	  
	  list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();
	  menorValor = (*posicaoListaNo)->getValor();
      posicaoListaNo++;
	  
	  while ( posicaoListaNo != listaNos.end() )
	  {
		 if ( (*posicaoListaNo)->getValor() < menorValor )
		 {
			menorValor = (*posicaoListaNo)->getValor();
		 }
		 posicaoListaNo++;
	  }

	  removeNoPorValor( menorValor );
   }
}
//---------------------------------------------------------------------------
void Grafo::removeNoMaiorValor()
{
   if ( !vazio() )
   {
	  int maiorValor;
	  
	  list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();
	  maiorValor = (*posicaoListaNo)->getValor();
      posicaoListaNo++;
	  
	  while ( posicaoListaNo != listaNos.end() )
	  {
		 if ( (*posicaoListaNo)->getValor() > maiorValor )
		 {
			maiorValor = (*posicaoListaNo)->getValor();
		 }
		 posicaoListaNo++;
	  }

	  removeNoPorValor( maiorValor );
   }
}
//---------------------------------------------------------------------------
NoGrafo* Grafo::procuraPonteiroNoValor( int valor )
{
   NoGrafo* retorno  = NULL;

   list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();

   while ( posicaoListaNo != listaNos.end() )
   {
	  if ( (*posicaoListaNo)->getValor() == valor )
	  {
		 retorno = (*posicaoListaNo);
		 break;    
	  }
   }

   return retorno;
}

//---------------------------------------------------------------------------
NoGrafo* Grafo::procuraPonteiroNoId( unsigned int id )
{
   NoGrafo* retorno  = NULL;

   list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();

   while ( posicaoListaNo != listaNos.end() )
   {
	  if ( (*posicaoListaNo)->getId() == id )
	  {
		 retorno = (*posicaoListaNo);
		 break;    
	  }
	  posicaoListaNo++;
   }

   return retorno;
}
//---------------------------------------------------------------------------
bool Grafo::procuraNoValor( int valor )
{
   bool retorno  = false;

   list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();

   while ( posicaoListaNo != listaNos.end() )
   {
	  if ( (*posicaoListaNo)->getValor() == valor )
	  {
		 retorno = true;
		 break;
	  }
	  posicaoListaNo++;
   }

   return retorno;
}
//---------------------------------------------------------------------------
void Grafo::moveNoPorValor( int valor, int x, int y, int z )
{
   NoGrafo* no = procuraPonteiroNoValor( valor );
   if ( no != NULL )
   {
      no->setXYZ( x, y, z );
   }
}
//---------------------------------------------------------------------------
void Grafo::insereArestaPorValor( int valorOrigem, int valorDestino, float peso )
{
   const NoGrafo* noOrigem = procuraPonteiroNoValor( valorOrigem );
   const NoGrafo* noDestino = procuraPonteiroNoValor( valorDestino );

   if ( ( noOrigem != NULL ) && ( noDestino != NULL ) )
   {
	  ArestaGrafo *aresta = new ArestaGrafo( noOrigem, noDestino, peso );
	  listaArestas.push_back( aresta );
   }
}
//---------------------------------------------------------------------------
void Grafo::insereArestaPorId( int idOrigem, int idDestino, float peso )
{
   const NoGrafo* noOrigem = procuraPonteiroNoId( idOrigem );
   const NoGrafo* noDestino = procuraPonteiroNoId( idDestino );

   if ( ( noOrigem != NULL ) && ( noDestino != NULL ) )
   {
	  ArestaGrafo *aresta = new ArestaGrafo( noOrigem, noDestino, peso );
	  listaArestas.push_back( aresta );
   }
}
//---------------------------------------------------------------------------
void Grafo::removeArestaPorPeso( float peso )
{
   list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();

   while ( posicaoListaAresta != listaArestas.end() )
   {
	  if ( (*posicaoListaAresta)->getPeso() == peso  )
	  {
		 delete *posicaoListaAresta;
		 *posicaoListaAresta = NULL;
		 listaArestas.erase( posicaoListaAresta );
	  }
	  
	  posicaoListaAresta++;
   }
}
//---------------------------------------------------------------------------
void Grafo::removeArestaPorCaminhoValor( int valorOrigem, int valorDestino )
{
   const NoGrafo *origem;
   const NoGrafo *destino;
   list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();
   
   while ( posicaoListaAresta != listaArestas.end() )
   {
	  origem = (*posicaoListaAresta)->getOrigem();
	  destino = (*posicaoListaAresta)->getDestino();
	  
	  if ( ( origem->getValor() == valorOrigem ) || ( destino->getValor() == valorDestino )  )
	  {
		 delete *posicaoListaAresta;
		 *posicaoListaAresta = NULL;
 		 listaArestas.erase( posicaoListaAresta );
	  }
	  
	  posicaoListaAresta++;
   }
}
//---------------------------------------------------------------------------
void Grafo::removeArestaPorCaminhoId( unsigned int idOrigem, unsigned int idDestino )
{
   const NoGrafo *origem;
   const NoGrafo *destino;
   list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();
   
   while ( posicaoListaAresta != listaArestas.end() )
   {
	  origem = (*posicaoListaAresta)->getOrigem();
	  destino = (*posicaoListaAresta)->getDestino();
	  
	  if ( ( origem->getId() == idOrigem ) && ( destino->getId() == idDestino )  )
	  {
		 delete *posicaoListaAresta;
		 *posicaoListaAresta = NULL;
		 listaArestas.erase( posicaoListaAresta );
		 break;
	  }
	  
	  posicaoListaAresta++;
   }
}
//---------------------------------------------------------------------------
unsigned int Grafo::numeroArestas()
{
   return listaArestas.size();
}
//---------------------------------------------------------------------------
unsigned int Grafo::numeroNos()
{
   return listaNos.size();
}
//---------------------------------------------------------------------------
bool Grafo::vazio()
{
   return listaNos.empty();
}
//---------------------------------------------------------------------------
void Grafo::limpa()
{
//deleta arestas
   list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();

   while ( posicaoListaAresta != listaArestas.end() )
   {
	  delete *posicaoListaAresta;
	  *posicaoListaAresta = NULL;
	  posicaoListaAresta++;
   }

   listaArestas.clear();

//deleta nos
   list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();

   while ( posicaoListaNo != listaNos.end() )
   {
	  delete *posicaoListaNo;
	  *posicaoListaNo = NULL;
      posicaoListaNo++;
   }

   listaNos.clear();
}
//---------------------------------------------------------------------------
void Grafo::setDirecionado( bool valor )
{
   direcionado = valor;
}
//---------------------------------------------------------------------------
bool Grafo::getDirecionado() const
{
   return direcionado;
}
//---------------------------------------------------------------------------
bool Grafo::arvoreGeradoraMinima( unsigned int idOrigem )
{
	bool retorno = false;
	unsigned int numeroNosChecados = 0;
	list<ArestaGrafo *> arvore;

	NoGrafo* no = procuraPonteiroNoId( idOrigem );
	ArestaGrafo* aresta = NULL;
	std::stack<unsigned int> *pilhaNos = new std::stack<unsigned int>;

	pilhaNos->push( no->getId() );
	numeroNosChecados++;
	
	no->setVisitado(true);

	while ( !(pilhaNos->empty()) )
	{


	   unsigned int idNoAtual = pilhaNos->top();
	   //pega proximo no adjacente nao visitado
	   no = getVerticeAdjacenteNaoVisitado( idNoAtual );

	   if ( no == NULL) // sem mais nos adjacentes
	   {
          pilhaNos->pop();
	   }
	   else
	   {
		  no->setVisitado( true ); //marca como visitado
		  pilhaNos->push( no->getId() ); //coloca na pilha
		  numeroNosChecados++; //contagem de nos checados
		  aresta = procuraArestaPorCaminhoId( idNoAtual, no->getId() );
		  if ( ( aresta == NULL ) && ( direcionado == false ) )
		  {
			 aresta = procuraArestaPorCaminhoId( no->getId() , idNoAtual );
		  }
		  
		  if ( aresta != NULL )
		  {
             arvore.push_back(aresta);
		     aresta = NULL;
		  }

	   }
	}

	//limpa nos visitados
	list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();

	while ( posicaoListaNo != listaNos.end() )
	{
       (*posicaoListaNo)->setVisitado(false);
	   posicaoListaNo++;
	}

	caminhoArestas.clear();
	if ( numeroNosChecados == numeroNos() )
	{
	   retorno = true;
	   caminhoArestas = arvore;
	}

	return retorno;
}
//---------------------------------------------------------------------------
NoGrafo* Grafo::getVerticeAdjacenteNaoVisitado( unsigned int id )
{
   NoGrafo* idAdjacente = NULL;
   list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();

   while ( posicaoListaAresta != listaArestas.end() )
   {
	  if ( ( (*posicaoListaAresta)->getOrigem()->getId() == id )  &&
		   ( (*posicaoListaAresta)->getDestino()->getVisitado() == false )
		 )
	  {
		 idAdjacente = procuraPonteiroNoId( (*posicaoListaAresta)->getDestino()->getId() );
		 break;
	  }
	  
	  if ( !direcionado )
	  {
		  if ( ( (*posicaoListaAresta)->getDestino()->getId() == id )  &&
			   ( (*posicaoListaAresta)->getOrigem()->getVisitado() == false )
			)
		  {
			  idAdjacente = procuraPonteiroNoId( (*posicaoListaAresta)->getOrigem()->getId() );
			  break;
		  }
	  }

	  posicaoListaAresta++;
   }

   return idAdjacente;
}
//---------------------------------------------------------------------------
ArestaGrafo* Grafo::procuraArestaPorCaminhoId( unsigned int idOrigem, unsigned int idDestino )
{
   ArestaGrafo* aresta = NULL;
   const NoGrafo *origem;
   const NoGrafo *destino;
   list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();
   
   while ( posicaoListaAresta != listaArestas.end() )
   {
	  origem = (*posicaoListaAresta)->getOrigem();
	  destino = (*posicaoListaAresta)->getDestino();
	  
	  if ( ( origem->getId() == idOrigem ) && ( destino->getId() == idDestino )  )
	  {
		 aresta = *posicaoListaAresta;
		 break;
	  }

	  posicaoListaAresta++;
   }

   return aresta;

}
//---------------------------------------------------------------------------
 bool Grafo::menorCaminho( unsigned int idOrigem, unsigned int idDestino )
{
// ARRUMAR PARA TRABALHAR COM NAO DIRECIONADO
   bool retorno = false;
   NoGrafo* origemCaminho =  procuraPonteiroNoId( idOrigem );
   NoGrafo* destinoCaminho = procuraPonteiroNoId( idDestino );
   
   if ( ( origemCaminho !=  NULL ) && ( destinoCaminho != NULL ) )
   {
	  //define que existe um menor caminho (previamente)
	  retorno  = true;

	  //variaveis para auxiliar calculo
	  unsigned int numeroNos = identificador; //considera o numero de nos como o numero de ids criados
	  unsigned int atual, auxiliarTroca; //caminha pela matriz de adjancencia para calculcar caminho
	  double novaDistancia, distanciaAtual, menorDistancia; //variaveis auxiliares calculo de distancia
	 //  int  anterior, aux_troca, percurso;

	  // Alocacao dinamica de matrizes e vetores.
	  double **matrizAdjacencia = new double*[numeroNos]; //cria caminho e distancias em matriz para facilitar calculo menor caminho
	  double *distancia = new double[numeroNos]; //armazena distancia calculcados entre caminhos
	  bool *veriricados =  new bool[numeroNos]; //lista de nos verificados
	  unsigned int *caminho = new unsigned int[numeroNos]; //armzena o caminho encontrado  ????

	  // Cria a segunda dimensao da matriz de adjacencias
	  for(unsigned int i = 0; i < numeroNos; i++)
	  {
		 matrizAdjacencia[i] = new double[numeroNos];
	  }
      //inicilia matriz de adjancencias com todos caminhos inifitos
	  for(unsigned int i = 0; i < numeroNos; i++)
	  {
		  for(unsigned int j = 0; j < numeroNos; j++)
		  {
			 matrizAdjacencia[i][j] = INFINITO;
		  }
	  }

	  // traz valores dos caminhos reais para matriz de adjacencias (transfere de lista para matriz)
	  list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();
	  unsigned int idOrigemAux, idDestinoAux;
	  while ( posicaoListaAresta != listaArestas.end() )
	  {
		 idOrigemAux = (*posicaoListaAresta)->getOrigem()->getId();
		 idDestinoAux = (*posicaoListaAresta)->getDestino()->getId();

		 matrizAdjacencia[idOrigemAux-1][idDestinoAux-1] = (*posicaoListaAresta)->getPeso();

		 if ( !direcionado )
		 {
			matrizAdjacencia[idDestinoAux-1][idOrigemAux-1] = (*posicaoListaAresta)->getPeso();
		 }

		 posicaoListaAresta++;
	  }

	  
	  // Inicializa todos os elementos do vetor conjunto com NAOMEMBRO, os
	  // do vetor distancia com INFINITO, e os do vetor caminho com zero.
	  for(unsigned int i = 0; i < numeroNos; i++)
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

		 for(unsigned int i = 0; i < numeroNos; i++)
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
		//AlteraNoSelecao(destino+1, true);
	 unsigned int percurso = idDestino;
	 unsigned int anterior = idDestino+1;
	 ArestaGrafo *aresta;
	 caminhoArestas.clear();
	 while(percurso != idOrigem)
	 {
		aresta = procuraArestaPorCaminhoId( caminho[percurso]+1, anterior);
		if ( !direcionado && ( aresta == NULL ) )
		{
           aresta = procuraArestaPorCaminhoId( anterior, caminho[percurso]+1 );    
		}
		
		if ( aresta != NULL )
		{
		   caminhoArestas.push_back( aresta );
		}

		anterior = (caminho[percurso] + 1);
		percurso = caminho[percurso];
	  }

	  }

     //limpa memoria
	 for( unsigned int i = 0; i < numeroNos; i++ )
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
//---------------------------------------------------------------------------
bool Grafo::cicloEuleriano()
{
   list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();

   const NoGrafo *origem;
   const NoGrafo *destino;

   while ( posicaoListaNo != listaNos.end() )
   {
	  if ( direcionado )
	  {
		 int contadorOrigem = 0;
		 int contadorDestino = 0;
		 list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();

		 while ( posicaoListaAresta != listaArestas.end() )
		 {
			origem = (*posicaoListaAresta)->getOrigem();
			destino = (*posicaoListaAresta)->getDestino();

			if ( (*posicaoListaNo)->getId() == origem->getId() )
			{
			   contadorOrigem ++;
			}
			if ( ( (*posicaoListaNo)->getId() == destino->getId() ) )
			{
			   contadorDestino ++;
			}
			posicaoListaAresta ++;
		 }

		 if ( contadorOrigem != contadorDestino )
		 {
			return false;
		 }
	  }
	  else
	  {
		 int contador = 0;
		 list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();
		 while ( posicaoListaAresta != listaArestas.end() )
		 {
			origem = (*posicaoListaAresta)->getOrigem();
			destino = (*posicaoListaAresta)->getDestino();

			if ( ( (*posicaoListaNo)->getId() == origem->getId() ) && ( (*posicaoListaNo)->getId() == destino->getId() ) )
			{
			   contador = contador + 2;
			}
			else
			{
			   if ( ( (*posicaoListaNo)->getId() == origem->getId() ) || ( (*posicaoListaNo)->getId() == destino->getId() ) )
			   {
				  contador ++;
			   }
			}
			posicaoListaAresta ++;
		 }

		 if ( contador % 2 == 1)
		 {
			return false;
		 }
	}
	posicaoListaNo ++;
  }
  return true;
}
//---------------------------------------------------------------------------
bool Grafo::cicloHamiltoniano()
{
   list<NoGrafo *>::iterator posicaoListaNo = listaNos.begin();

   const NoGrafo *origem;
   const NoGrafo *destino;

   while ( posicaoListaNo != listaNos.end() )
   {
	  if ( direcionado )
	  {
		 return false;
	  }
	  else
	  {
		 int contador = 0;
		 list<ArestaGrafo *>::iterator posicaoListaAresta = listaArestas.begin();

		 while ( posicaoListaAresta != listaArestas.end() )
		 {
			origem = (*posicaoListaAresta)->getOrigem();
			destino = (*posicaoListaAresta)->getDestino();

		 if ( ( (*posicaoListaNo)->getId() == origem->getId() ) && ( (*posicaoListaNo)->getId() == destino->getId() ) )
		 {
			contador = contador + 2;
		 }
		 else
		 {
			if ( ( (*posicaoListaNo)->getId() == origem->getId() ) || ( (*posicaoListaNo)->getId() == destino->getId() ) )
			{
			   contador ++;
			}
		 }
		 posicaoListaAresta ++;
		 }

		 float metadeNos = (float) listaNos.size()/2;
		 if ( contador < ( metadeNos ) )
		 {
			return false;
		 }
	  }
   posicaoListaNo ++;
  }
  return true;
}

