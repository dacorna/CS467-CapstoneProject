#include <iostream>
#include "Game.h"

int main()
{
	Game newGame;
	string gameName;
	cout << "               ______                              " << endl;
	cout << "              / ____/___ __   _____                " << endl;
	cout << "             / /   / __ `/ | / / _ \\               " << endl;
	cout << "            / /___/ /_/ /| |/ /  __/               " << endl;
	cout << "    ___     \\____/\\__,_/ |___/\\____                " << endl;
	cout << "   /   | ____/ /   _____  ____  / /___  __________ " << endl;
	cout << "  / /| |/ __  / | / / _ \\/ __ \\/ __/ / / / ___/ _ \\" << endl;
	cout << " / ___ / /_/ /| |/ /  __/ / / / /_/ /_/ / /  /  __/" << endl;
	cout << "/_/  |_\\__,_/ |___/\\___/_/ /_/\\__/\\__,_/_/   \\___/ " << endl;

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
		gameName = newGame.loadSavedGameList();	// this function will get list of all saved games, have user pick one, and then load that game instance
		newGame.loadGameFiles(gameName);
		newGame.startGame("load");
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