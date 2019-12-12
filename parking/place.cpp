#include "place.h"

#include <QSqlQuery>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableView>

Place::Place()
{
   num =0;
    dispo ="";
    duree ="";

}

Place::Place( int num, QString dispo, QString duree)
{
    this->num =num;
    this->dispo =dispo;
    this->duree =duree;
}

bool Place::ajouter()
{
    QSqlQuery query;
    QString res1=QString::number(num);


          query.prepare("INSERT INTO Place (num, dispo,duree) "
                        "VALUES (:num,:dispo,:duree)");
          query.bindValue(":num", res1);
          query.bindValue(":dispo", dispo);
query.bindValue(":duree",duree);
          return query.exec();
}

QSqlQueryModel* Place::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Place");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dispo"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
    return  model;
}

void Place::supprimer(int num)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Place WHERE num= :num");
    QString res1=QString::number(num);
    query.bindValue(":num", res1);
    query.exec();
}

bool Place :: modifier()
{
    QSqlQuery query;
    QString res1=QString::number(num);
         query.prepare("UPDATE Place SET dispo=:modifdispo, duree=:modifduree WHERE num =:modifnum;");
         query.bindValue(":modifnum",res1);
         query.bindValue(":modifdispo",dispo);
         query.bindValue(":modifduree",duree);
         return query.exec();
}

QSqlQueryModel * Place :: TriDuree()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Place ORDER BY duree");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dispo"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
    return model;
}

void Place::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}

void Place::searchRegexp(QTableView *table, QString x)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from Place where regexp_like(num,:num);");
   query->bindValue(":num",x);

   if(x==0)
   {
       qDebug("tawa 0");
       query->prepare("select * from Place;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}

bool Place:: recherche(int num)
{
    QSqlQuery query;
    query.prepare("select * from Place WHERE num=:num");
    query.bindValue(":num",num);
    return query.exec() ;
}
