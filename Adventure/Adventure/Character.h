#pragma once

#include "Room.h"
#include "Maze.h"
#include "Bag.h"
#include "Troll.h"
#include <string>
using std::string;

class Character
{
protected:
	string name;
	string description;
	bool isAlive;
	bool completedMaze;
	bool completedTroll;
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
	void CompletedMaze() { completedMaze = true; }
	void CompletedTroll() { completedTroll = true; }
};
