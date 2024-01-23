#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

class Tree{
	int level;
	std::vector<Tree*>children;
	Dane* data;
public: 
	Tree();
	~Tree();
	void addChild(Tree* child);
	void setData(Dane* newData);
	void display();
	int getLevel();
	const std::vector<Tree*>& getChildren();
	const Dane* getData();
};

#endif // !TREE_H

