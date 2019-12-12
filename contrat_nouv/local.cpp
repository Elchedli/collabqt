#include "local.h"


local::local()
{
    id = duree = 0 ;
    type = "";
    prix = superficie = 0 ;
    CIN_Locataire = 0 ;
    dispo = "" ;

}
local::local(int id,QString type,double superficie,double prix,QString dispo,int duree,long CIN_Locataire)
{
    this->id=id ;
    this->type=type ;
    this->superficie=superficie ;
    this->prix=prix ;
    this->dispo=dispo ;
    this->duree=duree;
    this->CIN_Locataire=CIN_Locataire ;
}
bool local::ajouter_local()
{
QSqlQuery query;
QString id1= QString::number(id);
QString superficie1= QString::number(superficie);
QString prix1= QString::number(prix);
QString duree1= QString::number(duree);
QString CIN_Locataire1= QString::number(CIN_Locataire);

query.prepare("INSERT INTO local (id, type, superficie, prix, dispo, duree, CIN_Locataire) "
                    "VALUES (:id, :type, :superficie, :prix , :dispo, :duree, :CIN_Locataire)");
query.bindValue(":id", id1);
query.bindValue(":type", type);
query.bindValue(":superficie", superficie1);
query.bindValue(":prix", prix1);
query.bindValue(":dispo", dispo);
query.bindValue(":duree", duree1);
query.bindValue(":CIN_Locataire", CIN_Locataire1);

return    query.exec();
}
QSqlQueryModel * local::afficher_local()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from local");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("superficie"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("disponibilite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN Locataire"));
    return model;
}
bool local::supprimer_local(int idd)
{
QSqlQuery query;
QString ID1= QString::number(idd);
query.prepare("Delete from local where id = :id ");
query.bindValue(":id", ID1);
return    query.exec();
}
bool local::modifier_local(int IDD)
{
    QSqlQuery query ;
    QString ID0 = QString::number(id);
    QString ID1 = QString::number(IDD);
    QString superficie1= QString::number(superficie);
    QString prix1= QString::number(prix);
    QString duree1= QString::number(duree);
    QString CIN_Locataire1= QString::number(CIN_Locataire);

    query.prepare("update local set id=:id ,type=:type,superficie=:superficie,prix=:prix,dispo=:dispo,duree=:duree,CIN_Locataire=:CIN_Locataire where ID=:IDD");
    query.bindValue(":id",ID0);
    query.bindValue(":IDD",ID1);
    query.bindValue(":type", type);
    query.bindValue(":superficie", superficie1);
    query.bindValue(":prix", prix1);
    query.bindValue(":dispo", dispo);
    query.bindValue(":duree", duree1);
    query.bindValue(":CIN Locataire", CIN_Locataire1);

return query.exec();
}
QSqlQueryModel *local::afficherlc(QString col)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from local ORDER BY " + col);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("superficie"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("disponibilite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN Locataire"));

    return model;
}

QSqlQueryModel *local::recherche(QString Type)
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from local where Type like '"+Type+"%'   ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("superficie"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("disponibilite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN Locataire"));
    return model;
}
