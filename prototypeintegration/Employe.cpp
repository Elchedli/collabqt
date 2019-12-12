#include "Employe.h"
#include <QDebug>
Employe::Employe()
{
id=0;
nom="";
prenom="";
poste="";
}
Employe::Employe(int id,QString nom,QString prenom,QString poste)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->poste=poste;
}
QString Employe::get_nom(){return  nom;}
QString Employe::get_poste(){return  poste;}
QString Employe::get_prenom(){return prenom;}
int Employe::get_id(){return  id;}

bool Employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO employe (ID, NOM, PRENOM,POSTE) "
                    "VALUES (:id, :nom, :prenom, :poste)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":poste", poste);

return    query.exec();
}

QSqlQueryModel * Employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));


    return model;
}

bool Employe::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from employe where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel *Employe::trierOffre()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  nom, id, prenom, poste from EMPLOYE order by nom");
   return model ;
}

QSqlQueryModel *Employe::rechercheremploye(QString ide)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from EMPLOYE where id= '"+ide+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}


