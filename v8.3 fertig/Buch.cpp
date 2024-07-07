/*
 * Buch.cpp
 *
 *  Created on: 14.06.2022
 *      Author: 13967
 */

#include "Buch.h"
#include <iostream>

Buch::Buch(std::string initTitel, std::string initAutor): Medium(initTitel), initAutor(initAutor) {
 }
Buch::~Buch() {
	// TODO Auto-generated destructor stub
}

std::ostream& Buch::ausgabe(std::ostream& out)
{
	Medium::ausgabe(out);
	out << "Autor: " << this->initAutor << std::endl;
	return out;
}

std::ostream& operator << (std::ostream& out, Buch& buch)
{
	return buch.ausgabe(out);
}
