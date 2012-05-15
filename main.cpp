#include <QtCore/QCoreApplication>
#include "Calculateur.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Calculateur c;
    c.insererElement("1 3 4+ 2 3 4 5 10+ - * /");
    c.afficherPile();
    return a.exec();
}
