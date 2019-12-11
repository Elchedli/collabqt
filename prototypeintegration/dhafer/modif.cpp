#include "dhafer/modif.h"
#include "ui_modif.h"

Modif::Modif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modif)
{
    ui->setupUi(this);
}

Modif::~Modif()
{
    delete ui;
}
