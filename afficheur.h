/**
 * \file Afficheur.h
 * \brief Contient la classe Afficheur
 * \author Vincent Meyer et Arthur Puyou
 * \version 0.1
 * \date 15 Mai 2012
 *
 * La classe Afficheur sert à afficher les données de la classe Calculateur. Elle gère
 * l'affichage de la fenêtre principale et hérite donc de QMainWindow.
 *
 */
#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QMainWindow>
#include <QActionGroup>
#include "Calculateur.h"
#include "onglet.h"

namespace Ui {
    class Afficheur;
}

/**
 * \class Afficheur
 * \brief Classe de la fenêtre principale, qui contient les onglets
 */
class Afficheur: public QMainWindow
{
    Q_OBJECT

public:
    /**
     * \fn Afficheur(QWidget *parent = 0)
     * \param parent : Parent de la classe auquel attacher l'afficheur
     * \brief Fonction : Créé une nouvelle instance de l'objet Afficheur
     */
    explicit Afficheur(QWidget *parent = 0);
    /**
     * \fn ~Afficheur()
     * \brief Fonction : Destruction d'un objet Afficheur
     */
    ~Afficheur();

private slots:
    /**
     * \brief Créé un nouvel onglet
     */
    void nouvelOnglet();
    /**
     * \brief Créé un nouvel onglet en recopiant l'onglet actuel
     */
    void nouvelOngletCopie();
    /**
     * \brief Ferme l'onglet actuel
     */
    void fermeOnglet();
    /**
     * \brief Masque le clavier
     */
    void clavierOff();
    /**
     * \brief Affiche seulement les opérateurs les plus simples
     */
    void clavierSimple();
    /**
     * \brief Affiche tous les opérateurs
     */
    void clavierEtendu();
    /**
     * \brief Appelle la méthode undo de l'onglet actif
     */
    void undo();
    /**
     * \brief Appelle la méthode redo de l'onglet actif
     */
    void redo();

private:
    Ui::Afficheur *ui;
    QActionGroup *clavierGroup;
};

#endif // AFFICHEUR_H
