#include "locataire.h"

locataire::locataire()
{
    nom=prenom=email=adr="" ;
    CIN=NumTel="" ;
    id_local=0 ;
}
locataire::locataire(QString nom,QString prenom,QString email,QString adr,QString NumTel,QString CIN,int id_local)
{
    this->nom=nom ;
    this->prenom=prenom;
    this->email=email ;
    this->adr=adr ;
    this->CIN = CIN ;
    this->NumTel = NumTel ;
    this->id_local= id_local ;
}
bool locataire::ajouter_locataire()
{
QSqlQuery query;

QString id_local1= QString::number(id_local);

query.prepare("INSERT INTO locataire (CIN, nom, prenom, email, adr, NumTel, id_local ) "
                    "VALUES (:CIN, :nom, :prenom, :email , :adr, :NumTel, :id_local)");
query.bindValue(":CIN", CIN);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adr", adr);
query.bindValue(":NumTel", NumTel);
query.bindValue(":email", email);
query.bindValue(":id_local", id_local1);

return    query.exec();
}

QSqlQueryModel * locataire::afficher_locataire()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from locataire");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero de telephone "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID local"));
    return model;
}
bool locataire::supprimer_locataire(QString CIN1)
{
    QSqlQuery query;

    query.prepare("Delete from locataire where CIN =:CIN ");
    query.bindValue(":CIN", CIN1);
    return    query.exec();
}

bool locataire::modifier_locataire(QString CIN1)
{
    QSqlQuery query ;
    QString id_local1= QString::number(id_local);

    query.prepare("update locataire set CIN=:CIN , nom=:nom , prenom=:prenom , email=:email , adr=:adr, NumTel=:NumTel, id_local=:id_local WHERE CIN=:CINN");
    query.bindValue(":CIN",CIN);
    query.bindValue(":CINN",CIN1);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adr", adr);
    query.bindValue(":NumTel", NumTel);
    query.bindValue(":email", email);
    query.bindValue(":id_local", id_local1);

return query.exec();
}

QSqlQueryModel *locataire::recherche(QString nom,QString prenom)
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from locataire where nom like '"+nom+"%' OR prenom like '"+prenom+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero de telephone "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID local"));

    return model;
}
QSqlQueryModel *locataire::afficherlct(QString col)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from locataire ORDER BY " + col);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero de telephone "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID local"));

    return model;
}

