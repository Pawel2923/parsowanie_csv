#pragma once
#include "tree.h"
#include "FileManager.h"
#include "Analyzer.h"

class Menu {
private:
	Tree* tree;
	DataAnalyzer* analyzer;
	FileManager fileManager;
	int choice;

public:
	Menu();
	~Menu();

	void printMenu();
	void start();
	void loadDataFromCsv();
	void saveDataToBinary();
	void loadDataFromBinary();
	void printAllData();
	void printDataInRange();
	void sumAutoconsumption();
	void sumExport();
	void sumImport();
	void sumDemand();
	void sumProduction();
	void avarageAutoconsumption();
	void avarageExport();
	void avarageImport();
	void avarageDemand();
	void avarageProduction();
	void compareAutoconsumption();
	void compareExport();
	void compareImport();
	void compareDemand();
	void compareProduction();
	void searchAndPrintRecords();
};