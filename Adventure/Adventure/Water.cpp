#include "Water.h"
#include <stdlib.h>
#include <limits>
#include <unistd.h>

Water::Water() {
	name = "Water";
	shortDescription = "A waterfall falls here into a pond.";
	longDescription = "Here is a waterfall flowing into a pond. Something sits in the middle of the pond but you can't quite make it out.";// There is a waterskin on the ground.";
	exploreStory = "Walking around the pond...the waterskin turns out to be empty...but boy does that waterfall look beautiful. I'll bet that water could put out even the brightest fire.";
}

Water::~Water() {

}

void Water::useItem(Bag bag, string item)
{
	if (item == "WATERSKIN") {
		// check if bag has waterskin
		if (bag.hasItem("WATERSKIN")) {
		// fill waterskin with water
			cout << "Filling up with some ice cold water..." << endl;
			usleep(400000);
			bag.getItem("WATERSKIN")->completeObjective(true);
		}
	}
}
