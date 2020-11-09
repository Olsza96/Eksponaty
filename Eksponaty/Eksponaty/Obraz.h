#ifndef OBRAZ_H
#define OBRAZ_H
#include "Sztuka.h"
#define TECHNIKA "BRAK";
#define OBRAZ "OBRAZ"

class Obraz :public Sztuka {
	std::string TechnikaMalarska;
public:
	Obraz();
	Obraz(std::string, std::string, std::string, double, double, double, std::string);
	virtual void print();
	void setObraz(std::string, std::string, std::string, double, double, double, std::string);
	virtual void wypelnij();
	virtual void save(std::ostream &str);
	virtual void load(std::istream &str);
	operator double() const;
};

#endif // !OBRAZ_H
