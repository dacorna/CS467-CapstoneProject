#include "Character.h"

Character::Character()
{
	isAlive = true;
	name = "Player1";
	description = "Cave dweller";
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
	 
	if (roomIn != NULL)
		{
		previousRoom = currentRoom;
		currentRoom = roomIn;
		if (currentRoom->getIsVisited() == false)
			 {
			currentRoom->setIsVisited();
			cout << currentRoom->getLongDescription() << endl;
			}
		else
			 {
			 
			cout << currentRoom->getShortDescription() << endl;
			}
		if (currentRoom->getName() == "Maze Room") {
			usleep(200000);
			cout << currentRoom->getExploreStory() << endl;
			usleep(200000);
			Maze maze;
			maze.enterMaze();
		}
		}

	else
		 {
		cout << "You can't go that way!" << endl;
		}
	}
