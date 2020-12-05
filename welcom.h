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
    void on_pushButton_4_clicked();

    void on_tableWidget_cellActivated(int row, int column);

    void on_tableWidget_activated(const QModelIndex &index);

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_tableWidget_pressed(const QModelIndex &index);

    void on_editMovie_clicked();

private:
    Ui::Welcom *ui;
    int rowSelected;
};

#endif // WELCOM_H
