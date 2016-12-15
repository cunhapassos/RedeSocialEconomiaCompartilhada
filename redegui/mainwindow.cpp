#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{



    if(ui->radioButtonUsuario->isChecked()) {
        QMessageBox::information(this, "Parabéns", "Seja bem vindo a Rede Social Colaborativa!");
        hide();
        usuario = new Usuario(this);
        usuario->show();
    }
    if(ui->radioButtonAdmin->isChecked()) {

        hide();
        admin = new Administrador(this);
        admin->show();
    }

}
