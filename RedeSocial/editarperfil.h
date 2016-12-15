#ifndef EDITARPERFIL_H
#define EDITARPERFIL_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "rede.h"

namespace Ui {
class EditarPerfil;
}

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
