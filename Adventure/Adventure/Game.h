#pragma once

#include "Cave.h"
#include "Character.h"
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
	bool playerAlive;
	int timeLimit;
	int timeCount;
	// more to come
public:
	Game();
	~Game();
	void startGame(string);
	void enterRoom(Room*);
};