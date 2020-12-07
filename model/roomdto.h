#ifndef ROOMDTO_H
#define ROOMDTO_H

#include <QString>



class RoomDTO
{
private:
    QString name;
    int count;
public:
    RoomDTO();
    QString getName() const;
    void setName(const QString &value);
    int getCount() const;
    void setCount(int value);
};

#endif // ROOMDTO_H
