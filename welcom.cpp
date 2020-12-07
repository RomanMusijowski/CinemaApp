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

static const QString path = "example.db";

Welcom::Welcom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcom)
{
    ui->setupUi(this);
    db_manager db(path);


    ui->tableWidget->setColumnCount(2);
    QStringList titles;
    titles << "Name" << "Session";
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);


    QList<MovieDTO> movies = db.getMovies();
    ui->tableWidget->setSortingEnabled( false );

    for (int i =0; i<movies.count(); i++ ) {
        MovieDTO dto = movies.at(i);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dto.getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(dto.getSessionCount())));
    }
    ui->tableWidget->setSortingEnabled( true );

    ui->editMovie->setEnabled(false);
    ui->deleteMovie->setEnabled(false);
    ui->movieList->setEnabled(false);
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
    rowSelected=index.row();
}

void Welcom::on_addMovie_clicked()
{
    AddMovie *addMovie=new AddMovie();
    addMovie->show();
    Welcom::close();
}

void Welcom::on_editMovie_clicked()
{
    QString name = ui->tableWidget->model()->data(ui->tableWidget->model()->index(rowSelected,0)).toString();
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
    QString name = ui->tableWidget->model()->data(ui->tableWidget->model()->index(rowSelected,0)).toString();
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

}

void Welcom::on_deleteR_clicked()
{

}

void Welcom::on_movieList_clicked()
{
    MovieTimetable *timeTable = new MovieTimetable();
    timeTable->show();
    Welcom::close();
}
