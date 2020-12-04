#include "moviedto.h"

#include <QString>

QString MovieDTO::getName() const
{
    return name;
}

void MovieDTO::setName(const QString &value)
{
    name = value;
}

int MovieDTO::getSessionCount() const
{
    return session;
}

void MovieDTO::setSession(int value)
{
    session = value;
}

MovieDTO::MovieDTO()
{

}
