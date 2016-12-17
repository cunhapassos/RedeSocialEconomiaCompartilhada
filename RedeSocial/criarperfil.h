/** ********************************************************************************
 *  @addtogroup MODULO REDE_SOCIAL
 *  @{
 *  @ingroup MOD_RS
 *
 *  @file Pessoa.h
 *  @brief Módulo de definição: Módulo Rede Social:
 *         Implementa a Rede Social de Economia Compartilhada por meio da estrutura
 *         de dados de umm grafo. Os pessoas da rede são representadas pelos vertices do gra-
 *         fo e os relacionamentos são representados pelas arestas.
 *         O grafo é implementado por meio de lista duplamente encadeada.
 *
 * @author NUR CORREIA - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

#ifndef USUARIOPERFIL_H
#define USUARIOPERFIL_H
#include <QDialog>
#include <QMessageBox>
#include "usuario.h"
#include "rede.h"

namespace Ui {
class CriarPerfil;
}

/** ********************************************************************************
 * Classe: CriarPerfil
 *
 * Descrição da classe
 *  Classe responsável pela criação do perfil do usuário. Através dela serão repassadas
 * para a rede os campos preenchidos pelo usuário para criação de uma pessoa.
 *
 * Requisitos assegurados pela classe:
 *  Armazenagem dos dados de uma pessoa assim como os protocolos para comunicação
 * com a interface gráfica.
 *
 * Hipóteses assumidas pela classe:
 *  Dados informados pelo usuário possuem de fato formato e valor corretos. 
 *
 * Restrições da classe:
 *  Não faz a verificação dos dados informados pelo usuário.
 *
 * ********************************************************************************/
class CriarPerfil : public QDialog
{
    Q_OBJECT

public:
    QMainWindow *main;

    explicit CriarPerfil(QWidget *parent = 0, Rede *_rede = 0);
    
    /** ******************************************************************************
      *
      *  Descricao da funcao:
      *      Método construtor da classe, responsável por inicializar os principais atributos.
      * 
      *  @param      nome         - Nome da pessoa.
      *  @param      idade        - Idade da pessoa.
      *  @param      genero       - Genero da pessoa. Deve ser M para masculino ou F para
      *                            feminino.
      *  @param      cep          - CEP residencial da pessoa. Deve ser um número inteiro.
      *  @param      escolaridade - Representa a escolaridade da pessoa. Deve ser uma das
      *                            seguintes opcoes: primeiro grau incompleto, primeiro
      *                            grau completo, segundo grau incompleto, segundo grau
      *                            completo, superior incompleto, superior completo ou
      *                            pós-graduação.
      *
      *  Assertiva de entrada
      *              idade, id e cep sao representados por inteiros sem sinal.
      *
      ** *******************************************************************************/
    void criarPessoa(string nome, unsigned int idade, string genero, unsigned int cep, string escolaridade);
    void setPessoa(Pessoa *p);
    ~CriarPerfil();

private slots:
    void on_pushButtonAdicionar_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CriarPerfil *ui;
    Rede *rede;
    Usuario *usuarioJanela;
    Pessoa *usuarioPerfil;

    int idade;
    int cep;
    string nome;
    string genero;
    int contInteresses;
    string escolaridade;
};

#endif // USUARIOPERFIL_H
