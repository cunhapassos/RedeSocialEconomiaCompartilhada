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

#include "pessoa.h"
//---------------------------------------------------------------------------
Pessoa::Pessoa(unsigned int _id, string _nome, unsigned int _idade, string _genero, unsigned int _cep, string _escolaridade)
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

void Pessoa::setId(unsigned int id)
{
    this->id = id;
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
void Pessoa::setGenero(string _genero)
{
   genero = _genero;
}
//---------------------------------------------------------------------------
string Pessoa::getGenero() const
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
bool Pessoa::inserirInteresse(string interesse)
{
    if(interesse.size() < 200 && interesses.size() < 20) {
        interesses.push_back(interesse);
        return true;
    }
    return false;
}

void Pessoa::inserirTransacao(int idTransacao)
{
    transacoes.push_back(idTransacao);
}

void Pessoa::inserirAvaliacao(int idAvaliacao)
{
    avaliacoes.push_back(idAvaliacao);
}

string Pessoa::getInteresse(int ordemInteresse)
{
    if(ordemInteresse < 20) return interesses[ordemInteresse];
    return "";
}

string Pessoa::pessoaJson() const
{
    string json;
    string aux1;

    stringstream aux2;
    stringstream aux3;
    stringstream aux4;

    stringstream idString;
    stringstream cepString;
    stringstream idadeString;

    idString << getId();
    cepString << getCep();
    idadeString << getIdade();

    json = "{\"id\":" + idString.str() + "," +
            "\"cep\":" + cepString.str() + ',' +
            "\"nome\":\"" + getNome() + "\"," +
            "\"idade\":" + idadeString.str() + ',' +
            "\"genero\":\"" + getGenero() + "\"," +
            "\"escolaridade\":\"" + getEscolaridade() + "\",";

    copy(interesses.begin(), interesses.end(), ostream_iterator<string>(aux2, "\",\""));
    aux1 = aux2.str();
    if(aux1.length() > 0){
        aux1 = "\"" + aux1.substr(0, aux1.length()-1);
    }
    aux1 = aux1.substr(0, aux1.length()-1);
    json = json + "\"interesses\":[" + aux1 + "],";

    copy(transacoes.begin(), transacoes.end(), ostream_iterator<int>(aux3, ","));
    aux1 = aux3.str();
    aux1 = aux1.substr(0, aux1.length()-1);
    json = json + "\"transacoes\":[" + aux1 + "],";

    copy(avaliacoes.begin(), avaliacoes.end(), ostream_iterator<int>(aux4, ","));
    aux1 = aux4.str();
    aux1 = aux1.substr(0, aux1.length()-1);
    json = json + "\"avaliacoes\":[" + aux1 + "]}";

    return json;
}
