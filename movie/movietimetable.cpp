#include "movietimetable.h"
#include "ui_movietimetable.h"

#include <welcom.h>

MovieTimetable::MovieTimetable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovieTimetable)
{
    ui->setupUi(this);
}

MovieTimetable::~MovieTimetable()
{
    delete ui;
}

void MovieTimetable::on_add_clicked()
{
    //show window
}

void MovieTimetable::on_edit_clicked()
{
    //show window
}

void MovieTimetable::on_delete_2_clicked()
{
    //by id
}

void MovieTimetable::on_back_clicked()
{
    Welcom *welcome = new Welcom();
    welcome->show();
    MovieTimetable::close();
}
