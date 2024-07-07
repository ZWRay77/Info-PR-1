#include "stateroad.h"
#include "city.h"

#include <QDebug>

StateRoad::StateRoad(City*city1,City*city2):stadt1(city1),stadt2(city2)
{

}

StateRoad::~StateRoad()
{

}

void StateRoad::draw(QGraphicsScene&scene)
{
    int x1=(stadt1)->getX();
    int x2=(stadt2)->getX();
    int y1=(stadt1)->getY();
    int y2=(stadt2)->getY();

    QPen Pen;
    Pen.setColor(Qt::red);
    Pen.setWidth(2);
    scene.addLine(x1,y1,x2,y2,Pen);
}
