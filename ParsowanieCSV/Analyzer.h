#pragma once

#include "tree.h"

class DataAnalyzer {
private:
	Drzewo& dataTree;

public:
    DataAnalyzer(Drzewo& dataTree);
    void readDataFromFile(const string& fileName);
    void printSelfConsumptionSum(const Drzewo& startDate, const Drzewo& endDate);
    void printExportSum(const Drzewo& startDate, const Drzewo& endDate);
    void printImportSum(const Drzewo& startDate, const Drzewo& endDate);
    void printConsumptionSum(const Drzewo& startDate, const Drzewo& endDate);
    void printProductionSum(const Drzewo& startDate, const Drzewo& endDate);
    void printAverageSelfConsumption(const Drzewo& startDate, const Drzewo& endDate);
    void printAverageExport(const Drzewo& startDate, const Drzewo& endDate);
    void printAverageImport(const Drzewo& startDate, const Drzewo& endDate);
    void printAverageConsumption(const Drzewo& startDate, const Drzewo& endDate);
    void printAverageProduction(const Drzewo& startDate, const Drzewo& endDate);
    void compareSelfConsumption(const Drzewo& startDate1, const Drzewo& endDate1, const Drzewo& startDate2, const Drzewo& endDate2);
    void compareExports(const Drzewo& startDate1, const Drzewo& endDate1, const Drzewo& startDate2, const Drzewo& endDate2);
    void compareImports(const Drzewo& startDate1, const Drzewo& endDate1, const Drzewo& startDate2, const Drzewo& endDate2);
    void compareConsumption(const Drzewo& startDate1, const Drzewo& endDate1, const Drzewo& startDate2, const Drzewo& endDate2);
    void compareProduction(const Drzewo& startDate1, const Drzewo& endDate1, const Drzewo& startDate2, const Drzewo& endDate2);
    void searchAndPrintRecords(const double searchedNumber, const double tolerance, const Drzewo& startDate, const Drzewo& endDate);
    void printDataInRange(const Drzewo& startDate, const Drzewo& endDate);
};