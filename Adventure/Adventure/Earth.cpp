#include "Earth.h"
#include <unistd.h>

Earth::Earth() {
	name = "Earth";
	shortDescription = "Earth room. Waterfall nearby. A strong wind swirls to the north.";
	longDescription = "A room full of rock and earth. A strong wind blows to the north, where there looks to be an opening.\n Yet it is unreachable, as a great iron lock bars the way. It sits atop a furnace altar.\nA small waterfall is nearby";
	exploreStory = "Seems to me that furnace altar could melt away the iron lock.\nBut you'd have to place something in it that will burn hot enough. Maybe try lighting it?"; 
}

Earth::~Earth() {}


void Earth::PlaceORE (){
	cout << "With a GREAT bang you place the ore on the altar." << endl;
	PlacedOre= true;
}

void Earth::LightFurnace(Bag bag){
	if(bag.getItem("TORCH")->isObjectiveCompleted()) {
		cout << "The furnace begins to heat up."  << endl;
		FurnanceLit = true;
	} else {
		cout << "The torch is not lit. Find a fire." << endl;
	}		
}

bool Earth::AlterStatus (){
	if(PlacedOre && FurnanceLit ){
		return 1;
	}else return 0;
}

void Earth::MeltLock (){
	cout << "The locks melts just enough to reveal a way north!"  << endl;
}

void Earth::useItem(Bag bag, string item) 
{
	if(item == "WATERSKIN") {
		if(bag.hasItem("WATERSKIN")) {

			cout << "Filling waterskin from the falls here..." << endl;
			usleep(400000);
			bag.getItem("WATERSKIN")->completeObjective(true);
		}
	}	
}
