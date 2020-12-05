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
    explicit EditMovie(QWidget *parent = 0);
    EditMovie(int id, QWidget *parent = 0);
    ~EditMovie();

private:
    Ui::EditMovie *ui;
    int id;
};

#endif // EDITMOVIE_H
