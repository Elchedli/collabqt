#include "acceuil.h"
#include "ui_acceuil.h"
#include "dhafer.h"
#include "chedli.h"
#include "amine.h"
acceuil::acceuil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::acceuil)
{
    ui->setupUi(this);
}

acceuil::~acceuil()
{
    delete ui;
}

void acceuil::on_vol_clicked(){
    ui->selection->move(0,146);
    dhafer dh;
    dh.exec();
}

void acceuil::on_agence_clicked()
{
    ui->selection->move(0,180);
    chedli ch;
    ch.exec();
}

void acceuil::on_voyage_clicked()
{
    ui->selection->move(0,217);
}

void acceuil::on_employes_clicked()
{
    ui->selection->move(0,256);
}

void acceuil::on_centres_clicked()
{
    ui->selection->move(0,297);
    amine am;
    am.exec();
}
