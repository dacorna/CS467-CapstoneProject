#include "Maze.h"
#include <limits>
#include <stdlib.h>

Maze::Maze()
{
	isFinished = false;
	mazeReversed = false;
	start = new Node;
	end = new Node;
	one = new Node;
	two = new Node;
	three = new Node;
	four = new Node;
	five = new Node;
	six = new Node;
	start->north = one;
	start->south = start;
	start->east = start;
	start->west = start;
	start->position = 0;
	end->south = six;
	end->north = end;
	end->east = end;
	end->west = end;
	end->position = 7;
	one->east = two;
	one->south = start;
	one->west = start;
	one->north = start;
	one->position = 1;
	two->west = one;
	two->north = three;
	two->east = start;
	two->south = start;
	two->position = 2;
	three->west = four;
	three->north = start;
	three->east = start;
	three->south = two;
	three->position = 3;
	four->east = three;
	four->north = five;
	four->south = one;
	four->west = start;
	four->position = 4;
	five->south = four;
	five->east = start;
	five->north = start;
	five->west = six;
	five->position = 5;
	six->east = five;
	six->south = start;
	six->west = start;
	six->north = end;
	six->position = 6;
}

Maze::~Maze()
{
	delete start;
	delete end;
	delete one;
	delete two;
	delete three;
	delete four;
	delete five;
	delete six;
}

void Maze::reverseMaze()
{
	Node* temp;
	temp = start;
	start = end;
	end = temp;
	temp = one;
	one = six;
	six = temp;
	temp = two;
	two = five;
	five = temp;
	temp = three;
	three = four;
	four = temp;
	one->west = start;
	one->south = start;
	two->east = start;
	two->north = start;
	three->west = start;
	three->south = six;
	four->north = start;
	four->east = start;
	five->east = start;
	five->south = start;
	six->west = start;
	six->north = start;
	mazeReversed = true;
}	

void Maze::setClues()
{
	start->clue = "clue:north";
	end->clue = "clue:finished. Pick up the sword.";
	one->clue = "clue:east";
	two->clue = "clue:north";
	three->clue = "clue:west";
	four->clue = "clue:north";
	five->clue = "clue:west";
	six->clue = "clue:north";
}

int Maze::enterMaze(Room* room)
{
	isFinished = false;
	setClues();
	currentNode = start;
	int choice;
	bool validInput = false;
	cout << "Entering..." << endl;
	usleep(400000);
	if(mazeReversed) {
		string input;
		cout << "You've entered the maze from the north. Traverse backwards to get back to the Mines, or get out while you can" << endl;
		cout << "Enter 1 to continue through the maze, anything else to go back" << endl;
		cin.sync();
		getline(cin,input);
		if(input != "1") {
			usleep(200000);
			cout << "You got out before the door shut!" << endl;
			return 0;
		}
	}
	else {  
		cout << "You are now inside the realm of the Avendorian elves. The way behind has shut. Forward lies the only reprieve." << endl;
		cout << endl << start->clue << endl;
	}
	cout << endl << "Which way do you go? " << endl;
	do {
		cout << "1) North	2) East		3) South	4) West" << endl;
		cout << ">  ";
		cin.sync();
		do{
			cin.sync();
			cin >> choice;
			if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
				validInput = true;
			else {
				validInput = false;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "The ancient maze only recognizes 1, 2, 3, or 4" << endl;
				cout << "<  ";
			}
		} while (!validInput);

		std::system("clear");
		go(choice);
		if(!mazeReversed)
			if (currentNode->position == 7)
				isFinished = true;
			else
				cout << "Where next? " << endl;
		else
			if(currentNode->position == 0)
				isFinished = true;
			else
				cout << "Where next? " << endl;

		if(!mazeReversed)
			cout << endl << currentNode->clue << endl;

	} while (!isFinished);

	cout << "Congratulations! You have successfully navigated the maze. You've proven yourself a worthy adversary." << endl;
	usleep(400000);
	if(room->hasItem("SWORD")) {
		room->getItem("SWORD")->setCanPickUp(true);
		cout << "The Sword of the Evening appears on the ground before you. " << endl;
	}
	usleep(300000);
	cin.get();
	return 1;
}

void Maze::go(int direction)
{
	
	switch (direction)
	{
	case 1:
		currentNode = currentNode->north;
		break;
	case 2:
		currentNode = currentNode->east;
		break;
	case 3:
		currentNode = currentNode->south;
		break;
	case 4:
		currentNode = currentNode->west;
		break;
	default:
		cout << "You were thwarted. Try again" << endl;

	}
	if(!mazeReversed)
		if (!currentNode->position)
			cout << "You fell into a time loop! All the way back to start." << endl;
		else
			cout << "You've reached level " << currentNode->position << " of the maze" << endl;
	else
		if(currentNode->position == 7)
			cout << "Fell into time loop! Back to the start." << endl;
		else
			cout << "You've reached level " << currentNode->position << " of the maze" << endl; 
}
