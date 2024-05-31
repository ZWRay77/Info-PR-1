///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <cstring>

string verschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code

	for(int i=0;i<wort.length();i++){
		wort[i]=toupper(wort[i]);
		for(int k=0;k<26;k++){
			if(schluessel[0][k]==wort[i]){
				wort[i]=schluessel[1][k];
				break;
			}
		}
	}
	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	for(int i=0;i<wort.length();i++){
		wort[i]=toupper(wort[i]);
		for(int k=0;k<26;k++){
			if(schluessel[0][k]==wort[i]){
				wort[i]=schluessel[1][k];
				break;
			}
		}
	}
	return wort;
}

int main()
{
	// Hier folgt Ihr Code
	char verTabelle[2][26];
	char entTabelle[2][26];
	for(int i=0;i<26;i++){
		verTabelle[0][i]='A'+i;
		entTabelle[1][i]='A'+i;
	}
	strcpy(verTabelle[1], "EGNJBLCTUWDFIMKOZQYXRSVAHP");


	/*char currentvalue[26];
	for(int i=0;i<26;i++){
		currentvalue[i]='A'+i;
	}

	for(int i=0;i<26;i++){
		int index=rand()%26;
		verTabelle[1][i]=currentvalue[index];
		currentvalue[index]=currentvalue[25-i];
	}*/

	for(int i=0;i<26;i++){
		entTabelle[0][i]=verTabelle[1][i];
	}

	cout<<"Klartext: ";
	for(int i=0;i<26;i++){
		cout<<verTabelle[0][i]<<" ";
	}
	cout<<endl;
	cout<<"Verschl¨¹sseln: ";
	for(int i=0;i<26;i++){
		cout<<verTabelle[1][i]<<" ";
	}
	cout<<endl;

	string Eingabe;
	cout<<"Geben  Sie ein Wort ein: "<<endl;
	cin>>Eingabe;

	string verschluesselnWort=verschluesseln(verTabelle, Eingabe);
	cout<<"Verschl¨¹sseltes Wort: "<<verschluesselnWort<<endl;
	string entschluesselnWort=entschluesseln(entTabelle,verschluesselnWort);
	cout<<"Entschl¨¹sseltes Wort: "<<entschluesselnWort<<endl;

	return 0;
}


