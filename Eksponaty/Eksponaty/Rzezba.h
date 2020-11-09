#ifndef RZEZBA_H
#define RZEZBA_H
#include "Sztuka.h"
#define EPOKA "Nieznana";
#define RZEZBA "RZEZBA"

class Rzezba:public Sztuka {
	std::string Epoka;
public:
	Rzezba();
	Rzezba(std::string, std::string, std::string, double, double, double, std::string);
	void setRzezba(std::string, std::string, std::string, double, double, double, std::string);
	virtual void print();
	virtual void wypelnij();
	virtual void save(std::ostream &str);
	virtual void load(std::istream &str);
};

#endif // !RZEZBA_H
