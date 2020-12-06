#include "editmovie.h"
#include "ui_editmovie.h"

#include <QDebug>
#include <db_manager.h>
#include <welcom.h>

static const QString path = "example.db";

EditMovie::EditMovie(QString x, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMovie)
{
    ui->setupUi(this);
    name = x;

    ui->lineEdit->setText(name);
}

EditMovie::~EditMovie()
{
    delete ui;
}


void EditMovie::on_update_clicked()
{

    db_manager db(path);
    if(db.editMovie(name, ui->lineEdit->text())){
        Welcom *welcome = new Welcom();
        welcome->show();
        EditMovie::close();
    }
}

void EditMovie::on_cencal_clicked()
{

}
