#include "editmovie.h"
#include "ui_editmovie.h"
#include <QDebug>

EditMovie::EditMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMovie)
{
    ui->setupUi(this);
}

EditMovie::EditMovie(int x, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMovie)
{
    id=x;
    qDebug() << id;
}

EditMovie::~EditMovie()
{
    delete ui;
}
