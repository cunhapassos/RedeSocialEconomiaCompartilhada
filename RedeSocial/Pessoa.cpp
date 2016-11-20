/** ********************************************************************************
 *  @addtogroup MODULO REDE_SOCIAL
 *  @{
 *  @ingroup MOD_RS
 *
 *  @file Pessoa.cpp
 *  @brief Módulo de implementação: Módulo Rede Social
 *
 *
 * @author NUR CORREIA - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

/* inclusão do módulo de definição */

#include "Pessoa.h"
//---------------------------------------------------------------------------
Pessoa::Pessoa(unsigned int _id, string _nome, unsigned int _idade, char _genero, unsigned int _cep, string _escolaridade)
{
   id = _id;
   setNome( _nome );
   setIdade( _idade );
   setGenero( _genero );
   setCep( _cep );
   setEscolaridade( _escolaridade);
   visitado = false;
}
//---------------------------------------------------------------------------
Pessoa::~Pessoa()
{
}
//--------------------------------------------------------------------------- /
unsigned int Pessoa::getId() const
{
   return id;
}
//---------------------------------------------------------------------------
void Pessoa::setNome( string _nome )
{
   nome = _nome;
}
//---------------------------------------------------------------------------
string Pessoa::getNome() const
{
   return nome;
}
//---------------------------------------------------------------------------
bool Pessoa::getVisitado() const
{
   return visitado;
}
//---------------------------------------------------------------------------
void Pessoa::setVisitado( bool valor )
{
   visitado = valor;
}
//---------------------------------------------------------------------------
void Pessoa::setIdade(unsigned int _idade)
{
   idade = _idade;
}
//---------------------------------------------------------------------------
unsigned int Pessoa::getIdade() const
{
   return idade;
}
//---------------------------------------------------------------------------
void Pessoa::setGenero(char _genero)
{
   genero = _genero;
}
//---------------------------------------------------------------------------
char Pessoa::getGenero() const
{
   return genero;
}
//---------------------------------------------------------------------------
void Pessoa::setCep(unsigned int _cep)
{
   cep = _cep;
}
//---------------------------------------------------------------------------
unsigned int Pessoa::getCep() const
{
   return cep;
}
//---------------------------------------------------------------------------
void Pessoa::setEscolaridade(string _escolaridade)
{
   escolaridade = _escolaridade;
}
//---------------------------------------------------------------------------
string Pessoa::getEscolaridade() const
{
   return escolaridade;
}
//---------------------------------------------------------------------------
