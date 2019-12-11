#ifndef DHAFER_H
#define DHAFER_H
#include "dhafer/vols.h"
#include "dhafer/modifier.h"
#include "dhafer/stat.h"
#include <QVBoxLayout>
#include "dhafer/historique.h"
#include <QDialog>

namespace Ui {
class dhafer;
}

class dhafer : public QDialog
{
    Q_OBJECT

public:
    explicit dhafer(QWidget *parent = nullptr);
    ~dhafer();

private slots:
    void on_ajouter_enregistrer_clicked();

    void on_supprimer_enregistrer_clicked();

    void on_modifier_enregistrer_clicked();

    void on_pushButton_modification_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_listertrier_currentIndexChanged(int index);

    void on_combo_type_stat_currentTextChanged();

    void on_pushButton_clicked();

    void on_Vol_currentChanged(int index);

private:
    Ui::dhafer *ui;
    Vols tempvols;

    QVBoxLayout* mainLayout;
        stat s;
        Historique  h;
};





#endif // DHAFER_H


/*
#include "vols.h"
#include "modifier.h"
#include <QMainWindow>
#include "stat.h"
#include <QVBoxLayout>
#include "historique.h"
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
   **** void on_ajouter_enregistrer_clicked();

    void on_Vol_currentChanged();

   **** void on_modifier_enregistrer_clicked();

  ****  void on_lineEdit_textChanged(const QString &arg1);

 ***   void on_listertrier_currentIndexChanged(int index);

   **** void on_supprimer_enregistrer_clicked();

    ***void on_pushButton_modification_clicked();




   *** void on_pushButton_clicked();

    ***void on_Vol_currentChanged(int index);

  ***  //void on_combo_type_stat_currentTextChanged();

private:
    Ui::MainWindow *ui;
    Vols tempvols;

    QVBoxLayout* mainLayout;
        Stat s;
        Historique  h;
};
#endif // MAINWINDOW_H
*/
