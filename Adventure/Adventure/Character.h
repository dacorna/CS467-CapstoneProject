#pragma once

#include "Room.h"
#include <string>
using std::string;

class Character
{
protected:
	string name;
	string description;
	Room* currentRoom;
	Room* previousRoom;
	// more to come
public:
	Character();
	~Character();
	virtual void enterRoom(Room*) {}
	Room* getRoom() { return currentRoom; }
	Room* getPreviousRoom() { return previousRoom; }
	string getName() { return name; }
	string getDescription() { return description; }
};
