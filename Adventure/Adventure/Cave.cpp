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
	outside->setExits(entrance, NULL, NULL, NULL);
	entrance->setExits(NULL, NULL, greatCavern, NULL);
	exit->setExits(NULL, NULL, outside, NULL);
	greatCavern->setExits(NULL, NULL, NULL, entrance);
	fire->setExits(NULL, NULL, NULL, NULL);
	water->setExits(NULL, NULL, NULL, NULL);
	earth->setExits(NULL, NULL, NULL, NULL);
	air->setExits(NULL, NULL, NULL, NULL);
	trollBridge->setExits(NULL, NULL, NULL, NULL);
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
}
