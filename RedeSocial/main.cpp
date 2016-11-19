#include <QCoreApplication>
#include <stdio>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printf("Ola mundo");

    return a.exec();
}
