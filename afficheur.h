#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QMainWindow>
#include <QActionGroup>
#include "Calculateur.h"
#include "onglet.h"

namespace Ui {
    class Afficheur;
}

class Afficheur: public QMainWindow
{
    Q_OBJECT

public:
    explicit Afficheur(QWidget *parent = 0);
    ~Afficheur();

private slots:
    void nouvelOnglet();
    void nouvelOngletCopie();
    void fermeOnglet();

private:
    Ui::Afficheur *ui; /* Interface graphique Qt */
    QActionGroup *clavierGroup;
};

#endif // AFFICHEUR_H
