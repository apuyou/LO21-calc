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

unsigned int Calculateur::compteur = 0;

Calculateur::Calculateur() : radiant_m(true), complexe_m(false), typeConstante_m(Reel)
{
    compteur++;
    onglet = compteur;
}

void Calculateur::sauvegarderPiles()
{
    //On cr�e une chaine de caract�re contenant le chemin du fichier
    std::string nomFichier("pileStockage");
    nomFichier += static_cast<char>('0'+onglet);
    nomFichier += ".pile";
    //On ouvre le fichier en mode �criture
    std::ofstream fichier;
    fichier.open(nomFichier.c_str(), ios::out);
    //Gestion des erreurs : On test que le fichier soit ouvert correctement
    if(fichier.bad())
        throw Erreur("Ouverture du fichier " + nomFichier + " impoossible");
    //On stocke l'ensemble de la pile des r�els dans le fichier
    QStack<float>::iterator it;
    for(it = pile_m.begin(); it < pile_m.end() ; ++it)
        fichier<<*it<<std::endl;
    fichier.close();
    if(complexe_m){
        //On cr�e une chaine de caract�re contenant le chemin du fichier
        std::string nomFichier("pileComplexes");
        nomFichier += static_cast<char>('0'+onglet);
        nomFichier += ".pile";
        //On ouvre le fichier pour la pile des complexes
        fichier.open(nomFichier.c_str(), ios::out);
        //Gestion des erreurs : On test que le fichier soit ouvert correctement
        if(fichier.bad())
            throw Erreur("Ouverture du fichier " + nomFichier + " impoossible");
        //On stocke l'ensemble de la pile des r�els dans le fichier
        QStack<float>::iterator it;
        for(it = pileImaginaire_m.begin(); it < pileImaginaire_m.end() ; ++it)
            fichier<<*it<<std::endl;
        fichier.close();
    }
}

void Calculateur::chargerPiles()
{
    //On cr�e une chaine de caract�re contenant le chemin du fichier
    std::string nomFichier("pileStockage");
    nomFichier += static_cast<char>('0'+onglet);
    nomFichier += ".pile";
    //On ouvre le fichier en mode lecture s'il existe
    ifstream fichier(nomFichier.c_str());
    if(fichier){
        //On ins�re les �l�ments du fichier dans la pile
        pile_m.clear();
        float nb;
        while(!fichier.eof()){
            fichier >> nb;
            pile_m.push(nb);
        }
        fichier.close();
        //On traite le cas du mode complexe
        if(complexe_m){
            //On cr�e une chaine de caract�re contenant le chemin du fichier
            std::string nomFichier("pileComplexes");
            nomFichier += static_cast<char>('0'+onglet);
            nomFichier += ".pile";
            //On ouvre le fichier pour la pile des complexes
            fichier.open(nomFichier.c_str(), ios::in);
            //Gestion des erreurs : On test que le fichier soit ouvert correctement
            if(fichier.bad())
                throw Erreur("Ouverture du fichier " + nomFichier + " impoossible");
            //On ins�re les �l�ments du fichier dans la pile des complexes
            pileImaginaire_m.clear();
            while(!fichier.eof()){
                fichier >> nb;
                pileImaginaire_m.push(nb);
            }
            fichier.close();
        }
    }else return; //Gestion des erreurs : Si le fichier n'existe pas, il n'y a rien � charger
}

