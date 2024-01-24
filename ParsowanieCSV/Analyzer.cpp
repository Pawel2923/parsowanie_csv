#include "Analyzer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

DataAnalyzer::DataAnalyzer(const Tree* tree) : tree(tree) {}

double DataAnalyzer::sumAutokonsumpcja(const string& startDateTime, const string& endDateTime) const {
    // Implementacja sumy autokonsumpcji
	double suma = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.autokonsumpcja;
    }

	return suma;
}

double DataAnalyzer::sumEksport(const string& startDateTime, const string& endDateTime) const {
    // Implementacja sumy eksportu
    double suma = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.eksport;
    }

    return suma;
}

double DataAnalyzer::sumImport(const string& startDateTime, const string& endDateTime) const {
    // Implementacja sumy importu
    double suma = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.import;
    }

    return suma;
}

double DataAnalyzer::sumPobor(const string& startDateTime, const string& endDateTime) const {
    // Implementacja sumy poboru
    double suma = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.pobor;
    }

    return suma;
}

double DataAnalyzer::sumProdukcja(const string& startDateTime, const string& endDateTime) const {
    // Implementacja sumy produkcji
    double suma = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.produkcja;
    }

    return suma;
}

double DataAnalyzer::averageAutokonsumpcja(const string& startDateTime, const string& endDateTime) const {
    // Implementacja œredniej autokonsumpcji
    double suma = 0;
    int counter = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.autokonsumpcja;
        counter++;
    }

    return suma / counter;
}

double DataAnalyzer::averageEksport(const string& startDateTime, const string& endDateTime) const {
    // Implementacja œredniej eksportu
    double suma = 0;
    int counter = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.eksport;
        counter++;
    }

    return suma / counter;
}

double DataAnalyzer::averageImport(const std::string& startDateTime, const std::string& endDateTime) const {
    double suma = 0;
    int counter = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.import;
        counter++;
    }

    return suma / counter;
}

double DataAnalyzer::averagePobor(const string& startDateTime, const string& endDateTime) const {
    // Implementacja œredniej poboru
    double suma = 0;
    int counter = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.pobor;
        counter++;
    }

    return suma / counter;
}

double DataAnalyzer::averageProdukcja(const string& startDateTime, const string& endDateTime) const {
    // Implementacja œredniej produkcji
    double suma = 0;
    int counter = 0;

    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);

    for (auto& point : dataPoints) {
        suma += point.produkcja;
        counter++;
    }

    return suma / counter;
}

void DataAnalyzer::compareAutokonsumpcja(const string& startDateTime1, const string& endDateTime1,
    const string& startDateTime2, const string& endDateTime2) const {
    // Implementacja porównania autokonsumpcji
    double suma1 = 0, suma2 = 0;
    vector<Point> dataPoints1 = tree->getDataPoint(startDateTime1, endDateTime1);
    vector<Point> dataPoints2 = tree->getDataPoint(startDateTime2, endDateTime2);
    for (auto& point : dataPoints1) {
        suma1 += point.autokonsumpcja;
    }
    for (auto& point : dataPoints2) {
        suma2 += point.autokonsumpcja;
    }
    cout << "Suma autokonsumpcji w pierwszym przedziale: " << suma1 << endl;
    cout << "Suma autokonsumpcji w drugim przedziale: " << suma2 << endl;
    cout << "Ró¿nica: " << suma1 - suma2 << endl;
    cout << "Stosunek: " << suma1 / suma2 << endl;
}

void DataAnalyzer::compareEksport(const string& startDateTime1, const string& endDateTime1,
    const string& startDateTime2, const string& endDateTime2) const {
    // Implementacja porównania eksportu
    double suma1 = 0, suma2 = 0;
    vector<Point> dataPoints1 = tree->getDataPoint(startDateTime1, endDateTime1);
    vector<Point> dataPoints2 = tree->getDataPoint(startDateTime2, endDateTime2);
    for (auto& point : dataPoints1) {
        suma1 += point.eksport;
    }
    for (auto& point : dataPoints2) {
        suma2 += point.eksport;
    }
    cout << "Suma eksportu w pierwszym przedziale: " << suma1 << endl;
    cout << "Suma eksportu w drugim przedziale: " << suma2 << endl;
    cout << "Ró¿nica: " << suma1 - suma2 << endl;
    cout << "Stosunek: " << suma1 / suma2 << endl;
}

void DataAnalyzer::compareImport(const string& startDateTime1, const string& endDateTime1,
    const string& startDateTime2, const string& endDateTime2) const {
    // Implementacja porównania importu
    double suma1 = 0, suma2 = 0;
    vector<Point> dataPoints1 = tree->getDataPoint(startDateTime1, endDateTime1);
    vector<Point> dataPoints2 = tree->getDataPoint(startDateTime2, endDateTime2);
    for (auto& point : dataPoints1) {
        suma1 += point.import;
    }
    for (auto& point : dataPoints2) {
        suma2 += point.import;
    }
    cout << "Suma importu w pierwszym przedziale: " << suma1 << endl;
    cout << "Suma importu w drugim przedziale: " << suma2 << endl;
    cout << "Ró¿nica: " << suma1 - suma2 << endl;
    cout << "Stosunek: " << suma1 / suma2 << endl;

}

