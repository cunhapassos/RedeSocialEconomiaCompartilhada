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



