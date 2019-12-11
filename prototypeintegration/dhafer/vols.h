#ifndef VOLS_H
#define VOLS_H
#include <QString>
#include <QSqlQueryModel>

class Vols
{
private:
    int num,nbp;
    int prix;
    QString es,destination,datedepart,dateretour,heuredepart,heurerearrive;

public:
    Vols();
    Vols(int,QString ,QString ,QString,QString,QString ,int ,int,QString);
    int get_num();
    QString get_type();
    int get_nbp();

    int get_prix();
    QString get_es();
    QString get_destination();
    QString get_datedepart();
    QString get_dateretour();
    QString get_heuredepart();
    QString get_heureretour();
    QSqlQueryModel* tri (int);
    QSqlQueryModel* recherche2 (QString,int);
    bool modfier(QString,QString,int);
    bool modifier();
    bool rechercher(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);


};

#endif // VOLS_H
