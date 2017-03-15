#include "Dragon.h"

Dragon::Dragon()
{
	hasSpokenToDragon = false;
	isGuardingTreasure = true;
	isGlowing = false;
	isGreedy = true;
	opponentHasSword = false;
	opponentHasGold = false;
	opponentHasWater = false;
	opponentHasPickaxe = false;
}

Dragon::~Dragon()
{

}

void Dragon::setItemStatus(Bag bag)
{
	if(bag.hasItem("SWORD"))
		opponentHasSword = true;
	if(bag.hasItem("GOLDPIECE"))
		opponentHasGold = true;
	if(bag.hasItem("WATERSKIN"))  // if water is filled 
		if(bag.getItem("WATERSKIN")->isObjectiveCompleted())
			opponentHasWater = true;
	if(bag.hasItem("PICKAXE"))
		opponentHasPickaxe = true;		  		
}

bool Dragon::encounter(string type, Bag bag)
{
	bool result;
	if(type == "a") {
		result = speakToDragon(bag);	
	}
	else if(type == "b") {
		result = fightDragon(bag);
	}
	else if(type == "c") {
		cout << "You tiptoe quietly around the room, trying not to wake the fiery beast..." << endl;
		usleep(250000);
		cout << "It is impossible but to notice the charred remains of some former occupants." << endl;
		usleep(250000);
		cout << "Treasure pieces are scattered about, but become more prevalent on the westerly edge of the room, near where the dragon sleeps.\n It looks as though a door of sorts lies beneath the monster" << endl;
		usleep(250000);
		cout << "You recall old stories which say the dragon cannot be defeated with any solid objects of mankind. Greed may be its greatest weakness" << endl;
		usleep(350000);
		cout << "Something stirs in the darkness ..." << endl;
		usleep(500000);
		cout << "..." << endl;
		usleep(500000);
		cout << "The dragon wakes in a confused rage!" << endl;     
		cout << "Cannot escape now" << endl;
		cout << "To fight it or to reason with it?" << endl;  
		usleep(500000);
		string choice;
		cout << "1) Fight" << endl;
		cout << "2) Reason" << endl;
		cin >> choice;
		trim(choice);
		if(choice == "1")
			result = fightDragon(bag);
		else 
			result = speakToDragon(bag);
	}	
	else {
		cout << "I don't understand what you want, which is annoying, so you've woken the dragon. Hope you have your wits about you!" << endl;
		result = fightDragon(bag);  
	}
	return result;
}

int Dragon::checkInput(string input)
{
	if(input == "1") return 1;
	else if(input == "2") return 2;
	else if(input == "3") return 3;
	else if(input == "4") return 4;
	else if(input == "5") return 5;
	else if(input == "6") return 6;
	else if(input == "7") return 7;
	else return 0;  	
}