void Calculateur::modeEntier()
{
    if(typeConstante_m == Entier)
        return;
    typeConstante_m = Entier;
    //Pour transformer les �l�ments de la pile en entiers, on parcourt la pile avec un it�rateur pour ne pas d�piler
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
    std::string op; // Contient une op�rande
    std::string reOp; // Contient la partie r�elle d'une op�rande complexe
    //On utilise un it�rateur pour parcourir l'objet string caract�re par caract�re
    std::string::const_iterator it;
    for (it=s.begin(); it < s.end(); ++it){
        if(*it == ' ' || *it == '+' || *it == '-' || *it == '*' || *it == '/'){ //Si on arrive � un espace ou � un op�rateur => fin d'une op�rande ou d'un op�rateur
            if(!op.empty() || !reOp.empty()){//On v�rifie que l'op�rande ne soit pas vide
                //On ajoute l'op�rande � la pile de stockage
                if(complexe_m){
                    //Gestion des erreurs : Si l'utilisateur rentre un r�el en mode complexe, celui-ci est convertit en complexe � partie imaginaire nulle
                    if(reOp.empty()){
                        reOp = op;
                        op = '0';
                    }
                    pile_m.push(atof(reOp.c_str()));
                    reOp.clear();
                    //Gestion des erreurs : Si le caract�re $ n'est pas suivit d'un nombre, la partie imaginaire du complexe est nulle
                    if(op.empty())
                        op = '0';
                    pileImaginaire_m.push(atof(op.c_str()));
                }else //On traite le cas du mode hors complexe
                    pile_m.push(atof(op.c_str()));
                op.clear();
            }
        }
        else if((*it >= '0' && *it <= '9') || *it =='.') //Si le caract�re courant est un chiffre, on continue de d�rouler l'objet string
            op += *it;
        else if(*it == '$'){
            //Gestion des erreurs : Si l'utilisateur tante de rentrer des complexes en dehors du mode complexe, on l�ve une exception
            if(!complexe_m)
                throw Erreur("Saisie impossible, la calculatrice n'est pas en mode complexe");
            //Gestion des erreurs : Si le caract�re $ n'est pas pr�c�d� d'un nombre, la partie r�elle du complexe est nulle
            if(op.empty())
                op = '0';
            reOp = op;
            op.clear();
        }
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
    if(!op.empty() || !reOp.empty())//On v�rifie qu'� la fin de la cha�ne, l'op�rande soit vide
        //On ajoute l'op�rande � la pile de stockage
        if(complexe_m){
            //Gestion des erreurs : Si l'utilisateur rentre un r�el en mode complexe, celui-ci est convertit en complexe � partie imaginaire nulle
            if(reOp.empty()){
                reOp = op;
                op = '0';
            }
            pile_m.push(atof(reOp.c_str()));
            reOp.clear();
            //Gestion des erreurs : Si le caract�re $ n'est pas suivit d'un nombre, la partie imaginaire du complexe est nulle
            if(op.empty())
                op = '0';
            pileImaginaire_m.push(atof(op.c_str()));
        }
        else if(!op.empty())//On v�rifie que l'op�rande ne soit pas vide
            pile_m.push(atof(op.c_str()));
        op.clear();
}

void Calculateur::addition()
{
    //Gestion des erreurs : on v�rifie que la pile contient au moins deux �l�ments
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
    //Gestion des erreurs : on v�rifie que la pile contient au moins deux �l�ments
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
    //Gestion des erreurs : on v�rifie que la pile contient au moins deux �l�ments
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
            //On ins�re dans les piles de stockage : (a + ib)(c + id) = (ac -bd) + i(ad + bc)
            pile_m.push(a*c - b*d);
            pileImaginaire_m.push(a*d + b*c);
        }
    }
}

void Calculateur::division()
{
    //Gestion des erreurs : on v�rifie que la pile contient au moins deux �l�ments
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
            //On ins�re dans la variable res, la partie r�elle de la division : (a + ib) / (c + id) = ((ac + bd) +i(bc - ad)) / (c� + d�)
            res = (a*c + b*d) / (c*c + d*d);
            //On modifie le r�sultat de la division en fonction du mode de constante
            if(typeConstante_m == Entier)
                res = std::floor(res);
            pile_m.push(res);
            //Ensuite on traite le cas de la partie imaginaire
            //On ins�re dans la variable res, la partie imaginaire de la division : (a + ib) / (c + id) = ((ac + bd) +i(bc - ad)) / (a� + b�)
            res = (b*c - a*d) / (c*c + d*d);
            //On modifie le r�sultat de la division en fonction du mode de constante
            if(typeConstante_m == Entier)
                res = std::floor(res);
            pileImaginaire_m.push(res);
        }
    }
}

