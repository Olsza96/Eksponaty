#ifndef REKOPIS_H
#define REKOPIS_H
#include "Pismo.h"
#define PAPIER "Brak";
#define OPRAWA "Brak";
#define REKOPIS "REKOPIS"

class Rekopis :public Pismo {
	std::string typPapieru;
	std::string rodzajOprawy;
public:
	Rekopis();
	Rekopis(std::string, std::string, std::string, int, std::string, std::string, std::string);
	void setRekopis(std::string, std::string, std::string, int, std::string, std::string, std::string);
	virtual void print();
	virtual void wypelnij();
	virtual void save(std::ostream &str);
	virtual void load(std::istream &str);
};

#endif // !REKOPIS_H
