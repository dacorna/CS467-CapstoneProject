#include "TrollBridge.h"

TrollBridge::TrollBridge() {
	name = "Troll Bridge";
	shortDescription = "Troll's Bridge. Continue north to cross";
	longDescription = "You have come upon a bridge. A huge cave troll sleeps at the edge to the north.";
	exploreStory = "Nothing much to explore. You simply can't go anywhere without crossing the troll. Fighting it is possible, but could be risky. Perhaps you could use your wits...if you have any";
}

void TrollBridge::useItem(Bag bag, string item)
{
	if (item == "PICKAXE" || item == "SWORD") {
		// check if bag has item
		// perform random simulation to determine result of attack
		// should be roughly 50% chance to defeat troll
		// use sleep() function to simulate time passing
	}
}