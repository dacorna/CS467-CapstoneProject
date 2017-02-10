#include "Game.h"
#include <ios>
#include <limits>

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
			// test return of parser
			cout << "p.command = " << p.command << endl;
			cout << "command length = " << p.command.length() << endl;
			cout << "p.firstObject = " << p.firstObject << endl;
			cout << "p.firstObject length = " << p.firstObject.length() << endl;  		
	
			
			// considering using a table-driven method with function pointers 
			//  but for now we go with the big huge if-else block
			  
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
				
				if(p.firstObject == "ROOM") {
					
					cout << player.getRoom()->getLongDescription() << endl;
				}
				else if(p.firstObject == "MAP") {
					
					if(player.getBag().hasItem("MAP"))
				  	   cout << "Looking at map..." << endl;
				}
				else if(p.firstObject == "BAG") {
					
					player.getBag().displayBag();
				}
				else {
					cout << player.getRoom()->getLongDescription() << endl;
				}
				
			}
			else if(p.command == "DROP") {
				cout << "Inside the drop block" << endl;
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
