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
	Room *north, *east, *south, *west;
	vector<Item> items;
	string longDescription;
	string shortDescription;
	string exploreStory;
	bool isVisited = false;
		//JP - 	In the specific room subclasses, would we want to put room specific booleans? Like switchPulled, or would be want something like northLocked, southLocked, etc? Just my ideas. I think something standard, like northLocked, etc would
		//		make for easier loading and saving. Maybe set item states within the items?
		// DC - I agree with a standard like northLocked, southLocked
public:
	Room();
	~Room();
	virtual string getName() { return name; }
	
	//virtual void setExits(Room*) {}
	//virtual void setExits(Room*, Room*) {}
	//virtual void setExits(Room*, Room*, Room*) {}
	void setExits(Room*, Room*, Room*, Room*);
	Room* getNorth(){ return north; }
	Room* getSouth(){ return south; }
	Room* getEast(){ return east; }
	Room* getWest(){ return west; }
	void addItem(Item);
	void removeItem(string);
	void showItems();
	bool hasItem(string);
	Item getItem(string);
	void setIsVisited();
	bool getIsVisited() { return isVisited; } //needed for testing, might not actually need?
	string getLongDescription() { return longDescription; }
	string getShortDescription() { return shortDescription; }
};
