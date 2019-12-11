#ifndef AMINE_H
#define AMINE_H

#include <QDialog>
#include "amine/locataire.h"
#include "amine/local.h"
#include "ui_amine.h"
#include <QtWidgets/QMessageBox>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

class amine : public QDialog
{
    Q_OBJECT

public:
    explicit amine(QWidget *parent = nullptr);
    ~amine();

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
    Ui::amine *ui;
    locataire tmplocataire ;
    local tmplocal ;

};
#endif // AMINE_H
