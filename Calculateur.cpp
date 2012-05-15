/**
 * \file Calculateur.cpp
 * \brief Contient les m�thodes de la classe Calculateur
 * \author Vincent Meyer et Arthur Puyou
 * \version 0.1
 * \date 15 Mai 2012
 *
 * La classe Calculateur est la classe principale de la claculatrice. Elle g�re la pile et effectue les op�rations
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
    std::string op; // Contient un op�rateur ou une op�rande
    //On utilise un it�rateur pour parcourir l'objet string caract�re par caract�re
    std::string::const_iterator it;
    for (it=s.begin(); it < s.end(); ++it){
        if(*it == ' ' || *it == '+' || *it == '-' || *it == '*' || *it == '/'){ //Si on arrive � un espace ou � un op�rateur => fin d'une op�rande ou d'un op�rateur
            if(!op.empty())//On v�rifie que l'op�rande ne soit pas vide
                //On ajoute l'op�rande � la pile de stockage
                pile_m.push(atof(op.c_str()));
            op.clear();
        }
        else if(*it >= '0' && *it <= '9') //Si le caract�re courant est un chiffre, on continue de d�rouler l'objet string
            op += *it;
        //Si le caract�re est un op�rateur, on effectue une op�ration
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
    //METTRE EN PLACE LA GESTION DES ERREURS : Moins de 2 �l�ments dans la pile
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() + pile_m.pop());
}

void Calculateur::soustraction()
{
    //METTRE EN PLACE LA GESTION DES ERREURS : Moins de 2 �l�ments dans la pile
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() - pile_m.pop());
}

void Calculateur::multiplication()
{
    //METTRE EN PLACE LA GESTION DES ERREURS : Moins de 2 �l�ments dans la pile
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() * pile_m.pop());
}

void Calculateur::division()
{
    //METTRE EN PLACE LA GESTION DES ERREURS : Moins de 2 �l�ments dans la pile
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() / pile_m.pop());
}

void Calculateur::afficherPile(std::ostream &f)
{
    //On parcourt la pile avec un it�rateur pour ne pas d�piler
    QStack<float>::iterator it;
    for(it = pile_m.begin(); it < pile_m.end() ; ++it)
        std::cout<<*it<<std::endl;
}
