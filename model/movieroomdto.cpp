#include "movieroomdto.h"

QString MovieRoomDTO::getName() const
{
    return name;
}

void MovieRoomDTO::setName(const QString &value)
{
    name = value;
}

QString MovieRoomDTO::getRoom() const
{
    return room;
}

void MovieRoomDTO::setRoom(const QString &value)
{
    room = value;
}

QString MovieRoomDTO::getPlaces() const
{
    return places;
}

void MovieRoomDTO::setPlaces(const QString &value)
{
    places = value;
}

QString MovieRoomDTO::getFreePlaces() const
{
    return freePlaces;
}

void MovieRoomDTO::setFreePlaces(const QString &value)
{
    freePlaces = value;
}

QString MovieRoomDTO::getTime() const
{
    return time;
}

void MovieRoomDTO::setTime(const QString &value)
{
    time = value;
}

QString MovieRoomDTO::getMovieId() const
{
    return movieId;
}

void MovieRoomDTO::setMovieId(const QString &value)
{
    movieId = value;
}

MovieRoomDTO::MovieRoomDTO()
{
    
}
