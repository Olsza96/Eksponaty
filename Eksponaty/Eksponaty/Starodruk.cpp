#include "Starodruk.h"

Starodruk::Starodruk(){
	autor = AUTOR;
	nazwa = NAZWA;
	okresPowstania = OKRES;
	iloscStron = ZERO;
	pochodzenie = POCHODZENIE;
	liczbaNakladu = ZERO;
}

Starodruk::Starodruk(std::string autor, std::string nazwa, std::string okresPowstania, int iloscStron, std::string pochodzenie, int naklad){
	setStarodruk(autor, nazwa, okresPowstania, iloscStron, pochodzenie, naklad);
}

void Starodruk::setStarodruk(std::string autor, std::string nazwa, std::string okresPowstania, int iloscStron, std::string pochodzenie, int naklad){
	this->autor = autor;
	this->nazwa = nazwa;
	this->okresPowstania = okresPowstania;
	this->iloscStron = iloscStron;
	this->pochodzenie = pochodzenie;
	this->liczbaNakladu = naklad;
}

void Starodruk::print(){
	std::cout << "Starodruk\n-----------------------------------\nNazwa: " << nazwa << "\nAutor: " << autor << "\nOkres powstania: " << okresPowstania << "\nIlosc stron: " << iloscStron << "\nPochodzenie: " << pochodzenie << "\nNaklad: " << liczbaNakladu << "\n-----------------------------------" << std::endl;
}

void Starodruk::wypelnij(){
	std::string text[4];
	int params[2];

	std::cout << "Podaj autora, nazwe, okres powstania oraz pochodzenie starodruku\n";
	for (int i = 0; i < 4; i++)
		std::cin >> text[i];

	std::cout << "Podaj ilosc stron oraz naklad starodruku\n";
	for (int i = 0; i < 2; i++) {
		while (!(std::cin >> params[i])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
			std::cout << "Podano bledne dane, sprobuj ponownie\n";
		}
	}

	setStarodruk(text[0], text[1], text[2], params[0], text[3], params[1]);
}

void Starodruk::save(std::ostream& str) {
	str << STARODRUK << "\n";
	str << this->autor << "\n";
	str << this->nazwa << "\n";
	str << this->okresPowstania << "\n";
	str << this->iloscStron << "\n";
	str << this->pochodzenie << "\n";
	str << this->liczbaNakladu << "\n";
}

void Starodruk::load(std::istream &str){
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
	this->liczbaNakladu = std::stoi(linia);
}
