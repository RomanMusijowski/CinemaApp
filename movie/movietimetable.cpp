#include "addmovieroom.h"
#include "movietimetable.h"
#include "ui_movietimetable.h"

#include <db_manager.h>
#include <list>
#include <list>
#include <welcom.h>

#include <model/movieroomdto.h>

static const QString path = "example.db";

MovieTimetable::MovieTimetable(QString movieName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovieTimetable)
{
    ui->setupUi(this);
    db_manager db(path);
    name = movieName;

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);

    QStringList titles;
    titles << "Name" << "Room" << "Places" << "Free places" << "Time";
    ui->tableWidget->setHorizontalHeaderLabels(titles);

    QList<MovieRoomDTO> movies = db.getMovieList(name);

    ui->tableWidget->setSortingEnabled( false );

    for (int i = 0; i < movies.count(); i++) {
        MovieRoomDTO dto = movies.at(i);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dto.getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(dto.getRoom()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(dto.getPlaces()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(dto.getFreePlaces()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(dto.getTime()));
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
    //show window
}

void MovieTimetable::on_delete_2_clicked()
{
    db_manager db(path);
    //by id
}

void MovieTimetable::on_back_clicked()
{
    Welcom *welcome = new Welcom();
    welcome->show();
    MovieTimetable::close();
}
