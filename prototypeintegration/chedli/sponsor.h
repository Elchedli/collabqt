#ifndef SPONSOR_H
#define SPONSOR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Sponsor{
    public:
    Sponsor();
    Sponsor(QString,QString,QString,int);
    Sponsor(QString,QString,QString,QString,int);
    bool ajouterbase();
    bool ajouterpourc(QString,float);
    bool modifierbase();
    bool modifier(QString nom , QString nv ,QString col);
    bool modifier2(QString nom , QString nv ,QString col);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2(QString);
    QSqlQueryModel * AfficherPerc();
    QSqlQueryModel * recherche(QString,QString);
    QSqlQueryModel * recherchepourtrie(QString);
    QSqlQueryModel * recherchepour(QString,QString);
    bool supprimer(QString);
    private:
    int contrat;
    QString nom,localisation,pays,changer;
};

#endif // SPONSOR_H
