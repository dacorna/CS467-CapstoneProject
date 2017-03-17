#include "Library.h"


Library::Library()
{
	name = "Library";
	longDescription = "A wondrous library. Books are scattered everywhere. \nJust ahead, a table sits with an open book.\nA fire burns in the hearth";
	shortDescription = "Libary. A book lies on a table ahead.\nFire burns in the hearth.";
	exploreStory = "Walking around the library...such a beautiful creation. \nInterestingly, the book on the table doesn't seem to be ON the table, but IN the table. \nEither someone really didn't want the book to leave this room, or they wanted to ensure a certain page was read.";
}

void Library::useItem(Bag bag, string item)
{
	if (item == "BOOK" || item == "PAGE") {
		cout << "The book describes the construction of this ancient place:" << endl;
		cout << "Of note is a passage about the creation of a nearby magical door that is only opened by scribing a word on the face of the door itself!" << endl;
		cout << "That word is in an ancient unspeakable-unpronounceable language, it is - YIGNAUT" << endl;
	}
	else if(item == "TORCH") {
		if(bag.hasItem("TORCH")) {
		  cout << "Walking over to fireplace to re-light the torch...";
		  usleep(500000);
		  bag.getItem("TORCH")->completeObjective(true);	
		  cout << "The torch is lit!" << endl;
		}
		else cout << "You don't have a torch!" << endl;
	}
	else cout << "That item has no use here!" << endl;
}
