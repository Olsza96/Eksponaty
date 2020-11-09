#include "functions.h"
#include "File_manager.h"

//#include <vld.h>


int main() {
	
	fileManager Plik;
	myList* database = new myList;

	Plik.load(database);
	 
	MENU(*database);

	Plik.save(database);

	delete database;
	
	return 0;
}
