#ifndef ADDMOVIE_H
#define ADDMOVIE_H

#include <QDialog>

namespace Ui {
class addMovie;
}

class AddMovie : public QDialog
{
    Q_OBJECT

public:
    explicit AddMovie(QWidget *parent = nullptr);
    ~AddMovie();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addMovie *ui;
};

#endif // ADDMOVIE_H
