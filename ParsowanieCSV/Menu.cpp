#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

Menu::Menu() : choice(0), tree(nullptr), analyzer(nullptr) {}
Menu::~Menu() {
	delete tree;
	delete analyzer;
}

void Menu::printMenu() {
    cout << "--------Parsowanie CSV--------" << endl;
    cout << "1. Wczytaj plik CSV" << endl;
    cout << "2. Zapisz do pliku binarnego" << endl;
    cout << "3. Wczytaj z pliku binarnego" << endl;
    cout << "4. Wyswietl wszystkie dane" << endl;
    cout << "5. Wypisz dane w przedziale" << endl;
    cout << "6. Wypisz sume autokonsumpcji" << endl;
	cout << "7. Wypisz sume eksportu" << endl;
    cout << "8. Wypisz sume importu" << endl;
    cout << "9. Wypisz sume poboru" << endl;
    cout << "10. Wypisz sume produkcji" << endl;
    cout << "11. Wypisz srednia autokonsumpcji" << endl;
	cout << "12. Wypisz srednia eksportu" << endl;
    cout << "23. Wypisz srednia importu" << endl;
    cout << "14. Wypisz srednia poboru" << endl;
    cout << "15. Wypisz srednia produkcji" << endl;
    cout << "16. Porownaj autokonsumpcje wyznaczony w dwoch przedzialach" << endl;
    cout << "17. Porownaj eksport wyznaczony w dwoch przedzialach" << endl;
    cout << "18. Porownaj import wyznaczony w dwoch przedzialach" << endl;
    cout << "19. Porownaj pobor wyznaczony w dwoch przedzialach" << endl;
    cout << "20. Porownaj produkcje wyznaczona w dwoch przedzialach" << endl;
    cout << "21. Wyszukaj i wypisz rekordy" << endl;
    cout << "0. Wyjdz z programu" << endl;
    cout << "Podaj numer opcji: " << endl;
}

void Menu::start() {
    do {
        printMenu();
        cin >> choice;
		cin.ignore();

        switch (choice) {
        case 1:
            cout << "Wczytaj plik CSV" << endl;
            loadDataFromCsv();
            break;
        case 2:
			cout << "Zapisz do pliku binarnego" << endl;
			saveDataToBinary();
			break;
        case 3:
            cout << "Wczytaj z pliku binarnego" << endl;
			loadDataFromBinary();
            break;
        case 4:
			cout << "Wyswietl wszystkie dane" << endl;
			printAllData();
			break;
		case 5:
			cout << "Wypisz dane w przedziale" << endl;
			printDataInRange();
			break;
        case 6:
			cout << "Wypisz sume autokonsumpcji" << endl;
			sumAutoconsumption();
			break;
        case 7:
			cout << "Wypisz sume eksportu" << endl;
			sumExport();
			break;
        case 8:
			cout << "Wypisz sume importu" << endl;
			sumImport();
			break;
        case 9:
			cout << "Wypisz sume poboru" << endl;
			sumDemand();
			break;
        case 10:
			cout << "Wypisz sume produkcji" << endl;
			sumProduction();
			break;
        case 11:
			cout << "Wypisz srednia autokonsumpcji" << endl;
			avarageAutoconsumption();
			break;
        case 12:
			cout << "Wypisz srednia eksportu" << endl;
			avarageExport();
			break;
        case 13:
			cout << "Wypisz srednia importu" << endl;
			avarageImport();
			break;
        case 14:
			cout << "Wypisz srednia poboru" << endl;
			avarageDemand();
			break;
        case 15:
			cout << "Wypisz srednia produkcji" << endl;
			avarageProduction();
			break;
        case 16:
			cout << "Porownaj autokonsumpcje wyznaczona w dwoch przedzialach" << endl;
			compareAutoconsumption();
			break;
        case 17:
			cout << "Porownaj eksport wyznaczony w dwoch przedzialach" << endl;
			compareExport();
			break;
        case 18:
			cout << "Porownaj import wyznaczony w dwoch przedzialach" << endl;
			compareImport();
			break;
        case 19:
			cout << "Porownaj pobor wyznaczony w dwoch przedzialach" << endl;
			compareDemand();
			break;
        case 20:
			cout << "Porownaj produkcje wyznaczona w dwoch przedzialach" << endl;
			compareProduction();
			break;
        case 21:
			cout << "Wyszukaj i wypisz rekordy" << endl;
			searchAndPrintRecords();
			break;
        case 0:
            cout << "Wychodzenie z programu..." << endl;
            break;
        default:
            cout << "Nie ma takiej opcji" << endl;
            break;
        }
    } while (choice != 0);
}

