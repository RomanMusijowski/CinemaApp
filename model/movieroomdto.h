#ifndef MOVIEROOMDTO_H
#define MOVIEROOMDTO_H

#include <QString>



class MovieRoomDTO
{
private:
    QString movieId;
    QString name;
    QString room;
    QString places;
    QString freePlaces;
    QString time;

public:
    MovieRoomDTO();
    QString getName() const;
    void setName(const QString &value);
    QString getRoom() const;
    void setRoom(const QString &value);
    QString getPlaces() const;
    void setPlaces(const QString &value);
    QString getFreePlaces() const;
    void setFreePlaces(const QString &value);
    QString getTime() const;
    void setTime(const QString &value);
    QString getMovieId() const;
    void setMovieId(const QString &value);
};

#endif // MOVIEROOMDTO_H
