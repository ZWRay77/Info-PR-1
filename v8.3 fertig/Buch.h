/*
 * Buch.h
 *
 *  Created on: 14.06.2022
 *      Author: 13967
 */

#ifndef BUCH_H_
#define BUCH_H_
#include "Medium.h"

class Buch: public Medium {

public:
	Buch();
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch();
	std::ostream& ausgabe(std::ostream& out);
	std::ostream& operator << (const Buch& buch) const;
	
protected:
	std::string initAutor;
};

#endif /* BUCH_H_ */
