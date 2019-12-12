#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "locataire.h"
#include "local.h"
#include <QtWidgets/QMessageBox>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajout_locataire_clicked();
    void on_supp_locataire_clicked();
    void on_modif_locataire_clicked();



    void on_Ajout_local_clicked();
    void on_modif_local_clicked();
    void on_supp_local_clicked();



    void on_Trier_locataire_clicked();


    void on_lineRNOM_textChanged();

    void on_lineRTYPE_textChanged();

    void on_Trier_local_clicked();

    void on_Envoyer_clicked();

private:
    Ui::MainWindow *ui;
    locataire tmplocataire ;
    local tmplocal ;

};

#endif // MAINWINDOW_H
