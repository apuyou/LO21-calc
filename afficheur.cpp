#include "afficheur.h"
#include "ui_afficheur.h"
#include "Calculateur.h"
#include <QActionGroup>

Afficheur::Afficheur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Afficheur)
{
    ui->setupUi(this);

    // Pavé numérique
    connect(ui->num0Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->num1Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->num2Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->num3Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->num4Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->num5Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->num6Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->num7Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->num8Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->num9Button, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->enterButton, SIGNAL(clicked()), this, SLOT(enterPressed()));
    connect(ui->spaceButton, SIGNAL(clicked()), this, SLOT(spacePressed()));
    connect(ui->opDivideButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->opMinusButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->opPlusButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->opTimesButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deletePressed()));
    connect(ui->quoteButton, SIGNAL(clicked()), this, SLOT(genericButtonPressed()));

    // Réglages
    connect(ui->checkboxComplexes, SIGNAL(toggled(bool)), this, SLOT(complexeChanged(bool)));
    connect(ui->comboAngles, SIGNAL(currentIndexChanged(int)), this, SLOT(anglesChanged(int)));
    connect(ui->comboType, SIGNAL(currentIndexChanged(int)), this, SLOT(modeChanged(int)));

    // Menus
    connect(ui->actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    clavierGroup = new QActionGroup(this);
    clavierGroup->addAction(ui->actionPas_de_clavier);
    clavierGroup->addAction(ui->actionClavier_simple);
    clavierGroup->addAction(ui->actionClavier_etendu);
}

void Afficheur::genericButtonPressed(){
    QPushButton *button = (QPushButton*) sender();
    ui->inputLine->setText(ui->inputLine->text() + button->text());
}

void Afficheur::enterPressed(){
    ui->labelStatus->setText("");
    try{
        // Lecture de l'entrée à traiter depuis le champ texte
        QString newElement = ui->inputLine->text();

        // Si quote : stockage de l'expression dans la pile de l'afficheur
        if(newElement.indexOf("'") == 0 && newElement.lastIndexOf("'") == newElement.length()-1){
            ui->listWidget->addItem(newElement);
        }
        // Sinon, ajout de l'expression dans la pile du calculateur et stockage du retour dans l'afficheur
        else {
            // Si effectivement il y a quelque chose dans le champ de saisie
            if(newElement.length() != 0){
                QString result = "";

                // Si un des deux derniers éléments est une expression
                if((ui->listWidget->item(ui->listWidget->count()-1) && ui->listWidget->item(ui->listWidget->count()-1)->text().indexOf("'") == 0)
                        || (ui->listWidget->item(ui->listWidget->count()-2) && ui->listWidget->item(ui->listWidget->count()-2)->text().indexOf("'") == 0)){
                    // Houla TODO
                    cout << "non géré"<<endl;
                }
                // Sinon, on fait l'opération tout de suite
                else {
                    // On ajoute l'opérateur dans la pile
                    c.insererElement(newElement.toStdString());
                    // Le résultat est le premier élément de la pile
                    result = QString::number(c.getTetePile());

                    // Si opération binaire, on supprime les deux éléments précédents (qui ont servi au calcul)
                    if(newElement == tr("+") || newElement == tr("-") || newElement == tr("*") || newElement == tr("/")){
                        ui->listWidget->takeItem(ui->listWidget->count()-1);
                        ui->listWidget->takeItem(ui->listWidget->count()-1);
                    }
                }

                // On ajoute le résultat tout en bas
                if(result != "")
                    ui->listWidget->addItem(result);
            }
        }

        // On affiche le haut de la pile et on vide le champ de saisie
        ui->listWidget->scrollToBottom();
        ui->inputLine->setText("");
    } catch(Erreur e){
        ui->labelStatus->setText(e.what());
    }
}

void Afficheur::spacePressed(){
    ui->inputLine->setText(ui->inputLine->text() + " ");
}

void Afficheur::deletePressed(){
    QString aff = ui->inputLine->text();
    aff.chop(1);
    ui->inputLine->setText(aff);
}

void Afficheur::complexeChanged(bool newState){
    if(newState)
        c.modeComplexe();
    else
        c.modeHorsComplexe();
    ui->listWidget->clear();
}

void Afficheur::anglesChanged(int index){
    if(index == 0)
        c.modeDegre();
    else if(index == 1)
        c.modeRadiant();
}

void Afficheur::modeChanged(int index){
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

Afficheur::~Afficheur()
{
    delete ui;
}
