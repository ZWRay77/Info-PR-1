//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf黨rung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#define PI acos(-1)

/**
 * @brief erstellen ein neues Objekt Vektor::Vektor
 *
 * @param inX x-Komponente des Vektors
 * @param inY y-Komponente des Vektors
 * @param inZ z-Komponente des Vektors
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Funktion zum Subtrahieren zweier Vektoren
 *
 * @param input Vektor, der vom aktuellen Vektor subtrahiert werden soll
 * @return Das Ergebnis der Subtraktion zweier Vektoren
 */
Vektor Vektor::sub(const Vektor& input) const
{
	return Vektor(x-input.x, y-input.y, z-input.z);
}

/**
 * @brief Funktion zur Berechnung der Länge eines Vektors
 * @return Länge des Vektors
 */
double Vektor::laenge() const
{
	return sqrt(x*x+y*y+z*z);
}

/**
 * @brief Funktion berechnet das Skalarprodukt zweier Vektoren
 *
 * @param input Der Vektor zur Berechnung des Skalarprodukts mit dem aktuellen Vektor
 * @return Das Ergebnis des Skalarprodukts zweier Vektoren
 */
double Vektor::skalarProd(const Vektor& input) const
{
	return(x*input.x+y*input.y+z*input.z);
}

/**
 * @brief Funktion berechnet den Winkel zwischen zwei Vektoren in Grad
 *
 * @param input Der Vektor zur Berechnung des Winkels mit dem aktuellen Vektor
 * @return Das Ergebnis des Winkels zwischen zwei Vektoren
 */
double Vektor::winkel(const Vektor& input) const
{	double Skalarprodukt=skalarProd(input);
	double Length=laenge()*input.laenge();
	return(acos(Skalarprodukt/Length)*(180.0/PI));
}

/**
 * @brief Funktion dreht den Vektor um die Z-Achse
 *
 * @param rad Winkel der Vektordrehung
 */
void Vektor::rotiereUmZ(const double rad)
{
	double cosWinkel=cos(rad);
	double sinWinkel=sin(rad);
	double newX=x*cosWinkel-y*sinWinkel;
	double newY=x*sinWinkel+y*cosWinkel;
	x=newX;
	y=newY;
}
