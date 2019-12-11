#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QtDebug>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test){
        w.resize(570,525);
        w.show();
    }
    return a.exec();
}
