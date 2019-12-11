#include "login.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
login::login(QString a, QString b){
    this->nom = a;
    this->pass = b;
}
bool login::verifierutilisateur(){
    QSqlQuery query;
    query.prepare("SELECT nom,pass FROM userr WHERE NOM = :nom AND PASS = :pass");
    query.bindValue(":nom", nom);
    query.bindValue(":pass", pass);
    if(query.exec()){
        if(query.next()) return 1;
    }
    return 0;
}

bool login::ajouteruser(){
    QSqlQuery query;
    qDebug() <<     query.prepare("INSERT INTO userr (nom,pass) "
                        "VALUES (:nom, :pass)");
    query.bindValue(":nom", nom);
    query.bindValue(":pass", pass);
    return query.exec();
}

