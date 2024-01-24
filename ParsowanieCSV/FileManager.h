#pragma once
#include <vector>
#include "Point.h"
#include "tree.h"

class FileManager {
private:
    std::vector<std::string> split(const std::string& str, char delimiter);
    std::string removeQuotes(const std::string& str);

public:
    std::vector<Point> loadDataFromCsv(const std::string& filePath);
    void saveDataToBinary(const Tree& dataTree, const std::string& filePath);
    Tree loadDataFromBinary(const std::string& filePath);
};