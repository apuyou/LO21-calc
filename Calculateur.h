/**
 * \file Calculateur.h
 * \brief Contient la classe Calculateur
 * \author Vincent Meyer et Arthur Puyou
 * \version 0.1
 * \date 15 Mai 2012
 *
 * La classe Calculateur est la classe principale de la claculatrice. Elle g�re la pile et effectue les op�rations
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
 * \brief Mode permet de diff�rencier les diff�rents types de don�es utilis�s
 */
enum Mode {Entier, Reel, Fraction};

/**
 * \class Calculateur
 * \brief Classe principale de la calculatrice permettant de g�rer une pile et effectuer les op�rations
 */
class Calculateur{
private:
    QStack<float> pile_m; /*!< Pile de r�elles permettant de stocker les r�sultats des op�rations */
    QStack<float> pileImaginaire_m; /*!< Pile de r�elles permettant de stocker la partie imaginaires des nombres complexes */
    bool radiant_m; /*!< Bool�en �gal � TRUE si le mode radian et activ� et FALSE si le mode degr� est activ� */
    bool complexe_m; /*!< Bool�en �gal � TRUE si le mode complexe et activ� et FALSE si le mode complexe est d�sactiv� */
    Mode typeConstante_m; /*!< Variable de type Mode (�num�ration) permettant de d�finir le mode de constante */
    static unsigned int compteur; /*!< Variable statique contant le nombre d'instances de la classe Calculateur */
    unsigned int onglet; /*!< Variable contenant le num�ro de l'onglet courant */
public:
    /**
     * \fn Calculateur()
     * \brief Fonction : Cr�er une nouvelle instance de l'objet Calculateur
     */
    Calculateur();
    /**
     * \fn Calculateur(const Calculateur& c)
     * \brief Fonction : Cr�er une nouvelle instance de l'objet Calculateur en copiant une instance existante
     */
    Calculateur(const Calculateur& c);
    /**
     * \fn Calculateur& operator=(const Calculateur& c)
     * \brief Fonction : Copie l'instance c du calculateur
     * \return Retourne une instance du Calculateur identique � c
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
     * \brief Fonction : Bascule le calculateur en mode degr�
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
     * \brief Fonction : Bascule le calculateur en mode r�el
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
     * \brief Fonction : d�composer un objet string en une suite d'op�randes et d'op�rateurs, ins�re les op�randes dans la pile de stockage, puis lance les op�rations correspondant aux op�rateurs
     *
     * \param s cha�ne de caract�re contenant l'expression � �valuer et � ins�rer dans la pile
     */
    void insererElement(const std::string& s);
    /**
     * \fn void addition()
     * \brief Fonction : D�pile deux �l�ments de la pile et effectue une addition avant d'ins�rer le r�sultat dans la pile
     */
    void addition();
    /**
     * \fn void soustraction()
     * \brief Fonction : D�pile deux �l�ments de la pile et effectue une soustraction avant d'ins�rer le r�sultat dans la pile
     */
    void soustraction();
    /**
     * \fn void multiplication()
     * \brief Fonction : D�pile deux �l�ments de la pile et effectue une multiplication avant d'ins�rer le r�sultat dans la pile
     */
    void multiplication();
    /**
     * \fn void division()
     * \brief Fonction : D�pile deux �l�ments de la pile et effectue une division avant d'ins�rer le r�sultat dans la pile
     */
    void division();
    /**
     * \fn void swap(int x, int y)
     * \brief Fonction : Inverse le x�me �l�ment de la pile avec le y�me
     *
     * \param x : Entier contenant l'indice du premier �l�ment
     * \param y : Entier contenant l'indice du deuxi�me �l�ment
     */
    void swap(int x, int y);
    /**
     * \fn void sum(int x)
     * \brief Fonction : Somme les x premiers �l�ments de la pile
     *
     * \param x : Entier d�signant le nombre d'�l�ments � sommer
     */
    void sum(int x);
    /**
     * \fn void mean(int x)
     * \brief Fonction : Effectue la moyenne des x premiers �l�ments de la pile
     *
     * \param x : Entier d�signant le nombre d'�l�ments compris dans la moyenne
     */
    void mean(int x);
    /**
     * \fn void clear()
     * \brief Fonction : Vide la pile
     */
    void clear();
    /**
     * \fn void dup()
     * \brief Fonction : Duplique le premier �l�ment de la pile
     */
    void dup();
    /**
     * \fn void drop()
     * \brief Fonction : Supprime le premier �l�ment de la pile
     */
    void drop();
    /**
     * \fn void pow()
     * \brief Fonction : D�pile deux �l�ments a et b et effectue a^b
     */
    void pow();
    /**
     * \fn void mod()
     * \brief Fonction : D�pile deux �l�ments a et b et effectue a%b
     */
    void mod();
    /**
     * \fn void sign()
     * \brief Fonction : Inverse le signe du premier �l�ment de la pile
     */
    void sign();
    /**
     * \fn void sin()
     * \brief Fonction : Effectue le sinus du premier �l�ment de la pile
     */
    void sin();
    /**
     * \fn void cos()
     * \brief Fonction : Effectue le cosinus du premier �l�ment de la pile
     */
    void cos();
    /**
     * \fn void tan()
     * \brief Fonction : Effectue la tangente du premier �l�ment de la pile
     */
    void tan();
    /**
     * \fn void sinh()
     * \brief Fonction : Effectue le sinus hyperbolique du premier �l�ment de la pile
     */
    void sinh();
    /**
     * \fn void cosh()
     * \brief Fonction : Effectue le cosinus hyperbolique du premier �l�ment de la pile
     */
    void cosh();
    /**
     * \fn void tanh()
     * \brief Fonction : Effectue la tangente hyperbolique du premier �l�ment de la pile
     */
    void tanh();
    /**
     * \fn void ln()
     * \brief Fonction : Effectue le logarithme n�p�rien du premier �l�ment de la pile
     */
    void ln();
    /**
     * \fn void log()
     * \brief Fonction : Effectue le logarithme d�cimal du premier �l�ment de la pile
     */
    void log();
    /**
     * \fn void inv()
     * \brief Fonction : Calcul l'inverse du premier �l�ment de la pile
     */
    void inv();
    /**
     * \fn void sqrt()
     * \brief Fonction : Calcul la racine carr�e du premier �l�ment de la pile
     */
    void sqrt();
    /**
     * \fn void sqr()
     * \brief Fonction : Calcul le carr�e du premier �l�ment de la pile
     */
    void sqr();
    /**
     * \fn void cube()
     * \brief Fonction : Calcul le cube du premier �l�ment de la pile
     */
    void cube();
    /**
     * \fn void factorielle()
     * \brief Fonction : Calcul le factorielle du premier �l�ment de la pile
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
     * \return Retourne l'�l�ment tout en haut de la pile
     */
    QString getTetePile();
};

#endif // CALCULATEUR_H
