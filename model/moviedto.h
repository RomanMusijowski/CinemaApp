#ifndef MOVIEDTO_H
#define MOVIEDTO_H

#include <QString>



class MovieDTO
{
private:
    QString name;
    int session;
public:
    MovieDTO();
    QString getName() const;
    void setName(const QString &value);
    int getSessionCount() const;
    void setSession(int value);
};

#endif // MOVIEDTO_H
