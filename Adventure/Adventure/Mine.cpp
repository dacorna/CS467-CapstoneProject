#include "Mine.h"


Mine::Mine()
{
	name = "Mine";
	longDescription = "A mine which was once the greatest producer of ore in the kingdom. During the age in which this mine was active, it was typical of the architects to include many exits, so as to avoid entrapment from a cave-in.";
	shortDescription = "An inactive mine.";
	exploreStory = "There is still plenty of ore here, but we'd need some sort of tool to get at it";
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
		

	}
	else
		cout << "Sounds fun, but that item has no effect here" << endl;
}
