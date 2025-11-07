#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QJSEngine>

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
#if 0
    QObject::connect(ui->pushButton0_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButton1_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButton2_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButton3_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButton4_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButton5_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButton6_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButton7_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButton8_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButton9_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButtonAdditionner_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButtonDiviser_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButtonMultiplier_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    QObject::connect(ui->pushButtonSoustraire_2, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
#endif

    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, allButtons) {
        if(button->text() != "=" && button->text() != "C") {
            connect(button, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
        }
    }
}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::onQPushButtonClicked()
{
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    QString valeur = touche->text();
    ui->lineEditAfficheur_2->setText(ui->lineEditAfficheur_2->text()+valeur);
}


void Calculatrice::on_pushButtonEgal_2_clicked()
{
    QJSEngine expression;
    ui->lineEditAfficheur_2->setText(expression.evaluate(ui->lineEditAfficheur_2->text()).toString());
}


void Calculatrice::on_pushButtonEffacer_2_clicked()
{
    ui->lineEditAfficheur_2->clear();
}
