#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "acceuil.h"
#include "login.h"
#include <QString>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QDebug>
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


void MainWindow::on_connect_4_clicked(){
    QString nom = ui->identifiant_4->text(),
            pass = ui->mdp_4->text();
    if(nom.length() == 0){
        QMessageBox::critical(nullptr, QObject::tr("Erreur dans le saisie"),
        QObject::tr("Rien n'est sasie dans le  champ du nom.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
    }else if(pass.length() == 0){
        QMessageBox::critical(nullptr, QObject::tr("Erreur dans le saisie"),
        QObject::tr("Rien n'est pas sasie dans le champ du mot de passe.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    login log(nom,pass);
    bool test = log.verifierutilisateur();
    if(test && nom.length() != 0 && pass.length() != 0){
        acceuil ac;
        close();
        ac.exec();

        //ui->marketing->setCurrentIndex(10);
        //resize(598,600);
        //ui->marketing->resize(598,600);
        /*player->setMedia(QUrl::fromLocalFile("son/connected.mp3"));
        player->setVolume(100);
        player->play();
        qDebug() << player->errorString();*/
    }else if(nom.length() != 0 && pass.length() != 0){
        QMessageBox::critical(nullptr, QObject::tr("utilisateur introuvable"),
        QObject::tr("L'utilisateur n'est pas introuvalbe dans la base.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
