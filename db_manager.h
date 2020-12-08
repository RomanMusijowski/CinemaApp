#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <QDateTime>
#include <QSqlDatabase>
#include <model/moviedto.h>
#include "model/movie.h"
#include "model/roomdto.h"
#include <model/movieroomdto.h>

class db_manager
{
public:
    db_manager(const QString& path);
    ~db_manager();
    bool isOpen() const;
    bool createTable();
    bool login(const QString& name, const QString& pass);

    QList<MovieDTO> getMovies();
    bool addMovie(const QString& name);
    bool editMovie(const QString& oldName, const QString& newName);
    bool removeMovie(const QString &name);


    QList<RoomDTO> getRooms();
    bool addRoom(const QString &name, const int &places);
    bool editRoom(const QString &oldName, const QString &newName, const int &newCount);
    bool removeRoom(const QString &name);

    QString stringify(int arr[], int size);
    int* makeList(const QString &list, int *arr);
    int getFreePlaces(QString &places);


    QList<MovieRoomDTO> getMovieList(const QString &name);
    bool addMovieRoom(const QString &name, const int &roomId, const QDateTime date);
    bool editMovieRoom(const QString &oldName, const QString &newName, const int &newCount);
    bool removeMovieRoom(const QString &name);





    bool addPerson(const QString& name);
    bool removePerson(const QString& name);
    bool personExists(const QString& name) const;
    void printAllPersons() const;

private:
    QSqlDatabase m_db;
};

#endif // DB_MANAGER_H
