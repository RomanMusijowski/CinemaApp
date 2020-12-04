#include "login.h"
#include "ui_login.h"
#include "welcom.h"
#include <db_manager.h>

#include <QDebug>

static const QString path = "example.db";

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    db_manager db(path);
    QString name = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();


    if (db.isOpen()){
        if(db.login(name, pass)){
            Welcom *welcom=new Welcom();
            welcom->show();
            Login::close();
        }else{
            qDebug() << "login error!";
        }
    }else
    {
        qDebug() << "Database is not open!";
    }
}