bool Dragon::fightDragon(Bag bag)
{
	srand(time(NULL));
	std::system("clear");
	string userInput;
	int healthPts = 100;
	int dragonPts = 100;
	int outcome = 0;
	while(healthPts > 0 && dragonPts > 0) {
		outcome = rand() % 25+1;
		cout << endl;
		if(outcome < 15) {
			isGlowing = true;
			cout << "The dragon is glowing!" << endl;
			usleep(750000);
			cout << "It breathes a stream of fire in your direction..." << endl; 
			usleep(500000);
			if(outcome % 3 == 0) {
				healthPts = 0; // struck by the flame, automatic death
				cout << "You dive but too late. The dragonfire engulfs you. This adventure has come to an unfortunate end." << endl;
				return false;
			}
			else {
				cout << "You dive out of the way! Dragon is susceptible while it glows..." << endl;
				usleep(500000);
			}
		}
		else {
			isGlowing = false;
			cout << "The dragon attacks!" << endl;
			usleep(250000);
			cout << "You are hit..." << endl;
			healthPts -= 25;
			if(healthPts <= 0) {
				cout << "Your health has diminished. The dragon will claim your bones for his own" << endl;
				return false;
			}
			else {
				cout << "But there is life left in you!" << endl;
				cout << "Your health is down to " << healthPts << "%" << endl;
			}
		}
		// Player attacks back
		cout << "The dragon is slowly recovering its energy...this is your chance!\n" << endl;
		usleep(550000);
		cout << "What's your move?" << endl;
		cout << endl << "> ";
		cin.clear();
		cin.sync();	//discard input buffer
		getline(cin,userInput);
		std::system("clear");	
		
		cout << "*****************************************************" << endl;
		cout << "	Player Health:  " << healthPts << " percent" << endl;
		cout << "	Dragon Health:  " << dragonPts << " percent" << endl;
		cout << "*****************************************************" << endl;
		cout << endl;
		
		p = parse(userInput);
		// trim leading or trailing white spaces
		trim(p.command);
		trim(p.firstObject);
		trim(p.secondObject);
		trim(userInput);
				
		/*
		else if(userInput == "run" || userInput == "flee" || userInput == "leave" || userInput == "escape")
			p.command = "RUN";
		else if(userInput == "attack" || userInput == "fight" || userInput == "battle")
			p.command = "ATTACK"
		*/

		if(p.command == "ATTACK") {
			cout << "With what? " << endl;
			bag.displayBag();
			cout << endl << "> ";
			cin.clear();
			cin.sync();
			getline(cin,userInput);
			trim(userInput);
			// check if user entered a number for the item
			int check = checkInput(userInput);
			if(check) {
				Item *itm = bag.getItemAtIndex(check-1);
				if(itm != NULL)
					p.firstObject = itm->getName();
			}
			else p.firstObject = userInput;
			p.command = "USE";
		}
		
		else if(p.command == "POUR" && p.firstObject == "WATERSKIN") p.command = "USE";

		boost::to_upper(p.firstObject);
		outcome = rand() % 10+1;
		cout << endl << "p.command = " << p.command << endl;
		cout << "p.firstObject = " << p.firstObject << endl << endl;
		if(p.command == "USE" || p.command == "GIVE") {
			if(p.firstObject == "SWORD") {
				if(opponentHasSword) {
					cout << "You attack with the Sword of the Evening!" << endl;
					usleep(250000);
					if(outcome > 3) {
					dragonPts -= 10;
					cout << "A clean strike! But the dragon's skin is legendary. It has little effect." << endl;
					}
					else cout << "The dragon evades your strike!" << endl;
				}
				else cout << "You don't have a sword!" << endl;

				usleep(1000000);
			}
			else if(p.firstObject == "WATER" || p.firstObject == "WATERSKIN") {
				if(opponentHasWater) {
					if(isGlowing) {
						usleep(550000);
						cout << "You've struck the dragon at its most vulnerable!" << endl;
						cout << "This water comes from the Falls of Elenior. It's magic has put the dragon's fire out for good.\n" << endl;
						usleep(1000000);
						cout << "DRAGON: 'I know when I am defeated. I take my leave of this place now...Congratulations..."; 
						usleep(550000); 
						cout << "\nThe treasure is yours' " << endl;
						return true;
					}
					else {
						usleep(550000);
						cout << "The dragon's flame is protected but the water's magic still has an effect" << endl;
						dragonPts -= 34;
						cout << "The great beast's resolve is weakened..." << endl;
						if(dragonPts <= 0) {
							usleep(750000);
							cout << endl << "DRAGON: 'I have had enough. You may pass.'" << endl;
							cout << "The dragon returns underground to its slumber\n" << endl;
							return true;
						}
						usleep(550000);
					}
				}
				else cout << "You don't have any water! Try filling up at the falls..." << endl;

			}
			else if(p.firstObject == "PICKAXE" || p.firstObject == "AXE") {
				cout << "The pickaxe has no effect against the dragon's scales...you've wasted a chance." << endl;
			}
			else if(p.firstObject == "GOLD" || p.firstObject == "GOLDPIECE") {
				cout << endl << "DRAGON: 'What's this? You're offering me gold?'" << endl;
				cout << "The dragon inspects the gold piece...." << endl;
				usleep(750000);
				cout << "DRAGON: 'I lost this particular treasure many ages ago...It is very precious to me.\nContrary to popular belief, I am not entirely unreasonable. You may pass to the next room...\nbut do not return.'" << endl;
				usleep(750000);
				return true;
			}
			else cout << "That has no effect here!" << endl;
		}
		else if(p.command == "RUN")
			cout << "Can't escape now!" << endl;
		
		else if(p.command == "TALK") {
			if(!hasSpokenToDragon) {
			    bool speakingResult = speakToDragon(bag);
			    usleep(750000);	
			    if(speakingResult)
				return true;	// good things for player
						
			    else return false;	// bad things for player
			}
			else cout << "The dragon will not speak with you again!" << endl;
		}
		else cout << "I don't know what that means!" << endl;
			
	}
	if(healthPts <= 0) {
		cout << "Your health is diminished. You faint..." << endl;
		usleep(1000000);
		return false;
	}
	if(dragonPts <= 0) {
		cout << "The dragon has had enough. It goes back underground to its slumber" << endl;
		usleep(1000000);
		return true;
	}	
}

