/**
 * \file Pile.h
 * \brief Contient la classe Pile
 * \author Vincent Meyer et Arthur Puyou
 * \version 0.1
 * \date 02 Mai 2012
 *
 * La classe Pile permet de gérer une pile d'objet quelconques.
 *
 */

#ifndef PILE_H
#define PILE_H

#include <iostream>
/**
 * \class Pile
 * \brief Classe permetant de gérer une pile d'objets quelconques
 */

class Pile{
private:
    float** tab; /*!< Tableau de pointeurs sur void, contient les objets de la pile */
    unsigned int n; /*!< Nombre d'éléments qui sont dans la pile */
    unsigned int max; /*!< Taille du tableau */
    /**
     * \fn bool pilePleine()
     * \brief Fonction : Tester si la pile est vide
     *
     * \return true si la pile est vide et false si la pile est non-vide
     */
    bool pilePleine();
public:
    /**
     * \fn Pile(unsigned int m=10)
     * \brief Fonction : Créer une nouvelle instance de l'objet Pile
     *
     * \param m taille initiale de la pile, optionnel
     */
    Pile(unsigned int m=10);
    /**
     * \fn Pile(const Pile& p)
     * \brief Fonction : Créer une nouvelle instance de l'objet Pile à partir d'une autre instance passé en paramètre
     *
     * \param p instance de pile à copier
     */
    Pile(const Pile& p);
    /**
     * \fn void operator=(const Pile& p)
     * \brief Fonction : copier une instance de l'objet Pile dans cette instance de l'objet Pile
     *
     * \param p instance de pile à copier
     */
    void operator=(const Pile& p);
    /**
     * \fn bool pileVide()
     * \brief Fonction : Tester si la pile est vide
     *
     * \return true si la pile est vide et false si la pile est non-vide
     */
    bool pileVide();
    /**
     * \fn void viderPile()
     * \brief Fonction : Vider la pile
     */
    void viderPile();
    /**
     * \fn void empiler(const void& obj)
     * \brief Fonction : Empiler un objet sur la pile
     *
     * \param référence const vers l'objet à empiler
     */
    void empiler(const float& obj);
    /**
     * \fn void& depiler()
     * \brief Fonction : Dépiler la pile et renvoyer l'objet dépilé
     *
     * \return référence vers l'objet dépilé
     */
    float& depiler();
    /**
     * \fn ~Pile()
     * \brief Fonction : destruction de l'objet pile
     */
    ~Pile();
};

#endif // PILE_H
