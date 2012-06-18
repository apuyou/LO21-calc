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
#include <fstream>   //Utilisation de fichiers
#include "Exception.h"
#include <string>
#include <cstdlib>
#include <algorithm> //Fonctions min et max
#define _USE_MATH_DEFINES //Permet d'utiliser pi : M_PI
#include <cmath>
#include <QString>

/**
 * \enum Mode
 * \brief Mode permet de différencier les différents types de donées utilisés
 */
enum Mode {Entier, Reel, Fraction};

/**
 * \class Calculateur
 * \brief Classe principale de la calculatrice permettant de gérer une pile et effectuer les opérations
 */
class Calculateur{
private:
    QStack<float> pile_m; /*!< Pile de réelles permettant de stocker les résultats des opérations */
    QStack<float> pileImaginaire_m; /*!< Pile de réelles permettant de stocker la partie imaginaires des nombres complexes */
    bool radiant_m; /*!< Booléen égal à TRUE si le mode radian et activé et FALSE si le mode degré est activé */
    bool complexe_m; /*!< Booléen égal à TRUE si le mode complexe et activé et FALSE si le mode complexe est désactivé */
    Mode typeConstante_m; /*!< Variable de type Mode (énumération) permettant de définir le mode de constante */
    static unsigned int compteur; /*!< Variable statique contant le nombre d'instances de la classe Calculateur */
    unsigned int onglet; /*!< Variable contenant le numéro de l'onglet courant */
public:
    /**
     * \fn Calculateur()
     * \brief Fonction : Créer une nouvelle instance de l'objet Calculateur
     */
    Calculateur();
    /**
     * \fn Calculateur(const Calculateur& c)
     * \brief Fonction : Créer une nouvelle instance de l'objet Calculateur en copiant une instance existante
     */
    Calculateur(const Calculateur& c);
    /**
     * \fn Calculateur& operator=(const Calculateur& c)
     * \brief Fonction : Copie l'instance c du calculateur
     * \return Retourne une instance du Calculateur identique à c
     */
    Calculateur& operator=(const Calculateur& c);
    /**
     * \fn sauvegarderPiles()
     * \brief Fonction : Sauvegarde les piles de stockage dans des fichiers
     */
    void sauvegarderPiles();
    /**
     * \fn chargerPiles()
     * \brief Fonction : Charge les piles de stockage depuis les fichiers de sauvegarde
     */
    void chargerPiles();
    /**
     * \fn modeDegre()
     * \brief Fonction : Bascule le calculateur en mode degré
     */
    void modeDegre(){radiant_m = false;}
    /**
     * \fn modeRadiant()
     * \brief Fonction : Bascule le calculateur en mode radiant
     */
    void modeRadiant(){radiant_m = true;}
    /**
     * \fn modeEntier()
     * \brief Fonction : Bascule le calculateur en mode entier
     */
    void modeEntier();
    /**
     * \fn modeReel()
     * \brief Fonction : Bascule le calculateur en mode réel
     */
    void modeReel(){typeConstante_m = Reel;}
    /**
     * \fn modeFraction()
     * \brief Fonction : Bascule le calculateur en mode fraction
     */
    void modeFraction(){typeConstante_m = Fraction;}
    /**
     * \fn modeComplexe()
     * \brief Fonction : Bascule le calculateur en mode complexe et vide la pile de stockage
     */
    void modeComplexe();
    /**
     * \fn modeHorsComplexe()
     * \brief Fonction : Bascule le calculateur en mode hors complexe et vide les piles de stockage
     */
    void modeHorsComplexe();
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
     *
     * \param x : Entier contenant l'indice du premier élément
     * \param y : Entier contenant l'indice du deuxième élément
     */
    void swap(int x, int y);
    /**
     * \fn void sum(int x)
     * \brief Fonction : Somme les x premiers éléments de la pile
     *
     * \param x : Entier désignant le nombre d'éléments à sommer
     */
    void sum(int x);
    /**
     * \fn void mean(int x)
     * \brief Fonction : Effectue la moyenne des x premiers éléments de la pile
     *
     * \param x : Entier désignant le nombre d'éléments compris dans la moyenne
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
     * \fn void pow()
     * \brief Fonction : Dépile deux éléments a et b et effectue a^b
     */
    void pow();
    /**
     * \fn void mod()
     * \brief Fonction : Dépile deux éléments a et b et effectue a%b
     */
    void mod();
    /**
     * \fn void sign()
     * \brief Fonction : Inverse le signe du premier élément de la pile
     */
    void sign();
    /**
     * \fn void sin()
     * \brief Fonction : Effectue le sinus du premier élément de la pile
     */
    void sin();
    /**
     * \fn void cos()
     * \brief Fonction : Effectue le cosinus du premier élément de la pile
     */
    void cos();
    /**
     * \fn void tan()
     * \brief Fonction : Effectue la tangente du premier élément de la pile
     */
    void tan();
    /**
     * \fn void sinh()
     * \brief Fonction : Effectue le sinus hyperbolique du premier élément de la pile
     */
    void sinh();
    /**
     * \fn void cosh()
     * \brief Fonction : Effectue le cosinus hyperbolique du premier élément de la pile
     */
    void cosh();
    /**
     * \fn void tanh()
     * \brief Fonction : Effectue la tangente hyperbolique du premier élément de la pile
     */
    void tanh();
    /**
     * \fn void ln()
     * \brief Fonction : Effectue le logarithme népérien du premier élément de la pile
     */
    void ln();
    /**
     * \fn void log()
     * \brief Fonction : Effectue le logarithme décimal du premier élément de la pile
     */
    void log();
    /**
     * \fn void inv()
     * \brief Fonction : Calcul l'inverse du premier élément de la pile
     */
    void inv();
    /**
     * \fn void sqrt()
     * \brief Fonction : Calcul la racine carrée du premier élément de la pile
     */
    void sqrt();
    /**
     * \fn void sqr()
     * \brief Fonction : Calcul le carrée du premier élément de la pile
     */
    void sqr();
    /**
     * \fn void cube()
     * \brief Fonction : Calcul le cube du premier élément de la pile
     */
    void cube();
    /**
     * \fn void factorielle()
     * \brief Fonction : Calcul le factorielle du premier élément de la pile
     */
    void factorielle();
    /**
     * \fn void afficherPile(std::ostream& f=std::cout)
     * \brief Fonction : affiche le contenu de la pile dans un flux
     *
     * \param f flux dans lequel on ajoute le contenu de la pile
     */
    void afficherPile(std::ostream& f=std::cout);

    /**
     * \fn QString getTetePile()
     * \brief Fonction : renvoie la tete de la pile
     * \return Retourne l'élément tout en haut de la pile
     */
    QString getTetePile();
};

#endif // CALCULATEUR_H
