#include "addmovieroom.h"
#include "ui_addmovieroom.h"

AddMovieRoom::AddMovieRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovieRoom)
{
    ui->setupUi(this);
}

AddMovieRoom::~AddMovieRoom()
{
    delete ui;
}

void AddMovieRoom::on_add_clicked()
{
    QString time = ui->dateTimeEdit->text();
}

void AddMovieRoom::on_cancel_clicked()
{

}
