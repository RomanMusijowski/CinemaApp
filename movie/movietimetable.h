#ifndef MOVIETIMETABLE_H
#define MOVIETIMETABLE_H

#include <QDialog>

namespace Ui {
class MovieTimetable;
}

class MovieTimetable : public QDialog
{
    Q_OBJECT

public:
    explicit MovieTimetable(QString, QWidget *parent = nullptr);
    ~MovieTimetable();

private slots:
    void on_add_clicked();

    void on_edit_clicked();

    void on_delete_2_clicked();

    void on_back_clicked();

    void on_tableWidget_pressed(const QModelIndex &index);

    void on_reserve_clicked();

private:
    Ui::MovieTimetable *ui;

    QString name;
    int movieId;
};

#endif // MOVIETIMETABLE_H
