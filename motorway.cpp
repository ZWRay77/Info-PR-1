#include "motorway.h"
#include "city.h"

Motorway::Motorway(City*city1,City*city2):stadt1(city1),stadt2(city2)
{

}

Motorway::~Motorway()
{

}

void Motorway::draw(QGraphicsScene&scene)
{
    int x1=(stadt1)->getX();
    int y1=(stadt1)->getY();
    int x2=(stadt2)->getX();
    int y2=(stadt2)->getY();

    QPen Pen;
    Pen.setColor(Qt::blue);
    Pen.setWidth(2);
    scene.addLine(x1,y1,x2,y2,Pen);
}
