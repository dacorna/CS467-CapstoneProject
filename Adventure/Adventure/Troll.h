#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "Bag.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Troll
{
	protected:
		bool hasWeapon;
	
	public:
		Troll();
		~Troll();
		void setWeaponStatus(Bag);
		bool encounterTroll();
		bool fightTroll();
		bool talkTroll();
};