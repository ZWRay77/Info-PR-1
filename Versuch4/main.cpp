//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf黨rung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include<iostream>
#include<cmath>

using namespace std;
#define PI acos(-1)

int main()
{
	Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);
    vector1.ausgabe();
    vector2.ausgabe();
    vector1.skalarProd(vector2);
    cout<<"Winkel zwischen Vektor1 und Vektor2: "<<vector1.winkel(vector2)<<endl;
    Vektor neu=vector2.sub(vector1);
    cout<<"Winkel zwischen vector1 und neu: "<<vector1.winkel(neu)<<endl;
    neu.ausgabe();

    double erdRadius=6371000;
    double beobachHoehe=555.7+1.70;
    double schrittWeite=0.00000001;

    Vektor erdradiusVektor(erdRadius,0,0);
    Vektor menschVektor(erdRadius+beobachHoehe,0,0);

	int iterationenAnzahl=0;
	double rad=0.0;

	while(true){
		erdradiusVektor.rotiereUmZ(-schrittWeite);
		rad+=schrittWeite;
		Vektor sicht=erdradiusVektor.sub(menschVektor);
		double angle=erdradiusVektor.winkel(sicht);
		if(angle<=90.0){
			cout<<fixed;
			cout<<setprecision(4);
			cout<<"Sie koennen"<<sicht.laenge()/1000<<" Km weit sehen."<<endl;
			cout<<"Sie sind "<<beobachHoehe<<" Meter hoch."<<endl;
			cout<<"Der Winkel betraegt "<<rad*180/PI<<" Grad."<<endl;
			cout<<"Anzahl Schritte: "<<iterationenAnzahl<<endl;
			break;
		}
		iterationenAnzahl++;
	}

    return 0;

}
