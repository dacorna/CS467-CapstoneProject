#include "Room.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Mine : public Room {

private:	
	bool secondStrike ; 
	bool firstSrike;
	bool DoorUnlocked;

public:
	bool StrikeStatus (){return secondStrike;}
	bool DoorStatus (){return DoorUnlocked;}
	Mine();
	void useItem(Bag, string);
};