//---------------------------------------------------------------------------
#ifndef ArestaGrafoH
#define ArestaGrafoH
//---------------------------------------------------------------------------
#include "NoGrafo.h"
//---------------------------------------------------------------------------
class ArestaGrafo
{
   private:
	  const NoGrafo *origem;
	  const NoGrafo *destino;
	  float peso;

   public:
	  ArestaGrafo(  const NoGrafo *_origem,  const NoGrafo *_destino, float _peso );
	  ~ArestaGrafo();
	  
	  const NoGrafo *getOrigem() const;
	  const NoGrafo *getDestino() const;

	  void setPeso( float valorPeso );
	  float getPeso() const;
};
//---------------------------------------------------------------------------
#endif