bool Dragon::speakToDragon(Bag bag)
{
	bool result;
	hasSpokenToDragon = true;	
	cout << "DRAGON: 'You dare enter my Lair? I hope you do not value your life dearly...\n";
	cout << " for it is no longer in your hands'" << endl;
	usleep(250000);
	cout << "What do you say to the dragon?" << endl;
	cout << "a) Let's play a game" << endl;
	cout << "b) I have something for you" << endl;
	cout << "c) You have an ugly face" << endl;
	cout << "d) Perhaps not, winged snake...but yours is (draws sword)" << endl;
	char choice;
	cout << "> ";
	cin.sync();
	cin >> choice; 
	if(choice == 'a') {
		result = playGame();
	}
	else if(choice == 'b') {
		result = giveGift(bag);
	}
	else if(choice == 'c') {
		// player dies
		result = false; 	
	}
	else {
		result = fightDragon(bag);
	}    	
	return result;
}

bool Dragon::playGame()
{
	return true;
}

bool Dragon::giveGift(Bag bag)
{
	bool result;
	cout << "DRAGON: 'Is that so? What is it you have for me, then?'" << endl;
	cout << "(You show the dragon your bag)" << endl;
	bag.displayBag();
	if(opponentHasGold) {
		cout << "The dragon's eyes begin to glow at spotting something inside" << endl;
	}
	int count = 0;
	usleep(500000);
	cout << "DRAGON: 'And which is the item you are offering me?'" << endl;  
	while(count < 2) {
	cout << "> ";
	cin.sync();
	cin.clear();
	cin.ignore(INT_MAX);
	string itemChoice;
	getline(cin,itemChoice);
	trim(itemChoice);
	p = parse(itemChoice);
	trim(p.command);
	
	if(p.command == "GOLDPIECE") {
	    if(opponentHasGold) {
		result = true;
		cout << "You present the dragon with the gold piece you obtained earlier." << endl;
		usleep(350000);
		cout << "DRAGON: (inspecting the gold)..."; usleep(350000);
		cout << " 'I lost this particular treasure many ages ago...It is very precious to me." << endl;
		cout << " Contrary to popular belief, I am not entirely unreasonable. You may pass to the next room";
		usleep(450000);
		cout << "...but do not return'" << endl;
		count = 2;
	    }
	    else {
		cout << "You don't have any gold to give! Uh oh..." << endl;
		usleep(350000);
		cout << "The dragon sees that you have played it false." << endl;
		usleep(250000);
		cout << "It begins to glow bright! In a fit of rage it breathes its fire" << endl;
		usleep(250000);
		cout << "Your ashes will lie for eternity amongst the others who have played false the dragon." << endl; 	
		result = false;
		count = 2;
     	    }
	}
	else {
		cout << "DRAGON: 'You disappoint me, dead one. What interest would I have in such a thing?'" << endl;
		if(count < 1) 
			cout << "What else do you offer me? Choose very carefully this time..." << endl; 
		else {
			usleep(250000);
			cout << "The dragon grows angry...it will accept no more gift offers." << endl;
			usleep(250000);
			result = fightDragon(bag);
		}
	 }
	count++;
       }
	return result;
}
