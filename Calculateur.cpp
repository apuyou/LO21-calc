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
#include <QString>

unsigned int Calculateur::compteur = 0;

Calculateur::Calculateur() : radiant_m(false), complexe_m(false), typeConstante_m(Reel)
{
    compteur++;
    onglet = compteur;
}

Calculateur::Calculateur(const Calculateur& c) : radiant_m(c.radiant_m), complexe_m(c.complexe_m), typeConstante_m(c.typeConstante_m)
{
    compteur++;
    onglet = compteur;
    //On copie les piles de c dans le Calculateur courant
    if(c.complexe_m){
        //On parcourt les piles simulatanément avec deux itérateurs pour ne pas dépiler
        QStack<float>::const_iterator reIt;
        QStack<float>::const_iterator imIt;
        imIt = c.pileImaginaire_m.begin();
        for(reIt = c.pile_m.begin(); reIt < c.pile_m.end() ; ++reIt){
            pile_m.push(*reIt);
            pileImaginaire_m.push(*imIt);
            imIt++;
        }
    }else{
    //On parcourt la pile avec un itérateur pour ne pas dépiler
    QStack<float>::const_iterator it;
    for(it = c.pile_m.begin(); it < c.pile_m.end() ; ++it)
        pile_m.push(*it);
    }
}

Calculateur& Calculateur::operator=(const Calculateur& c)
{
    if(this != &c){
        //On vide les piles
        pile_m.clear();
        pileImaginaire_m.clear();
        //On copie tous les modes du calculateur
        radiant_m = c.radiant_m;
        complexe_m = c.complexe_m;
        typeConstante_m = c.typeConstante_m;
        //On copie les piles de c dans le Calculateur courant
        if(c.complexe_m){
            //On parcourt les piles simulatanément avec deux itérateurs pour ne pas dépiler
            QStack<float>::const_iterator reIt;
            QStack<float>::const_iterator imIt;
            imIt = c.pileImaginaire_m.begin();
            for(reIt = c.pile_m.begin(); reIt < c.pile_m.end() ; ++reIt){
                pile_m.push(*reIt);
                pileImaginaire_m.push(*imIt);
                imIt++;
            }
        }else{
        //On parcourt la pile avec un itérateur pour ne pas dépiler
        QStack<float>::const_iterator it;
        for(it = c.pile_m.begin(); it < c.pile_m.end() ; ++it)
            pile_m.push(*it);
        }
    }
    return *this;
}

void Calculateur::sauvegarderPiles()
{
    //On crée une chaine de caractère contenant le chemin du fichier
    std::string nomFichier("pileStockage");
    nomFichier += static_cast<char>('0'+onglet);
    nomFichier += ".pile";
    //On ouvre le fichier en mode écriture
    std::ofstream fichier;
    fichier.open(nomFichier.c_str(), ios::out);
    //Gestion des erreurs : On test que le fichier soit ouvert correctement
    if(fichier.bad())
        throw Erreur("Ouverture du fichier " + nomFichier + " impoossible");
    //On stocke l'ensemble de la pile des réels dans le fichier
    QStack<float>::iterator it;
    for(it = pile_m.begin(); it < pile_m.end() ; ++it){
        fichier<<*it;
        if(it < pile_m.end()-1)
            fichier<<std::endl;
    }
    fichier.close();
    if(complexe_m){
        //On crée une chaine de caractère contenant le chemin du fichier
        std::string nomFichier("pileComplexes");
        nomFichier += static_cast<char>('0'+onglet);
        nomFichier += ".pile";
        //On ouvre le fichier pour la pile des complexes
        fichier.open(nomFichier.c_str(), ios::out);
        //Gestion des erreurs : On test que le fichier soit ouvert correctement
        if(fichier.bad())
            throw Erreur("Ouverture du fichier " + nomFichier + " impoossible");
        //On stocke l'ensemble de la pile des réels dans le fichier
        QStack<float>::iterator it;
        for(it = pileImaginaire_m.begin(); it < pileImaginaire_m.end() ; ++it){
            fichier<<*it;
            if(it < pileImaginaire_m.end()-1)
                fichier<<std::endl;
        }
        fichier.close();
    }
}

