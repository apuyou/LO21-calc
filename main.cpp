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
        c.insererElement("3 5");
        //c.swap(0, 1);
        //c.mean(3);
        //c.drop();
    }catch(Erreur e){
        std::cout<<e.what()<<std::endl;
    }

    c.afficherPile();

#if GUI
    Afficheur w;
    w.show();
#endif

    return a.exec();
}
