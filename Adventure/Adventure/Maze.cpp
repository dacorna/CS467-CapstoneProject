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
	seven = new Node;
	eight = new Node;
	start->north = one;
	start->south = start;
	start->east = start;
	start->west = start;
	start->position = 0;
	end->south = eight;
	end->north = end;
	end->east = end;
	end->west = end;
	end->position = 9;
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
	six->north = seven;
	six->position = 6;
	seven->south = six;
	seven->north = eight;
	seven->west = start;
	seven->east = start;
	seven->position = 7;
	eight->south = seven;
	eight->west = end;
	eight->north = start;
	eight->east = start;
	eight->position = 8;
	xLoc = 3;
	yLoc = 5; 
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
	delete seven;
	delete eight;
}

void Maze::displayMaze(bool reversed)
{
	char grid[6][6];
	for(int i=0; i<6; i++) {
	    for(int j=0; j<6; j++) {
		grid[i][j] = 'O';	
	    }
	}
	grid[yLoc][xLoc] = '*';
	if(!reversed)
		grid[0][1] = 'X';
	else
		grid[5][3] = 'X';

		
	for(int i=0; i<6; i++) {
	   cout << endl;
	  	   
	   for(int j=0; j<6; j++) {
		cout << grid[i][j] << "  ";
	   }
	}
}
void Maze::reverseMaze()
{
	xLoc = 1;
	yLoc = 0;
	Node* temp;
	temp = start;
	start = end;
	end = temp;
	temp = one;
	one = eight;
	eight = temp;
	temp = two;
	two = seven;
	seven = temp;
	temp = three;
	three = six;
	six = temp;
	temp = four;
	four = five;
	five = temp;
	start->east = one; start->south = start; start->west = start; start->north = start;
	one->west = start; one->east = start;
	one->south = two; one->north = start;
	two->east = start; two->west = start;
	two->north = one; two->south = three;
	three->west = start; three->east = four;
	three->south = start; three->north = two;
	four->north = start; four->south = five;
	four->east = start; four->west = three;
	five->east = six; five->west = start; 
	five->south = start; five->north = four;
	six->west = five; six->east = start; 
	six->north = start; six->south = seven;
	seven->west = eight; seven->east = start; 
	seven->south = start; seven->north = six;
	eight->north = five; eight->south = end;
	eight->west = start; eight->east = seven; 
	end->north = eight; end->west = end; end->east = end; end->south = end;
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
	seven->clue = "north";
	eight->clue = "west";
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
	displayMaze(mazeReversed);
	cout << endl << endl << "X marks the spot " << endl;
	cout << endl << "Which way do you go? " << endl;
	cout << "1 = North, 2 = South, 3 = East, 4 = West" << endl;
	do {
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
				cout << ">  ";
			}
						
		} while (!validInput);
					
		std::system("clear");
				
		go(choice);
		displayMaze(mazeReversed);
		
		if(!mazeReversed)
			if (currentNode->position == 9)
				isFinished = true;
			else
				cout << endl << "Where next? " << endl;
		else
			if(currentNode->position == 0)
				isFinished = true;
			else
				cout << endl << "Where next? " << endl;

		if(!mazeReversed)
			cout << endl << currentNode->clue << endl;

	} while (!isFinished);

	cout << "Congratulations! You have successfully navigated the maze. You've proven yourself a worthy adversary." << endl;
	usleep(400000);
	if(room->getNorth()->hasItem("SWORD")) {
		room->getNorth()->getItem("SWORD")->setCanPickUp(true);
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
		yLoc--;
		break;
	case 2:
		currentNode = currentNode->south;
		yLoc++;
		break;
	case 3:
		currentNode = currentNode->east;
		xLoc++;
		break;
	case 4:
		currentNode = currentNode->west;
		xLoc--;
		break;
	default:
		cout << "You were thwarted. Try again" << endl;

	}
	if(!mazeReversed)
		if (!currentNode->position) {
			xLoc = 3;
			yLoc = 5;
			cout << "Fell into a time loop! Back to the start." << endl;
		}
		else
			cout << "You've reached level " << currentNode->position << " of the maze" << endl;
	else
		if(currentNode->position == 9) {
			xLoc = 1;
			yLoc = 0;
			cout << "Fell into a time loop! Back to the start." << endl;
		}
		else
			cout << "You've reached level " << currentNode->position << " of the maze" << endl; 
}
