#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include "abonnement.h"
#include "place.h"
#include "connection.h"
#include <QDate>
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Ajouter_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}



Place p;
void MainWindow::on_Supprimer_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Supprimer3_clicked()
{
    int num= ui->Numedit->text().toInt();
    p.supprimer(num);
    ui->Numedit->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Modifier2_clicked()
{
    int num=ui->NumEdit2->text().toInt();
    QString dispo=ui->DispoEdit2->text();
    QString duree=ui->Dureedit2->text();

   Place p(num,dispo,duree);
    bool test=p.modifier();
    if(test)
           {
             ui->tableView->setModel(p.afficher());
           QMessageBox::information(nullptr, QObject::tr("modifier une place"),
                             QObject::tr("Place modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

           }
             else
        {
                 QMessageBox::critical(nullptr, QObject::tr("modifier une place"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
         }
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Ajout_clicked()
{

        int num= ui->NumEdit2_2->text().toInt();
        QString dispo= ui->DispoEdit2_2->text();
        QString duree= ui->Dureedit2_2->text();



        Place p(num,dispo,duree);
        bool test= p.ajouter();
        if(test)
             {
             QMessageBox::information(nullptr, QObject::tr("Ajouter une Place"),
                               QObject::tr("Place  ajouté.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

             }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Ajouter une Place"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
        ui->NumEdit2_2->clear();
        ui->DispoEdit2_2->clear();
        ui->Dureedit2_2->clear();


        ui->stackedWidget->setCurrentIndex(0);
    }


void MainWindow::on_Trier_clicked()
{
    Place p;
    bool test=true;
    if(test)
    {
        ui->tableView->setModel(p.TriDuree());
        QMessageBox::information(nullptr, QObject::tr("Trier Place"),
        QObject::tr("Place tries.\n"
        "Voulez-vous enregistrer les modifications ?"),
        QMessageBox::Save
        |QMessageBox::Cancel,
        QMessageBox::Save);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("trier Place"),
    QObject::tr("Erreur !.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_cherche_textChanged(const QString &arg1)
{
    Place p;
             p.clearTable(ui->tableView);
             QString matt=ui->cherche->text();
             p.searchRegexp(ui->tableView,matt);
}

void MainWindow::on_Active_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    this->ui->tableView->setModel(p.afficher());
}


void MainWindow::on_Abonnement_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_Supprimer2_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_Supprimer2_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_Supprimer2_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_Supprimer2_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void MainWindow::on_Ajouter2_clicked()
{
    int ID= ui->Idedit->text().toInt();
    QString nom= ui->Nomedit->text();
    QString prenom= ui->Predit->text();
    QString duree= ui->Duredit->text();
    QString adresse= ui->Adedit->text();

    Abonnement a(ID,nom, prenom,duree,adresse);


    bool test=a.ajouter();
    if(test)
         {
         QMessageBox::information(nullptr, QObject::tr("Ajouter un Abonnement"),
                           QObject::tr("Abonnement ajouté.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

         }
           else
               QMessageBox::critical(nullptr, QObject::tr("Ajouter un Abonnement"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    ui->Idedit->clear();
    ui->Nomedit->clear();
    ui->Predit->clear();
    ui->Duredit->clear();
    ui->Adedit->clear();




    ui->stackedWidget->setCurrentIndex(5);
}

Abonnement a;
void MainWindow::on_Retour_3_clicked()
{


    int ID= ui->NumEdit2_3->text().toInt();
    a.supprimer(ID);
    ui->NumEdit2_3->clear();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_Retour_4_clicked()
{
    int ID=ui->NumEdit2_4->text().toInt();

    QString duree=ui->NumEdit2_6->text();

    bool test=a.modifier();
    if(test)
           {
             ui->tableView->setModel(a.afficher());
           QMessageBox::information(nullptr, QObject::tr("modifier un abonnement"),
                             QObject::tr("Abonnement modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

           }
             else
        {
                 QMessageBox::critical(nullptr, QObject::tr("modifier une place"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
         }
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_Active_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    this->ui->tableView_2->setModel(a.afficher());
}

void MainWindow::on_Supprimer2_8_clicked()
{
    Abonnement a;
    bool test=true;
    if(test)
    {
        ui->tableView->setModel(a.TriDuree());
        QMessageBox::information(nullptr, QObject::tr("Trier Abonnement"),
        QObject::tr("Abonnements tries.\n"
        "Voulez-vous enregistrer les modifications ?"),
        QMessageBox::Save
        |QMessageBox::Cancel,
        QMessageBox::Save);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("trier Place"),
    QObject::tr("Erreur !.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_cherche_2_textChanged(const QString &arg1)
{
   Abonnement a;
             a.clearTable(ui->tableView);
             QString matt=ui->cherche_2->text();
             a.searchRegexp(ui->tableView,matt);

}