void Calculateur::chargerPiles()
{
    //On crée une chaine de caractère contenant le chemin du fichier
    std::string nomFichier("pileStockage");
    nomFichier += static_cast<char>('0'+onglet);
    nomFichier += ".pile";
    //On ouvre le fichier en mode lecture s'il existe
    ifstream fichier(nomFichier.c_str());
    if(fichier){
        //On insère les éléments du fichier dans la pile
        pile_m.clear();
        float nb;
        while(!fichier.eof()){
            fichier >> nb;
            pile_m.push(nb);
        }
        fichier.close();
        //On traite le cas du mode complexe
        if(complexe_m){
            //On crée une chaine de caractère contenant le chemin du fichier
            std::string nomFichier("pileComplexes");
            nomFichier += static_cast<char>('0'+onglet);
            nomFichier += ".pile";
            //On ouvre le fichier pour la pile des complexes
            fichier.open(nomFichier.c_str(), ios::in);
            //Gestion des erreurs : On test que le fichier soit ouvert correctement
            if(fichier.bad())
                throw Erreur("Ouverture du fichier " + nomFichier + " impoossible");
            //On insère les éléments du fichier dans la pile des complexes
            pileImaginaire_m.clear();
            while(!fichier.eof()){
                fichier >> nb;
                pileImaginaire_m.push(nb);
            }
            fichier.close();
        }
    }else return; //Gestion des erreurs : Si le fichier n'existe pas, il n'y a rien à charger
}

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

void Calculateur::modeComplexe()
{
    if(complexe_m)
        return;
    complexe_m = true;
    pile_m.clear();
}

void Calculateur::modeHorsComplexe()
{
    if(!complexe_m)
        return;
    complexe_m = false;
    pile_m.clear();
    pileImaginaire_m.clear();
}

