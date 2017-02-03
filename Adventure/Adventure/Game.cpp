#include "Game.h"

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
			getline(cin, userInput);
			p = parse(userInput);
			// get commandID from command? maybe use enum to store commands? 
			// or perhaps map a command string to a function that does something? this would prevent having a huge switch statement
			// just a test here
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

			}
			
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
