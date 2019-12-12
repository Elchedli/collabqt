#include "mainwindow.h"
#include <QMessageBox>
#include "connection.h"
#include <QApplication>
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    MainWindow w;

    try {c.createconnect();
        w.show();
    } catch (QString s)
    {qDebug()<<s;}

    return a.exec();
}
