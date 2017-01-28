#pragma once

#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Room
{
protected:
	string name;
	// tentative - each room contains a max of four exits into other rooms
	// currently named directionally 
	Room *north, *east, *south, *west;
	vector<Item> items;
	// more to come
public:
	Room();
	~Room();
	virtual string getName() { return name; }
	// also tentative - unsure if I want to do it this way 
	// setExits for a givenRoom can be implemented with anywhere from 1 to 4 exit rooms
	virtual void setExits(Room*) {}
	virtual void setExits(Room*, Room*) {}
	virtual void setExits(Room*, Room*, Room*) {}
	virtual void setExits(Room*, Room*, Room*, Room*) {}
	void addItem(Item);
	void showItems();
};