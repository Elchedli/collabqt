#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QByteArray>
#include "arduino.h"
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

void updatelcd();


void on_refresh_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray data;

    Arduino a;
};
#endif // MAINWINDOW_H
