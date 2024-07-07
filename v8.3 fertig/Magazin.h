/*
 * Magazin.h
 *
 *  Created on: 14.06.2022
 *      Author: 13967
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_
#include "Medium.h"

class Magazin: public Medium {
public:
	Magazin();
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual ~Magazin();
	bool ausleihen(Person person,Datum ausleihdatum);
	std::ostream& ausgabe(std::ostream& out);
	std::ostream& operator << (const Magazin& magazin) const;

protected:
	Datum initdatumAusgabe;
	std::string initsparte;
};

#endif /* MAGAZIN_H_ */
