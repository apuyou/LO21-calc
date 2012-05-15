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

#include <QStack>
#include <iostream>
#include <string>
#include <cstdlib>

/**
 * \enum Mode
 * \brief Mode permet de diff�rencier les diff�rents types de don�es utilis�s
 */
enum Mode {Entier, Reel, Fraction, Complexe};

/**
 * \class Calculateur
 * \brief Classe principale de la calculatrice permettant de g�rer une pile et effectuer les op�rations
 */
class Calculateur{
private:
    QStack<float> pile_m; /*!< Pile de r�elles permettant de stocker les r�sultats des op�rations */
public:
    /**
     * \fn Calculateur()
     * \brief Fonction : Cr�er une nouvelle instance de l'objet Calculateur
     */
    Calculateur();
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
     * \fn void afficherPile(std::ostream& f=std::cout)
     * \brief Fonction : affiche le contenu de la pile dans un flux
     *
     * \param f flux dans lequel on ajoute le contenu de la pile
     */
    void afficherPile(std::ostream& f=std::cout);
};

#endif // CALCULATEUR_H
