#include "connection.h"
#include <QSqlError>
#include <QString>
Connection::Connection(){

}

bool Connection::createconnect(){
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("shidono");
db.setUserName("shidono");//inserer nom de l'utilisateur
db.setPassword("closers1");//inserer mot de passe de cet utilisateur
if (db.open()) test=true;
else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}

void Connection::fermerConnexion(){
    db.close();
}

