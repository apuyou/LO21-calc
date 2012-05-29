#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QMainWindow>
#include "Calculateur.h"

namespace Ui {
    class Afficheur;
}

class Afficheur: public QMainWindow
{
    Q_OBJECT

private slots:
    void num0Pressed();
    void num1Pressed();
    void num2Pressed();
    void num3Pressed();
    void num4Pressed();
    void num5Pressed();
    void num6Pressed();
    void num7Pressed();
    void num8Pressed();
    void num9Pressed();
    void enterPressed();
    void spacePressed();

public:
    explicit Afficheur(QWidget *parent = 0);
    ~Afficheur();

private:
    Ui::Afficheur *ui;
    Calculateur c;
};

#endif // AFFICHEUR_H
