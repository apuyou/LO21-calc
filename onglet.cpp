#include "onglet.h"

onglet::onglet(QWidget *parent)
{
    setupUi(parent);
    retranslateUi(parent);
    setupSignals(parent);
}

void onglet::setupUi(QWidget *parent){
   this->setObjectName(QString::fromUtf8("tab"));
   verticalLayout_2 = new QVBoxLayout(this);
   verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
   horizontalLayout = new QHBoxLayout();
   horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
   verticalLayout_3 = new QVBoxLayout();
   verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
   listWidget = new QListWidget(this);
   listWidget->setObjectName(QString::fromUtf8("listWidget"));

   verticalLayout_3->addWidget(listWidget);

   inputLine = new QLineEdit(this);
   inputLine->setObjectName(QString::fromUtf8("inputLine"));
   inputLine->setReadOnly(true);

   verticalLayout_3->addWidget(inputLine);


   horizontalLayout->addLayout(verticalLayout_3);

   gridLayout = new QGridLayout();
   gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
   gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
   enterButton = new QPushButton(this);
   enterButton->setObjectName(QString::fromUtf8("enterButton"));

   gridLayout->addWidget(enterButton, 7, 0, 1, 3);

   opDivideButton = new QPushButton(this);
   opDivideButton->setObjectName(QString::fromUtf8("opDivideButton"));

   gridLayout->addWidget(opDivideButton, 0, 0, 1, 1);

   deleteButton = new QPushButton(this);
   deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

   gridLayout->addWidget(deleteButton, 0, 1, 1, 2);

   opPlusButton = new QPushButton(this);
   opPlusButton->setObjectName(QString::fromUtf8("opPlusButton"));

   gridLayout->addWidget(opPlusButton, 1, 0, 1, 1);

   opMinusButton = new QPushButton(this);
   opMinusButton->setObjectName(QString::fromUtf8("opMinusButton"));

   gridLayout->addWidget(opMinusButton, 1, 1, 1, 1);

   opTimesButton = new QPushButton(this);
   opTimesButton->setObjectName(QString::fromUtf8("opTimesButton"));

   gridLayout->addWidget(opTimesButton, 1, 2, 1, 1);

   num7Button = new QPushButton(this);
   num7Button->setObjectName(QString::fromUtf8("num7Button"));

   gridLayout->addWidget(num7Button, 2, 0, 1, 1);

   num8Button = new QPushButton(this);
   num8Button->setObjectName(QString::fromUtf8("num8Button"));

   gridLayout->addWidget(num8Button, 2, 1, 1, 1);

   num9Button = new QPushButton(this);
   num9Button->setObjectName(QString::fromUtf8("num9Button"));

   gridLayout->addWidget(num9Button, 2, 2, 1, 1);

   num4Button = new QPushButton(this);
   num4Button->setObjectName(QString::fromUtf8("num4Button"));

   gridLayout->addWidget(num4Button, 3, 0, 1, 1);

   num5Button = new QPushButton(this);
   num5Button->setObjectName(QString::fromUtf8("num5Button"));

   gridLayout->addWidget(num5Button, 3, 1, 1, 1);

   num6Button = new QPushButton(this);
   num6Button->setObjectName(QString::fromUtf8("num6Button"));

   gridLayout->addWidget(num6Button, 3, 2, 1, 1);

   num1Button = new QPushButton(this);
   num1Button->setObjectName(QString::fromUtf8("num1Button"));

   gridLayout->addWidget(num1Button, 4, 0, 1, 1);

   num2Button = new QPushButton(this);
   num2Button->setObjectName(QString::fromUtf8("num2Button"));

   gridLayout->addWidget(num2Button, 4, 1, 1, 1);

   num3Button = new QPushButton(this);
   num3Button->setObjectName(QString::fromUtf8("num3Button"));

   gridLayout->addWidget(num3Button, 4, 2, 1, 1);

   num0Button = new QPushButton(this);
   num0Button->setObjectName(QString::fromUtf8("num0Button"));

   gridLayout->addWidget(num0Button, 5, 0, 1, 1);

   quoteButton = new QPushButton(this);
   quoteButton->setObjectName(QString::fromUtf8("quoteButton"));

   gridLayout->addWidget(quoteButton, 6, 0, 1, 1);

   spaceButton = new QPushButton(this);
   spaceButton->setObjectName(QString::fromUtf8("spaceButton"));

   gridLayout->addWidget(spaceButton, 6, 1, 1, 2);

   decimalButton = new QPushButton(this);
   decimalButton->setObjectName(QString::fromUtf8("decimalButton"));
   decimalButton->setCheckable(false);

   gridLayout->addWidget(decimalButton, 5, 1, 1, 1);

   dollarButton = new QPushButton(this);
   dollarButton->setObjectName(QString::fromUtf8("dollarButton"));

   gridLayout->addWidget(dollarButton, 5, 2, 1, 1);


   horizontalLayout->addLayout(gridLayout);

   gridLayout_3 = new QGridLayout();
   gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
   sinButton = new QPushButton(this);
   sinButton->setObjectName(QString::fromUtf8("sinButton"));

   gridLayout_3->addWidget(sinButton, 0, 0, 1, 1);

   cosButton = new QPushButton(this);
   cosButton->setObjectName(QString::fromUtf8("cosButton"));

   gridLayout_3->addWidget(cosButton, 1, 0, 1, 1);

   tanButton = new QPushButton(this);
   tanButton->setObjectName(QString::fromUtf8("tanButton"));

   gridLayout_3->addWidget(tanButton, 2, 0, 1, 1);

   sinhButton = new QPushButton(this);
   sinhButton->setObjectName(QString::fromUtf8("sinhButton"));

   gridLayout_3->addWidget(sinhButton, 0, 1, 1, 1);

   coshButton = new QPushButton(this);
   coshButton->setObjectName(QString::fromUtf8("coshButton"));

   gridLayout_3->addWidget(coshButton, 1, 1, 1, 1);

   tanhButton = new QPushButton(this);
   tanhButton->setObjectName(QString::fromUtf8("tanhButton"));

   gridLayout_3->addWidget(tanhButton, 2, 1, 1, 1);

   lnButton = new QPushButton(this);
   lnButton->setObjectName(QString::fromUtf8("lnButton"));

   gridLayout_3->addWidget(lnButton, 3, 0, 1, 1);

   logButton = new QPushButton(this);
   logButton->setObjectName(QString::fromUtf8("logButton"));

   gridLayout_3->addWidget(logButton, 3, 1, 1, 1);

   sqrtButton = new QPushButton(this);
   sqrtButton->setObjectName(QString::fromUtf8("sqrtButton"));

   gridLayout_3->addWidget(sqrtButton, 4, 0, 1, 1);

   sqrButton = new QPushButton(this);
   sqrButton->setObjectName(QString::fromUtf8("sqrButton"));

   gridLayout_3->addWidget(sqrButton, 4, 1, 1, 1);

   invButton = new QPushButton(this);
   invButton->setObjectName(QString::fromUtf8("invButton"));

   gridLayout_3->addWidget(invButton, 5, 0, 1, 1);

   cubeButton = new QPushButton(this);
   cubeButton->setObjectName(QString::fromUtf8("cubeButton"));

   gridLayout_3->addWidget(cubeButton, 5, 1, 1, 1);

   factButton = new QPushButton(this);
   factButton->setObjectName(QString::fromUtf8("factButton"));

   gridLayout_3->addWidget(factButton, 6, 1, 1, 1);

   clearButton = new QPushButton(this);
   clearButton->setObjectName(QString::fromUtf8("clearButton"));

   gridLayout_3->addWidget(clearButton, 7, 1, 1, 1);

   swapButton = new QPushButton(this);
   swapButton->setObjectName(QString::fromUtf8("swapButton"));

   gridLayout_3->addWidget(swapButton, 7, 0, 1, 1);

   evalButton = new QPushButton(this);
   evalButton->setObjectName(QString::fromUtf8("evalButton"));

   gridLayout_3->addWidget(evalButton, 6, 0, 1, 1);


   horizontalLayout->addLayout(gridLayout_3);


   verticalLayout_2->addLayout(horizontalLayout);

   horizontalLayout_3 = new QHBoxLayout();
   horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
   comboType = new QComboBox(this);
   comboType->setObjectName(QString::fromUtf8("comboType"));

   horizontalLayout_3->addWidget(comboType);

   comboAngles = new QComboBox(this);
   comboAngles->setObjectName(QString::fromUtf8("comboAngles"));

   horizontalLayout_3->addWidget(comboAngles);

   checkboxComplexes = new QCheckBox(this);
   checkboxComplexes->setObjectName(QString::fromUtf8("checkboxComplexes"));

   horizontalLayout_3->addWidget(checkboxComplexes);

   horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

   horizontalLayout_3->addItem(horizontalSpacer);

   labelStatus = new QLabel(this);
   labelStatus->setObjectName(QString::fromUtf8("labelStatus"));

   horizontalLayout_3->addWidget(labelStatus);


   verticalLayout_2->addLayout(horizontalLayout_3);

   comboType->setCurrentIndex(1);
   comboAngles->setCurrentIndex(0);
}

