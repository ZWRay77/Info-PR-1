//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();     // Konstruktor mit Zeigerinitialisierung
    void pushFront(Student pData);
    void pushBack(Student pData);
    void popFront();
    void popBack();
    bool empty();
    Student dataFront(); //Daten des ersten Elements abrufen
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const;
    Student deleteMatNr(unsigned int matNr);//Element nach Matrikelnummer entfernt
};

#endif /*LISTE_H_*/
