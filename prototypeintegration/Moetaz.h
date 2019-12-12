#ifndef Moetaz_H
#define Moetaz_H
#include "Employe.h"
#include <QDialog>

namespace Ui {
class Moetaz;
}

class Moetaz : public QDialog
{
    Q_OBJECT

public:
    explicit Moetaz(QWidget *parent = nullptr);
    ~Moetaz();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();
    void makePlot_poste ();
    QVector<double> Statistique_poste();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    int on_pushButton_4_clicked();

    void on_tabetudiant_clicked(const QModelIndex &index);

    bool on_pushButton_5_clicked();

private:
    Ui::Moetaz *ui;
    Employe tmpetudiant;
};

#endif // Moetaz_H
