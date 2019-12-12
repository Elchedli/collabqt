#include "abonnement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableView>

Abonnement::Abonnement()
{
    ID =0;
    nom ="";
    prenom ="";
    adresse="";
    duree="";
}

Abonnement::Abonnement( int ID, QString nom, QString prenom, QString adresse,QString duree)
{
    this->ID =ID;
    this->nom =nom;
    this->prenom =prenom;
    this->adresse =adresse;
    this->duree =duree;
}

bool Abonnement::ajouter()
{
    QSqlQuery query;
    QString res1=QString::number(ID);


          query.prepare("INSERT INTO Abonnement (Id, nom, prenom, adresse,duree) "
                        "VALUES (:ID,:nom,:prenom,:adresse,:duree)");
          query.bindValue(":ID", res1);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
query.bindValue(":adresse",adresse);
query.bindValue(":duree",duree);
          return query.exec();
}

QSqlQueryModel* Abonnement::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Abonnement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("duree"));
    return  model;
}

void Abonnement::supprimer(int code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Abonnement WHERE ID=:ID");
    QString res1=QString::number(ID);
    query.bindValue(":ID", res1);
    query.exec();
}

bool Abonnement :: modifier()
{
    QSqlQuery query;
    QString res1=QString::number(ID);
         query.prepare("UPDATE Abonnement SET nom=:modifnom, prenom=:modifprenom , adresse=:modifadresse, duree=:modifduree WHERE ID =:modifID;");
         query.bindValue(":modifID",res1);
         query.bindValue(":modifnom",nom);
         query.bindValue(":modifprenom",prenom);
         query.bindValue(":modifadresse",adresse);
         query.bindValue(":modifduree",duree);
         return query.exec();
}

QSqlQueryModel * Abonnement :: TriDuree()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Abonnement ORDER BY duree");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("duree"));
    return model;
}

void Abonnement::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}

void Abonnement::searchRegexp(QTableView *table, QString x)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from Abonnement where regexp_like(ID,:ID);");
   query->bindValue(":ID",x);

   if(x==0)
   {
       qDebug("tawa 0");
       query->prepare("select * from Abonnement;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}

bool Abonnement:: recherche(int ID)
{
    QSqlQuery query;
    query.prepare("select * from Abonnement where ID=:ID");
    query.bindValue(":ID",ID);
    return query.exec() ;
}
