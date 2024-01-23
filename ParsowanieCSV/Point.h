#ifndef POINT_H
#define POINT_H

#include<iostream>
#include<string>

class Point {
public:
    Point(const std::string & date, const std::string & time, double autokonsumpcja, double eksport, double import, double pobor, double produkcja);


    std::string date;
    double autokonsumpcja;
    double eksport;
    double import;
    double pobor;
    double produkcja;


};

#endif // POINT_Hv