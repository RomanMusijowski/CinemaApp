#include "editmovieroom.h"
#include "movietimetable.h"
#include "ui_editmovieroom.h"

#include <db_manager.h>

static const QString path = "example.db";

EditMovieRoom::EditMovieRoom(QString x, int movie, int room, QDateTime time, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMovieRoom)
{
    ui->setupUi(this);
    name = x;
    movieId = movie;
    roomId = room;
    dateTime = time;

    ui->nameLabel->setText(name);
    ui->dateTimeEdit->setDateTime(time);
}

EditMovieRoom::~EditMovieRoom()
{
    delete ui;
}

void EditMovieRoom::on_add_clicked()
{
    db_manager db(path);
    QDateTime myDate= ui->dateTimeEdit->dateTime();

    if(db.editMovieRoom(movieId, roomId, myDate)){
        MovieTimetable *welcome = new MovieTimetable(name);
        welcome->show();
        EditMovieRoom::close();
    }
}

void EditMovieRoom::on_cancel_clicked()
{
    MovieTimetable *welcome = new MovieTimetable(name);
    welcome->show();
    EditMovieRoom::close();
}
