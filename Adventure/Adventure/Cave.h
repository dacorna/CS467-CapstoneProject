#pragma once

#include "Item.h"
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
#include "PostMaze.h"
#include "Bridge.h"
#include "DragonLair.h"
#include "GuardianPost.h"
#include "Library.h"
#include "Mine.h"
#include "Treasure.h"
#include "OutsideEnd.h"

class Cave
{
private:
	
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
	Room* postMaze;
	Room* bridge;
	Room* dragonLair;
	Room* guardianPost;
	Room* library;
	Room* mine;
	Room* treasure;
	Room* outsideEnd;

	Item* torch;
	Item* waterskin;
	Item* pickaxe;
	Item* ore;
	Item* feather;
	Item* inkPot;
	Item* sword;
	Item* goldPiece;
	Item* treasureChest;
	Item* map;
	Item* oar;
	Item* ale;
	Item* flagon;

	friend class Game;

public:
	Cave();
	~Cave();
	void setItems();
	void setLocks();
	void unlockAllDoors();
	//setupRooms(); //This function will set the exits for each of the rooms, and then call the function (room method?) to load gamestate variables from the files
	Item* returnItem(string); //provide name of an item to get it
};
