#include "addmovieroom.h"
#include "movietimetable.h"
#include "ui_addmovieroom.h"

#include <db_manager.h>
#include <QDebug>
#include <QTime>


static const QString path = "example.db";

AddMovieRoom::AddMovieRoom(QString x, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovieRoom){

    ui->setupUi(this);
    db_manager db(path);
    name = x;

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->add->setEnabled(false);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    QStringList titles;
    titles << "Name" << "Places";
    ui->tableWidget->setHorizontalHeaderLabels(titles);

    QList<RoomDTO> rooms = db.getRooms();

    ui->tableWidget->setSortingEnabled( false );

    for (int i = 0; i < rooms.count(); i++) {
        RoomDTO dto = rooms.at(i);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dto.getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(dto.getCount())));
    }
    ui->tableWidget->setSortingEnabled( true );
}

AddMovieRoom::~AddMovieRoom(){
    delete ui;
}

void AddMovieRoom::on_add_clicked(){
    db_manager db(path);
    QDateTime myDate= ui->dateTimeEdit->dateTime();



    if(db.addMovieRoom(name, selectedRow+1, myDate)){
        MovieTimetable *welcom=new MovieTimetable(name);
        welcom->show();
        AddMovieRoom::close();
    }
}

void AddMovieRoom::on_cancel_clicked(){
    MovieTimetable *welcome = new MovieTimetable(name);
    welcome->show();
    AddMovieRoom::close();
}


void AddMovieRoom::on_tableWidget_pressed(const QModelIndex &index)
{
    ui->add->setEnabled(true);
    roomName = ui->tableWidget->selectedItems().at(0)->text();
    selectedRow = index.row();
}
