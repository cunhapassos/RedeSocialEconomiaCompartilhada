#include <QCoreApplication>
#include <stdio.h>
#include <iostream>
#include "Rede.h"

int main(int argc, char *argv[])
{

    printf("olá mundo!");
    Rede rede("Economia");
    cout << rede.getNome() << "\n";
    cout << rede.vazia() << "\n";
    rede.inserePessoa("Paulo", 32, 'M', 71065904, "Superior");
    cout << rede.vazia() << "\n";

}
