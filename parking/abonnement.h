#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QString>
#include <QTableView>
#include <QSqlQueryModel>
#include <QTableView>

class Abonnement
{
    int ID;
   QString nom;
    QString prenom;
    QString adresse;
    QString duree;
public:
    Abonnement();
    Abonnement(int, QString, QString,QString,QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    void supprimer(int ID);
    bool modifier();
    QSqlQueryModel* TriDuree();
    void clearTable(QTableView* table);
    void searchRegexp(QTableView *table, QString x);
    bool recherche(int ID);
    ~Abonnement(){};
};

#endif // ABONNEMENT_H
