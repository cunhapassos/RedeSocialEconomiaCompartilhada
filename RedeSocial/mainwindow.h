#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "administrador.h"
#include "criarperfil.h"
#include "rede.h"

namespace Ui {
class MainWindow;
}

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
