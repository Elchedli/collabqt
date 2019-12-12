#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
    void on_ajouter_enregistrer_clicked();

    void on_Vol_currentChanged();

    void on_modifier_enregistrer_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_listertrier_currentIndexChanged(int index);

    void on_supprimer_enregistrer_clicked();

    void on_pushButton_modification_clicked();




    void on_pushButton_clicked();

    void on_Vol_currentChanged(int index);

    void on_combo_type_stat_currentTextChanged();

private:
    Ui::MainWindow *ui;
    Vols tempvols;

    QVBoxLayout* mainLayout;
        Stat s;
        Historique  h;
};
#endif // MAINWINDOW_H
