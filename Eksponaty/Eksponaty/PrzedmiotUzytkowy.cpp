#include "PrzedmiotUzytkowy.h"

PrzedmiotUzytkowy::PrzedmiotUzytkowy(){
	autor = AUTOR;
	nazwa = NAZWA;
	okresPowstania = OKRES;
	przeznaczenie = PRZEZNACZENIE;
}

PrzedmiotUzytkowy::PrzedmiotUzytkowy(std::string autor, std::string nazwa, std::string okresPowstania, std::string przeznaczenie){
	SetPrzedmiot(autor, nazwa, okresPowstania, przeznaczenie);
}

void PrzedmiotUzytkowy::SetPrzedmiot(std::string autor, std::string nazwa, std::string okresPowstania, std::string przeznaczenie){
	this->autor = autor;
	this->nazwa = nazwa;
	this->okresPowstania = okresPowstania;
	this->przeznaczenie = przeznaczenie;
}

void PrzedmiotUzytkowy::print(){
	std::cout << "Przedmiot uzytkowy\n-----------------------------------\nNazwa: " << nazwa << "\nAutor: " << autor << "\nOkres powstania: " << okresPowstania << "\nPrzeznaczenie: " << przeznaczenie << "\n-----------------------------------" << std::endl;
}

void PrzedmiotUzytkowy::wypelnij(){
	std::string text[4];

	std::cout << "Podaj autora, nazwe, okres powstania i przeznaczenie przedmiotu\n";
	for (int i = 0; i < 4; i++)
		std::cin >> text[i];

	SetPrzedmiot(text[0], text[1], text[2], text[3]);
}

void PrzedmiotUzytkowy::save(std::ostream &str){
	str << PRZEDMIOT_UZYTKOWY << "\n";
	str << this->autor << "\n";
	str << this->nazwa << "\n";
	str << this->okresPowstania << "\n";
	str << this->przeznaczenie << "\n";
}

void PrzedmiotUzytkowy::load(std::istream &str){
	std::string linia;

	std::getline(str, linia);
	this->autor = linia;

	std::getline(str, linia);
	this->nazwa = linia;

	std::getline(str, linia);
	this->okresPowstania = linia;

	std::getline(str, linia);
	this->przeznaczenie = linia;
}
