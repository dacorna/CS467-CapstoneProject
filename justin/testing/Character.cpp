#include "Character.h"

Character::Character()
{
	
}

Character::~Character()
{

}

void Character::setName(string nameIn)
{
	name = nameIn;
}

void Character::enterRoom(Room* roomIn)
{
	if(roomIn != NULL)
	{
		previousRoom = currentRoom;
		currentRoom = roomIn;
		if(currentRoom->getIsVisited() == false)
		{
			currentRoom->setIsVisited();
			cout << currentRoom->getLongDescription() << endl;
		}
		else
		{
			cout << currentRoom->getShortDescription() << endl;
		}
	}
	else
	{
		cout << "You can't go that way!" << endl;
	}
}