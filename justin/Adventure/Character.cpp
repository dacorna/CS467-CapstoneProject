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
		if (currentRoom->getIsVisited() == false && currentRoom->getName() != "Troll Bridge" && currentRoom->getName() != "Cave Guardian's Post")
			 {
			currentRoom->setIsVisited();
			//cout << currentRoom->getLongDescription() << endl;
			currentRoom->printLongDescAndItems();
			}
		else// if(currentRoom->getIsVisited() == true && currentRoom->getName() != "Troll Bridge" && currentRoom->getName() != "Cave Guardian's Post")
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
		else if(currentRoom->getName() == "Troll Bridge" && !completedTroll){
			usleep(200000);
			string choice;
			bool validChoice = false;
			bool alive;
			cout << currentRoom->getExploreStory() << endl;
			do{
				cout << "1) Face the troll \t 2) Go back" << endl;
				cin.sync();
				getline(cin,choice);
			
				if(choice == "1"){
					validChoice = true;
					usleep(200000);
					Troll troll;
					troll.setWeaponStatus(bag);
					alive = troll.encounterTroll();
					if(!alive)
					{
						isAlive = false;
					}
					else
					{
						completedTroll = true;
					}
				}
				else if(choice == "2")
				{
					enterRoom(currentRoom->getSouth());
					validChoice = true;
				}
				else
				{
					std::system("clear");
					cout << "Please choose a valid response" << endl;
				}
			} while(validChoice == false);
		}
		else if(currentRoom->getName() == "Cave Guardian's Post" && !completedGuardian){
			usleep(200000);
			string choice;
			bool validChoice = false;
			bool alive;
			cout << currentRoom->getExploreStory() << endl;
			do{
				cout << "1) Fight the guardian \t 2) Go back" << endl;
				cin.sync();
				getline(cin,choice);
			
				if(choice == "1"){
					validChoice = true;
					usleep(200000);
					Guardian guardian;
					guardian.setWeaponStatus(bag);
					alive = guardian.encounterGuardian();
					if(!alive)
					{
						isAlive = false;
					}
					else
					{
						completedGuardian = true;
					}
				}
				else if(choice == "2")
				{
					enterRoom(currentRoom->getSouth());
					validChoice = true;
				}
				else
				{
					std::system("clear");
					cout << "Please choose a valid response" << endl;
				}
			} while(validChoice == false);
		}
	}	

	else
		 {
		cout << "You can't go that way!" << endl;
		}
}
