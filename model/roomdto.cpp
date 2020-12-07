#include "roomdto.h"

QString RoomDTO::getName() const
{
    return name;
}

void RoomDTO::setName(const QString &value)
{
    name = value;
}

int RoomDTO::getCount() const
{
    return count;
}

void RoomDTO::setCount(int value)
{
    count = value;
}

RoomDTO::RoomDTO()
{

}
