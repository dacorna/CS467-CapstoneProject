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
	postMaze = new PostMaze;
	bridge = new Bridge;
	dragonLair = new DragonLair;
	guardianPost = new GuardianPost;
	library = new Library;
	mine = new Mine;
	treasure = new Treasure;
	outsideEnd = new OutsideEnd;
	outside->setExits(entrance, NULL, NULL, NULL);
	entrance->setExits(greatCavern, outside, NULL, NULL);
	exit->setExits(outsideEnd, dragonLair, outsideEnd, outsideEnd);
	greatCavern->setExits(bridge, entrance, fire, water);
	fire->setExits(NULL, NULL, NULL, greatCavern);
	water->setExits(NULL, NULL, greatCavern, NULL);
	bridge->setExits(mine, greatCavern, NULL, NULL);
	mine->setExits(mazeRoom, bridge, earth, library);
	earth->setExits(air, NULL, NULL, mine);
	air->setExits(NULL, earth, NULL, NULL);
	library->setExits(NULL, NULL, mine, NULL);
	mazeRoom->setExits(postMaze, mine, NULL, NULL);
	postMaze->setExits(trollBridge, mazeRoom, NULL, NULL);
	trollBridge->setExits(guardianPost, postMaze, NULL, NULL);
	guardianPost->setExits(dragonLair, trollBridge, dragonLair, dragonLair);
	dragonLair->setExits(exit, guardianPost, NULL, treasure);
	treasure->setExits(exit, NULL, dragonLair, NULL);
	map = new Item;
	torch = new Item;
	waterskin = new Item;
	pickaxe = new Item;
	treasureChest = new Item;
	goldPiece = new Item;
	sword = new Item;
	feather = new Item;
	inkPot = new Item;
	ore = new Item;
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
	delete postMaze;
	delete bridge;
	delete dragonLair;
	delete guardianPost;
	delete library;
	delete mine;
	delete outsideEnd;
	delete treasure;
	delete map;
	delete torch;
	delete waterskin;
	delete pickaxe;
	delete treasureChest;
	delete goldPiece;
	delete sword;
	delete feather;
	delete inkPot;
	delete ore;
}

void Cave::setItems()
{
	map->setName("MAP");
	torch->setName("TORCH");
	waterskin->setName("WATERSKIN");
	pickaxe->setName("PICKAXE");
	ore->setName("ORE");
	inkPot->setName("INKPOT");
	feather->setName("FEATHER");
	sword->setName("SWORD");
	goldPiece->setName("GOLDPIECE");
	treasureChest->setName("TREASURECHEST");
	map->setCanPickUp(true);
	torch->setCanPickUp(true);
	waterskin->setCanPickUp(true);
	pickaxe->setCanPickUp(true);
	ore->setCanPickUp(true);
	inkPot->setCanPickUp(true);
	feather->setCanPickUp(true);
	sword->setCanPickUp(true);	
	goldPiece->setCanPickUp(true);
	treasureChest->setCanPickUp(true);
	//JP - moving the intial item location assignment to the setUpNewGame function
	//	because these items will be saved/loaded into different files when the game 
	//	progresses.
	//entrance->addItem(map);
	//greatCavern->addItem(torch);
	//water->addItem(waterskin);
	//bridge->addItem(pickaxe);
	//mine->addItem(ore);
	//library->addItem(inkPot);
	//air->addItem(feather);
	//postMaze->addItem(sword);
	//guardianPost->addItem(goldPiece);
	//treasure->addItem(treasureChest);
}

void Cave::setLocks()
{
	greatCavern->setLock(1, true);
	mine->setLock(1, true);
	earth->setLock(1, true);
	trollBridge->setLock(1, true);
	guardianPost->setLock(1, true);
	guardianPost->setLock(3, true);
	guardianPost->setLock(4, true);
	dragonLair->setLock(4, true);
	dragonLair->setLock(1, true);	
}

void Cave::unlockAllDoors()
{
	greatCavern->setLock(1, false);
	mine->setLock(1, false);
	earth->setLock(1, false);
	trollBridge->setLock(1, false);
	guardianPost->setLock(1, false);
	guardianPost->setLock(3, false);
	guardianPost->setLock(4, false);
	dragonLair->setLock(4, false);
	dragonLair->setLock(1, false);
}

Item* Cave::returnItem(string nameIn)
{
	if(nameIn == "MAP")
	{
		return map;
	}
	else if(nameIn == "TORCH")
	{
		return torch;
	}
	else if(nameIn == "WATERSKIN")
	{
		return waterskin;
	}
	else if(nameIn == "PICKAXE")
	{
		return pickaxe;
	}
	else if(nameIn == "ORE")
	{
		return ore;
	}
	else if(nameIn == "INKPOT")
	{
		return inkPot;
	}
	else if(nameIn == "FEATHER")
	{
		return feather;
	}
	else if(nameIn == "SWORD")
	{
		return sword;
	}
	else if(nameIn == "GOLDPIECE")
	{
		return goldPiece;
	}
	else if(nameIn == "TREASURECHEST")
	{
		return treasureChest;
	}
	else
	{
		return NULL;
	}
}
