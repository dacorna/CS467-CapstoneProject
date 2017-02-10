#include "Cave.h"

Cave::Cave()
{
	outside = new Outside;
	entrance = new Entrance;
	exit = new Exit;
	greatCavern = new GreatCavern;
	fire = new Fire;
	water = new Water;
	earth = new Earth;
	air = new Air;
	trollBridge = new TrollBridge;
	mazeRoom = new MazeRoom;
	bridge = new Bridge;
	dragonLair = new DragonLair;
	guardianPost = new GuardianPost;
	library = new Library;
	mine = new Mine;
	treasure = new Treasure;
	outside->setExits(entrance, NULL, NULL, NULL);
	entrance->setExits(greatCavern, NULL, NULL, NULL);
	exit->setExits(outside, treasure, NULL, NULL);
	greatCavern->setExits(bridge, NULL, fire, water);
	fire->setExits(NULL, NULL, NULL, greatCavern);
	water->setExits(NULL, NULL, greatCavern, NULL);
	bridge->setExits(mine, greatCavern, NULL, NULL);
	mine->setExits(mazeRoom, bridge, earth, library);
	earth->setExits(air, NULL, NULL, mine);
	air->setExits(NULL, earth, NULL, NULL);
	library->setExits(NULL, NULL, mine, NULL);
	trollBridge->setExits(guardianPost, mazeRoom, NULL, NULL);
	mazeRoom->setExits(trollBridge, mine, NULL, NULL);
	dragonLair->setExits(exit, guardianPost, NULL, treasure);
	treasure->setExits(exit, NULL, dragonLair, NULL);
}

Cave::~Cave()
{
	delete outside;
	delete entrance;
	delete exit;
	delete greatCavern;
	delete fire;
	delete water;
	delete earth;
	delete air;
	delete trollBridge;
	delete mazeRoom;
}