void Menu::loadDataFromCsv() {
    string filePath;
    cout << "Podaj sciezke do pliku CSV: ";
	getline(cin, filePath);

    // Wczytaj dane z pliku CSV
    FileManager manager;
    vector<Point> dataPoints = manager.loadDataFromCsv(filePath);

    // Zbuduj drzewo danych
    tree = new Tree();
    for (const Point& point : dataPoints) {
        tree->dodanieDanych(point);
    }

	analyzer = new DataAnalyzer(tree);
}

void Menu::saveDataToBinary() {
	if (tree != nullptr) {
		string filePath;
		cout << "Podaj sciezke do pliku binarnego: ";
		getline(cin, filePath);

		FileManager manager;
		manager.saveDataToBinary(*tree, filePath);
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::loadDataFromBinary() {
	string filePath;
	cout << "Podaj sciezke do pliku binarnego: ";
	getline(cin, filePath);

	FileManager manager;
	tree = new Tree(manager.loadDataFromBinary(filePath));
	analyzer = new DataAnalyzer(tree);
}

void Menu::printAllData() {
    if (tree != nullptr && analyzer != nullptr) {
        tree->pokazDrzewo();
    }
    else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::printDataInRange() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime, endDateTime;
		cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime);
		cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime);

		analyzer->printDataInRange(startDateTime, endDateTime);
	}
    else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::sumAutoconsumption() {
    if (tree != nullptr && analyzer != nullptr) {
        string startDateTime, endDateTime;
        cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
        getline(cin, startDateTime);
        cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
        getline(cin, endDateTime);

		cout << "Podane daty: " << startDateTime << " - " << endDateTime << endl;
        cout << "Suma autokonsumpcji: " << analyzer->sumAutokonsumpcja(startDateTime, endDateTime) << endl;
    }
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::sumExport() {
    if (tree != nullptr && analyzer != nullptr) {
        string startDateTime, endDateTime;
        cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
        getline(cin, startDateTime);
        cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
        getline(cin, endDateTime);

		cout << "Podane daty: " << startDateTime << " - " << endDateTime << endl;
        cout << "Suma eksportu: " << analyzer->sumEksport(startDateTime, endDateTime) << endl;
    }
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::sumImport() {
    if (tree != nullptr && analyzer != nullptr) {
        string startDateTime, endDateTime;
        cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
        getline(cin, startDateTime);
        cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
        getline(cin, endDateTime);

        cout << "Suma importu: " << analyzer->sumImport(startDateTime, endDateTime) << endl;
    }
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::sumDemand() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime, endDateTime;
		cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime);
		cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime);

		cout << "Podane daty: " << startDateTime << " - " << endDateTime << endl;
		cout << "Suma poboru: " << analyzer->sumPobor(startDateTime, endDateTime) << endl;
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::sumProduction() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime, endDateTime;
		cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime);
		cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime);

		cout << "Podane daty: " << startDateTime << " - " << endDateTime << endl;
		cout << "Suma produkcji: " << analyzer->sumProdukcja(startDateTime, endDateTime) << endl;
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::avarageAutoconsumption() {
    if (tree != nullptr && analyzer != nullptr) {
        string startDateTime, endDateTime;
        cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
        getline(cin, startDateTime);
        cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
        getline(cin, endDateTime);

		cout << "Podane daty: " << startDateTime << " - " << endDateTime << endl;
        cout << "Suma produkcji: " << analyzer->averageAutokonsumpcja(startDateTime, endDateTime) << endl;
    }
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::avarageExport() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime, endDateTime;
		cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime);
		cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime);

		cout << "Podane daty: " << startDateTime << " - " << endDateTime << endl;
		cout << "Srednia eksportu: " << analyzer->averageEksport(startDateTime, endDateTime) << endl;
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::avarageImport() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime, endDateTime;
		cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime);
		cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime);

		cout << "Podane daty: " << startDateTime << " - " << endDateTime << endl;
		cout << "Srednia importu: " << analyzer->averageImport(startDateTime, endDateTime) << endl;
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::avarageDemand() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime, endDateTime;
		cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime);
		cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime);

		cout << "Podane daty: " << startDateTime << " - " << endDateTime << endl;
		cout << "Srednia poboru: " << analyzer->averagePobor(startDateTime, endDateTime) << endl;
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::avarageProduction() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime, endDateTime;
		cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime);
		cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime);

		cout << "Podane daty: " << startDateTime << " - " << endDateTime << endl;
		cout << "Srednia produkcji: " << analyzer->averageProdukcja(startDateTime, endDateTime) << endl;
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::compareAutoconsumption() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime1, endDateTime1, startDateTime2, endDateTime2;
		cout << "Podaj poczatkowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime1);
		cout << "Podaj koncowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime1);
		cout << "Podaj poczatkowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime2);
		cout << "Podaj koncowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime2);

		analyzer->compareAutokonsumpcja(startDateTime1, endDateTime1, startDateTime2, endDateTime2);
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::compareExport() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime1, endDateTime1, startDateTime2, endDateTime2;
		cout << "Podaj poczatkowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime1);
		cout << "Podaj koncowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime1);
		cout << "Podaj poczatkowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime2);
		cout << "Podaj koncowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime2);

		analyzer->compareEksport(startDateTime1, endDateTime1, startDateTime2, endDateTime2);
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::compareImport() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime1, endDateTime1, startDateTime2, endDateTime2;
		cout << "Podaj poczatkowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime1);
		cout << "Podaj koncowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime1);
		cout << "Podaj poczatkowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime2);
		cout << "Podaj koncowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime2);

		analyzer->compareImport(startDateTime1, endDateTime1, startDateTime2, endDateTime2);
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::compareDemand() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime1, endDateTime1, startDateTime2, endDateTime2;
		cout << "Podaj poczatkowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime1);
		cout << "Podaj koncowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime1);
		cout << "Podaj poczatkowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime2);
		cout << "Podaj koncowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime2);

		analyzer->comparePobor(startDateTime1, endDateTime1, startDateTime2, endDateTime2);
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::compareProduction() {
    if (tree != nullptr && analyzer != nullptr) {
		string startDateTime1, endDateTime1, startDateTime2, endDateTime2;
		cout << "Podaj poczatkowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime1);
		cout << "Podaj koncowa date i czas pierwszego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime1);
		cout << "Podaj poczatkowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime2);
		cout << "Podaj koncowa date i czas drugiego przedzialu (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime2);

		analyzer->compareProdukcja(startDateTime1, endDateTime1, startDateTime2, endDateTime2);
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}

void Menu::searchAndPrintRecords() {
	if (tree != nullptr && analyzer != nullptr) {
		double searchedValue, tolerance;
		string startDateTime, endDateTime;
		cout << "Podaj wartosc szukana: ";
		cin >> searchedValue;
		cout << "Podaj tolerancje: ";
		cin >> tolerance;
		cin.ignore();
		cout << "Podaj poczatkowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, startDateTime);
		cout << "Podaj koncowa date i czas (format daty dd.mm.rrrr h:mm):  ";
		getline(cin, endDateTime);

		analyzer->searchAndPrintRecords(searchedValue, tolerance, startDateTime, endDateTime);
	}
	else {
		cout << "Wystapil blad" << endl;
	}
}