#include "Analyzer.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DataAnalyzer::DataAnalyzer(Drzewo& data) : dataTree(data) {}

void DataAnalyzer::readDataFromFile(const string& fileName) {
	ifstream file(fileName);
	string line;
	getline(file, line);
	while (getline(file, line)) {
		int year = stoi(line.substr(0, 4));
		int month = stoi(line.substr(5, 2));
		int day = stoi(line.substr(8, 2));
		int quarter = stoi(line.substr(11, 1));
		double selfConsumption = stod(line.substr(13, 6));
		double exportValue = stod(line.substr(20, 6));
		double importValue = stod(line.substr(27, 6));
		double consumption = stod(line.substr(34, 6));
		double production = stod(line.substr(41, 6));
		dataTree.addDataPoint(Dane(year, month, day, quarter, selfConsumption, exportValue, importValue, consumption, production));
	}
}