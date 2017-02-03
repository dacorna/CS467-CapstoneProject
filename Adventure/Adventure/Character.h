#pragma once

#include "Room.h"
#include <string>
using std::string;

class Character
{
protected:
	string name;
	string description;
	bool isAlive;
	Room* currentRoom;
	Room* previousRoom;
	// more to come
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
};
