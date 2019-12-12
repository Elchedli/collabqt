#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   a.connect_arduino();

//QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(updatelcd()));


}

MainWindow::~MainWindow()
{
    delete ui;
    a. write_arduino("0");
    a.close_arduino();

}

void MainWindow::updatelcd()
{ a.getserial()->waitForReadyRead(500);

    data=a.read_arduino();

    qDebug()<<data;
    ui->lcdNumber->display(data.toDouble());
    if(data<"17.2")
       a. write_arduino("1");
    else if(data>="17.2")
       a. write_arduino("2");


}

void MainWindow::on_refresh_clicked()
{
   //a.write_arduino("4");
     a.close_arduino();
     a.connect_arduino();
    qDebug()<<"testing";
 updatelcd();

}
