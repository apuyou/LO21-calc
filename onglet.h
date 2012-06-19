#ifndef ONGLET_H
#define ONGLET_H

#include <iostream>
#include "Calculateur.h"
#include <QList>

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QTGui/QInputDialog>

class onglet: public QWidget
{
    Q_OBJECT

public:
    onglet(QWidget *);
    ~onglet();
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QLineEdit *inputLine;
    QGridLayout *gridLayout;
    QPushButton *enterButton;
    QPushButton *opDivideButton;
    QPushButton *deleteButton;
    QPushButton *opPlusButton;
    QPushButton *opMinusButton;
    QPushButton *opTimesButton;
    QPushButton *num7Button;
    QPushButton *num8Button;
    QPushButton *num9Button;
    QPushButton *num4Button;
    QPushButton *num5Button;
    QPushButton *num6Button;
    QPushButton *num1Button;
    QPushButton *num2Button;
    QPushButton *num3Button;
    QPushButton *num0Button;
    QPushButton *quoteButton;
    QPushButton *spaceButton;
    QPushButton *decimalButton;
    QPushButton *dollarButton;
    QGridLayout *gridLayout_3;
    QPushButton *sinButton;
    QPushButton *cosButton;
    QPushButton *tanButton;
    QPushButton *sinhButton;
    QPushButton *coshButton;
    QPushButton *tanhButton;
    QPushButton *lnButton;
    QPushButton *logButton;
    QPushButton *sqrtButton;
    QPushButton *sqrButton;
    QPushButton *invButton;
    QPushButton *cubeButton;
    QPushButton *factButton;
    QPushButton *clearButton;
    QPushButton *swapButton;
    QPushButton *evalButton;
    QPushButton *sumButton;
    QPushButton *modButton;
    QPushButton *signButton;
    QPushButton *meanButton;
    QPushButton *powButton;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboType;
    QComboBox *comboAngles;
    QCheckBox *checkboxComplexes;
    QSpacerItem *horizontalSpacer;
    QLabel *labelStatus;
    QWidget *clavierSimple;
    QWidget *clavierEtendu;
    /**
     * \fn chargerPiles()
     * \brief Appelle la méthode chargerPiles du calculateur et met à jour l'affichage
     */
    void chargerPiles();
    /**
     * \fn sauvegarderPiles()
     * \brief Appelle la méthode sauvegarderPiles du calculateur
     */
    void sauverPiles();


protected:
    /**
     * \fn setupUi()
     * \brief Fonction : Créé l'ensemble des widgets de l'onglet
     */
    void setupUi();
    /**
     * \fn retranslateUi()
     * \brief Fonction : Ajoute les raccourcis claviers aux boutons
     */
    void retranslateUi();
    /**
     * \fn setupSignals
     * \brief Fonction : Met en place les signaux entre boutons et slots
     */
    void setupSignals();

    Calculateur c;  /* Calculateur utilisé pour effectuer les opérations de l'utilisateur */
    QList<QList<QListWidgetItem*> > undoListItems;
    QList<Calculateur> undoCalculateur;
    int undoIndex;

    /**
     * \fn retireDerniereLigneAffichee()
     * \brief Fonction : Retire la dernière ligne de lineWidget qui n'est pas une expression
     */
    void retireDerniereLigneAffichee();
    /**
     * \fn evaluate(QString newElement)
     * \brief Fonction : Évalue l'expression passée en paramètre et place son résultat en haut de la pile
     */
    void evaluate(QString newElement);
    /**
     * \fn updateFromCalculateur()
     * \param newElement : chaîne à évaluer
     * \brief Fonction : Remplit la liste d'affichage à partir de la pile du calculateur
     */
    void updateFromCalculateur();
    /**
     * \fn float PGCD(float n, float d);
     * \brief Fonction : Calcul le PGCD de deux réels
     *
     * \param n : premier réel
     * \param d : deuxième réel
     * \return Retourne le PGCD de n et d
     */
    float PGCD(float n, float d);
    /**
     * \fn float getFraction(float a, float* denominateur);
     * \brief Fonction : Convertie le réel a en fraction
     *
     * \param a : réel à convertir
     * \param d : pointeur sur le dénominateur de la fraction
     * \return Retourne le numérateur de la fraction
     */
    float getFraction(float a, float* denominateur);

private slots:
    /**
     * \slot genericButtonPressed()
     * \brief Slot générique pour l'ensemble des boutons qui ne font qu'ajouter une opération dans le champ de saisie
     */
    void genericButtonPressed();
    /**
     * \slot enterPressed()
     * \brief Gère l'appui sur la touche Entrée (évaluation du champ de saisie ou bien DUP s'il est vide)
     */
    void enterPressed();
    /**
     * \slot spacePressed()
     * \brief Ajoute un espace dans le champ de saisie
     */
    void spacePressed();
    /**
     * \slot deletePressed()
     * \brief Gère l'appui sur la touche Effacer (effacer un caractère du champ de saisie ou bien DROP s'il est vide)
     */
    void deletePressed();
    /**
     * \slot complexeChanged(bool newState)
     * \param newState : état après le changement
     * \brief Active ou désactive le mode complexe
     */
    void complexeChanged(bool newState);
    /**
     * \slot anglesChanged(int index)
     * \param index : nouvel index du comboBox
     * \brief Modifie le système angulaire
     */
    void anglesChanged(int index);
    /**
     * \slot modeChanged(int index)
     * \param index : nouvel index du comboBox
     * \brief Modifie le mode d'affichage des nombres stockés dans la calculatrice
     */
    void modeChanged(int index);
    /**
     * \slot evalPressed()
     * \brief Gestion de l'appui sur la touche EVAL
     */
    void evalPressed();
    /**
     * \slot clearPressed()
     * \brief Gestion de l'appui sur la touche CLEAR
     */
    void clearPressed();
    /**
     * \slot dropPressed()
     * \brief Gestion de l'appui sur la touche DROP
     */
    void dropPressed();
    /**
     * \slot dupPressed()
     * \brief Gestion de l'appui sur la touche DUP
     */
    void dupPressed();
    /**
     * \slot popupButtonPressed()
     * \brief Slot générique pour les opérations nécessitant un paramètre supplémentaire à l'exécution (SUM, MEAN)
     */
    void popupButtonPressed();
    /**
     * \slot swapPressed()
     * \brief Gestion de l'appui sur SWAP, qui nécessite deux paramètres
     */
    void swapPressed();
    /**
     * \slot saveState()
     * \brief Enregistre l'état de la calculatrice pour pouvoir faire des undo/redo
     */
    void saveState();

public:
    /**
     * \fn Calculateur getCalculateur()
     * \brief Renvoie une copie de l'objet Calculateur utilisé par l'onglet
     * \return Calculateur
     */
    Calculateur getCalculateur();
    /**
     * \fn setCalculateur(Calculateur nouveau)
     * \brief Remplace le calculateur de l'onglet par nouveau
     * \param Calculateur nouveau : Calculateur à remplacer
     */
    void setCalculateur(Calculateur nouveau);
    /**
     * \fn undo()
     * \brief Annule la dernière opération
     */
    void undo();
    /**
     * \fn redo()
     * \brief Rétablit la dernière opération
     */
    void redo();

};

#endif // ONGLET_H
