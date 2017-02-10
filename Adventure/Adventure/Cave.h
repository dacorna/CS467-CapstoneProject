#pragma once

#include "Room.h"
#include "Entrance.h"
#include "Exit.h"
#include "GreatCavern.h"
#include "Outside.h"
#include "Fire.h"
#include "Earth.h"
#include "Air.h"
#include "Water.h"
#include "TrollBridge.h"
#include "MazeRoom.h"
#include "Bridge.h"
#include "DragonLair.h"
#include "GuardianPost.h"
#include "Library.h"
#include "Mine.h"
#include "Treasure.h"

class Cave
{
private:
	/*
		Pointers to Rooms go here
	*/
	Room* outside;
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
	Room* bridge;
	Room* dragonLair;
	Room* guardianPost;
	Room* library;
	Room* mine;
	Room* treasure;
	// more rooms to come!
	friend class Game;
	//JP - should all of the items be contained in here, too?

public:
	Cave();
	~Cave();
	//setupRooms(); //This function will set the exits for each of the rooms, and then call the function (room method?) to load gamestate variables from the files
	
};
