#ifndef USUARIOPERFIL_H
#define USUARIOPERFIL_H
#include <QDialog>

#include "rede.h"

namespace Ui {
class UsuarioPerfil;
}

class UsuarioPerfil : public QDialog
{
    Q_OBJECT

public:
    explicit UsuarioPerfil(QWidget *parent = 0, Rede *_rede = 0);
    void criarPessoa(string nome, unsigned int idade, string genero, unsigned int cep, string escolaridade);
    ~UsuarioPerfil();

private slots:
    void on_pushButtonAdicionar_clicked();

private:
    Ui::UsuarioPerfil *ui;
    Rede *rede;

    int idade;
    int cep;
    string nome;
    string genero;
    string escolaridade;
};

#endif // USUARIOPERFIL_H
