#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QMainWindow>
#include <QActionGroup>
#include "Calculateur.h"

namespace Ui {
    class Afficheur;
}

class Afficheur: public QMainWindow
{
    Q_OBJECT

private slots:
    void genericButtonPressed();
    void enterPressed();
    void spacePressed();
    void deletePressed();
    void complexeChanged(bool newState);
    void anglesChanged(int index);
    void modeChanged(int index);

public:
    explicit Afficheur(QWidget *parent = 0);
    ~Afficheur();

private:
    Ui::Afficheur *ui; /* Interface graphique Qt */
    Calculateur c;  /* Calculateur utilisé pour effectuer les opérations de l'utilisateur */
    QActionGroup *clavierGroup;
};

#endif // AFFICHEUR_H
