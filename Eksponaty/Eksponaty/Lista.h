#ifndef LISTA_H
#define LISTA_H
#include "Eksponat.h"

struct list{
	Eksponat* element;
	list* pNext;
};

class myList {
	list* root;
public:
	myList();
	void dodajElement(Eksponat*);
	void usunElement(Eksponat*);
	void wyswietlElement(Eksponat*);
	void wypiszListe();
	Eksponat *wyszukajElement(std::string);
	list* getRoot();
	void clear();
	~myList();
};

#endif // !LISTA_H
