#include "Mine.h"
#include <boost/algorithm/string.hpp>

Mine::Mine()
{
	name = "Mine";
	longDescription = "A mine which was once the greatest producer of ore in the kingdom. During the age in which this mine was active, it was typical of the architects to include many exits, so as to avoid entrapment from a cave-in.";
	shortDescription = "An inactive mine.";
	exploreStory = "There is still plenty of ore here, but we'd need some sort of tool to get at it. The door to the north - something was written here once, but it is now worn mostly away.";
}

void Mine::useItem(Bag bag, string item)
{
	if (item == "PICKAXE")
	{
		if (firstSrike == false){
			cout << "You hit down with the pick end cracking the ore. Maybe another swing is needed!" << endl;
			firstSrike = true;
		}else {
			cout << "You smash down with the blunt end knocking off a large ore chunk." << endl;
			cout << "You shove it in your bag. Maybe it will make a good doorstop someday?" << endl;
			secondStrike = true;
		}
		

	}else if (item == "FEATHER" ||  item == "INKPOT" ) {

		if( !bag.hasItem("INKPOT")){
			cout << "Find some ink." << endl;
			return;
		}

		if( !bag.hasItem("FEATHER")){
			cout << "Find something to write with." << endl;
			return;
		}

		cout << "What do you want to WRITE on the door?" << endl;
		cin.sync();
		string input;
		getline(cin,input);
		boost::algorithm::to_upper(input);
		if(input == "YIGNAUT") {
			cout << "The lock glows. The door opens." << endl;
			DoorUnlocked = true;
		}else {
			cout << "Nothing Happens." << endl;

		}


	} else
		cout << "Sounds fun, but that item has no effect here" << endl;
}