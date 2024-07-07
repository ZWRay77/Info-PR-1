#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

class City
{
public:
    City(QString name, int x, int y);
    ~City();
    void draw(QGraphicsScene& scene);
    QString getName();
    int getX();
    int getY();

protected:
    QString name;
    int x;
    int y;

};


#endif // CITY_H
