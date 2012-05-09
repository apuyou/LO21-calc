#include <QtCore/QCoreApplication>
#include <iostream>
#include "Pile.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout<<"Hello"<<std::endl;

    Pile p;
    p.empiler(12.3);
    p.empiler(14.4);
    p.empiler(15);

    int f= 45;
    p.empiler(f);

    Pile p2 = p;
    p2.empiler(98);
    p = p2;

    while(!p.pileVide())
        std::cout<<p.depiler()<<std::endl;

    return a.exec();
}
