#include "vols.h"
#include <QSqlQuery>
#include <QDebug>
#include <QString>
Vols::Vols(){
    num=0;
    es="";
    nbp=0;
    prix=0;
    destination="";
    datedepart="";
    dateretour="";
    heuredepart="";
    heurerearrive="";

}


Vols::Vols(int no,QString t,QString dd,QString dr,QString hd,QString hr,int n,int p,QString d)
{
num=no;
es=t;
nbp=n;

prix=p;
destination=d;
datedepart=dd;
dateretour=dr;
heuredepart=hd;
heurerearrive=hr;
}

int Vols::get_num(){return num;}
int Vols::get_nbp(){return nbp;}
int Vols::get_prix(){return prix;}

QString Vols::get_destination(){return  destination;}
QString Vols::get_datedepart(){return  datedepart;}
QString Vols::get_dateretour(){return  dateretour;}
QString Vols::get_heuredepart(){return  heuredepart;}
QString Vols::get_heureretour(){return  heurerearrive;}
QString Vols::get_es(){return  es;}


bool Vols::ajouter()
{
QSqlQuery query;
QString res= QString::number(num);
QString res2= QString::number(prix);
QString res3= QString::number(nbp);
query.prepare("INSERT INTO vol(num,datedepart,dateretour,heuredepart,heurerearrive,nbp,prix,destination, es) VALUES (:num,:datedepart,:dateretour,:heuredepart,:heurerearrive,:nbp,:prix,:destination, :es)");
query.bindValue(":num", res);
query.bindValue(":nbp", res3);
query.bindValue(":datedepart", datedepart);
query.bindValue(":dateretour", dateretour);

query.bindValue(":heuredepart", heuredepart);
query.bindValue(":heurerearrive", heurerearrive);
query.bindValue(":prix", res2);

query.bindValue(":destination", destination);
query.bindValue(":es", es);

return    query.exec();
}

QSqlQueryModel * Vols::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from vol");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date de depart"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date d arrivee"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure de depart"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Heure d arrivee"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de place"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Prix TND "));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Destination"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Type"));


return model;
}

bool Vols::supprimer(int num)
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("Delete from Vol where num =:num ");
query.bindValue(":num", res);

return    query.exec();
}

bool Vols::rechercher(int num)
{
    QSqlQuery query;
    int count=0;
    bool test=0;
    QString res=QString::number(num);
    if(query.exec("select id from Vol where  Num='" +res +"'"))
    {
    while(query.next())
        count++;
    if(count>=1)
        test=1;
    }

return test;

}

QString test_modifier(int c)
{
    if (c==0)
    {
        return "num" ;
    }
    else if (c==1)
    {
        return "datedepart";
    }
    else if (c==2)
    {
     return "dateretour" ;
    }
    else if (c==3)
    {
        return "heurededepart" ;
    }
    else if (c==4)
    {
        return "heurerearrive";
    }    else if (c==5)
    {
        return "nbp";
    }    else if (c==6)
    {
        return "prix";
    }    else if (c==7)
    {
        return "destination";
    }    else if (c==8)
    {
        return "es";
    }


    return "NULL";
}

bool Vols::modifier()
{
    QSqlQuery query;
    QString res=QString::number(num);
    QString res2=QString::number(prix);
    QString res3=QString::number(nbp);
    query.prepare("update Vol set num=:num,datedepart=:datedepart,dateretour=:dateretour,heuredepart=:heuredepart,heurerearrive=:heurerearrive,nbp=:nbp,prix=:prix,destination=:destination,es=:es  where num=:num ");
    query.bindValue(":num",res);
    query.bindValue(":datedepart",datedepart);
    query.bindValue(":dateretour",dateretour);
    query.bindValue(":heuredepart",heuredepart);
    query.bindValue(":heurearrive",heurerearrive);
    query.bindValue(":nbp",res3);
    query.bindValue(":prix",res2);
    query.bindValue(":destination",destination);
    query.bindValue(":es",es);
    qDebug()<<query.executedQuery();
    return query.exec();
}

bool Vols :: modfier(QString id,QString nval,int c)
{
     QString col = test_modifier(c);
     QString header ;
     QSqlQuery q;
     header = "update Vol set "+col+"=:nv where (num=:id);";
     q.prepare(header);
     q.bindValue(":nv",nval);
     q.bindValue(":id",id);

     return q.exec();
}





QString test_tri(int c)
{
    if (c==0)
    {
        return "num" ;
    }
    else if (c==1)
    {
        return "datedepart";
    }
    else if (c==2)
    {
     return "dateretour" ;
    }
    else if (c==3)
    {
        return "heurededepart" ;
    }
    else if (c==4)
    {
        return "heurerearrive";
    }    else if (c==5)
    {
        return "nbp";
    }    else if (c==6)
    {
        return "prix";
    }    else if (c==7)
    {
        return "destination";
    }
    else if (c==8)
    {
        return "es";
    }


    return "NULL";
}


QSqlQueryModel* Vols::tri(int i)
{
    QString col = test_tri(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT * FROM Vol ORDER BY "+col;
    model->setQuery(header);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date de depart"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de retour"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("heure de depart"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("heure de retour"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre de place"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("destination"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("type"));

    return model ;
}

QString test_recherche(int c)
{
    if (c==0)
    {
        return "num" ;
    }
    else if (c==1)
    {
        return "datedepart";
    }
    else if (c==2)
    {
     return "dateretour" ;
    }
    else if (c==3)
    {
        return "heurededepart" ;
    }
    else if (c==4)
    {
        return "heurerearrive";
    }    else if (c==5)
    {
        return "nbp";
    }    else if (c==6)
    {
        return "prix";
    }    else if (c==7)
    {
        return "destination";
    }    else if (c==8)
    {
        return "es";
    }


    return "NULL";
}


QSqlQueryModel*Vols:: recherche2(QString x,int i)
{
    QString col = test_recherche(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT* FROM vol WHERE "+col+" LIKE '"+x+"%'";
    model->setQuery(header);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date de depart"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de retour"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("heure de depart"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("heure de retour"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre de place"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("destination"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("type"));

    return model ;
}