void Calculateur::insererElement(const std::string &s)
{
    //On test si l'objet string est vide, dans quel cas, on ne fait rien
    if(s.empty())
        return;
    std::string op; // Contient une opérande
    std::string reOp; // Contient la partie réelle d'une opérande complexe
    //On utilise un itérateur pour parcourir l'objet string caractère par caractère
    std::string::const_iterator it;
    for (it=s.begin(); it < s.end(); ++it){
        if(*it == ' ' || *it == '+' || *it == '-' || *it == '*' || *it == '/'){ //Si on arrive à un espace ou à un opérateur => fin d'une opérande ou d'un opérateur
            if(!op.empty() || !reOp.empty()){//On vérifie que l'opérande ne soit pas vide
                //On ajoute l'opérande à la pile de stockage
                if(complexe_m){
                    //Gestion des erreurs : Si l'utilisateur rentre un réel en mode complexe, celui-ci est convertit en complexe à partie imaginaire nulle
                    if(reOp.empty()){
                        reOp = op;
                        op = '0';
                    }
                    pile_m.push(atof(reOp.c_str()));
                    reOp.clear();
                    //Gestion des erreurs : Si le caractère $ n'est pas suivit d'un nombre, la partie imaginaire du complexe est nulle
                    if(op.empty())
                        op = '0';
                    pileImaginaire_m.push(atof(op.c_str()));
                }else //On traite le cas du mode hors complexe
                    pile_m.push(atof(op.c_str()));
                op.clear();
            }
        }
        else if((*it >= '0' && *it <= '9') || *it =='.') //Si le caractère courant est un chiffre, on continue de dérouler l'objet string
            op += *it;
        else if(*it == '$'){
            //Gestion des erreurs : Si l'utilisateur tante de rentrer des complexes en dehors du mode complexe, on lève une exception
            if(!complexe_m)
                throw Erreur("Saisie impossible, la calculatrice n'est pas en mode complexe");
            //Gestion des erreurs : Si le caractère $ n'est pas précédé d'un nombre, la partie réelle du complexe est nulle
            if(op.empty())
                op = '0';
            reOp = op;
            op.clear();
        }
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
        case '!':
            factorielle();
            break;
        case 'C':
            if(*(it+1) == 'U') //Si la fonction est cube
                cube();
            else if(*(it+3) == 'H') //Si la fonction est cosh
                cosh();
            else if (*(it+2) == 'S') //Sinon la fonction est cos
                cos();
            break;
        case 'L':
            if(*(it+1) == 'N') //Si la fonction est ln
                ln();
            else if(*(it+1) == 'O') //Sinon la fonction est log
                log();
            break;
        case 'I':
            if(*(it+1) == 'N' && *(it+2) == 'V') //Si la fonction est inv
                inv();
            break;
        case 'M':
            if(*(it+1) == 'O') //Si la fonction est mod
                mod();
            break;
        case 'P':
            if(*(it+1) == 'O') //Si la fonction est pow
                pow();
            break;
        case 'S':
            if(*(it+2) == 'G') //Si la fonction est sign
                sign();
            else if(*(it+3) == 'H') //Si la fonction est sinh
                sinh();
            else if(*(it+2) == 'N') //Si la fonction est sin
                sin();
            else if(*(it+1) == 'Q' && *(it+3) == 'T') //Si la fonction est sqrt
                sqrt();
            else if(*(it+1) == 'Q') //Sinon la fonction est sqr
                sqr();
            break;
        case 'T':
            if(*(it+2) == 'N' && *(it+3) == 'H') //Si la fonction est tanh
                tanh();
            else if(*(it+2) == 'N') //Sinon la fonction est tan
                tan();
            break;
        default:
            break;
        }
    }
    if(!op.empty() || !reOp.empty()){//On vérifie qu'à la fin de la chaîne, l'opérande soit vide
        //On ajoute l'opérande à la pile de stockage
        if(complexe_m){
            //Gestion des erreurs : Si l'utilisateur rentre un réel en mode complexe, celui-ci est convertit en complexe à partie imaginaire nulle
            if(reOp.empty()){
                reOp = op;
                op = '0';
            }
            pile_m.push(atof(reOp.c_str()));
            reOp.clear();
            //Gestion des erreurs : Si le caractère $ n'est pas suivit d'un nombre, la partie imaginaire du complexe est nulle
            if(op.empty())
                op = '0';
            pileImaginaire_m.push(atof(op.c_str()));
        }
        else if(!op.empty())//On vérifie que l'opérande ne soit pas vide
            pile_m.push(atof(op.c_str()));
        op.clear();
    }
}

void Calculateur::addition()
{
    //Gestion des erreurs : on vérifie que la pile contient au moins deux éléments
    if(pile_m.size() < 2)
        throw Erreur("La pile ne contient pas assez d'elements");
    if(!pile_m.empty()){
        pile_m.push(pile_m.pop() + pile_m.pop());
        if(complexe_m)
            pileImaginaire_m.push(pileImaginaire_m.pop() + pileImaginaire_m.pop());
    }
}

void Calculateur::soustraction()
{
    //Gestion des erreurs : on vérifie que la pile contient au moins deux éléments
    if(pile_m.size() < 2)
        throw Erreur("La pile ne contient pas assez d'elements");
    if(!pile_m.empty()){
        pile_m.push(pile_m.pop() - pile_m.pop());
        if(complexe_m)
            pileImaginaire_m.push(pileImaginaire_m.pop() - pileImaginaire_m.pop());
    }
}

void Calculateur::multiplication()
{
    //Gestion des erreurs : on vérifie que la pile contient au moins deux éléments
    if(pile_m.size() < 2)
        throw Erreur("La pile ne contient pas assez d'elements");
    if(!pile_m.empty()){
        if(!complexe_m)
            pile_m.push(pile_m.pop() * pile_m.pop());
        else{
            float a(pile_m.pop());
            float b(pileImaginaire_m.pop());
            float c(pile_m.pop());
            float d(pileImaginaire_m.pop());
            //On insère dans les piles de stockage : (a + ib)(c + id) = (ac -bd) + i(ad + bc)
            pile_m.push(a*c - b*d);
            pileImaginaire_m.push(a*d + b*c);
        }
    }
}