void Calculateur::swap(int x, int y)
{
    //Gestion des erreurs : on v�rifie que la pile contient des �l�ments n�x et n�y
    if(pile_m.size() <= max(x,y) || x<0 || y<0)
        throw Erreur("Swap impossible : la pile ne contient pas les elements demandes");
    //Il faut modifier les valeurs des indices x et y � cause de la repr�sentation de la pile utilis� (sommet en bas)
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
    //Gestion des erreurs : on v�rifie que la pile contient au moins x �l�ments
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
    //Gestion des erreurs : on v�rifie que la pile contient au moins x �l�ments
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
        //On divise la partie imaginaire par x, car x est r�el
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
    //Gestion des erreurs : on v�rifie que la pile contient au moins 2 �l�ments
    if(pile_m.size() < 2)
        throw Erreur("Pow impossible : la pile ne contient pas assez d'elements pour effectuer la puissance");
    pile_m.push(std::pow(pile_m.pop(), pile_m.pop()));
}

void Calculateur::mod()
{
    //Gestion des erreurs : on v�rifie que la pile contient au moins 2 �l�ments
    if(pile_m.size() < 2)
        throw Erreur("Mod impossible : la pile ne contient pas assez d'elements pour effectuer le modulo");
    //Gestion des erreurs : le modulo est une op�ration utilisable uniquement dans le mode entier
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
    if(complexe_m)
        pileImaginaire_m.push(-pileImaginaire_m.pop());
}

void Calculateur::sin()
{
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    //On diff�rencie deux cas : mode radiant ou degr�
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
    //On diff�rencie deux cas : mode radiant ou degr�
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
    //On diff�rencie deux cas : mode radiant ou degr�
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
    pile_m.push(1);
    division();
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
    float a(pile_m.pop());
    if(!complexe_m)
        pile_m.push(a*a);
    else{
        float b(pileImaginaire_m.pop());
        //Si on est en mode complexe, on ins�re (a + ib)� = (a� - b�) + i(2ab)
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
        //Si on est en mode complexe, on ins�re (a + ib)^3 = (a^3 - 3ab�) + i(3a�b - b^3)
        pile_m.push(a*a*a -3*a*b*b);
        pileImaginaire_m.push(3*a*a*b - b*b*b);
    }
}

void Calculateur::factorielle()
{
    //Gestion des erreurs : On v�rifie que le mode de constante soit compatible avec la fonction
    if(typeConstante_m != Entier)
        return;
    //Gestion des erreurs : Si la pile est vide, on ne fait rien
    if(pile_m.isEmpty())
        return;
    float valeur(std::floor(pile_m.pop()));
    //Gestion des erreurs : On v�rifie que la variable est valide;
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
        //On parcourt les piles simulatan�ment avec deux it�rateurs pour ne pas d�piler
        QStack<float>::iterator reIt;
        QStack<float>::iterator imIt;
        imIt =pileImaginaire_m.begin();
        for(reIt = pile_m.begin(); reIt < pile_m.end() ; ++reIt){
            f<<*reIt<<" + i"<<*imIt<<std::endl;
            imIt++;
        }
    }else{
    //On parcourt la pile avec un it�rateur pour ne pas d�piler
    QStack<float>::iterator it;
    for(it = pile_m.begin(); it < pile_m.end() ; ++it)
        f<<*it<<std::endl;
    }
}

float Calculateur::getTetePile(){
    return pile_m.last();
}

float PGCD(float n, float d)
{
    //Gestion des erreurs : pour �viter les probl�mes d'utilisation d'entiers avec la fonction fmod, on convertie les float en int
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
    //On commence par s�parer la partie enti�re de la partie d�cimale
    float res(0);
    float P(0);
    float intpart(0);
    float fractpart(std::modf(a, &intpart));
    fractpart *= 1000000;
    //Il faut distinguer 2 cas : le r�el a a une partie d�cimal finie ou infinie.
    //Si le reel a a une partie d�cimal finie
    if(std::fmod(fractpart, 10) == 0){
        res = fractpart + 1000000*intpart;
        //On simplifie la fraction
        P = PGCD(res, 1000000);
        res /= P;
        *denominateur = 1000000 / P;
    }else //Si le reel a a une partie d�cimal infinie
    {
        res = fractpart + 999999*intpart;
        //On simplifie la fraction
        P = PGCD(res, 999999);
        res /= P;
        *denominateur = 999999 / P;
    }
    //On renvoie le num�rateur et le d�nominateur
    return res;
}
