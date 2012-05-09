#include "Pile.h"

//Constructeur de Pile
Pile::Pile(unsigned int m): n(0), max(m), tab(new float*[m])
{
    if(!tab)//Si le tableau n'a pas été correctement instancié
        ;//On lance une erreur
}

//Operateur de recopie
Pile::Pile(const Pile& p): n(p.n), max(p.max), tab(new float*[p.max])
{
    if(!tab)//Si le tableau n'a pas été correctement instancié
        ;//On lance une erreur
    for(unsigned int i=0; i<n; ++i)
        tab[i] = new float(*p.tab[i]);
}

//operateur d'affectation
void Pile::operator=(const Pile& p){
    if(this != &p){
        max = p.max;

        for(unsigned int i=0; i<n; ++i)
            delete tab[i];
        delete[] tab;

        n = p.n;
        tab = new float*[p.max];
        for(unsigned int i=0; i<n; ++i)
            tab[i] = new float(*p.tab[i]);
    }
}

//Fonction qui nous informe si la pile est vide
bool Pile::pileVide()
{
    return(n==0);
}

//Fonction qui nous informe si la pile est pleine
bool Pile::pilePleine()
{
    return(n==max);
}

//Fonction qui vide la pile
void Pile::viderPile(){
    if(!pileVide()){
        for(unsigned int i=0; i<n; ++i)
            delete tab[i];
        n=0;
    }
}

//On empile un élément entré en paramètre en agrandissant le tableau si besoin
void Pile::empiler(const float& obj)
{
    if(pilePleine()){
        max += 10;
        float** newtab = new float*[max];
        for(unsigned int i=0; i<n;++i)
            newtab[i] = tab[i];
        delete[] tab;
        tab = newtab;
    }
    tab[n]= new float(obj);
    n++;
}

//On dépile un élément ssi la pile est non-pleine. Sinon on retourne une erreur
float& Pile::depiler()
{
    float* res;
    if(!pileVide()){
        n--;
        res = tab[n];
        return *res;
    }
        //ERREUR("debordement de la pile par defaut");
}

//Destructeur de Pile
Pile::~Pile(){
    for(unsigned int i=0; i<n; ++i)
        delete tab[i];
    delete[] tab;
}
