#pragma once

#include "Room.h"

class Cave
{
private:
	/*
		Pointers to Rooms go here
	*/
	Room* entrance;
	Room* exit;
	Room* fire;
	Room* water;
	Room* earth;
	Room* air;
	Room* trollBridge;
	Room* waterfall;
	Room* dragonDen;
	Room* greatCavern;
	Room* mazeRoom;
	// more rooms to come!
	friend class Game;

public:
	Cave();
	~Cave();
};
