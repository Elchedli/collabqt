#ifndef CHEDLI_H
#define CHEDLI_H
#include <QDialog>
#include "chedli/sponsor.h"
#include "chedli/arduino.h"

#include <QMessageBox>
#include <QMediaPlayer>
#include <QTimer>
namespace Ui {class chedli;}
QT_END_NAMESPACE
class QSystemTrayIcon;
class chedli : public QDialog{
    Q_OBJECT

public:
    explicit chedli(QWidget *parent = nullptr);
    ~chedli();
public slots:
    void myfunction();
private slots:
    void on_ajouterbutt_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_Annuler_4_clicked();

    void on_pushButton_4_clicked();

    void on_Envoyer_clicked();

    void on_boxi_currentIndexChanged();

    void on_recherchebox_currentIndexChanged();

    void on_pourboxtrie_currentIndexChanged();

    void on_Ajouter_clicked();

    void on_pourbox_currentTextChanged();

    void on_recherchepour_textEdited();

    void on_recherche_textEdited();

private:
    Ui::chedli *ui;
    Sponsor tmpspon;
    QSystemTrayIcon *mSystemTrayIcon;
    QMediaPlayer* player;
    QByteArray data;
    Arduino A;
    QTimer *timer;
};

#endif // CHEDLI_H
