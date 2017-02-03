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
	//JP - should all of the items be contained in here, too?

public:
	Cave();
	~Cave();
	//setupRooms(); //This function will set the exits for each of the rooms, and then call the function (room method?) to load gamestate variables from the files
	
};
