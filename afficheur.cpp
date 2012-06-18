/**
 * \file afficheur.cpp
 * \brief Contient les méthodes de la classe Afficheur
 * \author Vincent Meyer et Arthur Puyou
 * \version 0.1
 * \date 15 Mai 2012
 *
 * La classe Afficheur sert à afficher les données de la classe Calculateur. Elle gère
 * l'affichage de la fenêtre principale et hérite donc de QMainWindow.
 *
 */

#include "afficheur.h"
#include "ui_afficheur.h"
#include "Calculateur.h"
#include <QActionGroup>

Afficheur::Afficheur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Afficheur)
{
    ui->setupUi(this);

    setWindowTitle(tr("calcul'utc"));

    // Menus
    connect(ui->actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->actionNouvel_onglet, SIGNAL(triggered()), this, SLOT(nouvelOnglet()));
    connect(ui->actionFermer_onglet, SIGNAL(triggered()), this, SLOT(fermeOnglet()));

    clavierGroup = new QActionGroup(this);
    clavierGroup->addAction(ui->actionPas_de_clavier);
    clavierGroup->addAction(ui->actionClavier_simple);
    clavierGroup->addAction(ui->actionClavier_etendu);

    ui->tabWidget->addTab(new onglet(this), QString("Onglet 1"));
    ui->tabWidget->setCurrentIndex(0);

}

Afficheur::~Afficheur()
{
    delete ui;
}


void Afficheur::nouvelOnglet(){
    int nbtab = ui->tabWidget->count();
    ui->tabWidget->addTab(new onglet(this), QString("Onglet %1").arg(QString::number(nbtab + 1)));
    ui->tabWidget->setCurrentIndex(nbtab);
}

void Afficheur::nouvelOngletCopie(){
    /*
    int nbtab = ui->tabWidget->count();
    int oldindex = ui->tabWidget->currentIndex();
    (onglet)ui->tabWidget->widget(0);
    onglet ancienonglet = (onglet)ui->tabWidget->widget(oldindex);
    Calculateur copie = ancienonglet.getCalculateur();
    */
    /*ui->tabWidget->addTab(new onglet(this), QString("Onglet %1").arg(QString::number(nbtab + 1)));
    ui->tabWidget->widget(nbtab)->setCalculateur(copie);*/
}

void Afficheur::fermeOnglet(){
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->removeTab(index);
}
