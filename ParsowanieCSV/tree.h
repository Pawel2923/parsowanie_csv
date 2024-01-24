// Tree.h
#ifndef TREE_H
#define TREE_H

#include <map>
#include <vector>
#include "Point.h"

class Tree {
private:
    
        std::map<int, std::map<int, std::map<int, std::map<int, std::vector<Point>>>>> tree;
    int getCwiartka(int hour, int minute) const;

public:
    class Iterator {
    private:
        using YearIterator = std::map<int, std::map<int, std::map<int, std::map<int, std::vector<Point>>>>>::iterator;
        using MonthIterator = std::map<int, std::map<int, std::map<int, std::vector<Point>>>>::iterator;
        using DayIterator = std::map<int, std::map<int, std::vector<Point>>>::iterator;
        using QuarterIterator = std::map<int, std::vector<Point>>::iterator;
        using PointIterator = std::vector<Point>::iterator;

        YearIterator yearIt;
        MonthIterator monthIt;
        DayIterator dayIt;
        QuarterIterator quarterIt;
        PointIterator pointIt;

    public:
        Iterator(YearIterator y, MonthIterator m, DayIterator d, QuarterIterator q, PointIterator p);
        Point& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();

    void dodanieDanych(const Point& dataPoint);
    void pokazDrzewo() const;
};

#endif // !TREE_H