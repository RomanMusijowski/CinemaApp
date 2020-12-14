#ifndef MAKERESERVATION_H
#define MAKERESERVATION_H

#include <QDialog>

namespace Ui {
class MakeReservation;
}

class MakeReservation : public QDialog
{
    Q_OBJECT

public:
    explicit MakeReservation(QString, int, QWidget *parent = nullptr);
    ~MakeReservation();

private slots:
    void on_back_clicked();

    void on_unreserve_clicked();

    void on_reserve_clicked();

    void on_tableWidget_pressed(const QModelIndex &index);

private:
    Ui::MakeReservation *ui;
    QString name;
    int movieId;
    int selectedRow;
    int selectedColumn;
};

#endif // MAKERESERVATION_H
