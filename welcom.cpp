#include "welcom.h"
#include "ui_welcom.h"

Welcom::Welcom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcom)
{
    ui->setupUi(this);
}

Welcom::~Welcom()
{
    delete ui;
}
