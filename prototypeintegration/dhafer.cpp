#include "dhafer.h"
#include "ui_dhafer.h"
#include <QMessageBox>
dhafer::dhafer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dhafer)
{
    ui->setupUi(this);
}

dhafer::~dhafer()
{
    delete ui;
}

void dhafer::on_ajouter_enregistrer_clicked()
{
    int num = ui->ajouter_numvol->text().toInt();
    int nbp = ui->ajouter_nbplace->text().toInt();
    float prix = ui->ajouter_prixx->text().toInt();
    QString destination = ui->ajouter_destination->text();
    QString datedepart= ui->ajouter_datedepart->text();
    QString heuredepart= ui->ajouter_heuredepart->text();
    QString datearrive= ui->ajouter_datearrivee->text();
    QString heurearrive= ui->ajouter_heurearrivee->text();
    QString typ=ui->ajouter_type->currentText();
   h.save("Num vol:","Vol AJOUTEE,NUMERO="+ui->ajouter_numvol->text());


Vols v(num,typ,datedepart,datearrive,heuredepart,heurearrive,nbp,prix,destination);

bool test=v.ajouter();
    if(test)
     {
        ui->tableView ->setModel(tempvols.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter"),
              QObject::tr("Vol ajouté.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);}
else
    QMessageBox::critical(nullptr, QObject::tr("Ajouter une vol"),
              QObject::tr("Erreur !.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void dhafer::on_supprimer_enregistrer_clicked()
{
    int num = ui->supprimer_numvol->text().toInt();
        bool test=tempvols.supprimer(num);
        h.save("Num vol:","Vol SUPPRIMEE,NUMERO="+ui->supprimer_numvol->text());

        if(test)
        {
            ui->tableView->setModel(tempvols.afficher());//refresh
            QMessageBox::information(nullptr,"SUPRESSION","supprimé.");}
        else
            QMessageBox::information(nullptr,"SUPRESSION","probleme suppresion");

}

void dhafer::on_modifier_enregistrer_clicked()
{
    int num = ui->modifier_num->text().toInt();
    int nbp = ui->modifier_nbp->text().toInt();
    float prix = ui->modifier_prix->text().toInt();
    QString destination = ui->modifier_destination->text();
    QString datedepart= ui->modifier_datedepart->text();
    QString heuredepart= ui->modifier_heuredepart->text();
    QString datearrive= ui->modifier_datearrivee->text();
    QString heurearrive= ui->modifier_heurearrive->text();
    QString typ=ui->Modifier_Type->currentText();

    h.save("Num vol:","Vol MODFIEE,NUMERO="+ui->modifier_num->text());

        /*if (ui->ajouter_entrante->isChecked())
            QString typ="Entrante";
        else
            if (ui->ajouter_sortante->isChecked())
                QString typ="Sortante";
            else
                QString typ="non décidé";*/

Vols v(num,typ,datedepart,datearrive,heuredepart,heurearrive,nbp,prix,destination);

bool test=v.modifier();
    if(test)
     {
        ui->tableView ->setModel(tempvols.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter"),
              QObject::tr("Vol Modifie.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);}
else
    QMessageBox::critical(nullptr, QObject::tr("Modifier Vol"),
              QObject::tr("Erreur !.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void dhafer::on_pushButton_modification_clicked()
{
    bool  res ;
    modifier v ;
    v.seta(0);
    QString q ;
    QModelIndex index ;
    QModelIndexList selection = ui->tableView->selectionModel()->selectedIndexes();


    //  h.save("Num vol:","Vol enregistre,NUMERO="+ui->lineEdit_numero->text()+","+"MESSAGE="+ui->lineEdit_message->text());


    for (int i =0;i<selection.count();i++)
    {
        index  = selection.at(i);
        q = QVariant(ui->tableView->model()->index(index.row(),0).data()).toString();
        v.setc(index.column());
        v.setid(q);
        res = v.exec() ;
        if (res == QDialog::Accepted)
        {
           ui->tableView->setModel(tempvols.afficher());
        }
    }
}

void dhafer::on_lineEdit_textChanged(const QString &arg1)
{
    int i = ui->listerrecherche->currentIndex();
    ui->tableView->setModel(tempvols.recherche2(arg1,i));
}

void dhafer::on_listertrier_currentIndexChanged(int index)
{
    if (index==0)
    {
          ui->tableView->setModel(tempvols.afficher());
    }
    else
    {
          ui->tableView->setModel(tempvols.tri(index));
    }
}

void dhafer::on_combo_type_stat_currentTextChanged()
{
    delete mainLayout;
            mainLayout=new QVBoxLayout ;
            //mainLayout->addWidget(s.Preparechart(ui->combo_type_stat->currentText()));
            ui->widget->setLayout(mainLayout);
}

void dhafer::on_pushButton_clicked()
{
    QFile file("‪C:\\Users\\shidono\\Desktop\\Vol\\histo.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
}

void dhafer::on_Vol_currentChanged(int index)
{
    if(index==4)
        {delete mainLayout;
            mainLayout=new QVBoxLayout ;
            //mainLayout->addWidget(s.Preparechart(ui->combo_type_stat->currentText()));
            ui->widget->setLayout(mainLayout);}
        else if (index==5)
            ui->textEdit->setPlainText(h.load());

}
