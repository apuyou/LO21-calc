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
    TypeElement type; /*!< Type de l'élément */
    ValeurElement valeur; /*!< Valeur de l'élément quel que soit son type */
};

#endif // ELEMENTPILE_H
