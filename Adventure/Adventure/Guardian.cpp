#include "Guardian.h"



Guardian::Guardian()
{
	hasWeapon = false;
}

Guardian::~Guardian()
{
	
}

void Guardian::setWeaponStatus(Bag bagIn)
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

bool Guardian::encounterGuardian()
{
	string choice;
	int score = 0;
	bool validChoice = false;
	bool result;
	//std::system("clear");
	//Two Paths, one is if you have weapons, the other is if you don'table
	if(hasWeapon)
	{
		
		cout << "You choose to fight the guardian. You pull out a weapon and he charges!" << endl;
		usleep(200000);
		do{	
			cout << "He attacks and you dodge. Where to counter-attack?" << endl << "1) Leg \t 2) Torso \t 3) Arm" << endl;
			cin.sync();
			getline(cin,choice);
			if(choice == "1")
			{
				validChoice = true;
				score += 5;
			}
			else if(choice == "2")
			{
				validChoice = true;
				score += 3;
			}
			else if(choice == "3")
			{
				validChoice = true;
				score += 5;
			}
		} while(validChoice == false);
		usleep(200000);
		
		
		validChoice = false;
		std::system("clear");
		cout << "He recovers from your attack, squares up, and charges again!" << endl;
		usleep(200000);
		do{	
			cout << "This attack is more vicious, but you manage to dodge at the last moment! Where to counter-attack?" << endl << "1) Leg \t 2) Torso \t 3) Arm" << endl;
			cin.sync();
			getline(cin,choice);
			if(choice == "1")
			{
				validChoice = true;
				score += 5;
			}
			else if(choice == "2")
			{
				validChoice = true;
				score += 3;
			}
			else if(choice == "3")
			{
				validChoice = true;
				score += 5;
			}
		} while(validChoice == false);
		usleep(200000);
		
		validChoice = false;
		std::system("clear");
		cout << "He recovers, again, from your attack, squares up, and charges!" << endl;
		usleep(200000);
		do{	
			cout << "This attack is violent and reckless. You dodge easliy! Is that an opening?" << endl <<  "Where to counter-attack?" << endl << "1) Leg \t 2) Torso \t 3) Arm \t 4) Neck" << endl;
			cin.sync();
			getline(cin,choice);
			if(choice == "1")
			{
				validChoice = true;
				score += 5;
			}
			else if(choice == "2")
			{
				validChoice = true;
				score += 3;
			}
			else if(choice == "3")
			{
				validChoice = true;
				score += 5;
			}
			else if(choice == "4")
			{
				validChoice = true;
				score += 10;
			}
		} while(validChoice == false);
		usleep(200000);
		
		if(score >= 15)
		{
			cout << "Your final attack has finally broken through the guardian's defense! He falls to the ground with a resounding THUD." << endl;
			usleep(300000);	
			cout << "Something falls from the guardian's pocket. A glowing, mysterious gold piece of some sort..." << endl;
			usleep(300000);
			result = true;
		}
		else
		{
			cout << "You have tired yourself out and the guardian takes a final swing, connecting, and ending your life!" << endl;
			result = false;
		}
		
		
		return result;
	}
	else
	{
		cout << "You attempt to fight the guardian, but being weaponless, he easily defeats you. He stands over your dying body." << endl;
		return false;
	}
}	
