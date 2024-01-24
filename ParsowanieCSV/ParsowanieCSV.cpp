#include <iostream>
#include "Point.h"
#include "tree.h"
#include "Analyzer.h"
#include "FileManager.h"
#include <vector>

using namespace std;

static void PrintMenu() {
    cout << "--------Parsowanie CSV--------" << endl;
    cout << "1. Wczytaj plik CSV" << endl;
    cout << "2. Zapisz do pliku binarnego" << endl;
    cout << "3. Wczytaj z pliku binarnego" << endl;
    cout << "0. Wyjdz z programu" << endl;
    cout << "Podaj numer opcji: " << endl;
}

static void LoadDataFromCsv(string filePath) {
    // Wczytaj dane z pliku CSV
    FileManager manager;
    std::vector<Point> dataPoints = manager.loadDataFromCsv(filePath);

    // Zbuduj drzewo danych
    Tree* dataTree = new Tree();
    for (const Point& point : dataPoints) {
		dataTree->dodanieDanych(point);
	}

    // wyswietl dane z drzewa
    //dataTree.pokazDrzewo();

    // Utwórz obiekt analizatora danych
    DataAnalyzer dataAnalyzer(dataTree);

    // Przyk³adowe wywo³anie funkcji analizatora
    cout << "Suma autokonsumpcji: " << dataAnalyzer.sumAutokonsumpcja("01.10.2020 0:00", "01.10.2020 8:00") << endl;
    cout << "Srednia importu: " << dataAnalyzer.averageImport("01.10.2020 0:00", "01.10.2020 8:00") << endl;
}

int main()
{
    int choice;

    do {
        PrintMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Wczytaj plik CSV" << endl;
            LoadDataFromCsv("plik.csv");
			break;
        case 2:
			cout << "Zapisz do pliku binarnego" << endl;
            break;
        case 3:
            cout << "Wczytaj z pliku binarnego" << endl;
			break;
        case 0:
			cout << "Wychodzenie z programu..." << endl;
            break;
        default:
            cout << "Nie ma takiej opcji" << endl;
			break;
        }
    } while (choice != 0);

    return 0;
}
