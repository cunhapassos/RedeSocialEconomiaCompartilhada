//---------------------------------------------------------------------------
#include "rede.h"

#define INFINITO 9999999
using namespace std;

//---------------------------------------------------------------------------
Rede::Rede(string _nome,  bool _direcionado )
{
   nome = _nome;
   direcionado = _direcionado;
   idPessoa = 0;
   idTransacao = 0;
   idColaboracao = 0;
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
void Rede::inserePessoa(string nome, unsigned int idade, string genero, unsigned int cep, string escolaridade)
{
   idPessoa++;
   Pessoa *pessoa = new Pessoa( idPessoa, nome, idade, genero, cep, escolaridade);
   listaPessoas.push_back( pessoa );
}

void Rede::editaPessoa(Pessoa *p, string nome, unsigned int idade, string genero, unsigned int cep, string escolaridade)
{
    p->setNome(nome);
    p->setIdade(idade);
    p->setGenero(genero);
    p->setCep(cep);
    p->setEscolaridade(escolaridade);
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
      posicaoListaPessoa++;
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
void Rede::iniciarRelacionamentoPorNome(string nomeOrigem, string nomeDestino)
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
void Rede::iniciarRelacionamentoPorId(int idOrigem, int idDestino)
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
bool Rede::relacionamentoExiste(string pes1, string pes2){

    if(listaRelacionamentos.empty())
    {
        return false;
    }
    for(list<Relacionamento *>::iterator i = listaRelacionamentos.begin(); i != listaRelacionamentos.end() ; i++ ){
        if ( (
                ( (*i)->getOrigem()->getNome() == pes1 )  &&
                ( (*i)->getDestino()->getNome() == pes2 )
              ) ||
             (
                ( (*i)->getOrigem()->getNome() == pes2 ) &&
                ( (*i)->getDestino()->getNome() == pes1 )
             )
           )
        {
           return true;
        }
    }
    return false;
}
//---------------------------------------------------------------------------
Pessoa *Rede::getRelacionamentoAdjacenteNaoVisitado(unsigned int id)
{
   Pessoa* idAdjacente = NULL;
   list<Relacionamento *>::iterator posicaoListaRelacionamentos = listaRelacionamentos.begin();

   while ( posicaoListaRelacionamentos != listaRelacionamentos.end() )
   {
      if ( ( (*posicaoListaRelacionamentos)->getOrigem()->getId() == id )  &&
           ( (*posicaoListaRelacionamentos)->getDestino()->getVisitado() == false )
         )
      {
         idAdjacente = procuraPonteiroPessoaId( (*posicaoListaRelacionamentos)->getDestino()->getId() );
         break;
      }


     if ( ( (*posicaoListaRelacionamentos)->getDestino()->getId() == id )  &&
               ( (*posicaoListaRelacionamentos)->getOrigem()->getVisitado() == false )
            )
     {
              idAdjacente = procuraPonteiroPessoaId( (*posicaoListaRelacionamentos)->getOrigem()->getId() );
              break;
     }

      posicaoListaRelacionamentos++;
   }

   return idAdjacente;
}
//---------------------------------------------------------------------------

bool Rede::arvoreGeradoraMinima( unsigned int idOrigem )
{
    bool retorno = false;
    unsigned int numeroPessoasChecadas = 0;
    list<Relacionamento *> arvore;

    Pessoa* p1 = procuraPonteiroPessoaId( idOrigem );
    Relacionamento* r1 = NULL;
    std::stack<unsigned int> *pilhaPessoas = new std::stack<unsigned int>;

    pilhaPessoas->push( p1->getId() );
    numeroPessoasChecadas++;

    p1->setVisitado(true);

    while ( !(pilhaPessoas->empty()) )
    {


       unsigned int idNoAtual = pilhaPessoas->top();
       //pega proximo no adjacente nao visitado
       p1 = getRelacionamentoAdjacenteNaoVisitado( idNoAtual );

       if ( p1 == NULL) // sem mais nos adjacentes
       {
          pilhaPessoas->pop();
       }
       else
       {
          p1->setVisitado( true ); //marca como visitado
          pilhaPessoas->push( p1->getId() ); //coloca na pilha
          numeroPessoasChecadas++; //contagem de pessoas checados
          r1 = procuraRelacionamentoPorCaminhoId( idNoAtual, p1->getId() );
          if ( r1 == NULL )
          {
             r1 = procuraRelacionamentoPorCaminhoId( p1->getId() , idNoAtual );
          }

          if ( r1 != NULL )
          {
             arvore.push_back(r1);
             r1 = NULL;
          }

       }
    }

    //limpa nos visitados
    list<Pessoa *>::iterator posicaoListaPessoas = listaPessoas.begin();

    while ( posicaoListaPessoas != listaPessoas.end() )
    {
       (*posicaoListaPessoas)->setVisitado(false);
       posicaoListaPessoas++;
    }

    caminhoRelacionamentos.clear();
    if ( numeroPessoasChecadas == numeroPessoas() )
    {
        caminhoRelacionamentos = arvore;
        retorno = true;

    }

    return retorno;
}

//---------------------------------------------------------------------------

void Rede::imprimirCaminhoRelacionamentos()
{
    list<Relacionamento *>::iterator posicaoListaCaminhos = caminhoRelacionamentos.begin();

    while ( posicaoListaCaminhos != caminhoRelacionamentos.end() )
    {
       cout << "Origem: " << (*posicaoListaCaminhos)->getOrigem()->getNome() << " Destino: " << (*posicaoListaCaminhos)->getDestino()->getNome() << "\n";
       posicaoListaCaminhos++;
    }
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
   bool retorno = false;
   Pessoa* origemCaminho =  procuraPonteiroPessoaId( idOrigem );
   Pessoa* destinoCaminho = procuraPonteiroPessoaId( idDestino );

   if ( ( origemCaminho !=  NULL ) && ( destinoCaminho != NULL ) )
   {
      //define que existe um menor caminho (previamente)
      retorno  = true;

      //variaveis para auxiliar calculo
      unsigned int numeroPessoas = idPessoa; //considera o numero de pessoas como o numero de ids criados
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
         matrizAdjacencia[idDestinoAux-1][idOrigemAux-1] = 1;

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

        // Percorre o vetor dos menores caminhos para encontrar as pessoas
        // e relacionamentsos que fazem parte do percurso.
     unsigned int percurso = idDestino;
     unsigned int anterior = idDestino+1;
     Relacionamento *rel;
     caminhoRelacionamentos.clear();
     while(percurso != idOrigem)
     {
        rel = procuraRelacionamentoPorCaminhoId( caminho[percurso]+1, anterior);
        if ( !direcionado && ( rel == NULL ) )
        {
           rel = procuraRelacionamentoPorCaminhoId( anterior, caminho[percurso]+1 );
        }

        if ( rel != NULL )
        {
           caminhoRelacionamentos.push_back( rel );
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
//---------------------------------------------------------------------------

void Rede::iniciarTransacao(Pessoa *solicitante, Pessoa *fornecedor, string inteSoliciatante, string inteFornecedor)
{
    idTransacao++;

    Transacao *tra = new Transacao(idTransacao, solicitante->getId(), fornecedor->getId(), inteSoliciatante, inteFornecedor);
    transacoes.push_back(tra);
}

void Rede::inserirTransacao(unsigned int id, Pessoa *solicitante, Pessoa *fornecedor, string inteSoliciatante, string inteFornecedor, bool finalizada)
{
    Transacao *tra = new Transacao(id, solicitante->getId(), fornecedor->getId(), inteSoliciatante, inteFornecedor);

    tra->setFim(finalizada); // Atualiza transação como finalizada ou não
    transacoes.push_back(tra);
    /* Para atualizar o valor do contador de transacoes, responsavel pelos ids de transacoes*/
    if(idTransacao < id){
        idTransacao = id;
    }
}

void Rede::guardarRedeJson(string arquivo)
{
    using json = nlohmann::json;

    // read a JSON file
    //std::ifstream i("teste.json");
    // i >> j;
    //cout << jsonS;
    json j = json::parse(redeJson());


    ofstream o(arquivo);
    o << setw(4) << j << endl;
}

string Rede::redeJson()
{
    int aux1, aux2;
    string json;

    list<Pessoa *>::iterator k;
    list<Transacao *>::iterator j;
    list<Relacionamento *>::iterator i;

    json = "{\"ListaPessoas\":[";
    for( k = listaPessoas.begin() ; k != listaPessoas.end() ; k++ ){
        json = json + (*k)->pessoaJson() + ",";
    }
    json = json.substr(0, json.length()-1); // retira ultima virgula a direita

    json = json + "], \"ListaRelacionamentos\":[";
    aux1 = json.length();
    for( i = listaRelacionamentos.begin() ; i != listaRelacionamentos.end() ; i++ ){
        json = json + (*i)->relacionamentoJson() + ",";
    }
    aux2 = json.length();
    if (aux2 > aux1){
        json = json.substr(0, json.length()-1); // retira ultima virgula a direita
    }
    json = json + "],\"transacoes\":[";
    aux1 = json.length();
    for( j = transacoes.begin() ; j != transacoes.end() ; j++ ){
        json = json + (*j)->transacaoJson() + ",";
    }
    aux2 = json.length();
    if(aux2 > aux1){
        json = json.substr(0, json.length()-1); // retira ultima virgula a direita
    }
    json = json + "]}";

    return json;

}

bool Rede::criarRedeJson(string arquivo)
{
    std::ifstream i(arquivo);
    json j;
    i >> j;

    for (json::iterator it = j.begin(); it != j.end(); ++it) {
        //cout << it.key() << endl;
        if(it.key() == "ListaPessoas"){
            for(auto& elem : *it){
                //cout << elem << "\n\n";
                inserirPessoasJson(elem);
            }
        }
        if(it.key() == "ListaRelacionamentos"){
            for(auto& elem : *it){
                //INSEREIR FUNCAO PARA INSERIR RELACIONAMENTOS NA REDE
                //cout << elem << "\n\n";
                inserirRelacionamentoJson(elem);
            }
        }
        if(it.key() == "transacoes"){
            for(auto& elem : *it){
                //cout << elem << "\n\n";
                inserirTransacaoJson(elem);
            }
         }
    }

    return true;
}

bool Rede::inserirPessoasJson(json js)
{
    if(js.empty()) return false;

    json j1, j2, j3;

    Pessoa *p1;
    string nomeJ;
    string generoJ;

    unsigned int idJ;
    unsigned int cepJ;
    unsigned int idadeJ;
    unsigned int idPessoaJ;
    string escolaridadeJ;
    vector<string> interessesJ;

    for (json::iterator it = js.begin(); it != js.end(); ++it)
    {
        if (it.key() == "id") {
            idJ = it.value();
            continue;
        }
        if (it.key() == "cep") {
            cepJ = it.value();
            continue;
        }
        if (it.key() == "nome") {
            nomeJ = it.value();
            continue;
        }
        if (it.key() == "idade") {
            idadeJ = it.value();
            continue;
        }
        if (it.key() == "genero") {
            generoJ = it.value();
            continue;
        }
        if (it.key() == "escolaridade") {
            escolaridadeJ = it.value();
            continue;
        }
        if (it.key() == "interesses") {
            j1 = *it;
            continue;
        }
        if (it.key() == "transacoes") {
            j2 = *it;
            continue;
        }
        if (it.key() == "avaliacoes") {
            j3 = *it;
            continue;
        }
    }

    inserePessoa(nomeJ, cepJ, generoJ, idadeJ, escolaridadeJ);
    p1 = procuraPonteiroPessoaNome(nomeJ);
    p1->setId(idJ); // necessário para dar o id que foi dado a pessoa inicialmente

    /* Para atualizar o valor do contador de Pessoas da rede */
    if(idPessoa < idJ){
        idPessoa = idJ;
    }

    for(auto& elem : j1)
    {
        p1->inserirInteresse(elem);
    }
    for(auto& elem : j2)
    {
        p1->inserirTransacao(elem);
    }
    for(auto& elem : j3)
    {
        p1->inserirAvaliacao(elem);
    }
    return true;
}

bool Rede::inserirTransacaoJson(json js)
{
    if(js.empty()) return false;


    Pessoa *p1, *p2;

    unsigned int idJ;
    bool finalizadaJ; // Verificar se acrescenta depois

    string intersseFornecedorJ;
    string interesseSolicitanteJ;

    for (json::iterator it = js.begin(); it != js.end(); ++it)
    {
        if (it.key() == "IdFornecedor") {
            p1 = procuraPonteiroPessoaId(it.value());
            continue;
        }
        if (it.key() == "IdConsumidor") {
            p2 = procuraPonteiroPessoaId(it.value());
            continue;
        }
        if (it.key() == "intersseFornecedor") {
            intersseFornecedorJ =it.value();
            continue;
        }
        if (it.key() == "interesseSolicitante") {
            interesseSolicitanteJ = it.value();
            continue;
        }
        if (it.key() == "finalizada") {
            finalizadaJ = it.value();
            continue;
        }
     }
    inserirTransacao(idJ, p1, p2, intersseFornecedorJ , interesseSolicitanteJ, finalizadaJ );
    // p1- // Inserir na lsita de transações da pessoa
    return true;
}

bool Rede::inserirRelacionamentoJson(json js)
{
    if(js.empty()) return false;

    int id1, id2;

    for (json::iterator it = js.begin(); it != js.end(); ++it)
    {
        if (it.key() == "idOrigem") {
            id1 = it.value();
            continue;
        }
        if (it.key() == "idDestino") {
            id2 = it.value();
            continue;
        } 
    }
    iniciarRelacionamentoPorId(id1, id2);

    return true;

}



