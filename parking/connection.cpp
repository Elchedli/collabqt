#include "connection.h"
#include <QDebug>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Zribi");//inserer nom de l'utilisateur
db.setPassword("Zribi1999");//inserer mot de passe de cet utilisateur
if (db.open())
test=true;
else
    throw QString("Erreur"+db.lastError().text());

    return  test;
}
