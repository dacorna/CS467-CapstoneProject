#pragma once

#include "Room.h"
#include "Maze.h"
#include "Bag.h"
#include "Troll.h"
#include "Guardian.h"
#include "Dragon.h"
#include <boost/algorithm/string.hpp>
#include <string>
using std::string;
using namespace boost;

class Character
{
protected:
	string name;
	string description;
	bool isAlive;
	bool completedMaze;
	bool completedTroll;
	bool completedGuardian;
	bool completedDragon;
	Room* currentRoom;
	Room* previousRoom;
	Bag bag;
	
	friend class Game;
public:
	Character();
	~Character();
	void enterRoom(Room*);
	void setCurrentRoom(Room* r) { currentRoom = r; }
	Room* getRoom() { return currentRoom; }
	Room* getPreviousRoom() { return previousRoom; }
	string getName() { return name; }
	string getDescription() { return description; }
	void setName(string);
	Bag getBag() {return bag;}
	void setBag(Bag bagIn) { bag = bagIn; }
	void CompletedMaze() { completedMaze = true; }
	void CompletedTroll() { completedTroll = true; }
	void CompletedGuardian() { completedGuardian = true; }
	void CompletedDragon() { completedDragon = true; }
	int fightDragon(Bag);
	int speakToDragon(Bag);
	int exploreDragon(Bag,string);
};
