//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"
using namespace std;

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufügen eines neuen Listenelements am Anfang der Liste
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
	ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);
	if(front==nullptr){
		front=neuesElement;
		back=neuesElement;
	}else{
		neuesElement->setNext(front);
		front->setPrev(neuesElement);
		front=neuesElement;
	}
}
/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                     // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        neuesElement->setPrev(back);
    	back->setNext(neuesElement);
        back = neuesElement;

    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
   if(front!=nullptr){
	   ListenElement*tmp=front;
	   if(front->getNext()!=nullptr){
		   front=front->getNext();
		   front->setPrev(nullptr);
	   }else{
		   front=nullptr;
		   back=nullptr;
	   }
	   delete tmp;
   }
}

/*
 * @brief Entfernen des letzten Listenelements
 *
 * @return void
 */
void Liste::popBack(){
	if(back!=nullptr){
		ListenElement*tmp=back;
		if(back->getPrev()){
		back->setNext(nullptr);
	}else{
		front=nullptr;
		back=nullptr;
	}
	delete tmp;
  }
}
/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    if(front!=nullptr){
    	return front->getData();
    }else{
    	return Student(); //leeres Student-Objekt zurückgeben
    }
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
	if(front!=nullptr){
		 ListenElement* cursor = front;

		  while (cursor != nullptr){
		    	cursor->getData().ausgabe();
		        cursor = cursor->getNext();
		    }
	}else{
		std::cout<<"Die Liste ist leer!"<<std::endl;
	}

}

/*
 * @brief Ausgabe der Listenelements in Rückwärtsrichtung
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const{
	if(back!=nullptr){
			 ListenElement* cursor = back;

			  while (cursor != nullptr){
			    	cursor->getData().ausgabe();
			        cursor = cursor->getPrev();
			  }
		}else{
			std::cout<<"Die Liste ist leer!"<<std::endl;
		}

}

/**
 * @brief Löschen eines Listenelements nach Matrikelnummer
 *
 * @param matNr Matrikelnummer des zu löschenden Elements
 * @return Student das gelöschte Element
 */
Student Liste::deleteMatNr(unsigned int matNr){
	if(front==nullptr){
		throw 99;
	}
	ListenElement* cursor=front;
	while(cursor!=nullptr){
		if(cursor->getData().getMatNr()==matNr){
			Student geloeschterStudent=cursor->getData();
			if(cursor->getPrev()!=nullptr){
				cursor->getPrev()->setNext(cursor->getNext());
			}else{
				front=cursor->getNext();
			}
			if(cursor->getNext()!=nullptr){
				cursor->getNext()->setPrev(cursor->getPrev());
			}else{
				back=cursor->getPrev();
			}
			delete cursor;
			return geloeschterStudent;
		}
		cursor=cursor->getNext();
	}
	throw 99; //Element mit der Matrikelnummer nicht gefunden
}
