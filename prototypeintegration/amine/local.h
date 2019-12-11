#ifndef LOCAL_H
#define LOCAL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class local
{
private:
    int id ;
    QString type ;
    double superficie ;
    double prix ;
    QString dispo ;
    int duree ;
    long CIN_Locataire ;

public:
    local();
    local(int,QString,double,double,QString,int,long) ;
    int get_ID()const { return id; }
    QString get_type() { return type;}
    double get_superficie() {return superficie ;}
    double get_prix() { return prix ; }
    QString get_dispo() { return dispo ; }
    int get_duree() { return duree ; }
    long get_CIN_Locat() { return CIN_Locataire ; }
    bool ajouter_local() ;
    bool modifier_local(int) ;
    void rechercher_local(int) ;
    bool supprimer_local(int) ;
    QSqlQueryModel * afficher_local() ;
    QSqlQueryModel * recherche(QString);
    QSqlQueryModel * afficherlc(QString);

};
#endif // LOCAL_H
