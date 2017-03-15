#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "Bag.h"
#include "parser.h"
#include <boost/algorithm/string.hpp>
#include <algorithm>
using namespace boost;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Dragon
{
protected:
	ParsedInput p;
	bool isGuardingTreasure;
	bool isGlowing;	// means susceptible to water
	bool isGreedy; // means susceptible to gold
	bool opponentHasSword;
	bool opponentHasGold;
	bool opponentHasWater;
	bool opponentHasPickaxe;
	bool hasSpokenToDragon; 
public:
	Dragon();
	~Dragon();
	void setItemStatus(Bag);
	bool encounter(string, Bag);
	bool fightDragon(Bag);
	bool speakToDragon(Bag);
	bool playGame();
	bool giveGift(Bag);	
	int checkInput(string);	
};
