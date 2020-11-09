#include "Lista.h"

myList::myList(){
	root = nullptr;
}

void myList::dodajElement(Eksponat* pHead){

	list* tmp = new list;
	tmp->element = pHead;
	tmp->pNext = root;
	root = tmp;

}

void myList::usunElement(Eksponat* pHead){

	if (root->element == pHead) {
		list *tmp = root->pNext;
		delete root->element;
		delete root;
		root = tmp;
	}
	else {
		list* tmp = root->pNext;
		list* point = root;
		while (tmp->element != pHead) {
			point = tmp;
			tmp = tmp->pNext;
		}
		point->pNext = tmp->pNext;

		delete tmp->element;
		delete tmp;
	}
		
}

Eksponat* myList::wyszukajElement(std::string nazwa) {

	if (root) {
		
		if (root->element->getName() == nazwa) {
			return root->element;
		}
		else {
			list* tmp = root->pNext;
			while (tmp) {
				if (tmp->element->getName() == nazwa)
					return tmp->element;
				tmp = tmp->pNext;
			}
		}
	}

	return nullptr;
}

list* myList::getRoot(){

	return this->root;
}

void myList::clear(){
	while (root) {
		list* tmp = root->pNext;
		delete root->element;
		delete root;
		root = tmp;
	}
}

void myList::wyswietlElement(Eksponat* pHead){
	pHead->print();
}

void myList::wypiszListe(){
	list* tmp = root;
	while (tmp) {
		tmp->element->print();
		tmp = tmp->pNext;
	}
}

myList::~myList(){
	
	while (root) {
		list* tmp = root->pNext;
		delete root->element;
		delete root;
		root = tmp;
	}
}
