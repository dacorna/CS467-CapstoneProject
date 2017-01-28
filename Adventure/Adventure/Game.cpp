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
		// load background/story files 
		// below will likely be stored in a game background/story file that will be loaded in 
		cout << "Welcome to Cave!" << endl << endl;
		cout << "It's the text-based adventure game where you navigate the deep, dark " << endl;
		cout << "tunnels and secret caverns of a mysterious and ancient cave " << endl;
		// load directions file  ... something better than below will come from a file in future 
		cout << "The goal of the game is to navigate the cave all the way through to a secret " << endl;
		cout << "exit, following clues, solving puzzles, getting through mazes, and picking up items " << endl;
		cout << "along the way. Oh, and you better get there before the door closes for good!" << endl;
		cout << endl << "OK. Time to enter the cave, at your own peril. Ready???" << endl;
		cout << "1. Yup" << endl;
		cout << "2. Sure thing" << endl;
		cout << "3. Not really, but I have to go in anyway" << endl;
		// player enters the cave 
		player.enterRoom(cave.entrance);
		// more to come next week!
	}
	else {
		// load saved game
	}
}

void Game::enterRoom(Room* nextRoom)
{

}