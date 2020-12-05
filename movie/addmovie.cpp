#include "addmovie.h"
#include "ui_addmovie.h"

#include <db_manager.h>
#include <welcom.h>

static const QString path = "example.db";

AddMovie::AddMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMovie)
{
    ui->setupUi(this);
}

AddMovie::~AddMovie()
{
    delete ui;
}

void AddMovie::on_pushButton_clicked()
{
    db_manager db(path);

    if(db.addMovie(ui->lineEdit->text())){
        Welcom *welcom=new Welcom();
        welcom->show();
        AddMovie::close();
    }
}

void AddMovie::on_pushButton_2_clicked()
{
    Welcom *welcom=new Welcom();
    welcom->show();
    AddMovie::close();
}
