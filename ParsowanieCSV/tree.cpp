#include "tree.h"
#include <iostream>
#include <locale>
#include <iomanip>
#include <sstream>

Tree::Tree() {}

void Tree::dodanieDanych(const Point& dataPoint) {
    int year, month, day, quarter;

    std::istringstream dateStream(dataPoint.date.substr(0, 10)); // Pobranie pierwszych 10 znaków jako data
    dateStream.imbue(std::locale("pl_PL.utf8"));  // Ustawienie lokalizacji dla polskiego formatu daty

    char dot; // Odczytuj kropkê oddzielaj¹c¹ dzieñ, miesi¹c i rok
    dateStream >> day >> dot >> month >> dot >> year;

    if (dateStream.fail()) {
        std::cerr << "Error reading date: " << dataPoint.date << std::endl;
        return;
    }

    quarter = getCwiartka(std::stoi(dataPoint.date.substr(11, 2)), std::stoi(dataPoint.date.substr(14, 2)));

    tree[year][month][day][quarter].push_back(dataPoint);
}

void Tree::pokazDrzewo() const {
    for (const auto& yearNode : tree) {
        std::cout << "Rok: " << yearNode.first << std::endl;

        for (int i = 0; i < 12; i++) {
            if (yearNode.second.find(i + 1) != yearNode.second.end()) {
                std::cout << "  Miesi¹c: " << i + 1 << std::endl;

                for (int j = 0; j < 31; j++) {
                    auto& monthNode = yearNode.second.at(i + 1);
                    if (monthNode.find(j + 1) != monthNode.end()) {
                        std::cout << "    Dzieñ: " << j + 1 << std::endl;

                        for (int k = 0; k < 4; k++) {
                            auto& dayNode = monthNode.at(j + 1);
                            if (dayNode.find(k + 1) != dayNode.end()) {
                                std::cout << "      Æwiartka: " << k + 1 << std::endl;

                                for (const auto& dataPoint : dayNode.at(k + 1)) {
                                    // Wypisz dane punktu (dataPoint)
                                    std::cout << "        Data: " << dataPoint.date
                                        << ", Autokonsumpcja: " << dataPoint.autokonsumpcja
                                        << ", Eksport: " << dataPoint.eksport
                                        << ", Import: " << dataPoint.import
                                        << ", Pobór: " << dataPoint.pobor
                                        << ", Produkcja: " << dataPoint.produkcja << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

std::vector<Point> Tree::getDataPoint(const std::string& startDateTime, const std::string& endDateTime) const {
    std::vector<Point> dataPoints;

    // Convert startDateTime and endDateTime to std::tm objects
    std::tm startTm = {};
    std::istringstream startStream(startDateTime);
    startStream >> std::get_time(&startTm, "%d.%m.%Y %H:%M");

    std::tm endTm = {};
    std::istringstream endStream(endDateTime);
    endStream >> std::get_time(&endTm, "%d.%m.%Y %H:%M");

    // Iterate over the tree data structure
    for (const auto& yearNode : tree) {
        for (int i = 0; i < 12; i++) {
            if (yearNode.second.find(i + 1) != yearNode.second.end()) {
                for (int j = 0; j < 31; j++) {
                    auto& monthNode = yearNode.second.at(i + 1);
                    if (monthNode.find(j + 1) != monthNode.end()) {
                        for (int k = 0; k < 4; k++) {
                            auto& dayNode = monthNode.at(j + 1);
                            if (dayNode.find(k + 1) != dayNode.end()) {
                                for (const auto& dataPoint : dayNode.at(k + 1)) {
                                    // Convert dataPoint.date to std::tm object
                                    std::tm dataTm = {};
                                    std::istringstream dataStream(dataPoint.date);
                                    dataStream >> std::get_time(&dataTm, "%d.%m.%Y %H:%M");

                                    // Check if dataPoint.date is within the specified range
                                    if (std::mktime(&dataTm) >= std::mktime(&startTm) && std::mktime(&dataTm) <= std::mktime(&endTm)) {
                                        dataPoints.push_back(dataPoint);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return dataPoints;
}

int Tree::getCwiartka(int hour, int minute) const {
    int time = hour * 60 + minute;  // Zamieñ godziny na minuty
    if (time >= 0 && time < 345) {
        return 1;
    }
    else if (time >= 345 && time < 705) {
        return 2;
    }
    else if (time >= 705 && time < 1065) {
        return 3;
    }
    else {
        return 4;
    }
}