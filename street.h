#ifndef STREET_H
#define STREET_H

#include <QGraphicsItem>
#include <QGraphicsView>

#include "city.h"

class Street
{
public:
    Street(City*, City*);
    ~Street();
    void draw(QGraphicsScene &scene);
    City* getStadt1() const;
    City* getStadt2() const;
    void strassen_id();
    void drawRed(QGraphicsScene &scene);

private:
    City* stadt1;
    City* stadt2;
};

#endif // STREET_H

