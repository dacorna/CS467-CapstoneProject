#pragma once

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
	//vector<Item> items;
	// more to come
	string longDescription;
	string shortDescription;
	bool isVisited = false;
		//JP - 	In the specific room subclasses, would we want to put room specific booleans? Like switchPulled, or would be want something like northLocked, southLocked, etc? Just my ideas. I think something standard, like northLocked, etc would
		//		make for easier loading and saving. Maybe set item states within the items?
public:
	Room();
	~Room();
	virtual string getName() {return name;}
	// also tentative - unsure if I want to do it this way 
	// setExits for a givenRoom can be implemented with anywhere from 1 to 4 exit rooms
	virtual void setExits(Room*, Room*, Room*, Room*);
	Room* getNorth(){ return north;}
	Room* getSouth(){ return south;}
	Room* getEast(){ return east;}
	Room* getWest(){ return west;}
	//void addItem(Item);
	//void showItems();
	void setIsVisited();
	bool getIsVisited() { return isVisited; } //needed for testing, might not actually need?
	string getLongDescription() { return longDescription; }
	string getShortDescription() { return shortDescription; }
	
};
