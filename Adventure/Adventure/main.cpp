#include <iostream>
#include "Game.h"

int main()
{
	Game newGame;
	cout << "Main Menu" << endl << endl;
	cout << "1. Start a new game" << endl;
	cout << "2. Continue saved game" << endl;
	cout << "3. Exit" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << endl << "Starting new game ... " << endl;
		newGame.startGame("new");
		break;
	case 2:
		// loadSavedGameList();	// this function will get list of all saved games, have user pick one, and then load that game instance
		break;
	case 3:
		cout << endl << "GOODBYE!" << endl;
		return 0;
	default:
		cout << endl << "Invalid Choice. Goodbye!" << endl;
		return 0;
	}
	

	cin.get();
	return 0;
}