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

#ifndef USUARIO_H
#define USUARIO_H

#include <QMainWindow>
#include "Rede.h"
#include "editarperfil.h"
#include "transacoesjanela.h"

/** ********************************************************************************
 * Classe: Usuario
 *
 * Descrição da classe
 *  Armazena uma pessoa como usuario para integração com a interface gráfica.
 *
 * Requisitos assegurados pela classe:
 *  Armazenagem dos dados de uma pessoa assim como os protocolos para comunicação
 * com a interface gráfica.
 *
 * Hipóteses assumidas pela classe:
 *  Formatação de termos corretamento inseridos pelo usuário, a principio módulo não
 * faz validação de campos.
 *
 * Restrições da classe:
 *  É necessário o iso de formatos válidos como assertiva de entrada.
 *
 * ********************************************************************************/
namespace Ui {
class Usuario;
}

class Usuario : public QMainWindow
{
    Q_OBJECT

public:
    QMainWindow *main;
    
    /** ******************************************************************************
      *  Funcao: listarPessoasDaRede
      *
      *  Descricao da funcao:
      *      Lista diretamente para interface gráfica todas as pessoas peretencentes a
      * a rede.
      * 
      ** *******************************************************************************/
    void listarPessoasDaRede();
    
    
    /** ******************************************************************************
      *  Funcao: listarAmigos
      *
      *  Descricao da funcao:
      *      Lista diretamente para interface gráfica todas as pessoas em relacionamentos 
      * com a pessoa a qual se refere o usuario.
      * 
      ** *******************************************************************************/
    void listarAmigos();
    
     /** ******************************************************************************
      *  Funcao: listarRelacionamentos
      *
      *  Descricao da funcao:
      *      Lista diretamente para interface gráfica todos os relacionamentos em que 
      * esta pessoa se encontra, informado destino e origem.
      * 
      ** *******************************************************************************/
    void listarRelacionamentos();
    explicit Usuario(QWidget *parent = 0, Rede *_rede = 0, Pessoa *_pes = 0);
    void setUsuario(Pessoa *usuario);
    ~Usuario();

private slots:

    void on_actionEditar_Perfil_triggered();

    void on_actionExcluir_Perfil_triggered();

    void on_pushButtonIniAmizade_clicked();

    void on_pushButtonExcAmizade_clicked();

    void on_actionAbrir_triggered();

    void on_pushButton_clicked();

private:
    Rede *rede;
    Ui::Usuario *ui;
    Pessoa *pes;
    EditarPerfil *edPerfil;
    TransacoesJanela *tJanela;

};

#endif // USUARIO_H
