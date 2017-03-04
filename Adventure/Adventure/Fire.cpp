#include "Fire.h"
#include <stdlib.h>
#include <limits>
#include <unistd.h>

Fire::Fire() {
	name = "Fire";
	shortDescription = "Fire room. No further exits.";
	longDescription = "A room of fire and light. A greath hearth lies ahead...must have been burning for centuries. The fire blocks a switch";
	exploreStory = "Would be interesting to find out what that switch does, but won't be able to push it until that fire is out. I don't see any water in here though.";
	switchPushed = false;
	fireExtinguished = false;
}

Fire::~Fire() {

}

bool Fire::pushSwitch()
{
	// isLocked of great cavern door will be set to the opposite of what is returned here
	bool currentState = switchPushed;
	switchPushed = !currentState;
	return switchPushed;
}

void Fire::useItem(Bag bag, string item)
{
	if (item == "TORCH") {
		if (bag.hasItem("TORCH")) {
			// light the torch
			bag.getItem("TORCH")->completeObjective(true);
			// to find out if torch is lit use torch->isObjectiveCompleted()
			cout << "The torch has been lit. It illuminates the room" << endl;
		}
		else {
			cout << "You don't have a torch!" << endl;
		}
	}
	else if (item == "WATERSKIN") {
		if (bag.hasItem("WATERSKIN")) {
			Item *water = bag.getItem("WATERSKIN");
			// check if waterskin is filled with water
			if (water->isObjectiveCompleted()) {
				cout << "Pouring water on the fire..." << endl;
				usleep(400000);	
				// empty the waterskin of water
				water->completeObjective(false);
				fireExtinguished = true;
				cout << "The fire has been extinguished! You can reach the switch above it" << endl;
			}
			else {
				cout << "Your waterskin is empty! Maybe you should fill it up next time" << endl;
			}
		}
		else {
			cout << "You don't have a waterskin!" << endl;
		}
	
	}
	else
		cout << "That item has no effect here" << endl;
}
