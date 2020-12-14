#include "addmovieroom.h"
#include "editmovieroom.h"
#include "movietimetable.h"
#include "ui_movietimetable.h"

#include <db_manager.h>
#include <list>
#include <list>
#include <welcom.h>
#include <QDebug>

#include <model/movieroomdto.h>

#include <reservation/makereservation.h>

static const QString path = "example.db";

MovieTimetable::MovieTimetable(QString movieName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovieTimetable)
{
    ui->setupUi(this);
    db_manager db(path);
    name = movieName;

    ui->edit->setEnabled(false);
    ui->delete_2->setEnabled(false);
    ui->reserve->setEnabled(false);

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);

    QStringList titles;
    titles << "id" << "Name" << "Room" << "Places" << "Free places" << "Time";
    ui->tableWidget->setHorizontalHeaderLabels(titles);

    QList<MovieRoomDTO> movies = db.getMovieList(name);

    ui->tableWidget->setSortingEnabled( false );

    for (int i = 0; i < movies.count(); i++) {
        MovieRoomDTO dto = movies.at(i);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dto.getMovieId()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(dto.getName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(dto.getRoom()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(dto.getPlaces()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(dto.getFreePlaces()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(dto.getTime()));
    }
    ui->tableWidget->setSortingEnabled( true );

}

MovieTimetable::~MovieTimetable()
{
    delete ui;
}

void MovieTimetable::on_add_clicked()
{
    db_manager db(path);
    AddMovieRoom *room = new AddMovieRoom(name);
    room->show();
    MovieTimetable::close();
}

void MovieTimetable::on_edit_clicked()
{
    db_manager db(path);

    int roomId = db.getRoomIdByName(ui->tableWidget->selectedItems().at(2)->text());
    if(roomId != 0){
        int movieId = ui->tableWidget->selectedItems().at(0)->text().toInt();
        QString time = ui->tableWidget->selectedItems().at(5)->text();

        EditMovieRoom *edit = new EditMovieRoom(name, movieId, roomId, QDateTime::fromString(time, "yyyy-MM-dd hh:mm:ss"));
        edit->show();
        MovieTimetable::close();
    }

}

void MovieTimetable::on_delete_2_clicked()
{
    db_manager db(path);
    if(db.removeMovieRoom(movieId)){
       qDebug() << "Movie has been deleted.";
       MovieTimetable *table = new MovieTimetable(name);
       table->show();
       MovieTimetable::close();
    }
}

void MovieTimetable::on_back_clicked()
{
    Welcom *welcome = new Welcom();
    MovieTimetable::close();
    welcome->show();
}

void MovieTimetable::on_tableWidget_pressed(const QModelIndex &index)
{

    ui->edit->setEnabled(true);
    ui->delete_2->setEnabled(true);
    ui->reserve->setEnabled(true);
    movieId = ui->tableWidget->selectedItems().at(0)->text().toInt();
}

void MovieTimetable::on_reserve_clicked()
{
    MakeReservation *reserve = new MakeReservation(name, movieId);
    reserve->show();
    MovieTimetable::close();
}
