#include "db_manager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <model/moviedto.h>

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

    query.prepare("CREATE TABLE  USERS (userId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,email VARCHAR(64) NOT NULL,username VARCHAR(64) NOT NULL,password VARCHAR(64) NOT NULL);");
    query2.prepare("CREATE TABLE  ROOMS (roomId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,placesCount INTEGER NOT NULL);");
    query3.prepare("CREATE TABLE  MOVIES (movieId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,name VARCHAR(64) NOT NULL,date TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,roomId INTEGER,FOREIGN KEY(roomId) REFERENCES ROOMS(roomId));");

    query4.prepare("INSERT INTO USERS (`email`, `username`, `password`) VALUES (\"user1@gmail.com\", \"user1\", \"user\"),(\"user2@gmail.com\", \"user2\", \"user\"),(\"user3@gmail.com\", \"user3\", \"user\");");
    query5.prepare("INSERT INTO ROOMS ('placesCount') VALUES (50),(50),(50),(50);");
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
        qDebug() << "Injection query4 error." << query4.lastError();
    }
    if(!query6.exec()){
        qDebug() << "Injection query4 error." << query4.lastError();
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
