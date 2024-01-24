// Analyzer.h
#ifndef ANALYZER_H
#define ANALYZER_H

#include "Tree.h"

class DataAnalyzer {
private:
    const Tree* tree;

public:
    DataAnalyzer(const Tree* tree);

    double sumAutokonsumpcja(const std::string& startDateTime, const std::string& endDateTime) const;
    double sumEksport(const std::string& startDateTime, const std::string& endDateTime) const;
    double sumImport(const std::string& startDateTime, const std::string& endDateTime) const;
    double sumPobor(const std::string& startDateTime, const std::string& endDateTime) const;
    double sumProdukcja(const std::string& startDateTime, const std::string& endDateTime) const;

    double averageAutokonsumpcja(const std::string& startDateTime, const std::string& endDateTime) const;
    double averageEksport(const std::string& startDateTime, const std::string& endDateTime) const;
    double averageImport(const std::string& startDateTime, const std::string& endDateTime) const;
    double averagePobor(const std::string& startDateTime, const std::string& endDateTime) const;
    double averageProdukcja(const std::string& startDateTime, const std::string& endDateTime) const;

    void compareAutokonsumpcja(const std::string& startDateTime1, const std::string& endDateTime1,
        const std::string& startDateTime2, const std::string& endDateTime2) const;

    void compareEksport(const std::string& startDateTime1, const std::string& endDateTime1,
        const std::string& startDateTime2, const std::string& endDateTime2) const;

    void compareImport(const std::string& startDateTime1, const std::string& endDateTime1,
        const std::string& startDateTime2, const std::string& endDateTime2) const;

    void comparePobor(const std::string& startDateTime1, const std::string& endDateTime1,
        const std::string& startDateTime2, const std::string& endDateTime2) const;

    void compareProdukcja(const std::string& startDateTime1, const std::string& endDateTime1,
        const std::string& startDateTime2, const std::string& endDateTime2) const;

    void searchAndPrintRecords(double searchedValue, double tolerance, const std::string& startDateTime, const std::string& endDateTime) const;

    void printDataInRange(const std::string& startDateTime, const std::string& endDateTime) const;
};

#endif // ANALYZER_H