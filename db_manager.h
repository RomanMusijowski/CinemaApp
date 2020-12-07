#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <QSqlDatabase>
#include <model/moviedto.h>
#include "model/movie.h"
#include "model/roomdto.h"

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
   bool editRoom(const QString& oldName, const QString& newName);
   bool removeRoom(const QString &name);
   QString stringify(int arr[]);
   int* makeList(const QString &list);





    bool addPerson(const QString& name);
    bool removePerson(const QString& name);
    bool personExists(const QString& name) const;
    void printAllPersons() const;

private:
    QSqlDatabase m_db;
};

#endif // DB_MANAGER_H
