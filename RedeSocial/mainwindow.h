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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "administrador.h"
#include "criarperfil.h"
#include "rede.h"

namespace Ui {
class MainWindow;
}

/** ********************************************************************************
 * Classe: MainWindow
 *
 * Descrição da classe
 *  A classe é responsável pela comunicação da janela principal com a rede. Funciona
 * como uma tela de login podendo ser feitas solicitações de entrada como usuário ou
 * como administrador.
 *
 * Requisitos assegurados pela classe:
 *  Após seleção correta, rede será carregada para utilização com as permissões 
 * devidas de usuário ou administrador.
 *
 * Hipóteses assumidas pela classe:
 *  Existência prévia de uma rede com usuarios e administrador.
 *
 * Restrições da classe:
 *  Não trabalha com checagem de login apenas seleciona entrada como usuario ou 
 * como administrador.
 *
 * ********************************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CriarPerfil *uPerfil;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addRede(Rede *_rede);

private slots:
    void on_pushButton_clicked();

private:
    Rede *rede;
    Ui::MainWindow *ui;
    Administrador *admin;
};

#endif // MAINWINDOW_H
