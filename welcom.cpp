#include "welcom.h"
#include "ui_welcom.h"
#include <QDebug>
#include <QStandardItemModel>
#include <db_manager.h>
#include "login.h"
#include <movie/addmovie.h>
#include <movie/editmovie.h>
#include <movie/movietimetable.h>
#include <room/addroom.h>
#include <room/editroom.h>

static const QString path = "example.db";

Welcom::Welcom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcom)
{
    ui->setupUi(this);

    setMovies();
    setRooms();

    ui->editMovie->setEnabled(false);
    ui->deleteMovie->setEnabled(false);
    ui->editR->setEnabled(false);
    ui->deleteR->setEnabled(false);
    ui->movieList->setEnabled(false);
}

void Welcom:: setRooms(){
    db_manager db(path);

    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    QStringList titles;
    titles << "Nazwa" << "Miejsca";
    ui->tableWidget_2->setHorizontalHeaderLabels(titles);

    QList<RoomDTO> rooms = db.getRooms();
    ui->tableWidget_2->setSortingEnabled( false );

    for (int i = 0; i < rooms.count(); i++) {
        RoomDTO dto = rooms.at(i);
        ui->tableWidget_2->insertRow(i);
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(dto.getName()));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::number(dto.getCount())));
    }
    ui->tableWidget_2->setSortingEnabled( true );
}


void Welcom:: setMovies(){
    db_manager db(path);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    QStringList titles;
    titles << "Nazwa" << "Liczba seansów";
    ui->tableWidget->setHorizontalHeaderLabels(titles);

    QList<MovieDTO> movies = db.getMovies();

    ui->tableWidget->setSortingEnabled( false );
    for (int i =0; i<movies.count(); i++ ) {
        MovieDTO dto = movies.at(i);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dto.getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(dto.getSessionCount())));
    }
    ui->tableWidget->setSortingEnabled( true );
}

Welcom::~Welcom()
{
    delete ui;
}


void Welcom::on_tableWidget_pressed(const QModelIndex &index)
{
    ui->editMovie->setEnabled(true);
    ui->deleteMovie->setEnabled(true);
    ui->movieList->setEnabled(true);
    rowSelectedMovie=index.row();
}

void Welcom::on_addMovie_clicked()
{
    AddMovie *addMovie=new AddMovie();
    addMovie->show();
    Welcom::close();
}

void Welcom::on_editMovie_clicked()
{
    QString name = ui->tableWidget->model()->data(ui->tableWidget->model()->index(rowSelectedMovie,0)).toString();
    EditMovie * ed=new EditMovie(name);
    ed->show();
    Welcom::close();
}

void Welcom::on_logOut_clicked()
{
    Login *login=new Login();
    login->show();
    Welcom::close();
}



void Welcom::on_deleteMovie_clicked()
{
    db_manager db(path);
    QString name = ui->tableWidget->model()->data(ui->tableWidget->model()->index(rowSelectedMovie,0)).toString();
    if(!name.isEmpty()){
        db.removeMovie(name);

        Welcom *w = new Welcom();
        w->show();
        Welcom::close();
    }

}



void Welcom::on_addR_clicked()
{
    AddRoom *addRoom=new AddRoom();
    addRoom->show();
    Welcom::close();
}

void Welcom::on_editR_clicked()
{
    QString name = ui->tableWidget_2->model()->data(ui->tableWidget_2->model()->index(rowSelectedRoom,0)).toString();
    QString places = ui->tableWidget_2->model()->data(ui->tableWidget_2->model()->index(rowSelectedRoom,1)).toString();
    EditRoom * ed=new EditRoom(name, places);
    ed->show();
    Welcom::close();
}

void Welcom::on_deleteR_clicked()
{
    db_manager db(path);
    QString name = ui->tableWidget_2->model()->data(ui->tableWidget_2->model()->index(rowSelectedRoom,0)).toString();
    if(!name.isEmpty()){
        db.removeRoom(name);

        Welcom *w = new Welcom();
        w->show();
        Welcom::close();
    }
}

void Welcom::on_movieList_clicked()
{
    QString name = ui->tableWidget->model()->data(ui->tableWidget->model()->index(rowSelectedMovie,0)).toString();
    MovieTimetable *timeTable = new MovieTimetable(name);
    timeTable->show();
    Welcom::close();
}

void Welcom::on_tableWidget_2_pressed(const QModelIndex &index)
{
    ui->editR->setEnabled(true);
    ui->deleteR->setEnabled(true);
    rowSelectedRoom=index.row();
}
