#include "Mebel.h"


Mebel::Mebel(){
	autor = AUTOR;
	nazwa = NAZWA;
	okresPowstania = OKRES;
	Szerokosc = ZERO;
	Wysokosc = ZERO;
	Waga = ZERO;
	typMaterialu = MATERIAL;
}

void Mebel::setMebel(std::string autor, std::string nazwa,std::string okresPowstania, double szer, double wys, double waga, std::string typMaterialu){
	this->autor = autor;
	this->nazwa = nazwa;
	this->okresPowstania = okresPowstania;
	this->Szerokosc = szer;
	this->Wysokosc = wys;
	this->Waga = waga;
	this->typMaterialu = typMaterialu;
}

void Mebel::print(){
	std::cout << "Mebel\n-----------------------------------\nNazwa: " << nazwa << "\nTworca: " << autor << "\nOkres powstania: " << okresPowstania << "\nWymiary: " << Szerokosc << "x" << Wysokosc << "\nWaga: " << Waga << "\nTyp materialu: " << typMaterialu << "\n-----------------------------------" << std::endl;
}

Mebel::Mebel(std::string autor, std::string nazwa, std::string okresPowstania, double szer, double wys, double waga, std::string typMaterialu) {
	setMebel(autor, nazwa, okresPowstania, szer, wys, waga, typMaterialu);
}

void Mebel::wypelnij() {
	std::string text[4];
	double params[3];

	std::cout << "Podaj autora, nazwe, okres powstania i rodzaj materialu z jakiego powstal mebel\n";
	for (int i = 0; i < 4; i++)
		std::cin >> text[i];

	std::cout << "Podaj szerokosc, wysokosc oraz wage mebla\n";
	for (int i = 0; i < 3; i++) {
		while (!(std::cin >> params[i])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
			std::cout << "Podano bledne dane, sprobuj ponownie\n";
		}
	}
	
	setMebel(text[0], text[1], text[2], params[0], params[1], params[2], text[3]);
}

void Mebel::save(std::ostream &str){
	str << MEBEL << "\n";
	str << this->autor << "\n";
	str << this->nazwa << "\n";
	str << this->okresPowstania << "\n";
	str << this->Szerokosc << "\n";
	str << this->Wysokosc << "\n";
	str << this->Waga << "\n";
	str << this->typMaterialu << "\n";
}

void Mebel::load(std::istream &str){
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
	this->typMaterialu = linia;
}
