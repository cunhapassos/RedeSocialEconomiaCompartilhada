#ifndef USUARIO_H
#define USUARIO_H

#include <QMainWindow>
#include "Rede.h"
#include "editarperfil.h"
#include "transacoesjanela.h"

namespace Ui {
class Usuario;
}

class Usuario : public QMainWindow
{
    Q_OBJECT

public:
    QMainWindow *main;

    void listarPessoasDaRede();
    void listarAmigos();
   // void listarInteresses();
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
