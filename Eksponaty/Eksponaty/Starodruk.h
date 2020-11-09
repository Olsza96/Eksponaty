#ifndef STARODRUK_H
#define STARODRUK_H
#include "Pismo.h"
#define STARODRUK "STARODRUK"

class Starodruk:public Pismo {
	int liczbaNakladu;
public:
	Starodruk();
	Starodruk(std::string, std::string, std::string, int, std::string, int);
	void setStarodruk(std::string, std::string, std::string, int, std::string, int);
	virtual void print();
	virtual void wypelnij();
	virtual void save(std::ostream &str);
	virtual void load(std::istream &str);
};

#endif // !STARODRUK_H
