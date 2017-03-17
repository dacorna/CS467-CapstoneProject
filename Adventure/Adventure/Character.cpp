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
		else if(currentRoom->getIsVisited() == false && (currentRoom->getName() == "Troll Bridge" || currentRoom->getName() == "Cave Guardian's Post"))
			 {
			 
			cout << currentRoom->getName() << endl;
			}
		else
			{
			 
			cout << currentRoom->getShortDescription() << endl;
			}
		if (currentRoom->getName() == "Maze Room") {
			usleep(500000);
			bool skipMaze = false;
			if(!completedMaze) {
				cout << currentRoom->getExploreStory() << endl;
				usleep(500000);
			}
				
			if(completedMaze) {
				cout << "You have already completed the maze..." << endl;
				cout << "Take secret passage below maze? (y/n)" << endl;
				string input;
				cin.clear(); cin.sync();
				cin >> input; 
				trim(input);
				if(input == "y" || input == "yes")
					skipMaze = true;

				cin.clear(); cin.sync();
			}
			if(!skipMaze) {
				Maze maze;
				maze.enterMaze(currentRoom);
				completedMaze = true;
			}
			usleep(750000);
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			if(previousRoom->getName() == "Mine") {
				enterRoom(currentRoom->getNorth());
			}
			else {
				enterRoom(currentRoom->getSouth());
			}
				
		}
		else if (currentRoom->getName() == "Post Maze" && previousRoom->getName() == "Troll Bridge") {	
			cout << endl << "The Avendorians built a secret passage to be seen only by those who have completed the maze" << endl;
			cout << "The passage appears to go below the maze" << endl;
			usleep(750000);
			cout << endl << "Take secret passage? (y/n)" << endl; 
			string input;
			bool skipMaze = false;
			cin.clear(); cin.sync();
			cin >> input;
			trim(input);
			if(input == "y" || input == "yes")
				skipMaze = true;
			
			cin.clear(); cin.sync();
			if(!skipMaze) {
				int finishedMaze = 0; 
				Maze mazeR;
			//cout << "Entering from north!" << endl;	// entering from north - reverse maze
				mazeR.reverseMaze();
				finishedMaze = mazeR.enterMaze(currentRoom);
				if(finishedMaze) {
					completedMaze = true;
					previousRoom = currentRoom->getSouth();
					currentRoom = currentRoom->getSouth()->getSouth(); // we want to get back to the Mines 
				}
				else {
					enterRoom(currentRoom->getNorth());
				}
			}
			if(skipMaze) {
				previousRoom = currentRoom->getSouth();
				currentRoom = currentRoom->getSouth()->getSouth(); // back to the Mine
			}
			cout << endl << currentRoom->getShortDescription() << endl;
			usleep(750000);
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
		else if (currentRoom->getName() == "Dragon's Lair") {
			if(!completedDragon) {
				// create Dragon object
				Dragon d;
				d.setItemStatus(bag); 
				string encounterType;
				cout << "What do you do?" << endl;
				cout << "a) Speak to dragon" << endl;
				cout << "b) Fight dragon" << endl;
				cout << "c) Explore a bit" << endl;
				cin.sync();
				getline(cin,encounterType);
				trim(encounterType);
				if(encounterType == "Speak" || encounterType == "speak") encounterType = "a";
				else if(encounterType == "Fight" || encounterType == "fight") encounterType = "b";
				else if(encounterType == "Explore" || encounterType == "explore") encounterType = "c";
 				if(encounterType != "a" && encounterType != "b" && encounterType != "c")
					encounterType = "b";
				bool result;
				result = d.encounter(encounterType,bag);
				usleep(1000000);
				cout << endl;
				if(result) {
					// enter the Treasure Room
					cout << endl << "You move forward through the glowing doors..." << endl;
					usleep(750000);  
					completedDragon = true; 
					enterRoom(currentRoom->getWest());
				}
				else {
					cout << endl << "You are defeated..." << endl << endl;
					cout << "Press [Enter] to continue" << endl;
					cin.get();
					enterRoom(currentRoom->getSouth());
				}
			}
			else {
				cout << "The dragon has left its lair. You are safe to continue" << endl;   
			}
		}
		
	}	

	else
		 {
		cout << "You can't go that way!" << endl;
		}
}

int Character::fightDragon(Bag bag)
{
	return 0;
}

int Character::speakToDragon(Bag bag)
{
	return 0;
}

int Character::exploreDragon(Bag bag, string room)
{
	return 0;
}
