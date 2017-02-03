#include "Room.h"
#include "Exit.h"
#include "Entrance.h"
#include "Character.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	string input_buffer;
	bool quit = false;
	//Set up the rooms -- mostly manually right now
	cout << "----------------------------------------------------" << endl;
	cout << "Creating Exit and Entrance rooms" << endl;
	
	Room* exit = new Exit;
	Room* entrance = new Entrance;

	cout << "----------------------------------------------------" << endl;
	cout << "Did their constructors work?" << endl;
	cout << exit->getName() << endl;
	cout << entrance->getName() << endl;
	
	cout << "----------------------------------------------------" << endl;
	cout << "Setting Room Exits" << endl;
	exit->setExits(NULL, NULL, NULL, entrance);
	entrance->setExits(NULL, NULL, exit, NULL);
    
	cout << "----------------------------------------------------" << endl;
	cout << "Did room exits get set correctly?" << endl;
	cout << exit->getWest()->getName() << endl;
	cout << entrance->getEast()->getName() << endl;
	
	cout << "----------------------------------------------------" << endl;
	cout << "Checking both room's isVisited:" << endl;
	cout << std::boolalpha;
	cout << "entrance: " << entrance->getIsVisited() << endl;
	cout << "exit: " << exit->getIsVisited() << endl;
	
	//Set up Character
	cout << "----------------------------------------------------" << endl;
	cout << "Setting up a Character" << endl;
	Character tester;
	
	tester.setName("Justin");
	
	cout << "----------------------------------------------------" << endl;
	cout << "Did character name get set correctly?" << endl;
	cout << tester.getName() << endl;
	
	//Since this is a "New Game", I'll set currentRoom as entrance to start.
	cout << "----------------------------------------------------" << endl;
	cout << "Setting up a Character's first room." << endl;
	cout << "Long Description should display:" << endl;
	tester.enterRoom(entrance);
	
	cout << "----------------------------------------------------" << endl;
	cout << "Did character get put in entrance?" << endl;
	cout << tester.getRoom()->getName() << endl;
	
	cout << "----------------------------------------------------" << endl;
	cout << "Did entrance's isVisited change?" << endl;
	cout << tester.getRoom()->getIsVisited() << endl;
	
	while(quit == false)
	{
		cout << ">";
		cin >> input_buffer;
		if(input_buffer == "quit")
		{
			quit = true;
		}
		else if(input_buffer == "north")
		{
			tester.enterRoom(tester.getRoom()->getNorth());
		}
		else if(input_buffer == "south")
		{
			tester.enterRoom(tester.getRoom()->getSouth());
		}
		else if(input_buffer == "east")
		{
			tester.enterRoom(tester.getRoom()->getEast());
		}
		else if(input_buffer == "west")
		{
			tester.enterRoom(tester.getRoom()->getWest());
		}
		else
		{
			cout << "I don't understand." << endl;
		}
	}
	
	return 0;
}