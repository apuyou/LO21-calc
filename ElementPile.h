#ifndef ELEMENTPILE_H
#define ELEMENTPILE_H

enum TypeElement {TypeEntier, TypeReel, TypeFraction, TypeComplexe};

union ValeurElement{
    int entier;
    float reel;
    Fraction fraction;
    Complexe complexe;
};

class ElementPile{
private:
    TypeElement type; /*!< Type de l'�l�ment */
    ValeurElement valeur; /*!< Valeur de l'�l�ment quel que soit son type */
};

#endif // ELEMENTPILE_H
