#include "movie.h"


int Movie::getRoomId() const
{
    return roomId;
}

void Movie::setRoomId(int value)
{
    roomId = value;
}

QString Movie::getDateTime() const
{
    return dateTime;
}

void Movie::setDateTime(const QString &value)
{
    dateTime = value;
}

QString Movie::getName() const
{
    return name;
}

void Movie::setName(const QString &value)
{
    name = value;
}

int Movie::getMovieId() const
{
    return movieId;
}

void Movie::setMovieId(int value)
{
    movieId = value;
}

Movie::Movie()
{
    movieId = 0;
    name ="";
    dateTime ="";
    roomId = 0;
}

Movie::Movie(const int id, const QString &nameF , const QString &date, const int room)
{
    movieId = id;
    name =nameF;
    dateTime =date;
    roomId = room;
}
