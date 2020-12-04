#include "login.h"
#include <db_manager.h>
#include <QApplication>

static const QString path = "example.db";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    db_manager db(path);
    if (db.isOpen()){
            db.createTable();
    }
    Login w;
    w.show();
    return a.exec();
}
