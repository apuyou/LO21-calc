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

void Afficheur::enterPressed(){
    try{
        c.insererElement(ui->inputLine->text().toStdString());
        std::cout << "la pile contient :";
        c.afficherPile();
        ui->inputLine->setText("");
    } catch(Erreur e){
        std::cout<<e.what()<<std::endl;
    }
}

void Afficheur::spacePressed(){
    ui->inputLine->setText(ui->inputLine->text() + " ");
}

Afficheur::~Afficheur()
{
    delete ui;
}
