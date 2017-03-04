#include "Troll.h"



Troll::Troll()
{
	hasWeapon = false;
}

Troll::~Troll()
{
	
}

void Troll::setWeaponStatus(Bag bagIn)
{
	if(bagIn.hasItem("SWORD") || bagIn.hasItem("PICKAXE"))
	{
		hasWeapon = true;
	}
	else
	{
		hasWeapon = false;
	}
}

bool Troll::encounterTroll()
{
	string choice;
	bool validChoice = false;
	bool result;
	//std::system("clear");
	//Two Paths, one is if you have weapons, the other is if you don'table
	if(hasWeapon)
	{
		do{
			cout << "You have two choices: " << endl << "1) Fight the troll \t 2) Reason with the troll" << endl;
			cin.sync();
			getline(cin,choice);
			if(choice == "1")
			{
				validChoice = true;
				result = fightTroll();
			}
			else if(choice == "2")
			{
				validChoice = true;
				result = talkTroll();
			}
		} while(validChoice == false);
		return result;
	}
	else
	{
		cout << "Being weaponless, the only way to pass is to reason with the troll" << endl;
		result = talkTroll();
		return result;
	}
}	

bool Troll::fightTroll()
{
	srand(time(NULL));
	std::system("clear");
	int combatOutcome = rand() % 10 + 1;
	cout << "The troll explains that he is a fearsome foe. The battle begins!!!" << endl; 
	usleep(200000);
	cout << "He charges at you..." << endl;
	usleep(200000);
	if(combatOutcome <= 5)
	{
		cout << "and connects!" << endl;
		usleep(200000);
		cout << "You have been defeated. Your lifeblood drains from your body as the troll stands victoriously over your body" << endl;
		return false;
	}
	else
	{
		cout << "and you dodge!" << endl;
		usleep(200000);
		cout << "Strafing behind the troll you swing your weapon and end his life! Victory!" << endl;
		cin.get();
		std::system("clear");
		return true;
	}
	

}

bool Troll::talkTroll()
{
	std::system("clear");
	string choice;
	bool validChoice = false;
	cout << "The troll explains to you the ancient rule of Troll Bridges:" << endl 
	<< "\"In order to pass, you must answer 3 riddles correctly. If you fail, I get to kill you.\"" << endl << endl;
	
	do{
		cout << "Here is your first riddle: " << endl << "What belongs to you but others use it more than you do?" << endl
		<< "1) Your Hammer \t 2) Your Name \t 3) Your shoes" << endl;
		cin.sync();
		getline(cin,choice);
		if(choice == "1" || choice == "3")
		{
			cout << "You've chosen incorrectly. Now you die." << endl;
			validChoice = true;
			return false;
		}
		else if(choice == "2")
		{
			cout << "You've chosen wisely." << endl;
			validChoice = true;
			//Now we can move on to question 2.
		}
		else
		{
			std::system("clear");
			cout << "Please choose a valid response" << endl;
		}
	} while(validChoice == false); 
	
	validChoice = false;
	do{
		cout << "Here is your second riddle: " << endl << "What is harder to catch the faster you run?" << endl
		<< "1) Your Breath \t 2) The Wind \t 3) True love" << endl;
		cin.sync();
		getline(cin,choice);
		if(choice == "2" || choice == "3")
		{
			cout << "You've chosen incorrectly. Now you die." << endl;
			validChoice = true;
			return false;
		}
		else if(choice == "1")
		{
			cout << "You've chosen wisely." << endl;
			validChoice = true;
			//Now we can move on to question 3.
		}
		else
		{
			std::system("clear");
			cout << "Please choose a valid response" << endl;
		}
	} while(validChoice == false); 
	
	validChoice = false;
	do{
		cout << "Here is your third and final riddle: " << endl << "What is easy to get into, but hard to get out of?" << endl
		<< "1) Jail \t 2) College \t 3) Trouble" << endl;
		cin.sync();
		getline(cin,choice);
		if(choice == "1" || choice == "2")
		{
			cout << "You've chosen incorrectly. Now you die." << endl;
			validChoice = true;
			return false;
		}
		else if(choice == "3")
		{
			cout << "You've chosen wisely. All three riddles have been answered correctly. You may pass. I will bother you no longer." << endl;
			validChoice = true;
			cin.get();
			std::system("clear");
			return true;
		}
		else
		{
			std::system("clear");
			cout << "Please choose a valid response" << endl;
		}
	} while(validChoice == false); 
}