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

int RoomDTO::getFreePlaces() const
{
    return freePlaces;
}

void RoomDTO::setFreePlaces(int value)
{
    freePlaces = value;
}

RoomDTO::RoomDTO()
{

}
