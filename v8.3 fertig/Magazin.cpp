/*
 * Magazin.cpp
 *
 *  Created on: 14.06.2022
 *      Author: 13967
 */

#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte) : Medium(initTitel), initdatumAusgabe(initDatumAusgabe), initsparte(initSparte)
{

}

std::ostream& Magazin::ausgabe(std::ostream& out)
{
	Medium::ausgabe(out);
	out << "Ausgabe: " << initdatumAusgabe << std::endl
		<< "Sparte: " << initsparte << std::endl;
	return out;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
	int diff = abs(ausleihdatum - this->initdatumAusgabe);
	if (diff != 0 && diff != 1)
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}

	else
	{
		std::cout << "Das Magazin darf nicht ausgeliehen werden, weil es sich um die neueste Ausgabe handelt." << std::endl;
		return false;
	}
}

Magazin::~Magazin() {
	// TODO Auto-generated destructor stub
}

std::ostream& operator << (std::ostream& out, Magazin& magazin)
{
	return magazin.ausgabe(out);
}

