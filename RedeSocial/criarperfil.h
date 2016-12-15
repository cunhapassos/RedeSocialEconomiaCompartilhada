#ifndef USUARIOPERFIL_H
#define USUARIOPERFIL_H
#include <QDialog>
#include <QMessageBox>
#include "usuario.h"
#include "rede.h"

namespace Ui {
class CriarPerfil;
}

class CriarPerfil : public QDialog
{
    Q_OBJECT

public:
    QMainWindow *main;

    explicit CriarPerfil(QWidget *parent = 0, Rede *_rede = 0);
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
