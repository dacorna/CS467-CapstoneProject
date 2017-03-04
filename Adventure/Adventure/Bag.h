#pragma once

#include "Item.h"
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Bag
{
protected:
	int maxSize;
	vector<Item*> items;

	friend class Game;
public:
	Bag();
	~Bag();
	bool add(Item*);
	bool hasItem(string);	// enter item.name
	int getItemIndex(string);
	Item* getItem(string);
	void displayBag();
	void dropItem(string);	
	int bagSize() { return items.size(); }
};
