#include "Fire.h"

Fire::Fire() {
	name = "Fire";
	shortDescription = "Fire room. No further exits.";
	longDescription = "A room of fire and light. A greath hearth lies ahead...must have been burning for centuries.";
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
