#include <iostream>
#include "Point.h"
#include "tree.h"
#include "Analyzer.h"
#include "FileManager.h"
#include <vector>

using namespace std;


int main()
{
    // Wczytaj dane z pliku CSV
    FileManager manager;
    std::vector<Point> dataPoints = manager.loadDataFromCsv("plik.csv");

    // Zbuduj drzewo danych
    Tree dataTree;
    for (const auto& dataPoint : dataPoints) {
        dataTree.dodanieDanych(dataPoint);
    }

    dataTree.pokazDrzewo();

    // Utwórz obiekt analizatora danych
    DataAnalyzer dataAnalyzer(dataTree);

    int choice;

    do {
        cout << "--------Parsowanie CSV--------" << endl;
        cout << "1. Wczytaj plik CSV" << endl;
        cout << "2. Zapisz do pliku binarnego" << endl;
        cout << "3. Wczytaj z pliku binarnego" << endl;
        cout << "0. Wyjdz z programu" << endl;
        cout << "Podaj numer opcji: " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Wczytaj plik CSV" << endl;
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
