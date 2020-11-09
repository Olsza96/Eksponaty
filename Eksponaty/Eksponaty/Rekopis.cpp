#include "Rekopis.h"

Rekopis::Rekopis(){
	autor = AUTOR;
	nazwa = NAZWA;
	okresPowstania = OKRES;
	iloscStron = ZERO;
	pochodzenie = POCHODZENIE;
	typPapieru = PAPIER;
	rodzajOprawy = OPRAWA;
}

Rekopis::Rekopis(std::string autor, std::string nazwa, std::string okresPowstania, int iloscStron, std::string pochodzenie, std::string papier, std::string oprawa){
	setRekopis(autor, nazwa, okresPowstania, iloscStron, pochodzenie, papier, oprawa);
}

void Rekopis::setRekopis(std::string autor, std::string nazwa, std::string okresPowstania, int iloscStron, std::string pochodzenie, std::string papier, std::string oprawa){
	this->autor = autor;
	this->nazwa = nazwa;
	this->okresPowstania = okresPowstania;
	this->iloscStron = iloscStron;
	this->pochodzenie = pochodzenie;
	this->typPapieru = papier;
	this->rodzajOprawy = oprawa;
}

void Rekopis::print(){
	std::cout << "Rekopis\n-----------------------------------\nNazwa: " << nazwa << "\nAutor: " << autor << "\nOkres powstania: " << okresPowstania << "\nIlosc stron: " << iloscStron << "\nPochodzenie: " << pochodzenie << "\nTyp papieru: " << typPapieru << "\nOprawa: " << rodzajOprawy << "\n-----------------------------------" << std::endl;
}

void Rekopis::wypelnij(){
	std::string text[6];
	int iloscStron;

	std::cout << "Podaj autora, nazwe, okres powstania, pochodzenie ,typ uzytego papieru oraz rodzaj oprawy rekopisu\n";
	for (int i = 0; i < 6; i++)
		std::cin >> text[i];

	std::cout << "Podaj ilosc stron rekopisu\n";
	while (!(std::cin >> iloscStron)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
		std::cout << "Podano bledne dane, sprobuj ponownie\n";
	}

	setRekopis(text[0], text[1], text[2], iloscStron, text[3], text[4], text[5]);
}

void Rekopis::save(std::ostream &str){
	str << REKOPIS << "\n";
	str << this->autor << "\n";
	str << this->nazwa << "\n";
	str << this->okresPowstania << "\n";
	str << this->iloscStron << "\n";
	str << this->pochodzenie << "\n";
	str << this->typPapieru << "\n";
	str << this->rodzajOprawy << "\n";
}

void Rekopis::load(std::istream &str){
	std::string linia;

	std::getline(str, linia);
	this->autor = linia;

	std::getline(str, linia);
	this->nazwa = linia;

	std::getline(str, linia);
	this->okresPowstania = linia;

	std::getline(str, linia);
	this->iloscStron = std::stoi(linia);

	std::getline(str, linia);
	this->pochodzenie = linia;

	std::getline(str, linia);
	this->typPapieru = linia;

	std::getline(str, linia);
	this->rodzajOprawy = linia;
}
