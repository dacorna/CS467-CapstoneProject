#include "Maze.h"
#include <limits>

Maze::Maze()
{
	isFinished = false;
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

void Maze::enterMaze()
{
	currentNode = start;
	int choice;
	bool validInput = false;
	cout << "Entering..." << endl;
	usleep(400000);
	cout << "You are now inside the realm of the Avendorian elves. The way behind has shut. Forward lies the only reprieve." << endl;
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

		go(choice);
		if (currentNode->position == 7)
			isFinished = true;
		else
			cout << "Where next? " << endl;

	} while (!isFinished);

	cout << "Congratulations! You have successfully navigated the maze. You've proven yourself a worthy adversary." << endl;
	usleep(400000);
	cout << "The Sword of the Evening appears on the ground before you. " << endl;
	usleep(300000);
	cin.get();
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
	if (!currentNode->position)
		cout << "You fell into a time loop! All the way back to start." << endl;
	else
		cout << "You've reached level " << currentNode->position << " of the maze" << endl;
}
