#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QMainWindow>

namespace Ui {
    class Afficheur;
}

class Afficheur: public QMainWindow
{
    Q_OBJECT
public:
    explicit Afficheur(QWidget *parent = 0);
    ~Afficheur();

private:
    Ui::Afficheur *ui;
};

#endif // AFFICHEUR_H
