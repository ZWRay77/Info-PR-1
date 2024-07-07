#include "map.h"

#include <QDebug>
#include <QGraphicsTextItem>
#include <qmath.h>

Map::Map()
{

}

Map::~Map()
{

}

void Map::addCity(City* stadt)
{
    stadt_Liste.append(stadt);
    qDebug() << stadt->getName() << " wurde in der Karte hinzugefügt";
}

void Map::draw(QGraphicsScene& scene)
{
    for(auto city : stadt_Liste)
    {
        city->draw(scene);
    }
    for(auto strasse : strassen_Liste)
    {
        strasse->draw(scene);
    }
}

City* Map::findCity(const QString cityName) const
{
    for(QVector<City*>::const_iterator it = stadt_Liste.begin(); it != stadt_Liste.end(); it++)
    {
        if ((*it)->getName() == cityName)
        {
            return *it;
        }
    }
    return nullptr;
}


QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector <Street*> cityStreetList;
    for(QVector<Street*>::const_iterator it = strassen_Liste.begin();
         it != strassen_Liste.end();
         it++)
    {
        if(city == (*it)->getStadt1() || city == (*it)->getStadt2())
        {
            cityStreetList.append(*it);
        }
    }
    return cityStreetList;
}

QVector<City*> Map::getCityList()
{
    return stadt_Liste;
}

bool Map::addStreet(Street* strasse)
{
    City* gorad1 = strasse->getStadt1();
    City* gorad2 = strasse->getStadt2();

    if (findCity(gorad1->getName()) != nullptr && findCity(gorad2->getName()) != nullptr)
    {
        strassen_Liste.append(strasse);
        return true;
    }
    else
    {
        return false;
    }
}

City* Map::getOppositeCity(const Street* strasse, const City* city) const
{
    if(city == strasse->getStadt1())
    {
        return strasse->getStadt2();
    }
    if(city == strasse->getStadt2())
    {
        return strasse->getStadt1();
    }
    else
    {
        return nullptr;
    }
}

double Map::getLength(const Street* strasse) const
{
    double x1 = strasse->getStadt1()->getX();
    double y1 = strasse->getStadt1()->getY();
    double x2 = strasse->getStadt2()->getX();
    double y2 = strasse->getStadt2()->getY();
    double abs = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    double laenge = sqrt(abs);
    return laenge;
}
