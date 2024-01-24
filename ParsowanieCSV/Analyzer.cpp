#include "Analyzer.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DataAnalyzer::DataAnalyzer(const Tree& tree) : tree(tree) {}

double DataAnalyzer::sumAutokonsumpcja(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja sumy autokonsumpcji
    double suma = 0;

    return suma;
}

double DataAnalyzer::sumEksport(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja sumy eksportu

    return 0;
}

double DataAnalyzer::sumImport(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja sumy importu
    return 0;
}

double DataAnalyzer::sumPobor(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja sumy poboru
    return 0;
}

double DataAnalyzer::sumProdukcja(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja sumy produkcji
    return 0;
}

double DataAnalyzer::averageAutokonsumpcja(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja œredniej autokonsumpcji
    return 0;
}

double DataAnalyzer::averageEksport(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja œredniej eksportu
    return 0;
}

double DataAnalyzer::averageImport(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja œredniej importu
    return 0;
}

double DataAnalyzer::averagePobor(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja œredniej poboru
    return 0;
}

double DataAnalyzer::averageProdukcja(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja œredniej produkcji
    return 0;
}

void DataAnalyzer::compareAutokonsumpcja(const std::string& startDateTime1, const std::string& endDateTime1,
    const std::string& startDateTime2, const std::string& endDateTime2) const {
    // Implementacja porównania autokonsumpcji
}

void DataAnalyzer::compareEksport(const std::string& startDateTime1, const std::string& endDateTime1,
    const std::string& startDateTime2, const std::string& endDateTime2) const {
    // Implementacja porównania eksportu
}

void DataAnalyzer::compareImport(const std::string& startDateTime1, const std::string& endDateTime1,
    const std::string& startDateTime2, const std::string& endDateTime2) const {
    // Implementacja porównania importu
}

void DataAnalyzer::comparePobor(const std::string& startDateTime1, const std::string& endDateTime1,
    const std::string& startDateTime2, const std::string& endDateTime2) const {
    // Implementacja porównania poboru
}

void DataAnalyzer::compareProdukcja(const std::string& startDateTime1, const std::string& endDateTime1,
    const std::string& startDateTime2, const std::string& endDateTime2) const {
    // Implementacja porównania produkcji
}

void DataAnalyzer::searchAndPrintRecords(double searchedValue, double tolerance,
    const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja wyszukiwania i wypisywania rekordów
}

void DataAnalyzer::printDataInRange(const std::string& startDateTime, const std::string& endDateTime) const {
    // Implementacja wypisywania danych w przedziale
}