#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>

#include <QSqlQueryModel>
class Employe
{public:
    Employe();
    Employe(int,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_poste();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * trierOffre();
    QSqlQueryModel *rechercheremploye(QString ide);



    bool supprimer(int);
private:
    QString nom,prenom,poste;
    int id;
};

#endif // ETUDIANT_H
