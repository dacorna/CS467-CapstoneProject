#include "DragonLair.h"
#include <unistd.h>

DragonLair::DragonLair()
{
	name = "Dragon's Lair";
	longDescription = "A massive and dimly lit room, littered with the bones of lost souls. Something very large stirs in the darkness. It sits atop a glowing door to the west. Ah yes, this must be the dragon's lair.";
	shortDescription = "Lair of the dragon.";
	exploreStory = "You tiptoe around gently, not wanting to summon back the fiery beast. Impossible but to notice the charred remains of some former occupants. Treasure pieces are scattered, but become more prevalent on the westerly edge of the room, near where the dragon once slept. Stories say the dragon cannot be defeated with any solid objects of mankind. Greed is its greatest weakness.";
}
/*
int DragonLair::special(Character player,Bag bag)
{
	usleep(500000);
	int result = 0;
	char choice;
	cout << endl << "What's your move, Adventurer?" << endl;
	cout << "1. Speak to the dragon" << endl;
	cout << "2. Fight the dragon" << endl;
	cout << "3. Explore quietly" << endl;
	cout << "4. Go back" << endl;	
	cin >> choice;
	if(choice == '1') {
		result = player.speakToDragon(bag);	
	}
	else if(choice == '2') {
		result = player.fightDragon(bag);
	}
	else if(choice == '3') {
		result = player.explore(bag,"dragonlair");
	}
	else {
		// go back
		return -1;
	}
	
	return result;
}
*/
