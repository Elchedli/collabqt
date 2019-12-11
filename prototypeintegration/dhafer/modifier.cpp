#include "modifier.h"
#include "ui_modifier.h"

modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
}

modifier::~modifier()
{
    delete ui;
}

void modifier::on_pushButton_2_clicked()
{
    {
        if (a==1)
        {
        tempvols.modfier(id,ui->lineEdit->text(),c);
        accept();
            return ;
        }
        tempvols.modfier(id,ui->lineEdit->text(),c);
            accept();
    }
}

void modifier::on_annuler_clicked()
{
        reject();
}
