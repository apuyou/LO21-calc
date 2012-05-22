#include "afficheur.h"
#include "ui_afficheur.h"

Afficheur::Afficheur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Afficheur)
{
    ui->setupUi(this);
}

Afficheur::~Afficheur()
{
    delete ui;
}
