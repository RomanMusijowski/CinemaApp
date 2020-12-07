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
    explicit MovieTimetable(QWidget *parent = nullptr);
    ~MovieTimetable();

private slots:
    void on_add_clicked();

    void on_edit_clicked();

    void on_delete_2_clicked();

    void on_back_clicked();

private:
    Ui::MovieTimetable *ui;
};

#endif // MOVIETIMETABLE_H
