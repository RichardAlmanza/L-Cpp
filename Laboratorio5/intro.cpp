#include "intro.h"
#include "ui_intro.h"

Intro::Intro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Intro)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(Datoingresado()));
    connect(ui->pushButton_2,SIGNAL(pressed()),this,SLOT(Cancelado()));
}

Intro::~Intro()
{
    delete ui;
}

int Intro::getvalor()
{
    return valor;
}


void Intro::Datoingresado()
{
    valor = ui->spinBox->value();
    emit ingresa();
}

void Intro::Cancelado()
{
    this->hide();
}
