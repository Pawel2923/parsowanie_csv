#pragma once
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <vector>
#include "Point.h"
#include "tree.h"
#include "Analyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class FileManager {
public:
    std::vector<Point> loadDataFromCsv(const std::string& filePath);
    void saveDataToBinary(const Tree& dataTree, const std::string& filePath);
    Tree loadDataFromBinary(const std::string& filePath);
};

#endif // !FILE_MANAGER_H
