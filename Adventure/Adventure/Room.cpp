#include "Room.h"

Room::Room()
{}

Room::~Room()
{}

void Room::addItem(Item item)
{
	items.push_back(item);
}

void Room::showItems()
{
	for (unsigned i = 0; i < items.size(); i++) {
		cout << items.at(i).getName();
		cout << " -- " << items.at(i).getDescription() << endl;
	}
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
