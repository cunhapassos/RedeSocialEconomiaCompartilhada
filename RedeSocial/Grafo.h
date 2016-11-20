//---------------------------------------------------------------------------
#ifndef GrafoH
#define GrafoH
//---------------------------------------------------------------------------
#include <list>
#include "NoGrafo.h"
#include "ArestaGrafo.h"
//---------------------------------------------------------------------------
class Rede
{
   protected:
	  list<NoGrafo *> listaNos;
	  list<ArestaGrafo *> listaArestas;
	  list<ArestaGrafo *> caminhoArestas;
	  
	  bool direcionado;
	  unsigned int identificador;
	  NoGrafo* procuraPonteiroNoValor( int valor );
	  NoGrafo* procuraPonteiroNoId( unsigned int id );

	  const NoGrafo* localizaNo( int posicaoX , int posicaoY );
	  ArestaGrafo* procuraRelacionamentoPorCaminhoId( unsigned int idOrigem, unsigned int idDestino );
	  
	  NoGrafo* getPessoaAdjacenteNaoVisitada( unsigned int id );
	  
   public:
	  Rede( bool _direcionado = false );
	  ~Rede();

	  void inserePessoa( int valor,  int posisaoX, int posicaoY, int posicaoZ );
	  void removeNoPorId( unsigned int id );
	  void removeNoPorValor( int valor );
      void removeNoMenorValor();
	  void removeNoMaiorValor();
	  bool procuraNoValor( int valor );
	  void moveNoPorValor( int valor, int x, int y, int z );

	  void setDirecionado( bool valor=true );
	  bool getDirecionado() const;

	  void insereRelacionamentoPorNome( int valorOrigem, int valorDestino, float peso );
	  void insereArestaPorId( int idOrigem, int idDestino, float peso );
	  void removeRelacionamentoPorPeso( float peso );
	  void removeArestaPorCaminhoValor( int valorOrigem, int valorDestino );
	  void removeArestaPorCaminhoId( unsigned int idOrigem, unsigned int idDestino );

	  unsigned int numeroArestas();
	  unsigned int numeroNos();
	  bool vazio();
	  void limpa();

	  bool menorCaminho( unsigned int idOrigem, unsigned int idDestino );
	  bool arvoreGeradoraMinima( unsigned int idOrigem );
	  bool cicloEuleriano();
  	  bool cicloHamiltoniano();
};
//---------------------------------------------------------------------------
#endif

