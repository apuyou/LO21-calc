#include <QtCore/QCoreApplication>
#include "Calculateur.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Calculateur c;
    try{
        c.insererElement("2 3 3 +");
        c.modeDegre();
        c.modeFraction();

        c.modeReel();
        c.mod();
    }catch(Erreur e){
        std::cout<<e.what()<<std::endl;
    }
    float d;
    float n = getFraction(0.25, &d);
    std::cout<<n<<"/"<<d<<std::endl;
    c.afficherPile();
    return a.exec();
}
