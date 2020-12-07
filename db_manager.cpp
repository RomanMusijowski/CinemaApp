#include "db_manager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <model/moviedto.h>
#include <iostream>
#include <sstream>

db_manager::db_manager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
       m_db.setDatabaseName(path);

       if (!m_db.open())
       {
           qDebug() << "Error: connection with database fail";
       }
       else
       {
           qDebug() << "Database: connection ok";
       }
}

db_manager::~db_manager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool db_manager::isOpen() const
{
    return m_db.isOpen();
}

bool db_manager::createTable()
{
    bool success = false;

    QSqlQuery query;
    QSqlQuery query2;
    QSqlQuery query3;

    QSqlQuery query4;
    QSqlQuery query5;
    QSqlQuery query6;

    query.prepare("CREATE TABLE  USERS (userId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,email VARCHAR(64) NOT NULL,username VARCHAR(64) UNIQUE NOT NULL,password VARCHAR(64) NOT NULL);");
    query2.prepare("CREATE TABLE  ROOMS (roomId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,name VARCHAR(64) UNIQUE NOT NULL,places VARCHAR(64) NOT NULL);");
    query3.prepare("CREATE TABLE  MOVIES (movieId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,name VARCHAR(64) UNIQUE NOT NULL,date TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,roomId INTEGER,FOREIGN KEY(roomId) REFERENCES ROOMS(roomId));");

    query4.prepare("INSERT INTO USERS (`email`, `username`, `password`) VALUES (\"user1@gmail.com\", \"user1\", \"user\"),(\"user2@gmail.com\", \"user2\", \"user\"),(\"user3@gmail.com\", \"user3\", \"user\");");
    query5.prepare("INSERT INTO ROOMS ('name', 'places') VALUES (\"one\", \"0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,\"), (\"two\",\"0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,\"), (\"three\",\"0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,\"), (\"four\",\"0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,\");");
    query6.prepare("INSERT INTO MOVIES (`name`, `roomId`) VALUES (\"Film1\" , 1), (\"Film2\" , 2), (\"Film3\", 3);");




    if (!query.exec() )
    {
        qDebug() << "Couldn't create the query, one might already exist.";
        success = false;
    }
    if ( !query2.exec())
    {
        qDebug() << "Couldn't create the query2, one might already exist.";
        success = false;
    }
    if (!query3.exec())
    {
        qDebug() << "Couldn't create the query3, one might already exist.";
        success = false;
    }
    if(!query4.exec()){
        qDebug() << "Injection query4 error." << query4.lastError();
    }
    if(!query5.exec()){
        qDebug() << "Injection query5 error." << query4.lastError();
    }
    if(!query6.exec()){
        qDebug() << "Injection query6 error." << query4.lastError();
    }

    return success;
}

bool db_manager::login(const QString& name, const QString& pass){
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM USERS WHERE username = (:username) AND password = (:password)");
    checkQuery.bindValue(":username", name);
    checkQuery.bindValue(":password", pass);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person login failed: " << checkQuery.lastError();
    }

    return exists;
}

QList<MovieDTO> db_manager::getMovies()
{
    QList<MovieDTO> movies;
    QSqlQuery query("SELECT name, COUNT(roomId) as cou from MOVIES group by name");
    int nameId= query.record().indexOf("name");
    int countId = query.record().indexOf("cou");

    while (query.next())
    {
        MovieDTO movie;
        movie.setName(query.value(nameId).toString());
        movie.setSession(query.value(countId).toInt());
        movies.append(movie);
    }
    return movies;
}

bool db_manager::addMovie(const QString &name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO MOVIES (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add movie failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add movie failed: name cannot be empty";
    }

    return success;
}

bool db_manager::editMovie(const QString &oldName, const QString &newName)
{
    bool success = false;
    if(!newName.isEmpty() && !oldName.isEmpty()){
        QSqlQuery queryUpdate;
        queryUpdate.prepare("UPDATE MOVIES SET name= (:newName) WHERE name = (:oldName)");
        queryUpdate.bindValue(":newName", newName);
        queryUpdate.bindValue(":oldName", oldName);
        if(queryUpdate.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "update movie failed: " << queryUpdate.lastError();
        }
    }
    return success;
}


bool db_manager::removeMovie(const QString &name)
{
    bool success = false;
    if(!name.isEmpty() ){
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM MOVIES WHERE name = (:name)");
        queryDelete.bindValue(":name", name);

        if(queryDelete.exec()){
            success = true;
        }
        else
        {
            qDebug() << "delete movie failed: " << queryDelete.lastError();
        }
    }
    return success;
}

QList<RoomDTO> db_manager::getRooms()
{
    QList<RoomDTO> rooms;
    QSqlQuery query("SELECT name, COUNT(roomId) as cou from MOVIES group by name");
    int nameId= query.record().indexOf("name");
    int countId = query.record().indexOf("cou");

    while (query.next())
    {
//        MovieDTO movie;
//        movie.setName(query.value(nameId).toString());
//        movie.setSession(query.value(countId).toInt());
//        rooms.append(movie);
    }
    return rooms;
}

bool db_manager::addRoom(const QString &name, const int &places)
{
    bool success = false;

    int arr[places];
    for(size_t i = 0; i < sizeof(arr); i++){
        arr[i]=0;
    }

    if (!name.isEmpty() && places != 0)
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO ROOMS (name, places) VALUES (:name, :places)");
        queryAdd.bindValue(":name", name);
        queryAdd.bindValue(":places", stringify(arr));

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add room failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add room failed: name and places cannot be empty";
    }

    return success;
}

bool db_manager::editRoom(const QString &oldName, const QString &newName)
{

}

bool db_manager::removeRoom(const QString &name)
{

}

QString db_manager::stringify(int arr[])
{
    QString returnstring = "";
    for (int i = 0; i < sizeof(arr); i++)
      returnstring.append(QString(arr[i]));
    return returnstring;
}


int *db_manager::makeList(const QString &list)
{

}


bool db_manager::addPerson(const QString& name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO people (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add person failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add person failed: name cannot be empty";
    }

    return success;
}

bool db_manager::removePerson(const QString& name)
{
    bool success = false;

    if (personExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM people WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove person failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person doesnt exist";
    }

    return success;
}

void db_manager::printAllPersons() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM people");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}

bool db_manager::personExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM people WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}



