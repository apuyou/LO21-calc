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
#include "onglet.h"

Afficheur::Afficheur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Afficheur)
{
    ui->setupUi(this);

    setWindowTitle(tr("calcul'utc"));
    clavierGroup = new QActionGroup(this);
    clavierGroup->addAction(ui->actionPas_de_clavier);
    clavierGroup->addAction(ui->actionClavier_simple);
    clavierGroup->addAction(ui->actionClavier_etendu);

    onglet *o = new onglet(this);
    ui->tabWidget->addTab(o, QString("Onglet 1"));
    ui->tabWidget->setCurrentIndex(0);
    o->chargerPiles();

    // Menus
    connect(ui->actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->actionNouvel_onglet, SIGNAL(triggered()), this, SLOT(nouvelOnglet()));
    connect(ui->actionNouvel_onglet_copie, SIGNAL(triggered()), this, SLOT(nouvelOngletCopie()));
    connect(ui->actionFermer_onglet, SIGNAL(triggered()), this, SLOT(fermeOnglet()));
    connect(ui->actionPas_de_clavier, SIGNAL(triggered()), this, SLOT(clavierOff()));
    connect(ui->actionClavier_simple, SIGNAL(triggered()), this, SLOT(clavierSimple()));
    connect(ui->actionClavier_etendu, SIGNAL(triggered()), this, SLOT(clavierEtendu()));
    connect(ui->actionAnnuler, SIGNAL(triggered()), this, SLOT(undo()));
    connect(ui->actionRetablir, SIGNAL(triggered()), this, SLOT(redo()));
}

Afficheur::~Afficheur()
{
    onglet *o = (onglet*) ui->tabWidget->currentWidget();
    o->sauverPiles();
    delete ui;
}


void Afficheur::nouvelOnglet(){
    int nbtab = ui->tabWidget->count();
    ui->tabWidget->addTab(new onglet(this), QString("Onglet %1").arg(QString::number(nbtab + 1)));
    ui->tabWidget->setCurrentIndex(nbtab);
}

void Afficheur::nouvelOngletCopie(){    
    int nbtab = ui->tabWidget->count();
    int oldindex = ui->tabWidget->currentIndex();

    // Récupération de l'ancien calculateur
    onglet *ancienOnglet = (onglet*) ui->tabWidget->widget(oldindex);
    Calculateur copie = ancienOnglet->getCalculateur();

    // Création du nouvel onglet et copie du calculateur
    onglet *newOnglet = new onglet(this);
    newOnglet->setCalculateur(copie);
    ui->tabWidget->addTab(newOnglet, QString("Onglet %1").arg(QString::number(nbtab + 1)));

    // Copie du contenu du listWidget
    for(int i=0;i<ancienOnglet->listWidget->count();i++){
        QListWidgetItem *item = ancienOnglet->listWidget->item(i)->clone();
        newOnglet->listWidget->addItem(item);
    }

    // Bascule sur le nouvel onglet
    ui->tabWidget->setCurrentIndex(nbtab);
}

void Afficheur::fermeOnglet(){
    if(ui->tabWidget->count() > 1){
        int index = ui->tabWidget->currentIndex();
        ui->tabWidget->removeTab(index);
    }
}

void Afficheur::clavierOff(){
    onglet *o = (onglet*) ui->tabWidget->currentWidget();
    o->clavierSimple->hide();
    o->clavierEtendu->hide();
}

void Afficheur::clavierSimple(){
    onglet *o = (onglet*) ui->tabWidget->currentWidget();
    o->clavierSimple->show();
    o->clavierEtendu->hide();
}

void Afficheur::clavierEtendu(){
    onglet *o = (onglet*) ui->tabWidget->currentWidget();
    o->clavierSimple->show();
    o->clavierEtendu->show();
}

void Afficheur::undo(){
    onglet *o = (onglet*) ui->tabWidget->currentWidget();
    o->undo();
}

void Afficheur::redo(){
    onglet *o = (onglet*) ui->tabWidget->currentWidget();
    o->redo();
}
