#include "Room.h"

Room::Room()
{}

Room::~Room()
{}

void Room::addItem(Item item)
{
	items.push_back(item);
}

void Room::removeItem(string item)
{
	for(unsigned i=0; i < items.size(); i++) {
		if(items.at(i).getName() == item)
			items.erase(items.begin() + i);
	} 
}

void Room::showItems()
{
	for (unsigned i = 0; i < items.size(); i++) {
		cout << items.at(i).getName();
		cout << " -- " << items.at(i).getDescription() << endl;
	}
}

bool Room::hasItem(string itemName)
{
	for (unsigned i = 0; i < items.size(); i++) {
		if (items.at(i).getName() == itemName)
			return true;
	}
	return false;
}

Item Room::getItem(string itemName)
{
	for (unsigned i = 0; i < items.size(); i++) {
		if (items.at(i).getName() == itemName)
			return items.at(i);
	}
	// item not found
	Item noItem("noItem");
	return noItem;
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
