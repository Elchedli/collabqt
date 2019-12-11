/*#include "stat.h"
#include <QDebug>
#include <algorithm>
using namespace  std;
Stat::Stat()
{



}
QChartView * Stat::Preparechart(QString type)
{
    QSqlQuery query;
    int count1=0;
    int count2=0;

    int maxcount=0;

    if(query.exec("select es from vol "))
    {
    while(query.next())
      {
         if(query.value(0).toString()=="Entrante")
             count1++;
         else if(query.value(0).toString()=="Sortante")
             count2++;

       }
     }

    if(type=="PIE"){
      QPieSeries *series;
    series = new QPieSeries();

    series->append("Entrante", count1);
    series->append("Sortante", count2);

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Les Types");
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    }
    else if(type=="BARRE"){

        maxcount=max(count1,count2);


             QBarSet *set0 = new QBarSet("Entrante");
             QBarSet *set1 = new QBarSet("Sortante");


             *set0 << count1 ;
             *set1 << count2 ;



             QBarSeries *series = new QBarSeries();
                 series->append(set0);
                 series->append(set1);



                 chart = new QChart();
                 chart->addSeries(series);
                 chart->setTitle("STATISTIQUE");
                 chart->setAnimationOptions(QChart::SeriesAnimations);
                 QStringList categories;
                 categories << "TYPE" ;
                 QBarCategoryAxis *axisX = new QBarCategoryAxis();
                 axisX->append(categories);
                 chart->addAxis(axisX, Qt::AlignBottom);
                 series->attachAxis(axisX);
                 QValueAxis *axisY = new QValueAxis();
                 axisY->setRange(0,maxcount);
                 chart->addAxis(axisY, Qt::AlignLeft);
                 series->attachAxis(axisY);
                 chart->legend()->setVisible(true);
                 chart->legend()->setAlignment(Qt::AlignBottom);
                 chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
    }





return chartView;
}*/
