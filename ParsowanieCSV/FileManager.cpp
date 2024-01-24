#include "FileManager.h"
#include "Analyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

vector<string> FileManager::split(const string& str, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(str);

    while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}

string FileManager::removeQuotes(const string& str) {
	string newStr = str;

    for (size_t i = 0; i < newStr.size(); ++i) {
        if (newStr[i] == '"') {
            newStr.erase(i, 1);
		}
	}

	return newStr;
}


#pragma warning(disable : 4996)
vector<Point> FileManager::loadDataFromCsv(const string& filePath) {
    vector<Point> dataPoints;

    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y_%H", timeinfo);
    std::string logTime(buffer);

    string logFilePath = "log_" + logTime + ".txt";
    string errorFilePath = "log_error_" + logTime + ".txt";

    ofstream logFile(logFilePath);
    ofstream errorFile(errorFilePath);
    ifstream csvFile(filePath);

    if (!logFile.is_open() || !errorFile.is_open()) {
		cerr << "Wystapil blad przy otwieraniu pliku log" << endl;
        throw exception("Wystapil blad przy otwieraniu pliku log");
	}

    if (!csvFile.is_open()) {
        cerr << "Wystapil blad przy otwieraniu " << filePath << endl;
        errorFile << "Wystapil blad przy otwieraniu " << filePath << endl;
        return dataPoints;
    }

    string line;

    while (getline(csvFile, line)) {
        if (line.find("Time") != string::npos) {
            clog << "Pominieto naglowek: " << line << endl;
            logFile << "Pominieto naglowek: " << line << endl;
			continue;
		}

        string dateTime;
        double autokonsumpcja, eksport, importD, pobor, produkcja;

        vector<string> dataFromCsv = split(line, ',');

        if (dataFromCsv.size() != 6) {
            cerr << "Bledna linia: " << line << endl;
            errorFile << "Bledna linia: " << line << endl;
            continue;
        }

        bool isLineInvalid = false;
        for (size_t i = 0; i < dataFromCsv.size(); ++i) {
            dataFromCsv[i] = removeQuotes(dataFromCsv[i]);

            if (dataFromCsv[i].empty()) {
				cerr << "Brak wartosci w linii: " << line << endl;
				errorFile << "Brak wartosci w linii: " << line << endl;
                isLineInvalid = true;
			}
        }

        if (isLineInvalid) {
            continue;
        }

        dateTime = dataFromCsv[0];
        autokonsumpcja = stod(dataFromCsv[1]);
        eksport = stod(dataFromCsv[2]);
        importD = stod(dataFromCsv[3]);
        pobor = stod(dataFromCsv[4]);
        produkcja = stod(dataFromCsv[5]);

        if (dateTime.empty()) {
            cerr << "Brak daty w linii: " << line << endl;
            errorFile << "Brak daty w linii: " << line << endl;
            continue;
        }

        Point* point = new Point(dateTime, autokonsumpcja, eksport, importD, pobor, produkcja);
        dataPoints.push_back(*point);
        delete point;
    }    

    if (dataPoints.empty()) {
		cerr << "Nie wczytano danych" << endl;
        errorFile << "Nie wczytano danych" << endl;
		return dataPoints;
	}

    csvFile.close();
    logFile.close();
    errorFile.close();
    return dataPoints;
}

void FileManager::saveDataToBinary(const Tree& dataTree, const string& filePath) {
    // Implementacja zapisywania danych do pliku binarnego
}

Tree FileManager::loadDataFromBinary(const string& filePath) {
    // Implementacja odczytywania danych z pliku binarnego

    return Tree();
}