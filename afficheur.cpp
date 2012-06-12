#include "afficheur.h"
#include "ui_afficheur.h"
#include "Calculateur.h"
#include <QActionGroup>

Afficheur::Afficheur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Afficheur)
{
    ui->setupUi(this);

    // Menus
    connect(ui->actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    clavierGroup = new QActionGroup(this);
    clavierGroup->addAction(ui->actionPas_de_clavier);
    clavierGroup->addAction(ui->actionClavier_simple);
    clavierGroup->addAction(ui->actionClavier_etendu);

    ui->tabWidget->addTab(new onglet(this), QString("Onglet 1"));
    ui->tabWidget->addTab(new onglet(this), QString("Onglet 2"));
    ui->tabWidget->setCurrentIndex(0);

}

Afficheur::~Afficheur()
{
    delete ui;
}
