#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "locataire.h"
#include "local.h"
#include "mailing/SmtpMime"
#include <QMessageBox>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablocataire->setModel(tmplocataire.afficher_locataire());
    ui->tablocal->setModel(tmplocal.afficher_local());
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajout_locataire_clicked()
{
    QString CIN = ui->lineCIN->text();
        QString nom= ui->lineNom->text();
        QString prenom= ui->linePrenom->text();
        QString email= ui->lineEmail->text();
        QString adr= ui->lineAdresse->text();
    QString NumTel = ui->lineNumTel->text();
    int id_local = ui->lineID_local->text().toInt();

      locataire lct(nom,prenom,email,adr,NumTel,CIN,id_local) ;
      bool test=lct.ajouter_locataire();
      if  (CIN.length()!=8)
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un locataire"),
                      QObject::tr("Veuillez verifier les informations !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      else {

      if(test)
    {ui->tablocataire->setModel(tmplocataire.afficher_locataire());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un locataire"),
                      QObject::tr("Locataire ajouté.\n"
                                 ), QMessageBox::Ok);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un locataire"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void MainWindow::on_supp_locataire_clicked()
{


    QString CIN = ui->lineSUPCIN->text();
    bool test=tmplocataire.supprimer_locataire(CIN);
    if(test)
    {ui->tablocataire->setModel(tmplocataire.afficher_locataire());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un locataire"),
                    QObject::tr("locataire supprimé.\n"), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un locataire"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_modif_locataire_clicked()
{
    QString CIN = ui->linemCIN->text();
           QString nom= ui->linemNom->text();
           QString prenom= ui->linemPrenom->text();
           QString email= ui->linemEmail->text();
           QString adr= ui->linemAdresse->text();
       QString NumTel = ui->linemNumTel->text();
       int id_local = ui->linemID_local->text().toInt();
       QString CINN = ui->linemCINN->text();


         locataire lct1(nom,prenom,email,adr,NumTel,CIN,id_local) ;
       bool test1=lct1.modifier_locataire(CINN);

       if(test1)
       {ui->tablocataire->setModel(tmplocataire.afficher_locataire());
       QMessageBox::information(nullptr, QObject::tr("Modifier un locataire"),
                         QObject::tr("Locataire modifié.\n"), QMessageBox::Ok);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier un locataire"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Ajout_local_clicked()
{
    int id = ui->lineID->text().toInt();
           QString type= ui->lineType->text();
           double superficie= ui->lineSuperficie->text().toDouble();
           double prix= ui->linePrix->text().toDouble();
           QString dispo= ui->lineDispo->text();
       int duree = ui->lineDuree->text().toInt();
       long CIN_Locataire = ui->lineCIN_Locataire->text().toLong();

         local lc(id,type,superficie,prix,dispo,duree,CIN_Locataire) ;
         bool test=lc.ajouter_local();
         if(test)
       {ui->tablocal->setModel(tmplocal.afficher_local());
       QMessageBox::information(nullptr, QObject::tr("Ajouter un local"),
                         QObject::tr("Local ajouté.\n"), QMessageBox::Ok);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter un local"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_modif_local_clicked()
{
    int id = ui->linemID->text().toInt();
           QString type= ui->linemType->text();
           double superficie= ui->linemSuperficie->text().toDouble();
           double prix= ui->linemPrix->text().toDouble();
           QString dispo= ui->linemDispo->text();
       int duree = ui->linemDuree->text().toInt();
       long CIN_Locataire = ui->linemCIN_locataire->text().toLong();

       int idd = ui->linemIDD->text().toInt();

         local lc(id,type,superficie,prix,dispo,duree,CIN_Locataire) ;
         bool test=lc.modifier_local(idd);
         if(test)
       {ui->tablocal->setModel(tmplocal.afficher_local());
       QMessageBox::information(nullptr, QObject::tr("modifier un local"),
                         QObject::tr("Local modifié.\n"), QMessageBox::Ok);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier un local"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supp_local_clicked()
{
    int id = ui->lineSUPID->text().toInt();
    bool test=tmplocal.supprimer_local(id);
    if(test)
   {ui->tablocal->setModel(tmplocal.afficher_local());
       QMessageBox::information(nullptr, QObject::tr("Supprimer un local"),
                         QObject::tr("Local supprimé.\n"), QMessageBox::Ok);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Supprimer un local"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}






void MainWindow::on_Trier_locataire_clicked()
{
     ui->tabt->setModel(tmplocataire.afficherlct(ui->boxlct->currentText()));
}

void MainWindow::on_lineRNOM_textChanged()
{
    QString nom = ui->lineRNOM->text();
    QString prenom=ui->lineRNOM->text();
   ui->tabr->setModel(tmplocataire.recherche(nom,prenom));
}

void MainWindow::on_lineRTYPE_textChanged()
{
    QString Type = ui->lineRTYPE->text();
        ui->tabrlc->setModel(tmplocal.recherche(Type));
}

void MainWindow::on_Trier_local_clicked()
{
    ui->tabtlc->setModel(tmplocal.afficherlc(ui->boxlc->currentText()));
}

void MainWindow::on_Envoyer_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
                QString ch=ui->textEdit->toPlainText();
                smtp.setUser("mohamedamine.achour@esprit.tn");
                smtp.setPassword("181JMT2328");
                MimeMessage message;
                message.setSender(new EmailAddress("mohamedamine.achour@esprit.tn", "Centre commercial"));
                message.addRecipient(new EmailAddress(ui->lineEdit->text(), "locataire"));
                message.setSubject("ATTENTION!");
                MimeText text;
                text.setText(ch);
                message.addPart(&text);
                smtp.connectToHost();
                smtp.login();
                if(smtp.sendMail(message)){
                    QMessageBox::information(this, "OK", "Mail envoyé");
                }else{
                    QMessageBox::critical(this, "Erreur", "Mail non envoye");
                }
                smtp.quit();

}
