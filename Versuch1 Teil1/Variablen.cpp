//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;

int main() {

    int iErste = 0;
    int iZweite = 0;

// Hier folgt Ihr eigener Code
//1.7.1
    cout<<"Bitte geben Sie zwei Zahlen ein:"<<endl;
    cin>>iErste;
    cin>>iZweite;

    int iSum=iErste+iZweite;
    int iQuotient=iErste/iZweite;
    cout<<"Summe:"<<iSum<<endl;
    cout<<"Quotient:"<<iQuotient<<endl;

//1.7.2
    double dSum=iErste+iZweite;
    double dQuotient=iErste/iZweite;
    cout<<"Summe:"<<dSum<<endl;
    cout<<"Quotient:"<<dQuotient<<endl;

//1.7.3
    double dSumCast=(double)iErste+iZweite;
    double dQuotientCast=(double)iErste/iZweite;
    cout<<"Summe:"<<dSumCast<<endl;
    cout<<"Quotient:"<<dQuotientCast<<endl;

//1.7.4
    string sVorname;
    string sNachname;
    string sVornameName;
    string sNameVorname;
    cout<<"Bitte geben Sie Ihren Vornamen und Nachnamen ein:"<<endl;
    cin>>sVorname;
    cin>>sNachname;

    string str1=sVorname;
    string str2=sNachname;
    string str12=str1+str2;
    string str21=str2+str1;
    sVornameName=str12;
    sNameVorname=str21;

    cout<<"sVorname ist "<<sVornameName<<endl;
    cout<<"sNameVorname ist "<<sNameVorname<<endl;

//1.7.5

    {	/*a*/
    	int iFled[2]={1,2};
    	cout<<iFled[0]<<endl;
    	cout<<iFled[1]<<endl;

    	/*b*/
    	int spielfeld[2][3]={{1,2,3},{4,5,6}};

    	int i;
    	int j;
    	for(i=0;i<2;i++){
    		for(j=0;j<3;j++){
    			cout<<spielfeld[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    	/*c*/
    	const int iZweite=1;
    	cout<<iZweite<<endl;
    }
    	cout<<iZweite<<endl;

//1.7.6
    	int iName1;
    	int iName2;
    	if(isupper(sVorname[0])){
    		iName1=(sVorname[0]-'A')+65;
    	}
    	else{
    		iName1=(sVorname[0]-'a')+97;
    	}
    	if(islower(sVorname[1])){
    		iName2=(sVorname[1]-'a')+97;
    	}
    	else{
    		iName2=(sVorname[1]-'A')+65;
    	}
    	cout<<iName1<<endl;
    	cout<<iName2<<endl;

//1.7.7
    	int position1=(iName1%64)%32;
    	int position2=(iName2%64)%32;
    	cout<<"Die Position des ersten Buchstabens ist die "<<position1<<"-te des deutschen Alphabets"<<endl;
    	cout<<"Die Position des zweiten Buchstabens ist die "<<position2<<"-te des deutschen Alphabets"<<endl;

	return 0;
}