void onglet::retranslateUi(QWidget *parent)
{
    enterButton->setText(QApplication::translate("Afficheur", "ENTR\303\211E", 0, QApplication::UnicodeUTF8));
    enterButton->setShortcut(QApplication::translate("Afficheur", "Return", 0, QApplication::UnicodeUTF8));
    opDivideButton->setText(QApplication::translate("Afficheur", "/", 0, QApplication::UnicodeUTF8));
    opDivideButton->setShortcut(QApplication::translate("Afficheur", "/", 0, QApplication::UnicodeUTF8));
    deleteButton->setText(QApplication::translate("Afficheur", "Del", 0, QApplication::UnicodeUTF8));
    deleteButton->setShortcut(QApplication::translate("Afficheur", "Backspace", 0, QApplication::UnicodeUTF8));
    opPlusButton->setText(QApplication::translate("Afficheur", "+", 0, QApplication::UnicodeUTF8));
    opPlusButton->setShortcut(QApplication::translate("Afficheur", "+", 0, QApplication::UnicodeUTF8));
    opMinusButton->setText(QApplication::translate("Afficheur", "-", 0, QApplication::UnicodeUTF8));
    opMinusButton->setShortcut(QApplication::translate("Afficheur", "-", 0, QApplication::UnicodeUTF8));
    opTimesButton->setText(QApplication::translate("Afficheur", "*", 0, QApplication::UnicodeUTF8));
    opTimesButton->setShortcut(QApplication::translate("Afficheur", "*", 0, QApplication::UnicodeUTF8));
    num7Button->setText(QApplication::translate("Afficheur", "7", 0, QApplication::UnicodeUTF8));
    num7Button->setShortcut(QApplication::translate("Afficheur", "7", 0, QApplication::UnicodeUTF8));
    num8Button->setText(QApplication::translate("Afficheur", "8", 0, QApplication::UnicodeUTF8));
    num8Button->setShortcut(QApplication::translate("Afficheur", "8", 0, QApplication::UnicodeUTF8));
    num9Button->setText(QApplication::translate("Afficheur", "9", 0, QApplication::UnicodeUTF8));
    num9Button->setShortcut(QApplication::translate("Afficheur", "9", 0, QApplication::UnicodeUTF8));
    num4Button->setText(QApplication::translate("Afficheur", "4", 0, QApplication::UnicodeUTF8));
    num4Button->setShortcut(QApplication::translate("Afficheur", "4", 0, QApplication::UnicodeUTF8));
    num5Button->setText(QApplication::translate("Afficheur", "5", 0, QApplication::UnicodeUTF8));
    num5Button->setShortcut(QApplication::translate("Afficheur", "5", 0, QApplication::UnicodeUTF8));
    num6Button->setText(QApplication::translate("Afficheur", "6", 0, QApplication::UnicodeUTF8));
    num6Button->setShortcut(QApplication::translate("Afficheur", "6", 0, QApplication::UnicodeUTF8));
    num1Button->setText(QApplication::translate("Afficheur", "1", 0, QApplication::UnicodeUTF8));
    num1Button->setShortcut(QApplication::translate("Afficheur", "1", 0, QApplication::UnicodeUTF8));
    num2Button->setText(QApplication::translate("Afficheur", "2", 0, QApplication::UnicodeUTF8));
    num2Button->setShortcut(QApplication::translate("Afficheur", "2", 0, QApplication::UnicodeUTF8));
    num3Button->setText(QApplication::translate("Afficheur", "3", 0, QApplication::UnicodeUTF8));
    num3Button->setShortcut(QApplication::translate("Afficheur", "3", 0, QApplication::UnicodeUTF8));
    num0Button->setText(QApplication::translate("Afficheur", "0", 0, QApplication::UnicodeUTF8));
    num0Button->setShortcut(QApplication::translate("Afficheur", "0", 0, QApplication::UnicodeUTF8));
    quoteButton->setText(QApplication::translate("Afficheur", "'", 0, QApplication::UnicodeUTF8));
    quoteButton->setShortcut(QApplication::translate("Afficheur", "'", 0, QApplication::UnicodeUTF8));
    spaceButton->setText(QApplication::translate("Afficheur", "Espace", 0, QApplication::UnicodeUTF8));
    spaceButton->setShortcut(QApplication::translate("Afficheur", "Space", 0, QApplication::UnicodeUTF8));
    decimalButton->setText(QApplication::translate("Afficheur", ".", 0, QApplication::UnicodeUTF8));
    decimalButton->setShortcut(QApplication::translate("Afficheur", ",", 0, QApplication::UnicodeUTF8));
    dollarButton->setText(QApplication::translate("Afficheur", "$", 0, QApplication::UnicodeUTF8));
    dollarButton->setShortcut(QApplication::translate("Afficheur", "$", 0, QApplication::UnicodeUTF8));
    sinButton->setText(QApplication::translate("Afficheur", "SIN", 0, QApplication::UnicodeUTF8));
    cosButton->setText(QApplication::translate("Afficheur", "COS", 0, QApplication::UnicodeUTF8));
    tanButton->setText(QApplication::translate("Afficheur", "TAN", 0, QApplication::UnicodeUTF8));
    sinhButton->setText(QApplication::translate("Afficheur", "SINH", 0, QApplication::UnicodeUTF8));
    coshButton->setText(QApplication::translate("Afficheur", "COSH", 0, QApplication::UnicodeUTF8));
    tanhButton->setText(QApplication::translate("Afficheur", "TANH", 0, QApplication::UnicodeUTF8));
    lnButton->setText(QApplication::translate("Afficheur", "LN", 0, QApplication::UnicodeUTF8));
    logButton->setText(QApplication::translate("Afficheur", "LOG", 0, QApplication::UnicodeUTF8));
    sqrtButton->setText(QApplication::translate("Afficheur", "SQRT", 0, QApplication::UnicodeUTF8));
    sqrButton->setText(QApplication::translate("Afficheur", "SQR", 0, QApplication::UnicodeUTF8));
    invButton->setText(QApplication::translate("Afficheur", "INV", 0, QApplication::UnicodeUTF8));
    cubeButton->setText(QApplication::translate("Afficheur", "CUBE", 0, QApplication::UnicodeUTF8));
    factButton->setText(QApplication::translate("Afficheur", "!", 0, QApplication::UnicodeUTF8));
    clearButton->setText(QApplication::translate("Afficheur", "CLEAR", 0, QApplication::UnicodeUTF8));
    swapButton->setText(QApplication::translate("Afficheur", "SWAP", 0, QApplication::UnicodeUTF8));
    evalButton->setText(QApplication::translate("Afficheur", "EVAL", 0, QApplication::UnicodeUTF8));
    comboType->clear();
    comboType->insertItems(0, QStringList()
     << QApplication::translate("Afficheur", "Entier", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("Afficheur", "R\303\251el", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("Afficheur", "Fraction", 0, QApplication::UnicodeUTF8)
    );
#ifndef QT_NO_TOOLTIP
    comboType->setToolTip(QApplication::translate("Afficheur", "Type de constantes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    comboAngles->clear();
    comboAngles->insertItems(0, QStringList()
     << QApplication::translate("Afficheur", "Degr\303\251s", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("Afficheur", "Radians", 0, QApplication::UnicodeUTF8)
    );
#ifndef QT_NO_TOOLTIP
    comboAngles->setToolTip(QApplication::translate("Afficheur", "Format des angles", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    checkboxComplexes->setText(QApplication::translate("Afficheur", "&Complexes", 0, QApplication::UnicodeUTF8));
    labelStatus->setText(QString());
} // retranslateUi

void onglet::setupSignals(QWidget *parent){
    // Pavé numérique
    connect(num0Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(num1Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(num2Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(num3Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(num4Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(num5Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(num6Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(num7Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(num8Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(num9Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(decimalButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(dollarButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));

    // Opérateurs
    connect(enterButton, SIGNAL(clicked()), this, SLOT(enterPressed()));
    connect(spaceButton, SIGNAL(clicked()), this, SLOT(spacePressed()));
    connect(opDivideButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(opMinusButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(opPlusButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(opTimesButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deletePressed()));
    connect(quoteButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(sinButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(sinhButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(cosButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(coshButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(tanButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(tanhButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(evalButton, SIGNAL(clicked()), this, SLOT(evalPressed()));

    // Réglages
    connect(checkboxComplexes, SIGNAL(toggled(bool)), this, SLOT(complexeChanged(bool)));
    connect(comboAngles, SIGNAL(currentIndexChanged(int)), this, SLOT(anglesChanged(int)));
    connect(comboType, SIGNAL(currentIndexChanged(int)), this, SLOT(modeChanged(int)));
}

void onglet::genericButtonPressed(){
    QPushButton *button = (QPushButton*) sender();
    QString previousText = inputLine->text();
    QString newText = button->text();
    QChar prevChar = '_', nextChar = '_';

    if(previousText.length() > 0 )
        prevChar = previousText.at(previousText.length()-1);
    if(newText.length() > 0)
        nextChar = newText.at(0);

    // Ne pas rajouter d'espace si on est au tout début, après un espace, ou si on est en train de taper un nombre
    if(previousText.endsWith(' ') || previousText.length() == 0
            || (prevChar.isNumber() && nextChar.isNumber()) || (previousText.endsWith('$') || newText.startsWith('$')))
        inputLine->setText(previousText + newText);
    // Rajouter un espace sinon
    else
        inputLine->setText(previousText + " " + newText);
}

void onglet::evaluate(QString newElement){
    labelStatus->setText("");
    try{
        // Si quote : stockage de l'expression dans la pile de l'afficheur
        if(newElement.indexOf("'") == 0 && newElement.lastIndexOf("'") == newElement.length()-1){
            listWidget->addItem(newElement);
        }
        // Sinon, ajout de l'expression dans la pile du calculateur et stockage du retour dans l'afficheur
        else {
            // Si effectivement il y a quelque chose dans le champ de saisie
            if(newElement.length() != 0){
                QString result = "";

                // On ajoute l'opérateur dans la pile
                c.insererElement(newElement.toStdString());
                // Le résultat est le premier élément de la pile
                result = c.getTetePile();

                // Si opération unaire (= pas un chiffre ou un complexe ou une chaîne avec espaces), on supprimer l'élément précédent
                if(!newElement.toFloat() && newElement.indexOf('$') == -1 && newElement.indexOf(" ") == -1){
                    retireDerniereLigneAffichee();

                    // Si opération binaire, on supprime le deuxième élément précédent (2ème opérande)
                    if(newElement == tr("+") || newElement == tr("-") || newElement == tr("*") || newElement == tr("/"))
                        retireDerniereLigneAffichee();
                }

                // On ajoute le résultat tout en bas
                if(result != "")
                    listWidget->addItem(result);
            }
        }

        // On affiche le haut de la pile et on vide le champ de saisie
        listWidget->scrollToBottom();
    } catch(Erreur e){
        labelStatus->setText(e.what());
    }
}

void onglet::enterPressed(){
    evaluate(inputLine->text());
    inputLine->setText("");
}

void onglet::retireDerniereLigneAffichee(){
    int lookback = listWidget->count();

    // On trouve la ligne
    do {
        lookback--;
    } while(lookback > -1 && listWidget->item(lookback) && listWidget->item(lookback)->text().indexOf("'") == 0);

    if(lookback > -1)
        listWidget->takeItem(lookback);
}

void onglet::spacePressed(){
    inputLine->setText(inputLine->text() + " ");
}

void onglet::deletePressed(){
    QString aff = inputLine->text();
    aff.chop(1);
    inputLine->setText(aff);
}

void onglet::complexeChanged(bool newState){
    if(newState)
        c.modeComplexe();
    else
        c.modeHorsComplexe();
    listWidget->clear();
}

void onglet::anglesChanged(int index){
    if(index == 0)
        c.modeDegre();
    else if(index == 1)
        c.modeRadiant();
}

void onglet::modeChanged(int index){
    switch(index){
    case 0:
        c.modeEntier();
        break;
    case 1:
        c.modeReel();
        break;
    case 2:
        c.modeFraction();
        break;
    default:
        break;
    }
}

Calculateur onglet::getCalculateur(){
    return c;
}

void onglet::setCalculateur(Calculateur nouveau){
    c = nouveau;
}

void onglet::evalPressed(){
    // Si le dernier élément de la liste d'affichage est une expression
    QString el = listWidget->item(listWidget->count()-1)->text();
    if(el.indexOf("'") == 0){
        // On retire le ' de gauche
        el = el.right(el.size()-1).trimmed();

        // S'il y a aussi un ' à la fin, on le retire
        if(el.indexOf("'") == el.size()-1)
            el = el.left(el.size()-1).trimmed();

        // On retire le dernier élément de la pile d'affichage
        listWidget->takeItem(listWidget->count()-1);
        // On évalue ce qu'il contenait (sans les quotes)
        evaluate(el);
    }
}
