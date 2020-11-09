#ifndef EKSPONAT_H
#define EKSPONAT_H
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

#define AUTOR "Brak autora"
#define NAZWA "Brak nazwy"
#define OKRES "Nieznany"
#define ZERO 0

class Eksponat {
protected:
	std::string autor;
	std::string nazwa;
	std::string okresPowstania;
public:
	virtual void print() = 0;
	virtual void wypelnij() = 0;
	virtual void save(std::ostream &) = 0;
	virtual void load(std::istream &) = 0;
	virtual ~Eksponat() {}
	std::string getName() { return nazwa; }
};

#endif // !EKSPONAT_H
