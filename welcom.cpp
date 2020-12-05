#include "welcom.h"
#include "ui_welcom.h"
#include <QDebug>
#include <QStandardItemModel>
#include <db_manager.h>
#include <movie/addmovie.h>
#include <movie/editmovie.h>

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
//    this->searchSlot();
}

Welcom::~Welcom()
{
    delete ui;
}

void Welcom::on_pushButton_4_clicked()
{
    AddMovie *addMovie=new AddMovie();
    addMovie->show();
    Welcom::close();
}

void Welcom::on_tableWidget_cellActivated(int row, int column)
{
}

void Welcom::on_tableWidget_activated(const QModelIndex &index)
{
    QString data = ui->tableWidget-> model() -> data(index).toString();
     qDebug() << data;
}

void Welcom::on_tableWidget_clicked(const QModelIndex &index)
{
//     qDebug() << index;
//     ui->
}

void Welcom::on_tableWidget_pressed(const QModelIndex &index)
{
    rowSelected=index.row();
    qDebug() << rowSelected;
}

void Welcom::on_editMovie_clicked()
{
    qDebug() << "0 = " <<  ui->tableWidget->model()->data(ui->tableWidget->model()->index(rowSelected,0)).toString();
    qDebug() << "1 = "<<  ui->tableWidget->model()->data(ui->tableWidget->model()->index(rowSelected,1)).toString();


    EditMovie * ed=new EditMovie(ui->tableWidget->model()->data(ui->tableWidget->model()->index(rowSelected,0)).toString().toInt()
,this);
    ed->show();
}
