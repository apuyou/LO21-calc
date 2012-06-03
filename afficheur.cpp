#include "afficheur.h"
#include "ui_afficheur.h"
#include "Calculateur.h"

Afficheur::Afficheur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Afficheur)
{
    ui->setupUi(this);
    connect(ui->num0Button, SIGNAL(clicked()), this, SLOT(num0Pressed()));
    connect(ui->num1Button, SIGNAL(clicked()), this, SLOT(num1Pressed()));
    connect(ui->num2Button, SIGNAL(clicked()), this, SLOT(num2Pressed()));
    connect(ui->num3Button, SIGNAL(clicked()), this, SLOT(num3Pressed()));
    connect(ui->num4Button, SIGNAL(clicked()), this, SLOT(num4Pressed()));
    connect(ui->num5Button, SIGNAL(clicked()), this, SLOT(num5Pressed()));
    connect(ui->num6Button, SIGNAL(clicked()), this, SLOT(num6Pressed()));
    connect(ui->num7Button, SIGNAL(clicked()), this, SLOT(num7Pressed()));
    connect(ui->num8Button, SIGNAL(clicked()), this, SLOT(num8Pressed()));
    connect(ui->num9Button, SIGNAL(clicked()), this, SLOT(num9Pressed()));
    connect(ui->enterButton, SIGNAL(clicked()), this, SLOT(enterPressed()));
    connect(ui->spaceButton, SIGNAL(clicked()), this, SLOT(spacePressed()));
    connect(ui->opDivideButton, SIGNAL(clicked()), this, SLOT(opDividePressed()));
    connect(ui->opMinusButton, SIGNAL(clicked()), this, SLOT(opMinusPressed()));
    connect(ui->opPlusButton, SIGNAL(clicked()), this, SLOT(opPlusPressed()));
    connect(ui->opTimesButton, SIGNAL(clicked()), this, SLOT(opTimesPressed()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deletePressed()));
}

void Afficheur::num0Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "0");
}

void Afficheur::num1Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "1");
}

void Afficheur::num2Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "2");
}

void Afficheur::num3Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "3");
}

void Afficheur::num4Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "4");
}

void Afficheur::num5Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "5");
}

void Afficheur::num6Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "6");
}

void Afficheur::num7Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "7");
}

void Afficheur::num8Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "8");
}

void Afficheur::num9Pressed(){
    ui->inputLine->setText(ui->inputLine->text() + "9");
}

void Afficheur::opDividePressed(){
    ui->inputLine->setText(ui->inputLine->text() + "/");
}

void Afficheur::opMinusPressed(){
    ui->inputLine->setText(ui->inputLine->text() + "-");
}

void Afficheur::opPlusPressed(){
    ui->inputLine->setText(ui->inputLine->text() + "+");
}

void Afficheur::opTimesPressed(){
    ui->inputLine->setText(ui->inputLine->text() + "*");
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
            c.insererElement(newElement.toStdString());
            QString result = QString::number(c.getTetePile());

            // Si opération binaire, on supprime les deux dernières lignes
            if(newElement == tr("+") || newElement == tr("-") || newElement == tr("*") || newElement == tr("/")){
                ui->listWidget->takeItem(ui->listWidget->count()-1);
                ui->listWidget->takeItem(ui->listWidget->count()-1);
            }

            ui->listWidget->addItem(result);
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

Afficheur::~Afficheur()
{
    delete ui;
}
