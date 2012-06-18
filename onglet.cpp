#include "onglet.h"

onglet::onglet(QWidget *parent)
{
    setupUi(parent);
    retranslateUi(parent);
    setupSignals(parent);
}

void onglet::setupUi(QWidget *parent){
    verticalLayout_2 = new QVBoxLayout(this);
    horizontalLayout = new QHBoxLayout();
    verticalLayout_3 = new QVBoxLayout();

    listWidget = new QListWidget(this);
    verticalLayout_3->addWidget(listWidget);

    inputLine = new QLineEdit(this);
    inputLine->setReadOnly(true);
    verticalLayout_3->addWidget(inputLine);

    horizontalLayout->addLayout(verticalLayout_3);

    clavierSimple = new QWidget(this);

    gridLayout = new QGridLayout(clavierSimple);

    enterButton = new QPushButton("Entree/DUP", this);
    gridLayout->addWidget(enterButton, 7, 0, 1, 3);

    opDivideButton = new QPushButton("/", this);
    gridLayout->addWidget(opDivideButton, 0, 0, 1, 1);

    deleteButton = new QPushButton("Del/DROP", this);
    gridLayout->addWidget(deleteButton, 0, 1, 1, 2);

    opPlusButton = new QPushButton("+", this);
    gridLayout->addWidget(opPlusButton, 1, 0, 1, 1);

    opMinusButton = new QPushButton("-", this);
    gridLayout->addWidget(opMinusButton, 1, 1, 1, 1);

    opTimesButton = new QPushButton("*", this);
    gridLayout->addWidget(opTimesButton, 1, 2, 1, 1);

    num7Button = new QPushButton("7", this);
    gridLayout->addWidget(num7Button, 2, 0, 1, 1);

    num8Button = new QPushButton("8", this);
    gridLayout->addWidget(num8Button, 2, 1, 1, 1);

    num9Button = new QPushButton("9", this);
    gridLayout->addWidget(num9Button, 2, 2, 1, 1);

    num4Button = new QPushButton("4", this);
    gridLayout->addWidget(num4Button, 3, 0, 1, 1);

    num5Button = new QPushButton("5", this);
    gridLayout->addWidget(num5Button, 3, 1, 1, 1);

    num6Button = new QPushButton("6", this);
    gridLayout->addWidget(num6Button, 3, 2, 1, 1);

    num1Button = new QPushButton("1", this);
    gridLayout->addWidget(num1Button, 4, 0, 1, 1);

    num2Button = new QPushButton("2", this);
    gridLayout->addWidget(num2Button, 4, 1, 1, 1);

    num3Button = new QPushButton("3", this);
    gridLayout->addWidget(num3Button, 4, 2, 1, 1);

    num0Button = new QPushButton("0", this);
    gridLayout->addWidget(num0Button, 5, 0, 1, 1);

    quoteButton = new QPushButton("'", this);
    gridLayout->addWidget(quoteButton, 6, 0, 1, 1);

    spaceButton = new QPushButton("Espace", this);
    gridLayout->addWidget(spaceButton, 6, 1, 1, 2);

    decimalButton = new QPushButton(".", this);
    gridLayout->addWidget(decimalButton, 5, 1, 1, 1);

    dollarButton = new QPushButton("$", this);
    gridLayout->addWidget(dollarButton, 5, 2, 1, 1);

    horizontalLayout->addWidget(clavierSimple);

    clavierEtendu = new QWidget(this);

    gridLayout_3 = new QGridLayout(clavierEtendu);

    sinButton = new QPushButton("SIN", this);
    gridLayout_3->addWidget(sinButton, 0, 0, 1, 1);

    cosButton = new QPushButton("COS", this);
    gridLayout_3->addWidget(cosButton, 1, 0, 1, 1);

    tanButton = new QPushButton("TAN", this);
    gridLayout_3->addWidget(tanButton, 2, 0, 1, 1);

    sinhButton = new QPushButton("SINH", this);
    gridLayout_3->addWidget(sinhButton, 0, 1, 1, 1);

    coshButton = new QPushButton("COSH", this);
    gridLayout_3->addWidget(coshButton, 1, 1, 1, 1);

    tanhButton = new QPushButton("TANH", this);
    gridLayout_3->addWidget(tanhButton, 2, 1, 1, 1);

    lnButton = new QPushButton("LN", this);
    gridLayout_3->addWidget(lnButton, 3, 0, 1, 1);

    logButton = new QPushButton("LOG", this);
    gridLayout_3->addWidget(logButton, 3, 1, 1, 1);

    sqrtButton = new QPushButton("SQRT", this);
    gridLayout_3->addWidget(sqrtButton, 4, 0, 1, 1);

    sqrButton = new QPushButton("SQR", this);
    gridLayout_3->addWidget(sqrButton, 4, 1, 1, 1);

    invButton = new QPushButton("INV", this);
    gridLayout_3->addWidget(invButton, 5, 0, 1, 1);

    cubeButton = new QPushButton("CUBE", this);
    gridLayout_3->addWidget(cubeButton, 5, 1, 1, 1);

    factButton = new QPushButton("!", this);
    gridLayout_3->addWidget(factButton, 6, 1, 1, 1);

    clearButton = new QPushButton("CLEAR", this);
    gridLayout_3->addWidget(clearButton, 7, 1, 1, 1);

    swapButton = new QPushButton("SWAP", this);
    gridLayout_3->addWidget(swapButton, 7, 0, 1, 1);

    evalButton = new QPushButton("EVAL", this);
    gridLayout_3->addWidget(evalButton, 6, 0, 1, 1);

    sumButton = new QPushButton("SUM", this);
    gridLayout_3->addWidget(sumButton, 0, 2, 1, 1);

    modButton = new QPushButton("MOD", this);
    gridLayout_3->addWidget(modButton, 1, 2, 1, 1);

    powButton = new QPushButton("POW", this);
    gridLayout_3->addWidget(powButton, 2, 2, 1, 1);

    meanButton = new QPushButton("MEAN", this);
    gridLayout_3->addWidget(meanButton, 3, 2, 1, 1);

    signButton = new QPushButton("SIGN", this);
    gridLayout_3->addWidget(signButton, 4, 2, 1, 1);

    horizontalLayout->addWidget(clavierEtendu);

    verticalLayout_2->addLayout(horizontalLayout);

    horizontalLayout_3 = new QHBoxLayout();

    comboType = new QComboBox(this);
    horizontalLayout_3->addWidget(comboType);

    comboAngles = new QComboBox(this);
    horizontalLayout_3->addWidget(comboAngles);

    checkboxComplexes = new QCheckBox(this);
    horizontalLayout_3->addWidget(checkboxComplexes);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout_3->addItem(horizontalSpacer);

    labelStatus = new QLabel(this);
    horizontalLayout_3->addWidget(labelStatus);

    verticalLayout_2->addLayout(horizontalLayout_3);
}

