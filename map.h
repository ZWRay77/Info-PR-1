#ifndef MAP_H
#define MAP_H

#include "city.h"
#include "street.h"
#include "abstractmap.h"

#include <QVector>

class Map : public AbstractMap
{
public:
    Map();
    ~Map();
    void addCity(City*);
    void draw(QGraphicsScene& scene);
    QVector<Street*> getStreetList(const City* city) const;
    bool addStreet(Street* strasse);
    City* findCity(const QString gorad) const;
    QVector<City*> getCityList();
    City* getOppositeCity(const Street* strasse, const City* city) const;
    double getLength(const Street* strasse) const;

private:
    QVector<City*> stadt_Liste;
    QVector <Street*> strassen_Liste;

};

#endif // MAP_H
