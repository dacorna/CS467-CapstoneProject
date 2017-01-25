#pragma once

#include "Item.h"
#include <vector>	
#include <string>
using std::vector;
using std::string;

class Bag
{
private:
	int maxSize;
	vector<Item> items;
public:
	Bag();
	~Bag();
	bool add(Item*);
	bool hasItem(string);	// enter item.name
	void displayBag();
};
