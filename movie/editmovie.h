#ifndef EDITMOVIE_H
#define EDITMOVIE_H

#include <QDialog>


namespace Ui {
class EditMovie;
}

class EditMovie : public QDialog
{
    Q_OBJECT

public:
    explicit EditMovie(QString, QWidget *parent = 0);
    ~EditMovie();

private slots:
    void on_update_clicked();

    void on_cencal_clicked();

private:
    Ui::EditMovie *ui;
    QString name;
};

#endif // EDITMOVIE_H
