#include "FileManager.h"

using namespace std;

std::vector<Point> FileManager::loadDataFromCsv(const std::string& filePath) {
    // Implementacja wczytywania danych z pliku CSV
    std::vector<Point> dataPoints;
    ifstream file(filePath);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string date, time;
            double autokonsumpcja, eksport, import, pobor, produkcja;

            if (!(iss >> date >> time >> autokonsumpcja >> eksport >> import >> pobor >> produkcja)) {
                continue;
            }

            dataPoints.emplace_back(date, time, autokonsumpcja, eksport, import, pobor, produkcja);
        }
    }
    else {
        cout << "Nie udalo sie otworzyc pliku" << endl;
    }

    file.close();
    return dataPoints;
}

void FileManager::saveDataToBinary(const Tree& dataTree, const std::string& filePath) {
    // Implementacja zapisywania danych do pliku binarnego
}

Tree FileManager::loadDataFromBinary(const std::string& filePath) {
    // Implementacja odczytywania danych z pliku binarnego

    return Tree();
}