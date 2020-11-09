#include "functions.h"

void MENU(myList& database) {
	int i = 1, ii = 1;
	std::string nazwa;
	Eksponat* element;

	while (true) {
		system("cls");
		std::cout << "-------------------------------------\nMENU\n-------------------------------------\n";
		std::cout << "1.Wprowadz dane\n2.Wyswietl baze danych\n3.Wyszukaj eksponat w bazie\n4.Wyczysc baze danych\n0.Zakoncz program\n";

		while (!(std::cin >> ii)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
		}

		switch (ii) {
		case 1:
			while (true) {
				system("cls");
				std::cout << "Wybierz element do dodania:\n";
				std::cout << "1.Obraz\n2.Rzezba\n3.Mebel\n4.Przedmiot uzytkowy\n5.Rekopis\n6.Starodruk\n0.Powrot do poprzednich opcji" << std::endl;
				
				while (!(std::cin >> i)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
				}

				if (i == 1) {
					Obraz* O = new Obraz;
					O->wypelnij();
					database.dodajElement(O);
				}
				else if (i == 2) {
					Rzezba* R = new Rzezba;
					R->wypelnij();
					database.dodajElement(R);
				}
				else if (i == 3) {
					Mebel* M = new Mebel;
					M->wypelnij();
					database.dodajElement(M);
				}
				else if (i == 4) {
					PrzedmiotUzytkowy* P = new PrzedmiotUzytkowy;
					P->wypelnij();
					database.dodajElement(P);
				}
				else if (i == 5) {
					Rekopis* R = new Rekopis;
					R->wypelnij();
					database.dodajElement(R);
				}
				else if (i == 6) {
					Starodruk* S = new Starodruk;
					S->wypelnij();
					database.dodajElement(S);
				}
				else if (i == 0) {
					break;
				}
				else {
					std::cout << "Nie ma takiego wyboru, sprobuj ponownie\n";
					system("pause");
				}
			}
			break;
		case 2:
			system("cls");
			database.wypiszListe();
			system("pause");
			break;
		case 3:
			std::cout << "Podaj nazwe eksponatu jaki chcesz znalezc: \n";
			std::cin >> nazwa;
			element = database.wyszukajElement(nazwa);
			if (element) {
				std::cout << "Znaleziony element to: \n";
				element->print();
				std::cout << "-------------------------------------\nDostepne opcje\n-------------------------------------\n1.Edytuj element\n2.Usun element\n0.Powrot\n";
				while (!(std::cin >> ii)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
				}

				if (ii == 1) {
					element->wypelnij();
				}
				else if (ii == 2) {
					database.usunElement(element);
				}
				else if (ii == 0) {
					break;
				}
				else {
					std::cout << "Brak takiej opcji, sprobuj ponownie\n";
					system("pause");
				}
			}
			else {
				std::cout << "Brak eksponatu o podanej nazwie\n";
				system("pause");
			}
			break;
		case 4:
			database.clear();
			std::cout << "Wyczyszczono zawartosc bazy\n";
			system("pause");
			break;
		case 0:
			return;
		default:
			std::cout << "Nie ma takiego wyboru, sprobuj ponownie\n";
			system("pause");
			break;
		}
	}
}