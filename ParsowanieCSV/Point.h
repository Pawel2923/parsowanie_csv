#ifndef POINT_H
#define POINT_H

#include<iostream>
#include<string>

class Point {
public:
    Point(const std::string & dateTime, double autokonsumpcja, double eksport, double import, double pobor, double produkcja);

    std::string dateTime;
    double autokonsumpcja;
    double eksport;
    double import;
    double pobor;
    double produkcja;
};

#endif // POINT_Hv