#include "city.h"
#include "mainwindow.h"

#include <QString>
#include <QDebug>
#include <QGraphicsTextItem>

City::City(QString name, int x, int y) :
    name(name), x(x), y(y)
{

}

City::~City()
{

}

void City::draw(QGraphicsScene& scene)
{
    int x, y = 0;
    x = getX();//qrand() * 200 / RAND_MAX;
    y = getY();//qrand() * 200 / RAND_MAX;
    scene.addRect(x-4, y-4, 8, 8, QPen(Qt::red),
                  QBrush(Qt::red, Qt::SolidPattern));
    qDebug() << "draw() Funktion ausführen.";

    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(x,y);
    text->setPlainText(name);
    scene.addItem(text);
}

QString City::getName()
{
    return name;
}

int City::getX()
{
    return x;
}

int City::getY()
{
    return y;
}
