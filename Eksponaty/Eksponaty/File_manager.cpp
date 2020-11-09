#include "File_manager.h"


void fileManager::save(myList *databse){
	std::fstream File(BAZA_EKSPONATOW, std::ios::out);
	list *tmp = databse->getRoot();

	if (File.is_open()) {
		
		while (tmp) {
			tmp->element->save(File);
			tmp = tmp->pNext;
		}

		File.close();
	}
	else
		std::cout << "Nie udalo sie utowrzyc pliku do zapisu\n";
}

void fileManager::load(myList *database){
	std::fstream File(BAZA_EKSPONATOW, std::ios::in);
	std::string category;

	if (File.is_open()) {

		while (std::getline(File, category)) {

			if (category == MEBEL) {
				Mebel* M = new Mebel;
				M->load(File);
				database->dodajElement(M);
			}
			else if (category == OBRAZ) {
				Obraz* O = new Obraz;
				O->load(File);
				database->dodajElement(O);
			}
			else if (category == RZEZBA) {
				Rzezba* R = new Rzezba;
				R->load(File);
				database->dodajElement(R);
			}
			else if (category == REKOPIS) {
				Rekopis* R = new Rekopis;
				R->load(File);
				database->dodajElement(R);
			}
			else if (category == STARODRUK) {
				Starodruk* S = new Starodruk;
				S->load(File);
				database->dodajElement(S);
			}
			else if (category == PRZEDMIOT_UZYTKOWY) {
				PrzedmiotUzytkowy* P = new PrzedmiotUzytkowy;
				P->load(File);
				database->dodajElement(P);
			}
			else {
				std::cout << "\n---------------------\nBlad, nieznany eksponat " << category << std::endl;
			}
		}

		File.close();
	}
	else
		std::cout << "Nie udalo sie otworzyc pliku do odczytu\n";
}
