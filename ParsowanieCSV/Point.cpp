#include "Point.h"

Point::Point(const std::string & dateTime, double autokonsumpcja, double eksport, double import, double pobor, double produkcja)
    : dateTime(dateTime), autokonsumpcja(autokonsumpcja), eksport(eksport), import(import), pobor(pobor), produkcja(produkcja) {}