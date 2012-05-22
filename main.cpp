#include <QtCore/QCoreApplication>
#include <QtGui/QApplication>
#include "Calculateur.h"
#include "afficheur.h"

#define GUI 1

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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

#if GUI
    Afficheur w;
    w.show();
#endif

    return a.exec();
}
