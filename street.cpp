#include "street.h"
#include "city.h"

#include <QDebug>

Street::Street(City* city1, City* city2) :
    stadt1(city1), stadt2(city2)
{

}

Street::~Street()
{

}

void Street::draw(QGraphicsScene &scene)
{
    int x1 = (stadt1)->getX();
    int y1 = (stadt1)->getY();
    int x2 = (stadt2)->getX();
    int y2 = (stadt2)->getY();

    QPen Pen;
    Pen.setColor(Qt::blue);
    Pen.setWidth(2);
    scene.addLine(x1, y1, x2, y2, Pen);
}

City* Street::getStadt1() const
{
    return stadt1;
}

City* Street::getStadt2() const
{
    return stadt2;
}

void Street::strassen_id()
{
    qDebug() << "Verbindung zwischen " << stadt1->getName() << " und " << stadt2->getName();
}

void Street::drawRed(QGraphicsScene &scene)
{
    int x1 = (stadt1)->getX();
    int y1 = (stadt1)->getY();
    int x2 = (stadt2)->getX();
    int y2 = (stadt2)->getY();

    QPen Pen;
    Pen.setColor(Qt::red);
    Pen.setWidth(4);
    scene.addLine(x1, y1, x2, y2, Pen);
}
