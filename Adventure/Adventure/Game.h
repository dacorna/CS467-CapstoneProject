#pragma once

#include "Cave.h"
#include "Character.h"
#include "parser.h"
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
	ParsedInput p;
	string userInput;
	bool playerAlive;
	int timeLimit;
	int timeCount;
	
public:
	Game();
	~Game();
	void startGame(string);
	void enterRoom(Room*);
};
