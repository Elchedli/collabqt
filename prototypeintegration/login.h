#ifndef LOGIN_H
#define LOGIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>

class login{
public:
    bool verifierutilisateur();
    login(QString,QString);
    bool ajouteruser();
private:
    QString nom,pass;
};

#endif // LOGIN_H
