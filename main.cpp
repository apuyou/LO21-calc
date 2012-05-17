#include <QtCore/QCoreApplication>
#include "Calculateur.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Calculateur c;
    try{
        c.insererElement("1 1 1 3 4+ 2 3 4 5 10+ + * / ");
        c.swap(0, 1);
        c.mean(3);
        c.drop();
    }catch(Erreur e){
        std::cout<<e.what()<<std::endl;
    }

    c.afficherPile();
    return a.exec();
}
