#include "Earth.h"

Earth::Earth() {
	name = "Earth";
	shortDescription = "Earth room. A strong wind swirls to the north.";
	longDescription = "A room full of rock and earth. A strong wind blows to the north, where there looks to be an opening. Yet it is unreachable, as a great iron lock bars the way. It sits atop a furnace altar.";
	exploreStory = "Seems to me that furnace altar could melt away the iron lock. Too bad there is nothing to burn in it.";
}

Earth::~Earth() {
}


void Earth::PlaceORE (){
	cout << "With a GREAT bang you place the ore on the altar." << endl;
	PlacedOre= true;
	
}

void Earth::LightFurnace(){
	cout << "The furnace begins to heat up."  << endl;
	FurnanceLit = true;
}

bool Earth::AlterStatus (){
	if(PlacedOre && FurnanceLit ){
		return 1;
	}else return 0;
}

void Earth::MeltLock (){
	cout << "Slowly the lock on the door to the north melts."  << endl;
}


