//---------------------------------------------------------------------------
#ifndef NoGrafoH
#define NoGrafoH
//---------------------------------------------------------------------------
#include <string>
using namespace std;
//---------------------------------------------------------------------------
class NoGrafo
{
   private:
	  int x;
	  int y;
	  int z;
	  unsigned int id;
	  bool visitado;
	  int valor;

   public:
	  NoGrafo( unsigned int _id, int _valor, int valorX, int valorY, int valorZ );
	  ~NoGrafo();
	  
	  void setX( int valorX );
	  int getX() const;

	  void setY( int valorY );
	  int getY() const;

	  void setZ( int valorZ );
	  int getZ() const;

	  bool getVisitado() const;
	  void setVisitado( bool valor );

	  void setXYZ( int valorX, int valorY, int valorZ );

	  unsigned int getId() const;

	  void setValor( int _valor );
	  int getValor() const;
};
//---------------------------------------------------------------------------
#endif
