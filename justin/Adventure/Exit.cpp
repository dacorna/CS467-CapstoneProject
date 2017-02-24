#include "Exit.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

Exit::Exit()
{
	name = "Exit";
	longDescription = "This is the exit. You've navigated the cave safely! The sorcerer's search party has long since given up looking for you. I reckon it'd be safe to go outside again. Hopefully you depart with a wealth of knowledge and a heavier purse";
	shortDescription = "This is the exit. You win! Go anywhere to get back outside.";
	exploreStory = "You notice some other tunnels leading in different directions from where you came. You begin to wonder if perhaps there are other hidden treasures and mysteries waiting to be uncovered by an adventurer such as yourself. No doubt there are. But you're suddenly distracted by three objects lying in the tunnel to the outside. A flagon of ale, a wineskin, and a root beer. You take all three for the trip home. One adventure has been enough...for now";
}
