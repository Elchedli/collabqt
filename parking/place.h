#ifndef PLACE_H
#define PLACE_H
#include <QString>
#include <QTableView>
#include <QSqlQueryModel>
#include <QTableView>

class Place
{
    int num;
  QString dispo;
  QString duree;

public:
    Place();
    Place(int, QString, QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    void supprimer(int num);
    bool modifier();
    QSqlQueryModel* TriDuree();
    void clearTable(QTableView* table);
    void searchRegexp(QTableView *table, QString x);
    bool recherche(int num);
    ~Place(){};
};
#endif // PLACE_H
