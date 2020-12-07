#ifndef ADDROOM_H
#define ADDROOM_H

#include <QDialog>

namespace Ui {
class AddRoom;
}

class AddRoom : public QDialog
{
    Q_OBJECT

public:
    explicit AddRoom(QWidget *parent = nullptr);
    ~AddRoom();

private slots:
    void on_add_clicked();

    void on_cencal_clicked();

private:
    Ui::AddRoom *ui;
};

#endif // ADDROOM_H
