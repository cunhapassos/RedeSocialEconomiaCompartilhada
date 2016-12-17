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
u *         O grafo é implementado por meio de lista duplamente encadeada.
 *
 * @author NUR CORREIA - MAT. 15/0143290
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 19/11/2016
 *
 @}********************************************************************************/

#ifndef EDITARPERFIL_H
#define EDITARPERFIL_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "rede.h"

namespace Ui {
class EditarPerfil;
}

/** ********************************************************************************
 * Classe: EditarPerfil
 *
 * Descrição da classe
 *  Classe responsável por integração da edição de perfil com a interface gráfica. Os
 * dados aqui obtidos serão atualizados diretamente na rede.
 *
 * Requisitos assegurados pela classe:
 *  Armazenagem de nome, genero, id, cep, idade, escolaridade como tipos basicos e
 * listas de interesses transacoes e avaliacoes como estruturas.
 *
 * Hipóteses assumidas pela classe:
 *  Formatação de termos corretamento inseridos pelo usuário, a principio módulo não
 * faz validação de campos.
 *
 * Restrições da classe:
 *  É necessário o uso de formatos válidos como assertiva de entrada.
 *
 * ********************************************************************************/
class EditarPerfil : public QDialog
{
    Q_OBJECT

public:
    explicit EditarPerfil(QWidget *parent = 0, Rede *_rede = 0, Pessoa *_pes = 0);
    ~EditarPerfil();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButtonAdicionar_clicked();

private:
    Ui::EditarPerfil *ui;
    Rede *rede;
    Pessoa *pes;

    int idade;
    QString cep;
    QString nome;
    QString genero;
    int contInteresses;
    QString escolaridade;

    int idadeEd;
    int cepEd;
    string nomeEd;
    string generoEd;
    int contInteressesEd;
    string escolaridadeEd;

};

#endif // EDITARPERFIL_H
