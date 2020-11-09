#ifndef PRZEDMIOTUZYTKOWY_H
#define PRZEDMIOTUZYTKOWY_H
#include "Eksponat.h"
#define PRZEZNACZENIE "Brak";
#define PRZEDMIOT_UZYTKOWY "PRZEDMIOT_UZYTKOWY"

class PrzedmiotUzytkowy :public Eksponat {
	std::string przeznaczenie;

public:
	PrzedmiotUzytkowy();
	PrzedmiotUzytkowy(std::string, std::string, std::string, std::string);
	void SetPrzedmiot(std::string, std::string, std::string, std::string);
	virtual void print();
	virtual void wypelnij();
	virtual void save(std::ostream &str);
	virtual void load(std::istream &str);
};

#endif // !PRZEDMIOTUZYTKOWY_H
