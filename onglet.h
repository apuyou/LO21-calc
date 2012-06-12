#ifndef ONGLET_H
#define ONGLET_H

#include <iostream>
#include "Calculateur.h"

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

class onglet: public QWidget
{
    Q_OBJECT

public:
    onglet(QWidget *parent = 0);
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
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboType;
    QComboBox *comboAngles;
    QCheckBox *checkboxComplexes;
    QSpacerItem *horizontalSpacer;
    QLabel *labelStatus;

protected:
    void setupUi(QWidget *parent);
    void retranslateUi(QWidget *parent);
    void setupSignals(QWidget *parent);
    Calculateur c;  /* Calculateur utilisé pour effectuer les opérations de l'utilisateur */

private slots:
    void genericButtonPressed();
    void enterPressed();
    void spacePressed();
    void deletePressed();
    void complexeChanged(bool newState);
    void anglesChanged(int index);
    void modeChanged(int index);

};

#endif // ONGLET_H
