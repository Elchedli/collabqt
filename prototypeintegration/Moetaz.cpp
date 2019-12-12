#include "Moetaz.h"
#include "ui_Moetaz.h"
#include "Employe.h"
#include <QMessageBox>
#include "qcustomplot.h"
#include <QSqlQuery>
#include <QtPrintSupport>
#include <QDebug>
#include <iostream>

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include "Moetaz.h"
#include "ui_Moetaz.h"
Moetaz::Moetaz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Moetaz)
{
ui->setupUi(this);
ui->tabetudiant->setModel(tmpetudiant.afficher());

}

Moetaz::~Moetaz()
{
    delete ui;
}

void Moetaz::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
     QString poste= ui->comboposte->currentText();
  Employe e(id,nom,prenom,poste);
  bool test=e.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Moetaz::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpetudiant.supprimer(id);
if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                QObject::tr("employe supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


QVector<double> Moetaz::Statistique_poste()
{QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;



    q.prepare("SELECT POSTE FROM EMPLOYE WHERE POSTE='hotesse' ");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT POSTE FROM EMPLOYE WHERE POSTE='pilote'");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT POSTE FROM EMPLOYE WHERE POSTE='service' ");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT POSTE FROM EMPLOYE WHERE POSTE='acceuil' ");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT POSTE FROM EMPLOYE WHERE POSTE='garde' ");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }





    return stat;
}
void Moetaz::makePlot_poste()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->CustomPlot->xAxis, ui->CustomPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, Moetaz::Statistique_poste());
    bars1->setName("Nombre d'employe selon poste");
    bars1->setAntialiased(false);
    bars1->setStackingGap(1);

    bars1->setPen(QPen(QColor(200, 40, 60).lighter(170)));
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->CustomPlot->replot();
    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5;
    QVector<QString> labels;
    labels<<"Hotesse(s)"<<"Pilote(s)"<<"Service(s)"<<"Acceuil(s)"<<"Garde(s)";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->CustomPlot->xAxis->setTicker(textTicker);
    ui->CustomPlot->xAxis->setSubTicks(false);
    ui->CustomPlot->xAxis->setTickLength(0,4);
    ui->CustomPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->CustomPlot->yAxis->setLabelColor(Qt::white);
    ui->CustomPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot->xAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot->yAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 1, Qt::DotLine));
    ui->CustomPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 1, Qt::DotLine));
    ui->CustomPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
   // ui->CustomPlot->xAxis->grid()->setSubGridVisible(true);
   // ui->CustomPlot->yAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->CustomPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->CustomPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->CustomPlot->axisRect()->setBackground(axisRectGradient);
    ui->CustomPlot->rescaleAxes();
    ui->CustomPlot->xAxis->setRange(0, 7);
    ui->CustomPlot->yAxis->setRange(0, 10);


}
void Moetaz::on_pushButton_clicked()
{
    Moetaz::makePlot_poste();


}

void Moetaz::on_pushButton_2_clicked()
{
    Employe *e= new Employe();
    ui->tabetudiant->setModel(e->trierOffre());
}

void Moetaz::on_pushButton_3_clicked()
{
    QString valeur=ui->lineEdit_ch->text();
    Employe *e=new Employe();
    ui->tabetudiant->setModel(e->rechercheremploye(valeur));

}

int Moetaz::on_pushButton_4_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/admin/Desktop/PDFF.pdf");
           QPainter painter;
           QImage imagen("C:/Users/admin/Desktop");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString N_demande=ui->lineEdit_id->text();
           QString Sujet=ui->lineEdit_nom->text();
           QString Description=ui->lineEdit_prenom->text();
           QString poste = ui->comboposte->currentText();





          /* QString  affaire=ui->lineEdit_29->text();
           QString reglement =ui->lineEdit_36->text();*/


           painter.drawImage(40,40,imagen);
           painter.drawText(180, 240, N_demande);

           painter.drawText(180, 300, Sujet);
           painter.drawText(180, 360, Description);
           painter.drawText(180, 420, poste);
        /*   painter.drawText(180, 380, affaire);

           painter.drawText(160, 400, reglement);*/
           //painter.drawText(160, 625, c);

           painter.end();
}

void Moetaz::on_tabetudiant_clicked(const QModelIndex &index)
{
    ui->lineEdit_id->setText(ui->tabetudiant->model()->data(ui->tabetudiant->model()->index(ui->tabetudiant->selectionModel()->currentIndex().row(),0)).toString());
        ui->lineEdit_nom->setText(ui->tabetudiant->model()->data(ui->tabetudiant->model()->index(ui->tabetudiant->selectionModel()->currentIndex().row(),1)).toString());
        ui->lineEdit_prenom->setText(ui->tabetudiant->model()->data(ui->tabetudiant->model()->index(ui->tabetudiant->selectionModel()->currentIndex().row(),2)).toString());
      ui->comboposte->setCurrentText(ui->tabetudiant->model()->data(ui->tabetudiant->model()->index(ui->tabetudiant->selectionModel()->currentIndex().row(),3)).toString());
}

bool Moetaz::on_pushButton_5_clicked()
{

    QSqlQuery q;
    q.prepare("update Employe set  nom=:nom,id=:id,prenom=:prenom,poste=:poste where id=:id" );
    q.bindValue(":nom",ui->lineEdit_nom->text());
    q.bindValue(":id",ui->lineEdit_id->text());
    q.bindValue(":prenom",ui->lineEdit_prenom->text());
    q.bindValue(":poste",ui->comboposte->currentText());
    if(q.exec())
    {
        if (    q.exec())
        {
             ui->tabetudiant->setModel(tmpetudiant.afficher());
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("l emloye a ete modifie ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("l employe n'est pas modifiee ");
                    msgBox.exec();
                    return false;
        }
    }



}
