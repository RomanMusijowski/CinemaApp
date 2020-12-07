#ifndef EDITROOM_H
#define EDITROOM_H

#include <QDialog>

namespace Ui {
class EditRoom;
}

class EditRoom : public QDialog
{
    Q_OBJECT

public:
    explicit EditRoom(QString, QString, QWidget *parent = nullptr);
    ~EditRoom();

private slots:
    void on_update_clicked();

    void on_cencal_clicked();

private:
    Ui::EditRoom *ui;

    QString nameF;

    QString placesF;
};

#endif // EDITROOM_H
