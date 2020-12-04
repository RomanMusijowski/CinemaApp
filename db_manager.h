#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <QSqlDatabase>


class db_manager
{
public:
    db_manager(const QString& path);
    ~db_manager();
    bool isOpen() const;
    bool createTable();
    bool login(const QString& name, const QString& pass);

    bool addPerson(const QString& name);
    bool removePerson(const QString& name);
    bool personExists(const QString& name) const;
    void printAllPersons() const;

private:
    QSqlDatabase m_db;
};

#endif // DB_MANAGER_H
