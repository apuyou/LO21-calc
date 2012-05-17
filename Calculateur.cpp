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
    //On test si l'objet string est vide, dans quel cas, on ne fait rien
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
    //Gestion des erreurs : on vérifie que la pile contient au moins deux éléments
    if(pile_m.size() < 2)
        throw Erreur("La pile ne contient pas assez d'elements");
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() + pile_m.pop());
}

void Calculateur::soustraction()
{
    //Gestion des erreurs : on vérifie que la pile contient au moins deux éléments
    if(pile_m.size() < 2)
        throw Erreur("La pile ne contient pas assez d'elements");
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() - pile_m.pop());
}

void Calculateur::multiplication()
{
    //Gestion des erreurs : on vérifie que la pile contient au moins deux éléments
    if(pile_m.size() < 2)
        throw Erreur("La pile ne contient pas assez d'elements");
    if(!pile_m.empty())
        pile_m.push(pile_m.pop() * pile_m.pop());
}

void Calculateur::division()
{
    //Gestion des erreurs : on vérifie que la pile contient au moins deux éléments
    if(pile_m.size() < 2)
        throw Erreur("La pile ne contient pas assez d'elements");
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

void Calculateur::swap(int x, int y)
{
    //Gestion des erreurs : on vérifie que la pile contient des éléments n°x et n°y
    if(pile_m.size() <= max(x,y) || x<0 || y<0)
        throw Erreur("Swap impossible : la pile ne contient pas les elements demandes");
    //Il faut modifier les valeurs des indices x et y à cause de la représentation de la pile utilisé (sommet en bas)
    x = pile_m.size()-1 - x;
    y = pile_m.size()-1 - y;
    float temp = pile_m[x];
    pile_m[x] = pile_m[y];
    pile_m[y] = temp;
}

void Calculateur::sum(int x)
{
    //Gestion des erreurs : on vérifie que la pile contient au moins x éléments
    if(pile_m.size() < x || x<0)
        throw Erreur("Sum impossible : la pile ne contient pas assez d'elements pour effectuer la somme");
    float res(0);
    for(int i=0; i<x; ++i)
        res += pile_m.pop();
    pile_m.push(res);
}

void Calculateur::mean(int x)
{
    //Gestion des erreurs : on vérifie que la pile contient au moins x éléments
    if(pile_m.size() < x || x<0)
        throw Erreur("Mean impossible : la pile ne contient pas assez d'elements pour effectuer la moyenne");
    float res(0);
    for(int i=0; i<x; ++i)
        res += pile_m.pop();
    res /= x;
    pile_m.push(res);
}

void Calculateur::clear()
{
    pile_m.clear();
}

void Calculateur::dup()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    float e(pile_m.pop());
    pile_m.push(e);
    pile_m.push(e);
}

void Calculateur::drop()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.pop();
}
