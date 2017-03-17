#include "Bridge.h"


Bridge::Bridge()
{
	name = "Great Bridge";
	longDescription = "The great bridge of the ancient ones. Very old, very long, and wide enough only for one.\nTo go east or west would most definitely result in a precipitous fall. The mines are close by.";
	shortDescription = "Great and ancient bridge. Best not venture east or west.";
	exploreStory = "Do you dare look down to pick anything up here?";
}

bool Bridge::GotPickaxe()
{


	if (firstTimeGotPickaxe == false){
	 	cout << "The pickaxe is at a perilous place on the bridge!"<<endl;
		firstTimeGotPickaxe = true;
		cout << "Are you brave enough to reach for it? (yes/no):" ;
		cin.sync();
		string input;
		getline(cin,input);
		if(input != "y" && input != "yes" && input != "YES"  ) {
			cout << "OK, but sometime it is GOOD to be brave."<<endl;
			firstTimeGotPickaxe = false;
			return 0;
			
		}

	}

	 int number;
	srand (time(NULL));
	number = rand() % 10 + 1;	

	if (number <=5){
	   cout << "You skillfully grab the pickaxe!" << endl;
	   return 1;
	}else {
	  cout << "The bridge sways and you fumble the pickaxe - it almost fell off!" << endl;
	  return 0;
	}


}
