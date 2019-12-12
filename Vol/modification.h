#ifndef MODIFICATION_H
#define MODIFICATION_H
#include "vols.h"
#include <QDialog>

namespace Ui
{
class Modification;
}

class Modification : public QDialog
{
    Q_OBJECT

public:
    explicit Modification(QWidget *parent = nullptr);
    ~Modification();
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Vols tempvols;
    QString id;
    int c ;
    int a ;
    Ui::modification *ui;
};

#endif // MODIFICATION_H
