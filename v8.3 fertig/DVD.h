/*
 * DVD.h
 *
 *  Created on: 14.06.2022
 *      Author: 13967
 */

#ifndef DVD_H_
#define DVD_H_
#include "Medium.h"

class DVD: public Medium {
public:
	DVD();
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();
	bool ausleihen(Person person, Datum ausleihdatum);
	std::ostream& ausgabe(std::ostream& out);
	std::ostream& operator << (const DVD& dvd) const;

protected:
	int initaltersfreigabe;
	std::string initgenre;

};

#endif /* DVD_H_ */
