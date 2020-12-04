#ifndef MOVIE_H
#define MOVIE_H
#include <QString>
using namespace std;

class Movie
{
private:
      int movieId;
      QString name;
      QString dateTime;
      int roomId;
public:
    Movie();
    Movie(const int, const QString&, const QString&, const int);


    int getRoomId() const;
    void setRoomId(int value);
    QString getDateTime() const;
    void setDateTime(const QString &value);
    QString getName() const;
    void setName(const QString &value);
    int getMovieId() const;
    void setMovieId(int value);
};

#endif // MOVIE_H
