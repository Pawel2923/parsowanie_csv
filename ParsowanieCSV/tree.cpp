#include "Tree.h"
#include <iostream>
#include <locale>
#include <iomanip>
#include <sstream>

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
        std::cout << "Rok " << yearNode.first << std::endl;
        for (const auto& monthNode : yearNode.second) {
            std::cout << "  Miesi¹c " << monthNode.first << std::endl;
            for (const auto& dayNode : monthNode.second) {
                std::cout << "    Dzieñ " << dayNode.first << std::endl;
                for (const auto& quarterNode : dayNode.second) {
                    std::cout << "      Æwiartka " << quarterNode.first << std::endl;
                    for (const auto& dataPoint : quarterNode.second) {
                        // Wypisz dane punktu (dataPoint)
                        std::cout << "Data"<<dataPoint.date
                            << ",Autokonsumpcja: " << dataPoint.autokonsumpcja 
                            << " Eksport : " << dataPoint.eksport
                            << " Import: " << dataPoint.import 
                            << " Pobór: " << dataPoint.pobor 
                            << " Produkcja: " << dataPoint.produkcja << std::endl;
                    }
                }
            }
        }
    }
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
