#include "Game.h"
#include <ios>
#include <limits>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;

Game::Game()
{
	playerAlive = true;
	timeLimit = 150; // whatever we decide - maybe none
	timeCount = 0;
}

Game::~Game()
{

}

void Game::displayCommands()
{
	
	for (int i = 0; i < 20; i++)
	{
		if (commandTable[i][0] == "")
			return;
		cout << commandTable[i][0] << "  ---  " << commandTable[i][1] << endl;
	}
}

void Game::startGame(string type)
{
	Room* rm;
	cave.setItems();
	cave.setLocks();
	if (type == "new") {
		// start new game
		player.setCurrentRoom(cave.outside);
		setUpNewGame();
		// load background/story files 
		// below will likely be stored in a game background/story file that will be loaded in
		// maybe the player has to read a scroll (or something) to get this information 
		cout << "Welcome to Cave!" << endl << endl;
		cout << "It's the text-based adventure game where you navigate the deep, dark " << endl;
		cout << "tunnels and secret caverns of a mysterious and ancient cave " << endl;
		// load directions file  ... something better than below will come from a file in future 
		cout << "The goal of the game is to navigate the cave all the way through to a secret " << endl;
		cout << "exit, following clues, solving puzzles, getting through mazes, and picking up items " << endl;
		cout << "along the way. Oh, and you better get there before the door closes for good!" << endl;
		cout << endl << "..." << endl;
	}
	else {
		loadGameFiles(getGameName());
	}
	cout << endl;// << player.getRoom()->getLongDescription() << endl;
	player.getRoom()->printLongDescAndItems();
	cin.get();
		do {
			if(player.getRoom()->getName() == "OutsideEnd") {
				cout << "Safe travels!" << endl;
				return; 	
			}
			timeCount++;
			if(timeCount > timeLimit) playerAlive = false;

			cout << "> ";
			cin.sync();	// discard input buffer
			getline(cin, userInput);
			std::system("clear");
			
			cout << "******************************************************" << endl;
			cout << "*		CAVE ADVENTURE			       " << endl;
			cout << "* " << player.getName() << endl;
			cout << "* Time Left: " << timeLimit - timeCount << endl;
			cout << "******************************************************" << endl;
			cout << endl << endl;	
			
			p = parse(userInput);
			// trim any leading or trailing white spaces
			trim(p.command);
			trim(p.firstObject);
			trim(p.secondObject);
			
			/*  -- test return of parser
			cout << "p.command = " << p.command << endl;
			cout << "command length = " << p.command.length() << endl;
			cout << "p.firstObject = " << p.firstObject << endl;
			cout << "p.firstObject length = " << p.firstObject.length() << endl;  		
			*/

			// this is for testing until certain commands are added to the parser 
			// ********************************************************************
			trim(userInput);
			if (userInput == "cheat")
				p.command = "CHEAT";
			//else if (userInput == "explore")
			//	p.command = "EXPLORE";
			else if (userInput == "uncheat")
				p.command = "UNCHEAT";
			else if (userInput == "use")
				p.command = "USE";
			// ********************************************************************

			rm = player.getRoom();
			
			// considering using a table-driven method with function pointers 
			//  but for now we go with the big huge if-else block
			  
			if(p.command == "GO") {
				if(p.firstObject == "NORTH") {
					if(!(rm->isLocked("NORTH")))
						player.enterRoom(rm->getNorth());
					else
						cout << "The door is locked" << endl; 
				}	
				else if(p.firstObject == "SOUTH")
					player.enterRoom(rm->getSouth());
				else if(p.firstObject == "EAST") {
					if(!(rm->isLocked("EAST")))
						player.enterRoom(rm->getEast());
					else
						cout << "The door is locked" << endl;
				}
				else if(p.firstObject == "WEST") {
					if(!(rm->isLocked("WEST")))
						player.enterRoom(rm->getWest());
					else
						cout << "The door is locked" << endl;
				}
				else if (p.firstObject == "BACK") {
					player.enterRoom(player.getPreviousRoom());
				}
				else
					cout << "I don't know where that is" << endl; 
			}
			else if(p.command == "LOOK") {
				
				if(p.firstObject == "ROOM") {
					
					//cout << player.getRoom()->getLongDescription() << endl;
					player.getRoom()->printLongDescAndItems();
				}
				else if(p.firstObject == "MAP") {
					
					if(bag.hasItem("MAP"))
				 	   displayMap(); 	   
					else
					   cout << "You don't have a map!" << endl;	
				}
				else if(p.firstObject == "BAG") {
					bag.displayBag();
				}
				else {
					//cout << player.getRoom()->getLongDescription() << endl;
					player.getRoom()->printLongDescAndItems();
				}
				
			}
			else if(p.command == "DROP") {
				
				if(p.firstObject == "")
					cout << "Drop what? " << endl;
				else {
					// first add item to current room, then drop it from bag
					Item* itm = bag.getItem(p.firstObject);
					if(itm != NULL) {
						rm->addItem(itm);
						bag.dropItem(p.firstObject);
						cout << p.firstObject << " has been dropped" << endl;
					}
					else
						cout << "You don't have such a thing to drop!" << endl;
				}
			} 	
			else if (p.command == "TAKE") {
				if (p.firstObject == "treasure") p.firstObject = "TREASURECHEST";	// temporary fix
				if (p.firstObject == "ink") p.firstObject = "INKPOT";			// same
				if (p.firstObject == "")
					cout << "Take what? " << endl;
				
				else {
					
					if (rm->hasItem(p.firstObject)) {
						if (rm->getItem(p.firstObject)->canPickupItem()) {
							Item* itm = rm->getItem(p.firstObject);
							if (bag.add(itm)) {
								// remove item from room after adding to bag
								rm->removeItem(p.firstObject);
								cout << p.firstObject << " has been added to your bag" << endl;
															
							}
						}
						else
							cout << "Can't reach that item yet!" << endl;
					}
					else
						cout << "Nothing like that around here!" << endl;
				}
			}
			else if (p.command == "PUSH") {
				// push the switch
				if(player.getRoom()->getName() == "Fire") {
					
					if(player.getRoom()->FireExtinguished()) {
						bool lock;
						lock = player.getRoom()->pushSwitch();
						cout << "Switch has been pushed" << endl;
						cave.greatCavern->setLock(1, !lock);
					}
					else
						cout << "A fire blocks you from pushing the switch!" << endl;
				}
				else 
					cout << "There's nothing to push here." << endl;
						 
			}
			else if (p.command == "EXPLORE") {
				cout << rm->getExploreStory() << endl;
			}else if (p.command == "PLACE") {
				if(player.getRoom()->getName() == "Earth" && p.firstObject == "ORE") {
					rm->PlaceORE();
					if(rm->AlterStatus()== true){
						rm->MeltLock();
						cave.earth->setLock(1,0);
					} 
				}

			}
			else if(p.command == "USE") {
				// call rm->useItem(bag, p.firstObject);	// uses an item however it was intended in given room
				if(p.firstObject == "MAP")
					if(bag.hasItem("MAP"))
					    displayMap();	
				else if(player.getRoom()->getName() == "Mine" && p.firstObject == "PICKAXE") {
					rm->useItem(bag, p.firstObject);
					if (rm->StrikeStatus()  == true){
						Item* itm = rm->getItem("ORE");
						bag.add(itm);
					}
				}
				else if (player.getRoom()->getName() == "Mine" && p.firstObject == "FEATHER"  ) {
					rm->useItem(bag, p.firstObject);
					if(rm->DoorStatus ()){
						cave.mine->setLock(1,0);
					}
		
				}else if (player.getRoom()->getName() == "Library" && p.firstObject == "BOOK"){
					rm->useItem(bag, p.firstObject);
				}else if (player.getRoom()->getName() == "Earth" && p.firstObject == "TORCH"){
					rm->LightFurnace();
					if(rm->AlterStatus()== true){
						rm->MeltLock();
						cave.earth->setLock(1,0);
					} 
				}
				else{
					rm->useItem(bag, p.firstObject);		
				} 
			} 
			else if (p.command == "CHEAT") {
				cave.unlockAllDoors();
				cout << "CHEAT CODE ACTIVATED! All doors have been unlocked. Proceed with caution." << endl;  
			}
			else if (p.command == "UNCHEAT") {
				cave.setLocks();
				cout << "Cheat code has been deactivated. All locks have been reset" << endl;
			}
			else if (p.command == "INVENTORY") {
				bag.displayBag();
			}
			else if (p.command == "HELP") {
				cout << endl;
				displayCommands();
			}
			
			else if (p.command == "SAVE") {
				cout << "SAVING..." << endl;
				saveGameFiles(getGameName());				
			}
			else
				cout << "I don't understand" << endl; 
			

		} while (playerAlive);

		if (!playerAlive) {
			cout << "You have run out of time! The exit has been closed forever..." << endl;
		}
}

