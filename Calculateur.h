/**
 * \file Calculateur.h
 * \brief Contient la classe Calculateur
 * \author Vincent Meyer et Arthur Puyou
 * \version 0.1
 * \date 15 Mai 2012
 *
 * La classe Calculateur est la classe principale de la claculatrice. Elle gère la pile et effectue les opérations
 *
 */

#ifndef CALCULATEUR_H
#define CALCULATEUR_H

#include <QStack>    //Utlisation d'une pile QStack
#include <iostream>
#include "Exception.h"
#include <string>
#include <cstdlib>
#include <algorithm> //Fonctions min et max

/**
 * \enum Mode
 * \brief Mode permet de différencier les différents types de donées utilisés
 */
enum Mode {Entier, Reel, Fraction, Complexe};

/**
 * \class Calculateur
 * \brief Classe principale de la calculatrice permettant de gérer une pile et effectuer les opérations
 */
class Calculateur{
private:
    QStack<float> pile_m; /*!< Pile de réelles permettant de stocker les résultats des opérations */
public:
    /**
     * \fn Calculateur()
     * \brief Fonction : Créer une nouvelle instance de l'objet Calculateur
     */
    Calculateur();
    /**
     * \fn void insererElement(const std::string& s)
     * \brief Fonction : décomposer un objet string en une suite d'opérandes et d'opérateurs, insère les opérandes dans la pile de stockage, puis lance les opérations correspondant aux opérateurs
     *
     * \param s chaîne de caractère contenant l'expression à évaluer et à insérer dans la pile
     */
    void insererElement(const std::string& s);
    /**
     * \fn void addition()
     * \brief Fonction : Dépile deux éléments de la pile et effectue une addition avant d'insérer le résultat dans la pile
     */
    void addition();
    /**
     * \fn void soustraction()
     * \brief Fonction : Dépile deux éléments de la pile et effectue une soustraction avant d'insérer le résultat dans la pile
     */
    void soustraction();
    /**
     * \fn void multiplication()
     * \brief Fonction : Dépile deux éléments de la pile et effectue une multiplication avant d'insérer le résultat dans la pile
     */
    void multiplication();
    /**
     * \fn void division()
     * \brief Fonction : Dépile deux éléments de la pile et effectue une division avant d'insérer le résultat dans la pile
     */
    void division();
    /**
     * \fn void swap(int x, int y)
     * \brief Fonction : Inverse le xème élément de la pile avec le yème
     */
    void swap(int x, int y);
    /**
     * \fn void sum(int x)
     * \brief Fonction : Somme les x premiers éléments de la pile
     */
    void sum(int x);
    /**
     * \fn void mean(int x)
     * \brief Fonction : Effectue la moyenne des x premiers éléments de la pile
     */
    void mean(int x);
    /**
     * \fn void clear()
     * \brief Fonction : Vide la pile
     */
    void clear();
    /**
     * \fn void dup()
     * \brief Fonction : Duplique le premier élément de la pile
     */
    void dup();
    /**
     * \fn void drop()
     * \brief Fonction : Supprime le premier élément de la pile
     */
    void drop();
    /**
     * \fn void afficherPile(std::ostream& f=std::cout)
     * \brief Fonction : affiche le contenu de la pile dans un flux
     *
     * \param f flux dans lequel on ajoute le contenu de la pile
     */
    void afficherPile(std::ostream& f=std::cout);
};

#endif // CALCULATEUR_H