void Calculateur::division()
{
    //Gestion des erreurs : on vérifie que la pile contient au moins deux éléments
    if(pile_m.size() < 2)
        throw Erreur("La pile ne contient pas assez d'elements");
    float res;
    if(!pile_m.empty()){
        if(!complexe_m){
            res = pile_m.pop() / pile_m.pop();
            if(typeConstante_m == Entier)
                res = std::floor(res);
            pile_m.push(res);
        }else{
            float a(pile_m.pop());
            float b(pileImaginaire_m.pop());
            float c(pile_m.pop());
            float d(pileImaginaire_m.pop());
            //On insère dans la variable res, la partie réelle de la division : (a + ib) / (c + id) = ((ac + bd) +i(bc - ad)) / (c² + d²)
            res = (a*c + b*d) / (c*c + d*d);
            //On modifie le résultat de la division en fonction du mode de constante
            if(typeConstante_m == Entier)
                res = std::floor(res);
            pile_m.push(res);
            //Ensuite on traite le cas de la partie imaginaire
            //On insère dans la variable res, la partie imaginaire de la division : (a + ib) / (c + id) = ((ac + bd) +i(bc - ad)) / (a² + b²)
            res = (b*c - a*d) / (c*c + d*d);
            //On modifie le résultat de la division en fonction du mode de constante
            if(typeConstante_m == Entier)
                res = std::floor(res);
            pileImaginaire_m.push(res);
        }
    }
}

void Calculateur::swap(int x, int y)
{
    //Gestion des erreurs : on vérifie que la pile contient des éléments n°x et n°y
    if(pile_m.size() <= max(x,y) || x<0 || y<0)
        throw Erreur("Swap impossible : la pile ne contient pas les elements demandes");
    //Il faut modifier les valeurs des indices x et y à cause de la représentation de la pile utilisé (sommet en bas)
    x = pile_m.size()-1 - x;
    y = pile_m.size()-1 - y;
    float temp(pile_m[x]);
    pile_m[x] = pile_m[y];
    pile_m[y] = temp;
    //On traite ensuite le cas particulier du mode complexe
    if(complexe_m){
        temp = pileImaginaire_m[x];
        pileImaginaire_m[x] = pileImaginaire_m[y];
        pileImaginaire_m[y] = temp;
    }
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
    //On traite ensuite le cas particulier du mode complexe
    if(complexe_m){
        res = 0;
        for(int i=0; i<x; ++i)
            res += pileImaginaire_m.pop();
        pileImaginaire_m.push(res);
    }
}

void Calculateur::mean(int x)
{
    //Gestion des erreurs : on vérifie que la pile contient au moins x éléments
    if(pile_m.size() < x || x<0)
        throw Erreur("Mean impossible : la pile ne contient pas assez d'elements pour effectuer la moyenne");
    float res(0);
    for(int i=0; i<x; ++i)
        res += pile_m.pop();
    pile_m.push(res / x);
    //On traite le cas du mode complexe
    if(complexe_m){
        res = 0;
        for(int i=0; i<x; ++i)
            res += pileImaginaire_m.pop();
        //On divise la partie imaginaire par x, car x est réel
        pileImaginaire_m.push(res / x);
    }
}

void Calculateur::clear()
{
    pile_m.clear();
    pileImaginaire_m.clear();
}

void Calculateur::dup()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(pile_m[pile_m.size()-1]);
    //On traite le cas du mode complexe
    if(complexe_m)
        pileImaginaire_m.push(pileImaginaire_m[pileImaginaire_m.size()-1]);
}

void Calculateur::drop()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.pop();
    //On traite le cas du mode complexe
    if(complexe_m)
        pileImaginaire_m.pop();
}

void Calculateur::pow()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
    //Gestion des erreurs : on vérifie que la pile contient au moins 2 éléments
    if(pile_m.size() < 2)
        throw Erreur("Pow impossible : la pile ne contient pas assez d'elements pour effectuer la puissance");
    pile_m.push(std::pow(pile_m.pop(), pile_m.pop()));
}

