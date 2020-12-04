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

private:
    Ui::Welcom *ui;
};

#endif // WELCOM_H
