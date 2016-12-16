
#include <stdio.h>
#include <iostream>

#include <QApplication>

#include "rede.h"
#include "gtest/gtest.h"
#include "json.cpp"
#include "mainwindow.h"

int main(int argc, char *argv[])
{

    Rede *rede = new Rede("Economia");
    Pessoa *p;
    rede->criarRedeJson("rede.json");

    QApplication a(argc, argv);
    MainWindow w;
    w.addRede(rede);
    w.show();
    a.exec();

    rede->guardarRedeJson("rede.json");

    return 0;
/*
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); */
}
