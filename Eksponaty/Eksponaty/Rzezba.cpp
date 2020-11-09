#include "Rzezba.h"

Rzezba::Rzezba(){
	autor = AUTOR;
	nazwa = NAZWA;
	okresPowstania = OKRES;
	Wysokosc = ZERO;
	Szerokosc = ZERO;
	Waga = ZERO;
	Epoka = EPOKA;
}

Rzezba::Rzezba(std::string autor, std::string nazwa, std::string okresPowstania, double szer, double wys, double waga, std::string epoka){
	setRzezba(autor, nazwa, okresPowstania, szer, wys, waga, epoka);
}

void Rzezba::setRzezba(std::string autor, std::string nazwa, std::string okresPowstania, double szer, double wys, double waga, std::string epoka){
	this->autor = autor;
	this->nazwa = nazwa;
	this->okresPowstania = okresPowstania;
	this->Szerokosc = szer;
	this->Wysokosc = wys;
	this->Waga = waga;
	this->Epoka = epoka;
}

void Rzezba::print(){
	std::cout << "Rzezba\n-----------------------------------\nNazwa: " << nazwa << "\nAutor: " << autor << "\nOkres powstania: " << okresPowstania << "\nWymiary: " << Szerokosc << "x" << Wysokosc << "\nWaga: " << Waga << "\nEpoka: " << Epoka << "\n-----------------------------------" << std::endl;
}

void Rzezba::wypelnij(){
	std::string text[4];
	double params[3];

	std::cout << "Podaj autora, nazwe, okres powstania i nazwe epoki w jakiej powstala rzezba\n";
	for (int i = 0; i < 4; i++)
		std::cin >> text[i];

	std::cout << "Podaj szerokosc, wysokosc oraz wage rzezby\n";
	for (int i = 0; i < 3; i++) {
		while (!(std::cin >> params[i])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
			std::cout << "Podano bledne dane, sprobuj ponownie\n";
		}
	}

	setRzezba(text[0], text[1], text[2], params[0], params[1], params[2], text[3]);
}

void Rzezba::save(std::ostream &str){
	str << RZEZBA << "\n";
	str << this->autor << "\n";
	str << this->nazwa << "\n";
	str << this->okresPowstania << "\n";
	str << this->Szerokosc << "\n";
	str << this->Wysokosc << "\n";
	str << this->Waga << "\n";
	str << this->Epoka << "\n";
}

void Rzezba::load(std::istream &str){
	std::string linia;

	std::getline(str, linia);
	this->autor = linia;

	std::getline(str, linia);
	this->nazwa = linia;

	std::getline(str, linia);
	this->okresPowstania = linia;

	std::getline(str, linia);
	this->Szerokosc = std::stod(linia);

	std::getline(str, linia);
	this->Wysokosc = std::stod(linia);

	std::getline(str, linia);
	this->Waga = std::stod(linia);

	std::getline(str, linia);
	this->Epoka = linia;
}

