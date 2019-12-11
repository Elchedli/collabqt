#ifndef MODIFIER_H
#define MODIFIER_H

#include <QWidget>
#include <QDialog>
#include "sponsor.h"
namespace Ui {
class modifierchedli;
}

class modifierchedli : public QDialog
{
    Q_OBJECT

public:
    explicit modifierchedli(QWidget *parent = nullptr);
    ~modifierchedli();
    void setcol(QString c){col =c;}
    void setnom(QString n){nom =n;}

private slots:
    void on_Annuler_clicked();

    void on_modifier_2_clicked();

private:
    QString col ;
    QString nom ;
    Sponsor stmp;
    Ui::modifierchedli *ui;
};

#endif // MODIFIER_H