void Calculateur::mod()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
    //Gestion des erreurs : on vérifie que la pile contient au moins 2 éléments
    if(pile_m.size() < 2)
        throw Erreur("Mod impossible : la pile ne contient pas assez d'elements pour effectuer le modulo");
    //Gestion des erreurs : le modulo est une opération utilisable uniquement dans le mode entier
    if(typeConstante_m != Entier)
        throw Erreur("Mod impossible : le modulo n'est utilisable qu'en mode entier");
    pile_m.push(std::fmod(pile_m.pop(), pile_m.pop()));
}

void Calculateur::sign()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(-pile_m.pop());
    if(complexe_m)
        pileImaginaire_m.push(-pileImaginaire_m.pop());
}

void Calculateur::sin()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
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
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
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
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
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
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::sinh(pile_m.pop()));
}

void Calculateur::cosh()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::cosh(pile_m.pop()));
}

void Calculateur::tanh()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::tanh(pile_m.pop()));
}

void Calculateur::ln()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::log(pile_m.pop()));
}

void Calculateur::log()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(std::log10(pile_m.pop()));
}

void Calculateur::inv()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    pile_m.push(1);
    division();
}

void Calculateur::sqrt()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
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
    float a(pile_m.pop());
    if(!complexe_m)
        pile_m.push(a*a);
    else{
        float b(pileImaginaire_m.pop());
        //Si on est en mode complexe, on insère (a + ib)² = (a² - b²) + i(2ab)
        pile_m.push(a*a - b*b);
        pileImaginaire_m.push(2*a*b);
    }
}

void Calculateur::cube()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    float a(pile_m.pop());
    if(!complexe_m)
        pile_m.push(a*a*a);
    else{
        float b(pileImaginaire_m.pop());
        //Si on est en mode complexe, on insère (a + ib)^3 = (a^3 - 3ab²) + i(3a²b - b^3)
        pile_m.push(a*a*a -3*a*b*b);
        pileImaginaire_m.push(3*a*a*b - b*b*b);
    }
}

void Calculateur::factorielle()
{
    //Gestion des erreurs : on vérifie que le mode complexe est désactivé
    if(complexe_m)
        throw Erreur("Fonction non utilisable en mode complexe");
    //Gestion des erreurs : On vérifie que le mode de constante soit compatible avec la fonction
    if(typeConstante_m != Entier)
        throw Erreur("La fonction factorielle ne fonctionne que sur les entiers");
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

void Calculateur::afficherPile(std::ostream &f)
{
    if(complexe_m){
        //On parcourt les piles simulatanément avec deux itérateurs pour ne pas dépiler
        QStack<float>::iterator reIt;
        QStack<float>::iterator imIt;
        imIt =pileImaginaire_m.begin();
        for(reIt = pile_m.begin(); reIt < pile_m.end() ; ++reIt){
            f<<*reIt<<" + i"<<*imIt<<std::endl;
            imIt++;
        }
    }else{
    //On parcourt la pile avec un itérateur pour ne pas dépiler
    QStack<float>::iterator it;
    for(it = pile_m.begin(); it < pile_m.end() ; ++it)
        f<<*it<<std::endl;
    }
}

QStack<QString> Calculateur::getPile()
{
    QStack<QString> ret;
    if(complexe_m){
        //On parcourt les piles simulatanément avec deux itérateurs pour ne pas dépiler
        QStack<float>::iterator reIt;
        QStack<float>::iterator imIt;
        imIt =pileImaginaire_m.begin();
        for(reIt = pile_m.begin(); reIt < pile_m.end() ; ++reIt){
            ret.push(QString("%1$%2").arg(*reIt).arg(*imIt));
            imIt++;
        }
    }else{
    //On parcourt la pile avec un itérateur pour ne pas dépiler
    QStack<float>::iterator it;
    for(it = pile_m.begin(); it < pile_m.end() ; ++it)
        ret.push(QString("%1").arg(*it));
    }
   return ret;
}

QString Calculateur::getTetePile(){
    if(complexe_m)
        return QString::number(pile_m.last()) + "$" + QString::number(pileImaginaire_m.last());

    return QString::number(pile_m.last());
}

