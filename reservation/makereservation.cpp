#include "makereservation.h"
#include "ui_makereservation.h"

#include <movie/movietimetable.h>

#include <db_manager.h>
#include <list>
#include <QDebug>

static const QString path = "example.db";

MakeReservation::MakeReservation(QString x, int y, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MakeReservation)
{
    ui->setupUi(this);
    name = x;
    movieId = y;

    db_manager db(path);
    QList<QChar> places = db.getPlaces(movieId);

     ui->tableWidget->setColumnCount(5);
     ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
     ui->tableWidget->setSortingEnabled( false );
     ui->reserve->setEnabled(false);
     ui->unreserve->setEnabled(false);
     ui->movieName->setText(name);

     int j = 0;
     int i = 0;
     for ( int j = 0; j < ((places.count() + 5 - 1) / 5); j++) {
         ui->tableWidget->insertRow(j);

         while(i < places.count()){
              QChar qchar = places.at(i);
              if(qchar == '0'){
                  ui->tableWidget->setItem(j, i%5, new QTableWidgetItem("F"));
                  i++;
              }else if(qchar == '1'){
                  ui->tableWidget->setItem(j, i%5, new QTableWidgetItem("B"));
                  i++;
              }
              if(i % 5 == 0 && i != 0){
                  break;
              }
         }
     }
}

MakeReservation::~MakeReservation()
{
    delete ui;
}

void MakeReservation::on_back_clicked()
{
    MovieTimetable *table = new MovieTimetable(name);
    table->show();
    MakeReservation::close();
}

void MakeReservation::on_unreserve_clicked()
{
    db_manager db(path);
    if(db.unreserve(movieId, selectedRow * 5 + selectedColumn)){
        MovieTimetable *table = new MovieTimetable(name);
        table->show();
        MakeReservation::close();
    }
}

void MakeReservation::on_reserve_clicked()
{
    db_manager db(path);

    if(db.reserve(movieId, selectedRow * 5 + selectedColumn)){
        MovieTimetable *table = new MovieTimetable(name);
        table->show();
        MakeReservation::close();
    }
}

void MakeReservation::on_tableWidget_pressed(const QModelIndex &index)
{
    ui->reserve->setEnabled(true);
    ui->unreserve->setEnabled(true);
   selectedRow = index.row();
   selectedColumn = index.column();
}
