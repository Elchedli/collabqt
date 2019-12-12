#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_Ajouter_clicked();

    void on_Ajouter2_clicked();

    void on_Supprimer_clicked();

    void on_Supprimer3_clicked();

    void on_Modifier_clicked();

    void on_Modifier2_clicked();

    void on_Ajout_clicked();

    void on_Trier_clicked();

    void on_cherche_textChanged(const QString &arg1);

    void on_Active_clicked();

    void on_cherche_cursorPositionChanged(int arg1, int arg2);

    void on_tableView_activated(const QModelIndex &index);

    void on_Abonnement_clicked();

    void on_Supprimer2_7_clicked();

    void on_Supprimer2_4_clicked();

    void on_Supprimer2_9_clicked();

    void on_Supprimer2_6_clicked();

    void on_NumEdit2_2_cursorPositionChanged(int arg1, int arg2);

    void on_Retour_3_clicked();

    void on_Retour_4_clicked();

    void on_Active_2_clicked();

    void on_Supprimer2_8_clicked();

    void on_cherche_2_cursorPositionChanged(int arg1, int arg2);

    void on_cherche_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
