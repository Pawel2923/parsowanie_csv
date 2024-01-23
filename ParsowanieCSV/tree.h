// Tree.h
#ifndef TREE_H
#define TREE_H

#include <map>
#include <vector>
#include "Point.h"

class Tree {
private:
    
        std::map<int, std::map<int, std::map<int, std::map<int, std::vector<Point>>>>> tree;

public:
    int getCwiartka(int hour, int minute) const;
    void dodanieDanych(const Point& dataPoint);
    void pokazDrzewo() const;
};

#endif // !TREE_H