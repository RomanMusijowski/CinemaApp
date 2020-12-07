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
    explicit AddMovieRoom(QWidget *parent = nullptr);
    ~AddMovieRoom();

private slots:
    void on_add_clicked();

    void on_cancel_clicked();

private:
    Ui::AddMovieRoom *ui;
};

#endif // ADDMOVIEROOM_H
