#include "editroom.h"
#include "ui_editroom.h"
#include <QDebug>
#include <db_manager.h>
#include <welcom.h>

static const QString path = "example.db";

EditRoom::EditRoom(QString x, QString count, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRoom)
{
    ui->setupUi(this);
    nameF = x;
    placesF = count;

    ui->name->setText(nameF);
    ui->places->setText(placesF);
}

EditRoom::~EditRoom()
{
    delete ui;
}

void EditRoom::on_update_clicked()
{
    db_manager db(path);
    if(db.editRoom(nameF, ui->name->text(), ui->places->text().toInt())){
        Welcom *welcome = new Welcom();
        welcome->show();
        EditRoom::close();
    }
}

void EditRoom::on_cencal_clicked()
{
    Welcom *welcome = new Welcom();
    welcome->show();
    EditRoom::close();
}
