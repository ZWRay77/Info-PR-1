#ifndef STATEROAD_H
#define STATEROAD_H

#include "city.h"

#include <QGraphicsItem>
#include <QGraphicsView>

class StateRoad
{
public:
    StateRoad(City*,City*);
    ~StateRoad();
    void draw(QGraphicsScene&scene);

private:
    City*stadt1;
    City*stadt2;

};

#endif // STATEROAD_H