void Game::displayMap()
{
	cout << "---------------------------------------------------------------------\n" << endl;
	cout <<	"				Outside				      \n";
	cout << "---------------------------------------------------------------------\n";
	cout << "\t\t\t|\t\t|\n\t\t\t|\tExit\t|\n\t\t\t|\t\t|" << endl;	
	cout << "  ---------------------------------------------------------------\n";
	cout << "  |\t\t\t\t|\t\t\t\t|\n  |\t\t\t\t|\t\t\t\t|\n  |\tTreasure\t\t|\t\tLair\t\t|\n";
	cout << "  |\t\t\t\t|\t\tof  \t\t|\n  |\t\t\t\t|\t\tFlame\t\t|\n  |\t\t\t\t|\t\t\t\t|\n";
	cout << "   --------------------------------------------------------------\n";
	cout << "   \t\t\t\t|\t\t\t|\n   \t\t\t\t|\tGuardian's\t|\n   \t\t\t\t|\t  Post  \t|\n   \t\t\t\t|\t\t\t|\n";
	cout << "   \t\t\t\t ------------------------\n";
	cout << "   \t\t\t\t   |\t|\n   \t\t\t\t   |\t|\n    \t\t\t\t   |\t|\n";
	cout << "   \tUnknown\t\t---------------------------------\n";   
	cout << "   \t\t\t|\t\t\t\t|\n   \t\t\t|\tAvendorian\t\t|\n";
	cout << "   \t\t\t|\tTerritory\t\t|\n   \t\t\t|\t\t\t\t|\n";
	cout << "   \t\t\t---------------------------------\n";
	cout << "   Library\t\t\t\t\t\t\t--------------\n   \t\t\t\tMining\t\t\t\t| Spirit's Wind |\n";
	cout << "   \t\t\t\tRegion\t\t\t\t------------------\n   \t\t\t\t\t\t\t\t|  Earth's Gate    |\n";
	cout << "   \t--------------------------------------------------------|\t\t|\n   \t\t|\t|\t\t\t\t\t------------------\n";
	cout << "   \t\t|\t|\n   \t\t|\t|\n";	// bridge
	cout << " -----------\t--------------------------------\n|\t   |\t|\t\t\t\t|----------------\n";
	cout << "| Waterfall|____| Great Cavern \t\t\t| Fiery Chasm \t|\n";
	cout << " -----------____ \t\t\t\t|\t\t|\n\t\t--------------------------------|-----------------\n"; 
	cout << "\t\t\t| Entrance |\n\t\t\t ----------" << endl;         
}

