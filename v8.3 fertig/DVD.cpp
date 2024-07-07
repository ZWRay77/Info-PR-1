/*
 * DVD.cpp
 *
 *  Created on: 14.06.2022
 *      Author: 13967
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) : Medium(initTitel), initaltersfreigabe(initAltersfreigabe), initgenre(initGenre)
{

}

std::ostream& DVD::ausgabe(std::ostream& out)
{
	Medium::ausgabe(out);
	out << "FSK: " << this->initaltersfreigabe << std::endl
		<< "Genre: " << this->initgenre << std::endl;
	return out;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	Datum aktuellesDatum;
	if (this->initaltersfreigabe <= abs(person.getGeburtsdatum() - aktuellesDatum) / 12)
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}

	else
	{
		std::cout << "DVD darf nicht ausgeliehen werden!" << std::endl;
		return false;
	}
}

DVD::~DVD() {
	// TODO Auto-generated destructor stub
}

std::ostream& operator << (std::ostream& out, DVD& dvd)
{
	return dvd.ausgabe(out);
}

