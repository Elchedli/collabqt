#include "sponsor.h"
#include <QDebug>
#include <QString>
Sponsor::Sponsor(){
    nom="";
    localisation="";
    pays="";
    contrat = 0;
}
Sponsor::Sponsor(QString a,QString b,QString c,int d){
    this->nom = a;
    this->localisation = b;
    this->pays = c;
    this->contrat = d;
}

Sponsor::Sponsor(QString a,QString h,QString b,QString c,int d){
    this->nom = a;
    this->changer = h;
    this->localisation = b;
    this->pays = c;
    this->contrat = d;
}
bool Sponsor::ajouterpourc(QString a,float percent){
    QSqlQuery query;
    QString p;
    p.setNum(percent);
    query.prepare("INSERT INTO SponsorPerc (nom,percent) "
                        "VALUES (:nom, :percent)");
    query.bindValue(":nom",a);
    query.bindValue(":percent", p);
    return query.exec();
}
bool Sponsor::ajouterbase(){
    QSqlQuery query;
    query.prepare("INSERT INTO Sponsor (nom,localisation,pays,contrat) "
                        "VALUES (:nom, :localisation, :pays, :contrat)");
    query.bindValue(":nom", nom);
    query.bindValue(":localisation", localisation);
    query.bindValue(":pays", pays);
    query.bindValue(":contrat", contrat);
    return (query.exec() && ajouterpourc(nom,20));
}


bool Sponsor::modifierbase(){
    QSqlQuery query;
    if(localisation != "") query.prepare("UPDATE TABLE Sponsor SET localisation = :localisation WHERE  nom = :nom");
    if(pays != "") query.prepare("UPDATE TABLE Sponsor SET pays = :pays WHERE  nom = :nom");
    if(contrat != 0) query.prepare("UPDATE TABLE Sponsor SET contrat = :contrat WHERE  nom = :nom");
    if(changer != "") query.prepare("UPDATE TABLE Sponsor SET nom = :changer WHERE  nom = :nom");
    query.bindValue(":nom", nom);
    query.bindValue(":changer", changer);
    query.bindValue(":localisation", localisation);
    query.bindValue(":pays", pays);
    query.bindValue(":contrat", contrat);
    return    query.exec();
}

QSqlQueryModel * Sponsor::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Sponsor");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCALISATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CONTRAT"));
    return model;
}
QSqlQueryModel * Sponsor::afficher2(QString a){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM Sponsor ORDER BY ("+a+")");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCALISATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CONTRAT"));
    return model;
}
QSqlQueryModel * Sponsor::recherchepourtrie(QString a){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM SponsorPerc ORDER BY ("+a+")");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PERCENT"));
    return model;
}

QSqlQueryModel * Sponsor::AfficherPerc(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from SponsorPerc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PERCENT"));
    return model;
}
bool Sponsor::supprimer(QString nom){
    QSqlQuery query;
    query.prepare("Delete from Sponsor where nom = :nom ");
    query.bindValue(":nom", nom);
    return    query.exec();
}


bool Sponsor::modifier(QString nom, QString nv, QString col){
   QSqlQuery q ;
   QString header = "Update Sponsor set "+col+" = :nv where (nom = :nom)";
   q.prepare(header);
   q.bindValue(":nv",nv);
   q.bindValue(":nom",nom);
return q.exec();
}

bool Sponsor::modifier2(QString nom, QString nv, QString col){
   QSqlQuery q ;
   QString header = "Update SponsorPerc set "+col+" = :nv where (nom = :nom)";
   q.prepare(header);
   q.bindValue(":nv",nv);
   q.bindValue(":nom",nom);
    return q.exec();
}


QSqlQueryModel * Sponsor::recherche(QString a,QString b){
   QSqlQuery q ;
   QSqlQueryModel * model= new QSqlQueryModel();
   model->setQuery("SELECT * FROM Sponsor WHERE "+a+" LIKE '%"+b+"%'");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCALISATION"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("CONTRAT"));
   return model;
}

QSqlQueryModel * Sponsor::recherchepour(QString a,QString b){
   QSqlQuery q ;
   QSqlQueryModel * model= new QSqlQueryModel();
   model->setQuery("SELECT * FROM SponsorPerc WHERE "+a+" LIKE '%"+b+"%'");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("PERCENT"));
   return model;
}
