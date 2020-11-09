#include "Obraz.h"


Obraz::Obraz() {
	this->autor = AUTOR;
	this->nazwa = NAZWA;
	this->okresPowstania = OKRES;
	this->Szerokosc = ZERO;
	this->Wysokosc = ZERO;
	this->Waga = ZERO;
	this->TechnikaMalarska = TECHNIKA;
}

Obraz::Obraz(std::string autor, std::string nazwa, std::string okresPowstania, double szer, double wys, double waga, std::string technika) {
	setObraz(autor, nazwa, okresPowstania, szer, wys, waga, technika);
}

void Obraz::print() {
	std::cout << "Obraz\n-----------------------------------\nTytul: " << nazwa << "\nAutor: " << autor << "\nOkres powstania: " << okresPowstania << "\nWymiary: " << Szerokosc << "x" << Wysokosc << "\nWaga: " << Waga << "\nTechnika malarska: " << TechnikaMalarska << "\n-----------------------------------" << std::endl;
}

void Obraz::setObraz(std::string autor, std::string nazwa, std::string okresPowstania, double szer, double wys, double waga, std::string technika) {
	this->autor = autor;
	this->nazwa = nazwa;
	this->okresPowstania = okresPowstania;
	this->Szerokosc = szer;
	this->Wysokosc = wys;
	this->Waga = waga;
	this->TechnikaMalarska = technika;
}

void Obraz::wypelnij(){
	std::string text[4];
	double params[3];

	std::cout << "Podaj autora, nazwe, okres powstania i technike malowania obrazu\n";
	for (int i = 0; i < 4; i++) {
		while (!(std::cin >> text[i])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
		}
	}

	std::cout << "Podaj szerokosc, wysokosc oraz wage obrazu\n";
	for (int i = 0; i < 3; i++) {
		while (!(std::cin >> params[i])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
			std::cout << "Podano bledne dane, sprobuj ponownie\n";
		}
	}
	
	setObraz(text[0], text[1], text[2], params[0], params[1], params[2], text[3]);
}

void Obraz::save(std::ostream &str){
	str << OBRAZ << "\n";
	str << this->autor << "\n";
	str << this->nazwa << "\n";
	str << this->okresPowstania << "\n";
	str << this->Szerokosc << "\n";
	str << this->Wysokosc << "\n";
	str << this->Waga << "\n";
	str << this->TechnikaMalarska << "\n";
}

void Obraz::load(std::istream &str){
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
	this->TechnikaMalarska = linia;
}

Obraz::operator double() const{
	return this->Wysokosc;
}
