#include "Character.h"

Character::Character()
{
	isAlive = true;
	name = "Player1";
	description = "Cave dweller";
	completedMaze = false;
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
			//cout << currentRoom->getLongDescription() << endl;
			currentRoom->printLongDescAndItems();
			}
		else
			 {
			 
			cout << currentRoom->getShortDescription() << endl;
			}
		if (currentRoom->getName() == "Maze Room") {
			usleep(200000);
			if(!completedMaze) {
				cout << currentRoom->getExploreStory() << endl;
				usleep(200000);
			}
			Maze maze;
			maze.enterMaze(currentRoom);
			completedMaze = true;
			previousRoom = currentRoom;
			currentRoom = currentRoom->getNorth();
		}
		else if (currentRoom->getName() == "Post Maze" && previousRoom->getName() == "Troll Bridge") {	
			int finishedMaze = 0; 
			Maze mazeR;
			cout << "Entering from north!" << endl;	// entering from north - reverse maze
			mazeR.reverseMaze();
			finishedMaze = mazeR.enterMaze(currentRoom);
			if(finishedMaze) {
				completedMaze = true;
				previousRoom = currentRoom;
				currentRoom = currentRoom->getSouth();
			}
			else {
				previousRoom = currentRoom;
				currentRoom = currentRoom->getNorth();
			}
		}
	}	

	else
		 {
		cout << "You can't go that way!" << endl;
		}
}
