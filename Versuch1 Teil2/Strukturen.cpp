/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;


	struct Person{
		string sNachname;
		string sVorname;
		int iGeburtsjahr;
		int iAlter;
	};

int main() {
	Person nBenutzer;

	cout<<"Bitte geben Sie Ihren Nachnamen, Vornamen, Geburtsjahr und Alter ein"<<endl;
	cin>>nBenutzer.sNachname;
	cin>>nBenutzer.sVorname;
	cin>>nBenutzer.iGeburtsjahr;
	cin>>nBenutzer.iAlter;
	cout<<"Nachname: "<<nBenutzer.sNachname<<endl;
	cout<<"Vorname: "<<nBenutzer.sVorname<<endl;
	cout<<"Geburtsjahr: "<<nBenutzer.iGeburtsjahr<<endl;
	cout<<"Alter: "<<nBenutzer.iAlter<<endl;

	Person nKopieGesamt=nBenutzer;
	Person nKopieEinzeln;
	nKopieEinzeln.sNachname=nBenutzer.sNachname;
	nKopieEinzeln.sVorname=nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr=nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter=nBenutzer.iAlter;

	cout<<"Kopie der gesamten Struktur:"<<endl;
	cout<<"Nachname: "<<nKopieGesamt.sNachname<<endl;
	cout<<"Vorname: "<<nKopieGesamt.sVorname<<endl;
	cout<<"Geburtsjahr: "<<nKopieGesamt.iGeburtsjahr<<endl;
	cout<<"Alter: "<<nKopieGesamt.iAlter<<endl;

	cout<<"Kopie jedes Elements einzeln:"<<endl;
	cout<<"Nachname: "<<nKopieEinzeln.sNachname<<endl;
	cout<<"Vorname: "<<nKopieEinzeln.sVorname<<endl;
	cout<<"Geburtsjahr: "<<nKopieEinzeln.iGeburtsjahr<<endl;
	cout<<"Alter: "<<nKopieEinzeln.iAlter<<endl;

	return 0;
}
