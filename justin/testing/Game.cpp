#include "Game.h"
#include <ios>
#include <limits>
#include <fstream>
#include <iostream>
//#include <boost/filesystem.hpp>

Game::Game()
{
	playerAlive = true;
	timeLimit = 100; // whatever we decide - maybe none
	timeCount = 0;
}

Game::~Game()
{

}

void Game::startGame(string type)
{
	if (type == "new") {
		// start new game
		setUpNewGame();
		player.setCurrentRoom(cave.outside);
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
		cout << endl << player.getRoom()->getLongDescription() << endl;
		do {
			timeCount++;
			if (timeCount > timeLimit) playerAlive = false;

			cout << ">  ";
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');		- not defined 
			// discard input buffer
			cin.sync();
			getline(cin, userInput);
			p = parse(userInput);
			// get commandID from command? maybe use enum to store commands? 
			// or perhaps map a command string to a function that does something? this would prevent having a huge switch statement
			// just a test here
			if(p.command == "GO") {
				if(p.firstObject == "NORTH")
					player.enterRoom(player.getRoom()->getNorth());
				else if(p.firstObject == "SOUTH")
					player.enterRoom(player.getRoom()->getSouth());
				else if(p.firstObject == "EAST")
					player.enterRoom(player.getRoom()->getEast());
				else
					player.enterRoom(player.getRoom()->getWest());
			}
			else if(p.command == "LOOK") {
				if(p.firstObject == "ROOM")
					player.getRoom()->getLongDescription();
				else if(p.firstObject == "MAP")
					if(player.getBag().hasItem("MAP"))
						cout << "Looking at map..." << endl;
				else if(p.firstObject == "BAG")
					player.getBag().displayBag();
				else
					player.getRoom()->getShortDescription();
			}
			else if(p.command == "DROP") {
				if(p.firstObject == "")
					cout << "Drop what? " << endl;
				else {
					Item itm = player.getBag().getItem(p.firstObject);
					if(itm.getName() != "noItem")
						player.getRoom()->addItem(itm);

					player.getBag().dropItem(p.firstObject);
							 	
				}
			} 	  

			/*
			int commandId = 1;

			switch (commandId) {
			case 1:		// north
				player.enterRoom(player.getRoom()->getNorth());
				// do some stuff
				break;
			case 2:
				player.enterRoom(player.getRoom()->getEast());
				// do something
				break;
			case 3:
				player.enterRoom(player.getRoom()->getSouth());
				break;
			case 4:
				player.enterRoom(player.getRoom()->getWest());
				break;
			// other cases here 
			default:
				// likely invalid command - jump back to get user input again
				break;
			}
			*/

		} while (playerAlive);

		if (!playerAlive) {
			cout << "You have run out of time! The exit has been closed forever..." << endl;
		}
	}
	else {
		// load saved game
	}
}


void Game::enterRoom(Room* nextRoom)
{

}

string Game::loadSavedGameList()
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
		cin >> choice;
	}
	
	return listOfGames[choice - 1];
}

void Game::loadRoomFiles(string nameOfGame)
{
	////I don't know of an easy way to iterate through the rooms, so I didn't
	//std::ifstream airFile (nameOfGame + "\\" + "air.txt");
	//if(airFile.is_open())
	//{
	//	getline(airFile, buffer);
	//	cave.air->setIsVisited();
	//}
	//else
	//{
	//	//TODO: Handle the error
	//}
	//airFile.close();
	//
	//std::ifstream earthFile (nameOfGame + "\\" + "earth.txt");
	//if(earthFile.is_open())
	//{
	//	cave.earth->setIsVisited();
	//}
	//else
	//{
	//	//TODO: Handle the error
	//}
	//earthFile.close();
	//
	//std::ifstream entranceFile (nameOfGame + "\\" + "entrance.txt");
	//if(entranceFile.is_open())
	//{
	//	cave.entrance->setIsVisited();
	//}
	//else
	//{
	//	//TODO: Handle the error
	//}
	//entranceFile.close();
	//
	//std::ifstream exitFile (nameOfGame + "\\" + "exit.txt");
	//if(exitFile.is_open())
	//{
	//	cave.exit->setIsVisited();
	//}
	//else
	//{
	//	//TODO: Handle the error
	//}
	//exitFile.close();
	//
	//std::ifstream fireFile (nameOfGame + "\\" + "fire.txt");
	//if(fireFile.is_open())
	//{
	//	cave.fire->setIsVisited();
	//}
	//else
	//{
	//	//TODO: Handle the error
	//}
	//fireFile.close();
	//
	//cout << cave.air->getIsVisited() << endl;
	//cout << cave.earth->getIsVisited() << endl;
	//cout << cave.entrance->getIsVisited() << endl;
	//cout << cave.exit->getIsVisited() << endl;
	//cout << cave.fire->getIsVisited() << endl;
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
	//Check for uniqueness, and repeat until a unique name is provided
	do
	{
		uniqueName = true;
		cout << "Please choose a name for your new game" << endl << "(if already taken, you will be prompted again): ";
		cin >> gameNameUser;
		for(int i = 0; i < listOfGameNames.size(); i++)
		{
			if(gameNameUser == listOfGameNames[i])
			{
				uniqueName = false;
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
	
	//Ok, now the game has a unique name listed in the game.list file, which was be used from loadgame
	//Now to create a directory for this game's files
	//boost::filesystem::path newDirectory(gameNameUser.c_str());
	//boost::filesystem::path dir(newDirectory);
	
}