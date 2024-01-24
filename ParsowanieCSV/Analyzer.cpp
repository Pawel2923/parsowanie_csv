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
    // Implementacja �redniej autokonsumpcji
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
    // Implementacja �redniej eksportu
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
    // Implementacja �redniej poboru
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
    // Implementacja �redniej produkcji
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
    // Implementacja por�wnania autokonsumpcji
}

void DataAnalyzer::compareEksport(const string& startDateTime1, const string& endDateTime1,
    const string& startDateTime2, const string& endDateTime2) const {
    // Implementacja por�wnania eksportu
}

void DataAnalyzer::compareImport(const string& startDateTime1, const string& endDateTime1,
    const string& startDateTime2, const string& endDateTime2) const {
    // Implementacja por�wnania importu
}

void DataAnalyzer::comparePobor(const string& startDateTime1, const string& endDateTime1,
    const string& startDateTime2, const string& endDateTime2) const {
    // Implementacja por�wnania poboru
}

void DataAnalyzer::compareProdukcja(const string& startDateTime1, const string& endDateTime1,
    const string& startDateTime2, const string& endDateTime2) const {
    // Implementacja por�wnania produkcji
}

void DataAnalyzer::searchAndPrintRecords(double searchedValue, double tolerance,
    const string& startDateTime, const string& endDateTime) const {
    // Implementacja wyszukiwania i wypisywania rekord�w
}

void DataAnalyzer::printDataInRange(const string& startDateTime, const string& endDateTime) const {
    // Implementacja wypisywania danych w przedziale
}