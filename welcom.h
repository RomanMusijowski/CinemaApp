#ifndef WELCOM_H
#define WELCOM_H

#include <QDialog>

namespace Ui {
class Welcom;
}

class Welcom : public QDialog
{
    Q_OBJECT

public:
    explicit Welcom(QWidget *parent = nullptr);
    ~Welcom();

private slots:

    void on_tableWidget_pressed(const QModelIndex &index);

    void on_editMovie_clicked();

    void on_logOut_clicked();

    void on_addMovie_clicked();

    void on_deleteMovie_clicked();

    void on_addR_clicked();

    void on_editR_clicked();

    void on_deleteR_clicked();

    void on_movieList_clicked();
    void setMovies();
    void setRooms();

    void on_tableWidget_2_pressed(const QModelIndex &index);

private:
    Ui::Welcom *ui;
    int rowSelectedMovie;
    int rowSelectedRoom;
};

#endif // WELCOM_H
