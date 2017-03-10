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

class Guardian
{
	protected:
		bool hasWeapon;
	
	public:
		Guardian();
		~Guardian();
		void setWeaponStatus(Bag);
		bool encounterGuardian();
};