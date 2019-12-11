#ifndef LOCATAIRE_H
#define LOCATAIRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class locataire
{
private :
    QString nom,prenom,email,adr;
    QString CIN,NumTel ;
    int id_local ;
public :
    locataire();
    locataire(QString,QString,QString,QString,QString,QString,int);
    QString get_nom() { return nom; }
    QString get_prenom() { return prenom ; }
    QString get_email() { return email ; }
    QString get_adr() { return adr ; }
    int get_id_local() { return id_local ; }
    QString get_CIN() const { return CIN ; }
    QString get_NumTel()  { return NumTel ; }
    bool ajouter_locataire() ;
    QSqlQueryModel * afficher_locataire();
    void rechercher_locataire(QString) ;
    bool supprimer_locataire(QString) ;
    bool modifier_locataire(QString) ;
    QSqlQueryModel * recherche(QString,QString);
    QSqlQueryModel * afficherlct(QString);

} ;
#endif // LOCATAIRE_H
