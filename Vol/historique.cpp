#include "historique.h"


Historique::Historique()
{

}
void Historique::save(QString type,QString req)
{    QFile file ("C:/Users/Dhafer/Desktop/Vol/hiso.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << type+"\n"+req << "\n";


}
QString Historique::load()
{   tmp="";
    QFile file("C:/Users/Dhafer/Desktop/Vol/hiso.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();  // readline automatically removes the EOL
         tmp+=myString+"\n";

   }
   return tmp;
}

