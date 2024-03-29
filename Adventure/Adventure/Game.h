#pragma once

#include "Cave.h"
#include "Character.h"
#include "parser.h"
#include "Bag.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Game
{
private:
	Cave cave;
	Character player;
	Bag bag;
	ParsedInput p;
	string userInput;
	bool playerAlive;
	int timeLimit;
	int timeCount;
	string commandTable[20][2] = { 
			{ "go [direction]", "moves player toward the direction given (north/east/etc)" } 
			, { "look", "gives long description of current room" }
			, { "look at [object]", "gives description of the object specified" }
			, { "open [object]", "opens object specified if possible (ex. door, chest)" }
			, { "take [object]", "adds object specified to player's bag, if possible" }
			, { "inventory", "lists the items in player's bag" }
			, { "use [object]", "if player has object, it may be used" }
			, { "drop [object]", "remove object from player's bag" }
			, { "explore", "walks player around current room to reveal intricacies" }
			, { "cheat", "unlocks all doors" }
			, { "uncheat", "re-locks the doors" }
			, { "push", "pushes a switch (or other pushable things)" }
			, { "light [object]", "lights a torch/furnace, etc" }
			, { "read book/page", "reads something on a page"}
			, { "fill water", "if near water, can fill a container" }
			, { "pour water", "can pour water on something" }
			, { "get/grab/pickup [object]", "adds object to bag" }
	};
	
	string gameName;
	bool isTorchLit;
	
public:
	Game();
	~Game();
	void startGame(string);
	void enterRoom(Room*);
	void displayCommands();
	void displayMap();
	void loadSavedGameList();
	void loadGameFiles(string);
	void setUpNewGame();
	void saveGameFiles(string);
	void setGameName(string);
	std::string getGameName();
};
