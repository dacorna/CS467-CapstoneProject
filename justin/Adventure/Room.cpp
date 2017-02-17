#include "Room.h"

Room::Room()
{
	northLocked = false;
	southLocked = false;
	eastLocked = false;
	westLocked = false;
}

Room::~Room()
{}

bool Room::isLocked(string direction)
{
	if(direction == "NORTH")
		return northLocked;
	else if(direction == "SOUTH")
		return southLocked;
	else if(direction == "EAST")
		return eastLocked;
	else if(direction == "WEST")
		return westLocked; 
	else 
		return true;	// return true because we don't want to assume door is unlocked if incorrect input given
}

void Room::setLock(int direction, bool choice)
{
	switch(direction) {
	
	case 1:
		northLocked = choice;
		break;
	case 2:
		southLocked = choice;
		break;
	case 3: 
		eastLocked = choice;
		break;
	case 4:
		westLocked = choice;
		break;
	default:
		return;
	}
}

void Room::addItem(Item* item)
{
	items.push_back(item);
}

void Room::removeItem(string item)
{
	for(unsigned i=0; i < items.size(); i++) {
		if(items.at(i)->getName() == item)
			items.erase(items.begin() + i);
	} 
}

void Room::showItems()
{
	for (unsigned i = 0; i < items.size(); i++) {
		cout << items.at(i)->getName();
		cout << " -- " << items.at(i)->getDescription() << endl;
	}
}

bool Room::hasItem(string itemName)
{
	for (unsigned i = 0; i < items.size(); i++) {
		if (items.at(i)->getName() == itemName)
			return true;
	}
	return false;
}

Item* Room::getItem(string itemName)
{
	for (unsigned i = 0; i < items.size(); i++) {
		if (items.at(i)->getName() == itemName)
			return items.at(i);
	}
	// item not found
	//Item noItem("noItem");
	//return &noItem;
	return NULL;
}

void Room::setIsVisited()
{
	isVisited = true;
}

void Room::setExits(Room* northIn, Room* southIn, Room* eastIn, Room* westIn)
{
	north = northIn;
	south = southIn;
	east = eastIn;
	west = westIn;
}

bool Room::pushSwitch()
{}

void Room::extinguishFire()
{}

bool Room::FireExtinguished()
{}
