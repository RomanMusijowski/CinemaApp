#include "welcom.h"
#include "ui_welcom.h"
#include <QDebug>
#include <db_manager.h>

static const QString path = "example.db";

Welcom::Welcom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcom)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    QStringList titles;
    titles << "Name" << "Session";
    ui->tableWidget->setHorizontalHeaderLabels(titles);

    db_manager db(path);
    QList<MovieDTO> movies = db.getMovies();
    for(int i = 0; i < movies.count(); i++){

        qDebug() << "===" << movies.at(i).getName() << " " << movies.at(i).getSessionCount();
    }
}

Welcom::~Welcom()
{
    delete ui;
}
