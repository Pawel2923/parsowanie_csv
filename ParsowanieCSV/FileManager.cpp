#include "FileManager.h"

using namespace std;

vector<Point> FileManager::loadDataFromCsv(const string& filePath) {
    vector<Point> dataPoints;

    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Wystapil blad przy otwieraniu " << filePath << endl;
        return dataPoints;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);
        string dateTime;
        double autokonsumpcja, eksport, import, pobor, produkcja;

        if (!(iss >> dateTime >> autokonsumpcja >> eksport >> import >> pobor >> produkcja)) {
            cout << "Bledna linia: " << line << endl;
            continue;
        }

        if (dateTime.empty()) {
			cout << "Brak daty w linii: " << line << endl;
			continue;
		}

        dataPoints.emplace_back(dateTime, autokonsumpcja, eksport, import, pobor, produkcja);
    }

    file.close();
    return dataPoints;
}

void FileManager::saveDataToBinary(const Tree& dataTree, const string& filePath) {
    // Implementacja zapisywania danych do pliku binarnego
}

Tree FileManager::loadDataFromBinary(const string& filePath) {
    // Implementacja odczytywania danych z pliku binarnego

    return Tree();
}