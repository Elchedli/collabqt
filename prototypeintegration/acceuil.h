#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QDialog>

namespace Ui {
class acceuil;
}

class acceuil : public QDialog
{
    Q_OBJECT

public:
    explicit acceuil(QWidget *parent = nullptr);
    ~acceuil();

private slots:
    void on_vol_clicked();

    void on_agence_clicked();

    void on_voyage_clicked();

    void on_employes_clicked();

    void on_centres_clicked();

private:
    Ui::acceuil *ui;
};

#endif // ACCEUIL_H
