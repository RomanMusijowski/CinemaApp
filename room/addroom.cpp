#include "addroom.h"
#include "ui_addroom.h"
#include <QDebug>
#include <db_manager.h>
#include <welcom.h>

static const QString path = "example.db";

AddRoom::AddRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRoom)
{
    ui->setupUi(this);
}

AddRoom::~AddRoom()
{
    delete ui;
}

void AddRoom::on_add_clicked()
{
    db_manager db(path);
    int count = ui->places->text().toInt();
    QString name = ui->name->text();

    qDebug() << count << ", " << name;

    if(db.addRoom(name, count)){
        Welcom *welcom=new Welcom();
        welcom->show();
        AddRoom::close();
    }
}

void AddRoom::on_cencal_clicked()
{
    Welcom *welcom=new Welcom();
    welcom->show();
    AddRoom::close();
}
