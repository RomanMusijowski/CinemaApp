#ifndef EDITMOVIEROOM_H
#define EDITMOVIEROOM_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class EditMovieRoom;
}

class EditMovieRoom : public QDialog
{
    Q_OBJECT

public:
    explicit EditMovieRoom(QString, int, int, QDateTime, QWidget *parent = nullptr);
    ~EditMovieRoom();

private slots:
    void on_add_clicked();

    void on_cancel_clicked();

private:
    Ui::EditMovieRoom *ui;
    QString name;
    QDateTime dateTime;
    int movieId;
    int roomId;
};

#endif // EDITMOVIEROOM_H
