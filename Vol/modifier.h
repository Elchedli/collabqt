#ifndef MODIFIER_H
#define MODIFIER_H
#include "vols.h"
#include <QDialog>

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QWidget *parent = nullptr);
    ~modifier();
    void setc(int x)
    {
        c=x ;
    }
    void setid(QString x)
    {
        id=x ;
    }
    void control(int c);
    void seta(int i)
    {
        a=i;
    }
private slots:
    void on_pushButton_2_clicked();

    void on_annuler_clicked();

private:
    Vols tempvols;
    QString id;
    int c ;
    int a ;
    Ui::modifier *ui;
};

#endif // MODIFIER_H
