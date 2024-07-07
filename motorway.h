#ifndef MOTORWAY_H
#define MOTORWAY_H

#include "city.h"

#include <QGraphicsItem>
#include <QGraphicsView>

class Motorway
{
public:
    Motorway(City*,City*);
    ~Motorway();
    void draw(QGraphicsScene&scene);

private:
    City*stadt1;
    City*stadt2;
};

#endif // MOTORWAY_H
