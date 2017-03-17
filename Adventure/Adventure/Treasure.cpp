#include "Treasure.h"


Treasure::Treasure()
{
	name = "Room of Lost Treasure";
	longDescription = "\nA vast and glorious room, flowing with treasure all around.\nThe lost treasure chest of Imyhalian lies at your feet. Light shines in from above to the north";
	shortDescription = "Room of Lost Treasure. Light above to the north.";
	exploreStory = "Why would you want to explore? Just PICK UP THE TREASURE CHEST and get out of here!\nHow do we know it's the lost treasure of Imyhalian, you ask?\nEasy, it says his name right on the side of the chest!\n Here's a hint: 'take treasure'";
}

void Treasure::useItem(Bag bag, string item)
{
	if (item == "KEY") {
		// check if bag has key
		// unlock treasure chest with key // set objectiveComplete to true on item
		// use room->getItem("treasure")->objectiveComplete or something
	}
	else
		cout << "That has no effect here" << endl;
}
