#include "Fire.h"

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
	bool currentState = switchPushed;
	switchPushed = !currentState;
	return switchPushed;
}

void Fire::useItem(Bag bag, string item)
{
	if (item == "TORCH") {
		// check if bag has torch
		// light the torch
	}
	else if (item == "WATERSKIN") {
		// check if bag has waterskin
		// check to see if waterskin is filled with water
		// put out fire with water
		// waterskin is now empty, fireExtinguished = true
		// state that you can now reach the switch
	}
	else
		cout << "That item has no effect here" << endl;
}
