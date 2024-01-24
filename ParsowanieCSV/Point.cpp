#include "Point.h"

Point::Point(const std::string & date, double autokonsumpcja, double eksport, double import, double pobor, double produkcja)
    : date(date), autokonsumpcja(autokonsumpcja), eksport(eksport), import(import), pobor(pobor), produkcja(produkcja) {}