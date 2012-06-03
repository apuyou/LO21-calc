LO21-calc
=========

Une calculatrice à notation polonaise inversée (projet LO21).


TODO
====

MODÈLE
- finir le UML

CLASSES DE BASE
X classe ElementPile XXXXX
X classe Pile XXXXX
- une pile pour les affichages
V une pile sur laquelle on empile le résultat (de stockage)
V Calculatrice : créer une nouvelle pile à partir d'une chaîne de caractères 
X Calculatrice : évaluer le contenu de la pile temporaire
V Calculateur : effectuer les opérations de base (+, -, *, /)
V Calculateur : Gestion des erreurs
V Calculateur : effectuer les opérations sur la pile (à relier directement aux boutons)
V Calculateur : Effectuer les fonctions POW, MOD et SIGN
V Calculateur : Effectuer les opérateurs unaires
V Calculateur : Mettre au points les différents modes (Entier, Réelle, Fraction)
		Comment convertir les float en fraction ? Implémenter des méthodes spéciales
V Calculateur : Mettre au point le mode Complexe
		Peut-on créer une pile de parties imaginaires ? OUI
V Calculateur : Adapter les opérateurs unaires aux complexes
		Comment afficher un complexe à partir imaginaire négative ???
V Calculateur : Adapter les opérateurs sur pile aux complexes
V Calculateur : Sauvegarde des piles de stockage
		On ne sauvegarde que les piles, le contexte (mode constante, mode complexe, .. .) est sauvegardé dans une
		autre classe, puis les piles sont chargées.
- Calculateur : Fonctions annuler et rétablir
		Comment faire ???? peut on annuler plusieurs fois ?
		Doit-on utiliser setjmp() et longjmp() ?
V Calculateur : Mettre en place les onglets : Il est possible de créer plusieurs instances de la classe Calculateur, et
		chaque instance porte un numéro "onglet" unique. 

INTERFACE
- classe Clavier
  - tous les widgets boutons
  - Associer les boutons aux touches claviers
  - capture les raccourcis clavier (Ctrl -C, -Z, -Y, ...)
- classe Afficheur
  - affiche les saisies au clavier
  - reçoit des événements du clavier
  - envoie des événements à la calculatrice
- classe AfficheurPile
- paramètres
- sauvegarde état
- annuler/rétablir
- onglets

DOXYGEN
- Générer la doc