void DataAnalyzer::comparePobor(const string& startDateTime1, const string& endDateTime1,
    const string& startDateTime2, const string& endDateTime2) const {
    // Implementacja porównania poboru
    double suma1 = 0, suma2 = 0;
    vector<Point> dataPoints1 = tree->getDataPoint(startDateTime1, endDateTime1);
    vector<Point> dataPoints2 = tree->getDataPoint(startDateTime2, endDateTime2);
    for (auto& point : dataPoints1) {
        suma1 += point.pobor;
    }
    for (auto& point : dataPoints2) {
        suma2 += point.pobor;
    }
    cout << "Suma poboru w pierwszym przedziale: " << suma1 << endl;
    cout << "Suma poboru w drugim przedziale: " << suma2 << endl;
    cout << "Ró¿nica: " << suma1 - suma2 << endl;
    cout << "Stosunek: " << suma1 / suma2 << endl;

}

void DataAnalyzer::compareProdukcja(const string& startDateTime1, const string& endDateTime1,
    const string& startDateTime2, const string& endDateTime2) const {
    // Implementacja porównania produkcji
    double suma1 = 0, suma2 = 0;
    vector<Point> dataPoints1 = tree->getDataPoint(startDateTime1, endDateTime1);
    vector<Point> dataPoints2 = tree->getDataPoint(startDateTime2, endDateTime2);
    for (auto& point : dataPoints1) {
        suma1 += point.produkcja;
    }
    for (auto& point : dataPoints2) {
        suma2 += point.produkcja;
    }
    cout << "Suma produkcji w pierwszym przedziale: " << suma1 << endl;
    cout << "Suma produkcji w drugim przedziale: " << suma2 << endl;
    cout << "Ró¿nica: " << suma1 - suma2 << endl;
    cout << "Stosunek: " << suma1 / suma2 << endl;
}

void DataAnalyzer::searchAndPrintRecords(double searchedValue, double tolerance,
    const string& startDateTime, const string& endDateTime) const {
    // Implementacja wyszukiwania i wypisywania rekordów
    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);
    for (auto& point : dataPoints) {
        if (point.autokonsumpcja >= searchedValue - tolerance && point.autokonsumpcja <= searchedValue + tolerance) {
            cout << "Data: " << point.date << endl;
            cout << "Autokonsumpcja: " << point.autokonsumpcja << endl;
            cout << "Eksport: " << point.eksport << endl;
            cout << "Import: " << point.import << endl;
            cout << "Pobor: " << point.pobor << endl;
            cout << "Produkcja: " << point.produkcja << endl;
        }
        else if (point.eksport >= searchedValue - tolerance && point.eksport <= searchedValue + tolerance) {
            cout << "Data: " << point.date << endl;
            cout << "Autokonsumpcja: " << point.autokonsumpcja << endl;
            cout << "Eksport: " << point.eksport << endl;
            cout << "Import: " << point.import << endl;
            cout << "Pobor: " << point.pobor << endl;
            cout << "Produkcja: " << point.produkcja << endl;
        }
        else if (point.import >= searchedValue - tolerance && point.import <= searchedValue + tolerance) {
            cout << "Data: " << point.date << endl;
            cout << "Autokonsumpcja: " << point.autokonsumpcja << endl;
            cout << "Eksport: " << point.eksport << endl;
            cout << "Import: " << point.import << endl;
            cout << "Pobor: " << point.pobor << endl;
            cout << "Produkcja: " << point.produkcja << endl;
        }
        else if (point.pobor >= searchedValue - tolerance && point.pobor <= searchedValue + tolerance) {
            cout << "Data: " << point.date << endl;
            cout << "Autokonsumpcja: " << point.autokonsumpcja << endl;
            cout << "Eksport: " << point.eksport << endl;
            cout << "Import: " << point.import << endl;
            cout << "Pobor: " << point.pobor << endl;
            cout << "Produkcja: " << point.produkcja << endl;
        }
        else if (point.produkcja >= searchedValue - tolerance && point.produkcja <= searchedValue + tolerance) {
            cout << "Data: " << point.date << endl;
            cout << "Autokonsumpcja: " << point.autokonsumpcja << endl;
            cout << "Eksport: " << point.eksport << endl;
            cout << "Import: " << point.import << endl;
            cout << "Pobor: " << point.pobor << endl;
            cout << "Produkcja: " << point.produkcja << endl;
        }
    }
}

void DataAnalyzer::printDataInRange(const string& startDateTime, const string& endDateTime) const {
    // Implementacja wypisywania danych w przedziale
    vector<Point> dataPoints = tree->getDataPoint(startDateTime, endDateTime);
    for (auto& point : dataPoints) {
        cout << "Data: " << point.date << endl;
        cout << "Autokonsumpcja: " << point.autokonsumpcja << endl;
        cout << "Eksport: " << point.eksport << endl;
        cout << "Import: " << point.import << endl;
        cout << "Pobor: " << point.pobor << endl;
        cout << "Produkcja: " << point.produkcja << endl;
    }
}