void Game::enterRoom(Room* nextRoom)
{}

void Game::loadSavedGameList()
{
	vector<string> listOfGames;
	string listFilename = "game.list";
	string buffer;
	int i = 0;
	
	std::ifstream gameListFile (listFilename);
	if(gameListFile.is_open())
	{
		while(getline(gameListFile, buffer))
		{
			listOfGames.push_back(buffer);
			i++;
		}
		
		for(int j = 0; j < i; j++)
		{
			cout << j + 1 << ". " << listOfGames[j] << endl;
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	int choice;
	cin >> choice;
	while(choice < 1 || choice > i)
	{
		cout << "Invalid choice. Choose again!" << endl;
		cin.ignore();
		cin >> choice;
	}
	
	//return listOfGames[choice - 1];
	
	setGameName(listOfGames[choice - 1]);
	
}

void Game::loadGameFiles(string gameNameIn)
{
	string sBuffer;
	int iBuffer;
	
	std::ifstream airFile (gameNameIn + "/" + "air");
	if(airFile.is_open())
	{
		//Read in isVisited value
		getline(airFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.air->setIsVisited();
		}
		//Read in items
		while(getline(airFile, sBuffer))
		{
			cave.air->addItem(cave.returnItem(sBuffer));
		}
	}
	else
	{
		//TODO: Handle the error
	}
	airFile.close();
	
	std::ifstream bridgeFile (gameNameIn + "/" + "bridge");
	if(bridgeFile.is_open())
	{
		//Read in isVisited value
		getline(bridgeFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.bridge->setIsVisited();
		}
		//Read in items
		while(getline(bridgeFile, sBuffer))
		{
			cave.bridge->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	bridgeFile.close();
	
	std::ifstream dragonLairFile (gameNameIn + "/" + "dragonLair");
	if(dragonLairFile.is_open())
	{
		//Read in isVisited value
		getline(dragonLairFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.dragonLair->setIsVisited();
		}
		
		//Read in westLocked value
		getline(dragonLairFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.dragonLair->setLock(4, false);
		}
		
		//Read in northLocked value
		getline(dragonLairFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.dragonLair->setLock(1, false);
		}
		//Read in items
		while(getline(dragonLairFile, sBuffer))
		{
			cave.dragonLair->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	dragonLairFile.close();
	
	std::ifstream earthFile (gameNameIn + "/" + "earth");
	if(earthFile.is_open())
	{
		//Read in isVisited value
		getline(earthFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.earth->setIsVisited();
		}
		
		//Read in northLocked value
		getline(earthFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 0)
		{
			cave.earth->setLock(1, false);
		}
		//Read in items
		while(getline(earthFile, sBuffer))
		{
			cave.earth->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	earthFile.close();
	
	std::ifstream entranceFile (gameNameIn + "/" + "entrance");
	if(entranceFile.is_open())
	{
		//Read in isVisited value
		getline(entranceFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.entrance->setIsVisited();
		}
		//Read in items
		while(getline(entranceFile, sBuffer))
		{
			cave.entrance->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	entranceFile.close();
	
	std::ifstream exitFile (gameNameIn + "/" + "exit");
	if(exitFile.is_open())
	{
		//Read in isVisited value
		getline(exitFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.exit->setIsVisited();
		}
		//Read in items
		while(getline(exitFile, sBuffer))
		{
			cave.exit->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	exitFile.close();
	
	std::ifstream fireFile (gameNameIn + "/" + "fire");
	if(fireFile.is_open())
	{
		//Read in isVisited value
		getline(fireFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.fire->setIsVisited();
		}
		//Read in items
		while(getline(fireFile, sBuffer))
		{
			cave.fire->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	fireFile.close();
	
	std::ifstream greatCavernFile (gameNameIn + "/" + "greatCavern");
	if(greatCavernFile.is_open())
	{
		//Read in isVisited value
		getline(greatCavernFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.greatCavern->setIsVisited();
		}
		
		//Read in the value of northLocked
		getline(greatCavernFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 0)
		{
			cave.greatCavern->setLock(1, false);
		}
		//Read in items
		while(getline(greatCavernFile, sBuffer))
		{
			cave.greatCavern->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	greatCavernFile.close();
	
	std::ifstream guardianPostFile (gameNameIn + "/" + "guardianPost");
	if(guardianPostFile.is_open())
	{
		//Read in isVisited value
		getline(guardianPostFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.guardianPost->setIsVisited();
		}
		
		//Read in northLocked value
		getline(guardianPostFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 0)
		{
			cave.guardianPost->setLock(1, false);
		}
		
		//Read in eastLocked value
		getline(guardianPostFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 0)
		{
			cave.guardianPost->setLock(3, false);
		}
		
		//Read in westLocked value
		getline(guardianPostFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 0)
		{
			cave.guardianPost->setLock(4, false);
		}
		//Read in items
		while(getline(guardianPostFile, sBuffer))
		{
			cave.guardianPost->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	guardianPostFile.close();
	
	std::ifstream libraryFile (gameNameIn + "/" + "library");
	if(libraryFile.is_open())
	{
		//Read in isVisited value
		getline(libraryFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.library->setIsVisited();
		}
		//Read in items
		while(getline(libraryFile, sBuffer))
		{
			cave.library->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	libraryFile.close();
	
	std::ifstream mazeRoomFile (gameNameIn + "/" + "mazeRoom");
	if(mazeRoomFile.is_open())
	{
		//Read in isVisited value
		getline(mazeRoomFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.mazeRoom->setIsVisited();
		}
		//Read in items
		while(getline(mazeRoomFile, sBuffer))
		{
			cave.mazeRoom->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	mazeRoomFile.close();
	
	std::ifstream mineFile (gameNameIn + "/" + "mine");
	if(mineFile.is_open())
	{
		//Read in isVisited value
		getline(mineFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.mine->setIsVisited();
		}
		
		//Read in northLocked value
		getline(mineFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 0)
		{
			cave.mine->setLock(1, false);
		}
		//Read in items
		while(getline(mineFile, sBuffer))
		{
			cave.mine->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	mineFile.close();
	
	std::ifstream outsideFile (gameNameIn + "/" + "outside");
	if(outsideFile.is_open())
	{
		//Read in isVisited value
		getline(outsideFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.outside->setIsVisited();
		}
		//Read in items
		while(getline(outsideFile, sBuffer))
		{
			cave.outside->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	outsideFile.close();
	
	std::ifstream outsideEndFile (gameNameIn + "/" + "outsideEnd");
	if(outsideEndFile.is_open())
	{
		//Read in isVisited value
		getline(outsideEndFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.outsideEnd->setIsVisited();
		}
		//Read in items
		while(getline(outsideEndFile, sBuffer))
		{
			cave.outsideEnd->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	outsideEndFile.close();
	
	std::ifstream postMazeFile (gameNameIn + "/" + "postMaze");
	if(postMazeFile.is_open())
	{
		//Read in isVisited value
		getline(postMazeFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.postMaze->setIsVisited();
		}
		//Read in items
		while(getline(postMazeFile, sBuffer))
		{
			cave.postMaze->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	postMazeFile.close();
	
	std::ifstream treasureFile (gameNameIn + "/" + "treasure");
	if(treasureFile.is_open())
	{
		//Read in isVisited value
		getline(treasureFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.treasure->setIsVisited();
		}
		//Read in items
		while(getline(treasureFile, sBuffer))
		{
			cave.treasure->addItem(cave.returnItem(sBuffer));
		}
	}
	else
	{
		//TODO: Handle the error
	}
	treasureFile.close();
	
	std::ifstream trollBridgeFile (gameNameIn + "/" + "trollBridge");
	if(trollBridgeFile.is_open())
	{
		//Read in isVisited value
		getline(trollBridgeFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.trollBridge->setIsVisited();
		}
		
		//Read in northLocked value
		getline(trollBridgeFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 0)
		{
			cave.trollBridge->setLock(1, false);
		}
		//Read in items
		while(getline(trollBridgeFile, sBuffer))
		{
			cave.trollBridge->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	trollBridgeFile.close();
	
	std::ifstream waterFile (gameNameIn + "/" + "water");
	if(waterFile.is_open())
	{
		//Read in isVisited value
		getline(waterFile, sBuffer);
		iBuffer = std::stoi(sBuffer);
		if(iBuffer == 1)
		{
			cave.water->setIsVisited();
		}
		//Read in items
		while(getline(waterFile, sBuffer))
		{
			cave.water->addItem(cave.returnItem(sBuffer));
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	waterFile.close();
	
	std::ifstream playerFile (gameNameIn + "/" + "player");
	if(playerFile.is_open())
	{
		//Read in playerAlive value
		getline(playerFile, sBuffer);
		playerAlive = std::stoi(sBuffer);
		
		//Read in timeLimit value
		getline(playerFile, sBuffer);
		timeLimit = std::stoi(sBuffer);
		
		//Read in timeCount value
		getline(playerFile, sBuffer);
		timeCount = std::stoi(sBuffer);
		
		getline(playerFile, sBuffer);
		player.completedMaze = std::stoi(sBuffer);
		
		//Read in player's current room name
		getline(playerFile, sBuffer);
		if(sBuffer == "Air")
		{
			player.setCurrentRoom(cave.air);
		}
		else if(sBuffer == "Great Bridge")
		{
			player.setCurrentRoom(cave.bridge);
		}
		else if(sBuffer == "Dragon's Lair")
		{
			player.setCurrentRoom(cave.dragonLair);
		}
		else if(sBuffer == "Earth")
		{
			player.setCurrentRoom(cave.earth);
		}
		else if(sBuffer == "Entrance")
		{
			player.setCurrentRoom(cave.entrance);
		}
		else if(sBuffer == "Exit")
		{
			player.setCurrentRoom(cave.exit);
		}
		else if(sBuffer == "Fire")
		{
			player.setCurrentRoom(cave.fire);
		}
		else if(sBuffer == "Great Cavern")
		{
			player.setCurrentRoom(cave.greatCavern);
		}
		else if(sBuffer == "Cave Guardian's Post")
		{
			player.setCurrentRoom(cave.guardianPost);
		}
		else if(sBuffer == "Library")
		{
			player.setCurrentRoom(cave.library);
		}
		else if(sBuffer == "Maze Room")
		{
			player.setCurrentRoom(cave.mazeRoom);
		}
		else if(sBuffer == "Mine")
		{
			player.setCurrentRoom(cave.mine);
		}
		else if(sBuffer == "Outside")
		{
			player.setCurrentRoom(cave.outside);
		}
		else if(sBuffer == "Post Maze")
		{
			player.setCurrentRoom(cave.postMaze);
		}
		else if(sBuffer == "Room of Lost Treasure")
		{
			player.setCurrentRoom(cave.treasure);
		}
		else if(sBuffer == "Troll Bridge")
		{
			player.setCurrentRoom(cave.trollBridge);
		}
		else if(sBuffer == "Water")
		{
			player.setCurrentRoom(cave.water);
		}
		//Read in items
		while(getline(playerFile, sBuffer))
		{
			bag.add(cave.returnItem(sBuffer));
		}
	}
	else
	{
		//TODO: Handle the error
	}
	playerFile.close();
}

void Game::setUpNewGame()
{
	string gameNameUser;
	string buffer;
	vector<string> listOfGameNames;
	bool uniqueName;
	
	//Read all of the previous game names
	std::ifstream gameFileListRead;
	gameFileListRead.open("game.list");
	if(gameFileListRead.is_open())
	{
		while(getline(gameFileListRead, buffer))
		{
			listOfGameNames.push_back(buffer);
		}
	}
	else
	{
		exit;
	}
	cout << "Please choose a name for your new game: " << endl;
	//Check for uniqueness, and repeat until a unique name is provided
	do
	{
		uniqueName = true;
		cin >> gameNameUser;
		for(int i = 0; i < listOfGameNames.size(); i++)
		{
			if(gameNameUser == listOfGameNames[i])
			{
				uniqueName = false;
				cout << "Name already in use, please choose another." << endl;
			}
		}
		
	} while(uniqueName == false);
	
	gameFileListRead.close();
	
	//Open file to write, and write the new, unique game name to the end of the file
	std::ofstream gameFileListWrite;
	gameFileListWrite.open("game.list", std::ifstream::app);
	if(gameFileListWrite.is_open())
	{
		gameFileListWrite << gameNameUser << endl;
	}
	else
	{
		exit;
	}
	gameFileListWrite.close();
	
	//Set the gameName variable to access this specific game
	setGameName(gameNameUser);
	
	//Ok, now the game has a unique name listed in the game.list file, which was be used from loadgame
	//Now to create a directory for this game's files
	boost::filesystem::path dir(gameNameUser);	//http://stackoverflow.com/questions/8388005/create-directory-from-boostfilesystem-succeeds-however-no-dir-is-created
	//if (boost::filesystem::create_directory(dir))
    //std::cout << "Success" << "\n";

	boost::filesystem::create_directory(dir);
	
	cave.entrance->addItem(cave.map);
	cave.entrance->addItem(cave.flagon);
	cave.greatCavern->addItem(cave.torch);
	cave.water->addItem(cave.waterskin);
	cave.water->addItem(cave.oar);
	cave.bridge->addItem(cave.pickaxe);
	cave.mine->addItem(cave.ore);
	cave.library->addItem(cave.inkPot);
	cave.air->addItem(cave.feather);
	cave.postMaze->addItem(cave.sword);
	cave.guardianPost->addItem(cave.goldPiece);
	cave.treasure->addItem(cave.treasureChest);
	cave.exit->addItem(cave.ale);
	
	saveGameFiles(gameNameUser);
}

void Game::saveGameFiles(string gameNameIn)
{
	std::ofstream airFile (gameNameIn + "/" + "air");
	if(airFile.is_open())
	{
		airFile << cave.air->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.air->items.size(); i++)
		{
			airFile << cave.air->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	airFile.close();
	
	std::ofstream bridgeFile (gameNameIn + "/" + "bridge");
	if(bridgeFile.is_open())
	{
		bridgeFile << cave.bridge->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.bridge->items.size(); i++)
		{
			bridgeFile << cave.bridge->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	bridgeFile.close();
	
	std::ofstream dragonLairFile (gameNameIn + "/" + "dragonLair");
	if(dragonLairFile.is_open())
	{
		dragonLairFile << cave.dragonLair->getIsVisited() << endl;
		dragonLairFile << cave.dragonLair->isLocked("WEST") << endl;
		dragonLairFile << cave.dragonLair->isLocked("NORTH") << endl;
		
		//This room's current items
		for(int i = 0; i < cave.dragonLair->items.size(); i++)
		{
			dragonLairFile << cave.dragonLair->items.at(i)->getName() << endl;
		}
		
	}
	else
	{
		//TODO: Handle the error
	}
	dragonLairFile.close();
	
	std::ofstream earthFile (gameNameIn + "/" + "earth");
	if(earthFile.is_open())
	{
		earthFile << cave.earth->getIsVisited() << endl;
		earthFile << cave.earth->isLocked("NORTH") << endl;
		
		//This room's current items
		for(int i = 0; i < cave.earth->items.size(); i++)
		{
			earthFile << cave.earth->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	earthFile.close();
	
	std::ofstream entranceFile (gameNameIn + "/" + "entrance");
	if(entranceFile.is_open())
	{
		entranceFile << cave.entrance->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.entrance->items.size(); i++)
		{
			entranceFile << cave.entrance->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	entranceFile.close();
	
	std::ofstream exitFile (gameNameIn + "/" + "exit");
	if(exitFile.is_open())
	{
		exitFile << cave.exit->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.exit->items.size(); i++)
		{
			exitFile << cave.exit->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	exitFile.close();
	
	std::ofstream fireFile (gameNameIn + "/" + "fire");
	if(fireFile.is_open())
	{
		fireFile << cave.fire->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.fire->items.size(); i++)
		{
			fireFile << cave.fire->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	fireFile.close();
	
	std::ofstream greatCavernFile (gameNameIn + "/" + "greatCavern");
	if(greatCavernFile.is_open())
	{
		greatCavernFile << cave.greatCavern->getIsVisited() << endl;
		greatCavernFile << cave.greatCavern->isLocked("NORTH") << endl;
		
		//This room's current items
		for(int i = 0; i < cave.greatCavern->items.size(); i++)
		{
			greatCavernFile << cave.greatCavern->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	greatCavernFile.close();
	
	std::ofstream guardianPostFile (gameNameIn + "/" + "guardianPost");
	if(guardianPostFile.is_open())
	{
		guardianPostFile << cave.guardianPost->getIsVisited() << endl;
		guardianPostFile << cave.guardianPost->isLocked("NORTH") << endl;
		guardianPostFile << cave.guardianPost->isLocked("EAST") << endl;
		guardianPostFile << cave.guardianPost->isLocked("WEST") << endl;
		
		//This room's current items
		for(int i = 0; i < cave.guardianPost->items.size(); i++)
		{
			guardianPostFile << cave.guardianPost->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	guardianPostFile.close();
	
	std::ofstream libraryFile (gameNameIn + "/" + "library");
	if(libraryFile.is_open())
	{
		libraryFile << cave.library->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.library->items.size(); i++)
		{
			libraryFile << cave.library->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	libraryFile.close();
	
	std::ofstream mazeRoomFile (gameNameIn + "/" + "mazeRoom");
	if(mazeRoomFile.is_open())
	{
		mazeRoomFile << cave.mazeRoom->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.mazeRoom->items.size(); i++)
		{
			mazeRoomFile << cave.mazeRoom->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	mazeRoomFile.close();
	
	std::ofstream mineFile (gameNameIn + "/" + "mine");
	if(mineFile.is_open())
	{
		mineFile << cave.mine->getIsVisited() << endl;
		mineFile << cave.mine->isLocked("NORTH") << endl;
		
		//This room's current items
		for(int i = 0; i < cave.mine->items.size(); i++)
		{
			mineFile << cave.mine->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	mineFile.close();
	
	std::ofstream outsideFile (gameNameIn + "/" + "outside");
	if(outsideFile.is_open())
	{
		outsideFile << cave.outside->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.outside->items.size(); i++)
		{
			outsideFile << cave.outside->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	outsideFile.close();
	
	std::ofstream outsideEndFile (gameNameIn + "/" + "outsideEnd");
	if(outsideEndFile.is_open())
	{
		outsideEndFile << cave.outsideEnd->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.outsideEnd->items.size(); i++)
		{
			outsideEndFile << cave.outsideEnd->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	outsideEndFile.close();
	
	std::ofstream postMazeFile (gameNameIn + "/" + "postMaze");
	if(postMazeFile.is_open())
	{
		postMazeFile << cave.postMaze->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.outsideEnd->items.size(); i++)
		{
			outsideEndFile << cave.outsideEnd->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	postMazeFile.close();
	
	std::ofstream treasureFile (gameNameIn + "/" + "treasure");
	if(treasureFile.is_open())
	{
		treasureFile << cave.treasure->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.treasure->items.size(); i++)
		{
			treasureFile << cave.treasure->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	treasureFile.close();
	
	std::ofstream trollBridgeFile (gameNameIn + "/" + "trollBridge");
	if(trollBridgeFile.is_open())
	{
		trollBridgeFile << cave.trollBridge->getIsVisited() << endl;
		trollBridgeFile << cave.trollBridge->isLocked("NORTH") << endl;
		
		//This room's current items
		for(int i = 0; i < cave.trollBridge->items.size(); i++)
		{
			trollBridgeFile << cave.trollBridge->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	trollBridgeFile.close();
	
	std::ofstream waterFile (gameNameIn + "/" + "water");
	if(waterFile.is_open())
	{
		waterFile << cave.water->getIsVisited() << endl;
		
		//This room's current items
		for(int i = 0; i < cave.water->items.size(); i++)
		{
			waterFile << cave.water->items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	waterFile.close();
	
	std::ofstream playerFile (gameNameIn + "/" + "player");
	if(playerFile.is_open())
	{
		playerFile << playerAlive << endl;
		playerFile << timeLimit << endl;
		playerFile << timeCount << endl;
		playerFile << player.completedMaze << endl;
		playerFile << player.getRoom()->getName() << endl;
		
		//The player's current items
		for(int i = 0; i < bag.items.size(); i++)
		{
			playerFile << bag.items.at(i)->getName() << endl;
		}
	}
	else
	{
		//TODO: Handle the error
	}
	playerFile.close();
}

void Game::setGameName(string gameNameIn)
{
	gameName = gameNameIn;
}

string Game::getGameName()
{
	return gameName;
}
