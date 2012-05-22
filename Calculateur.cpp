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

Calculateur::Calculateur() : radiant_m(true), typeConstante_m(Entier)
{}

void Calculateur::modeEntier()
{
    if(typeConstante_m == Entier)
        return;
    typeConstante_m = Entier;
    //Pour transformer les éléments de la pile en entiers, on parcourt la pile avec un itérateur pour ne pas dépiler
    QStack<float>::iterator it;
    for(it = pile_m.begin(); it < pile_m.end() ; ++it)
        *it = std::floor(*it);
}

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
        else if((*it >= '0' && *it <= '9') || *it =='.') //Si le caractère courant est un chiffre, on continue de dérouler l'objet string
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
    if(!op.empty())//On vérifie qu'à la fin de la chaîne, l'opérande soit vide
        //On ajoute l'opérande à la pile de stockage
        pile_m.push(atof(op.c_str()));
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
    float res;
    if(!pile_m.empty())
        res = pile_m.pop() / pile_m.pop();
    //On modifie le résultat de la division en fonction du mode de constante
    if(typeConstante_m == Entier)
        res = std::floor(res);
    pile_m.push(res);
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

void Calculateur::pow()
{
    //Gestion des erreurs : on vérifie que la pile contient au moins 2 éléments
    if(pile_m.size() < 2)
        throw Erreur("Pow impossible : la pile ne contient pas assez d'elements pour effectuer la puissance");
    pile_m.push(std::pow(pile_m.pop(), pile_m.pop()));
}

void Calculateur::mod()
{
    //Gestion des erreurs : on vérifie que la pile contient au moins 2 éléments
    if(pile_m.size() < 2)
        throw Erreur("Mod impossible : la pile ne contient pas assez d'elements pour effectuer le modulo");
    //Gestion des erreurs : le modulo est une opération utilisable uniquement dans le mode entier
    if(typeConstante_m != Entier)
        return;
    pile_m.push(std::fmod(pile_m.pop(), pile_m.pop()));
}

void Calculateur::sign()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(-pile_m.pop());
}

void Calculateur::sin()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    //On différencie deux cas : mode radiant ou degré
    if(radiant_m)
        pile_m.push(std::sin(pile_m.pop()));
    else
         pile_m.push(std::sin(M_PI*pile_m.pop()/180));
}

void Calculateur::cos()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    //On différencie deux cas : mode radiant ou degré
    if(radiant_m)
        pile_m.push(std::cos(pile_m.pop()));
    else
         pile_m.push(std::cos(M_PI*pile_m.pop()/180));
}

void Calculateur::tan()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    //On différencie deux cas : mode radiant ou degré
    if(radiant_m)
        pile_m.push(std::tan(pile_m.pop()));
    else
         pile_m.push(std::tan(M_PI*pile_m.pop()/180));
}

void Calculateur::sinh()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::sinh(pile_m.pop()));
}

void Calculateur::cosh()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::cosh(pile_m.pop()));
}

void Calculateur::tanh()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::tanh(pile_m.pop()));
}

void Calculateur::ln()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::log(pile_m.pop()));
}

void Calculateur::log()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::log10(pile_m.pop()));
}

void Calculateur::inv()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(1/(pile_m.pop()));
}

void Calculateur::sqrt()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::sqrt(pile_m.pop()));
}

void Calculateur::sqr()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    float temp(pile_m.pop());
    pile_m.push(temp*temp);
}

void Calculateur::cube()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    float temp(pile_m.pop());
    pile_m.push(temp*temp*temp);
}

void Calculateur::factorielle()
{
    //Gestion des erreurs : On vérifie que le mode de constante soit compatible avec la fonction
    if(typeConstante_m != Entier)
        return;
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    float valeur(std::floor(pile_m.pop()));
    //Gestion des erreurs : On vérifie que la variable est valide;
    if(valeur < 0){
        pile_m.push(valeur);
        throw Erreur("Factorielle impossible, la factorielle d'un nombre negatif n'est pas defini");
    }
    //Calcul du factoriel :
    float res(1);
    for(int i = valeur; i > 1; --i)
        res *= i;
    pile_m.push(res);
}

float PGCD(float n, float d)
{
    //Gestion des erreurs : pour éviter les problèmes d'utilisation d'entiers avec la fonction fmod, on convertie les float en int
    int a(static_cast<int> (n));
    int b(static_cast<int> (d));
    int c;
    //Gestion des erreurs : on s'assure que a est plus grand que b
    if(b > a){
        c = b;
        b = a;
        a = b;
    }
    while(b!=0){
        c = a%b;
        a = b;
        b = c;
    }
    return static_cast<float> (a);
}

float getFraction(float a, float* denominateur)
{
    //On commence par séparer la partie entière de la partie décimale
    float res(0);
    float P(0);
    float intpart(0);
    float fractpart(std::modf(a, &intpart));
    fractpart *= 1000000;
    //Il faut distinguer 2 cas : le réel a a une partie décimal finie ou infinie.
    //Si le reel a a une partie décimal finie
    if(std::fmod(fractpart, 10) == 0){
        res = fractpart + 1000000*intpart;
        //On simplifie la fraction
        P = PGCD(res, 1000000);
        res /= P;
        *denominateur = 1000000 / P;
    }else //Si le reel a a une partie décimal infinie
    {
        res = fractpart + 999999*intpart;
        //On simplifie la fraction
        P = PGCD(res, 999999);
        res /= P;
        *denominateur = 999999 / P;
    }
    //On renvoie le numérateur et le dénominateur
    return res;
}
