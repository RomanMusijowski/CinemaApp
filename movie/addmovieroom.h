#ifndef ADDMOVIEROOM_H
#define ADDMOVIEROOM_H

#include <QDialog>

namespace Ui {
class AddMovieRoom;
}

class AddMovieRoom : public QDialog
{
    Q_OBJECT

public:
    explicit AddMovieRoom(QString, QWidget *parent = nullptr);
    ~AddMovieRoom();

private slots:
    void on_add_clicked();

    void on_cancel_clicked();


    void on_tableWidget_pressed(const QModelIndex &index);

private:
    Ui::AddMovieRoom *ui;
    QString name;
    int selectedRow;
    QString roomName;
};

#endif // ADDMOVIEROOM_H
