#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "functions.h"

#define BAZA_EKSPONATOW "Baza_eksponatow.txt"

class fileManager {
public:
	void save(myList *databse);
	void load(myList *database);
};

#endif // !FILE MANAGER_H
