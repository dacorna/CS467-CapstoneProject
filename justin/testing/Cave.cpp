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
	outside->setExits(entrance, NULL, NULL, NULL);
	entrance->setExits(NULL, NULL, greatCavern, NULL);
	exit->setExits(NULL, NULL, outside, NULL);
	greatCavern->setExits(mazeRoom, NULL, NULL, entrance);
	fire->setExits(trollBridge, NULL, mazeRoom, NULL);
	water->setExits(NULL, NULL, NULL, NULL);
	earth->setExits(NULL, NULL, trollBridge, NULL);
	air->setExits(NULL, NULL, NULL, NULL);
	trollBridge->setExits(NULL, fire, NULL, earth);
	mazeRoom->setExits(NULL, greatCavern, NULL, fire);
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
