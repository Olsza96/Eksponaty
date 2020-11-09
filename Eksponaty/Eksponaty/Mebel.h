#ifndef MEBEL_H
#define MEBEL_H
#include "Sztuka.h"
#define MATERIAL "BRAK"
#define MEBEL "MEBEL"

class Mebel :public Sztuka {
	std::string typMaterialu;
public:
	Mebel();
	Mebel(std::string, std::string, std::string, double, double, double, std::string);
	void setMebel(std::string, std::string, std::string, double, double, double, std::string);
	virtual void print();
	virtual void wypelnij();
	virtual void save(std::ostream &str);
	virtual void load(std::istream &str);
};

#endif // !MEBEL_H
