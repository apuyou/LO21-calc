/**
 * \file Calculateur.cpp
 * \brief Contient les méthodes de la classe Calculateur
 * \author Vincent Meyer et Arthur Puyou
 * \version 0.1
 * \date 15 Mai 2012
 *
 * La classe Calculateur est la classe principale de la claculatrice. Elle gère la pile et effectue les opérations
 *
 */

#include "Calculateur.h"

Calculateur::Calculateur()
{}

void Calculateur::insererElement(const std::string &s)
{
    //On test si la pile est vide, dans quel cas, on ne fait rien
    if(s.empty())
        return;
    std::string op; // Contient un opérateur ou une opérande
    //On utilise un itérateur pour parcourir l'objet string caractère par caractère
    std::string::const_iterator it;
    for (it=s.begin(); it < s.end(); ++it){
        if(*it == ' ' || *it == '+' || *it == '-' || *it == '*' || *it == '/'){ //Si on arrive à un espace ou à un opérateur => fin d'une opérande ou d'un opérateur
            if(!op.empty())//On vérifie que l'opérande ne soit pas vide
                //On ajoute l'opérande à la pile de stockage
                pile_m.push(atof(op.c_str()));
            op.clear();
        }
        else if(*it >= '0' && *it <= '9') //Si le caractère courant est un chiffre, on continue de dérouler l'objet string
            op += *it;
        //Si le caractère est un opérateur, on effectue une opération
        switch (*it){
        case '+':
            addition();
            break;
        case '-':
            soustraction();
            break;
        case '*':
            multiplication();
            break;
        case '/':
            division();
            break;
        }
    }
}

void Calculateur::addition()
{
    //METTRE EN PLACE LA GESTION DES ERREURS : Moins de 2 éléments dans la pile
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() + pile_m.pop());
}

void Calculateur::soustraction()
{
    //METTRE EN PLACE LA GESTION DES ERREURS : Moins de 2 éléments dans la pile
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() - pile_m.pop());
}

void Calculateur::multiplication()
{
    //METTRE EN PLACE LA GESTION DES ERREURS : Moins de 2 éléments dans la pile
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() * pile_m.pop());
}

void Calculateur::division()
{
    //METTRE EN PLACE LA GESTION DES ERREURS : Moins de 2 éléments dans la pile
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() / pile_m.pop());
}

void Calculateur::afficherPile(std::ostream &f)
{
    //On parcourt la pile avec un itérateur pour ne pas dépiler
    QStack<float>::iterator it;
    for(it = pile_m.begin(); it < pile_m.end() ; ++it)
        std::cout<<*it<<std::endl;
}
