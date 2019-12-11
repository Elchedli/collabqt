#include "modifierchedli.h"
#include "ui_modifierchedli.h"

modifierchedli::modifierchedli(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierchedli)
{
    ui->setupUi(this);
}

modifierchedli::~modifierchedli()
{
    delete ui;
}

void modifierchedli::on_Annuler_clicked(){
  accept();
}

void modifierchedli::on_modifier_2_clicked(){
    stmp.modifier(nom,ui->nv->text(),col);
    accept();
}