void onglet::retranslateUi(QWidget *parent)
{
    enterButton->setShortcut(QString("Return"));
    opDivideButton->setShortcut(QString("/"));
    deleteButton->setShortcut(QString("Backspace"));
    opPlusButton->setShortcut(QString("+"));
    opMinusButton->setShortcut(QString("-"));
    opTimesButton->setShortcut(QString("*"));
    num7Button->setShortcut(QString("7"));
    num8Button->setShortcut(QString("8"));
    num9Button->setShortcut(QString("9"));
    num4Button->setShortcut(QString("4"));
    num5Button->setShortcut(QString("5"));
    num6Button->setShortcut(QString("6"));
    num1Button->setShortcut(QString("1"));
    num2Button->setShortcut(QString("2"));
    num3Button->setShortcut(QString("3"));
    num0Button->setShortcut(QString("0"));
    quoteButton->setShortcut(QString("'"));
    spaceButton->setShortcut(QString("Space"));
    decimalButton->setShortcut(QString(","));
    dollarButton->setShortcut(QString("$"));
    clearButton->setShortcut(QString("CTRL+C"));


    comboType->clear();
    comboType->insertItems(0, QStringList()
     << QApplication::translate("Afficheur", "Entier", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("Afficheur", "R\303\251el", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("Afficheur", "Fraction", 0, QApplication::UnicodeUTF8)
    );
#ifndef QT_NO_TOOLTIP
    comboType->setToolTip(QApplication::translate("Afficheur", "Type de constantes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    comboType->setCurrentIndex(1);

    comboAngles->clear();
    comboAngles->insertItems(0, QStringList()
     << QApplication::translate("Afficheur", "Degr\303\251s", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("Afficheur", "Radians", 0, QApplication::UnicodeUTF8)
    );
#ifndef QT_NO_TOOLTIP
    comboAngles->setToolTip(QApplication::translate("Afficheur", "Format des angles", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    comboAngles->setCurrentIndex(0);

    checkboxComplexes->setText(QApplication::translate("Afficheur", "&Complexes", 0, QApplication::UnicodeUTF8));

    labelStatus->setText(QString());
}

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
    connect(clearButton, SIGNAL(clicked()), this, SLOT(clearPressed()));
    connect(sumButton, SIGNAL(clicked()), this, SLOT(popupButtonPressed()));
    connect(signButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(modButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(powButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(meanButton, SIGNAL(clicked()), this, SLOT(popupButtonPressed()));
    connect(swapButton, SIGNAL(clicked()), this, SLOT(swapPressed()));

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

                // Si opération unaire (= pas un chiffre ou un complexe ou une chaîne avec espaces), on supprime l'élément précédent
                bool isFloat;
                newElement.toFloat(&isFloat);
                if(!isFloat && newElement.indexOf('$') == -1 && newElement.indexOf(" ") == -1){
                    retireDerniereLigneAffichee();

                    // Si opération binaire, on supprime le deuxième élément précédent (2ème opérande)
                    if(newElement == tr("+") || newElement == tr("-") || newElement == tr("*") || newElement == tr("/")
                            || newElement == tr("MOD") || newElement == tr("POW"))
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
    if(inputLine->text().size() > 0){
        evaluate(inputLine->text().trimmed());
        inputLine->setText("");
    }
    else
        dupPressed();
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
    if(aff.size() > 0){
        aff.chop(1);
        inputLine->setText(aff);
    }
    else {
        dropPressed();
    }
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

void onglet::clearPressed(){
    c.clear();
    listWidget->clear();
    inputLine->clear();
}

void onglet::dropPressed(){
    if(listWidget->count() == 0)
        return;

    // On sort le dernier élément
    QListWidgetItem *out = listWidget->takeItem(listWidget->count()-1);

    // Si ce n'est pas une expression, on le retire aussi du calculateur
    if(out->text().indexOf("'") == -1)
        c.drop();
}

void onglet::dupPressed(){
    if(listWidget->count() == 0)
        return;

    QListWidgetItem *item = listWidget->item(listWidget->count()-1);

    listWidget->addItem(item->text());
    if(item->text().indexOf("'") == -1)
        c.insererElement(item->text().toStdString());
}

void onglet::popupButtonPressed(){
    QPushButton *button = (QPushButton*) sender();
    QString operation = button->text();

    bool ok;
    int i = QInputDialog::getInt(this, operation,
         tr("Nombre de lignes sur laquelle appliquer l'operation :"), 0, 0,  2147483647, 1, &ok);

    if(ok){
        if(operation == "SUM")
            c.sum(i);
        else if(operation == "MEAN")
            c.mean(i);

        for(int j = 0;j<i;j++)
            retireDerniereLigneAffichee();

        QString result = c.getTetePile();
        listWidget->addItem(result);
    }
}

void onglet::swapPressed(){
    labelStatus->setText("");
    bool ok;
    int i = QInputDialog::getInt(this, tr("SWAP"),
            tr("Premier element :"), 0, 0,  2147483647, 1, &ok);

    if(!ok) return;

    int j = QInputDialog::getInt(this, tr("SWAP"),
            tr("Deuxieme element :"), 0, 0,  2147483647, 1, &ok);

    if(ok){
        if(i > listWidget->count()-1 || j > listWidget->count()-1){
            labelStatus->setText(tr("Erreur : un des index saisi est incorrect."));
            return;
        }

        QString texti = listWidget->item(i)->text();
        QString textj = listWidget->item(j)->text();

        if(i > j){
            int tmp = i;
            i = j;
            j = tmp;
        }

        if(texti.indexOf("'") != -1 || textj.indexOf("'") != -1){
            labelStatus->setText(tr("Erreur : impossible d'échanger des expressions."));
            return;
        }

        c.swap(i, j);

        listWidget->takeItem(i);
        listWidget->takeItem(j-1); // j-1 car i a disparu pendant cet instant
        listWidget->insertItem(i, textj);
        listWidget->insertItem(j, texti);
    }
}

float onglet::PGCD(float n, float d)
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

float onglet::getFraction(float a, float* denominateur)
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
