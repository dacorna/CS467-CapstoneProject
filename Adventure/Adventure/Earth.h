#include "Room.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Earth : public Room {

private: 
	bool PlacedOre;

public:
	Earth();
	~Earth();
	void useItem(Bag, string);
	void MeltLock();
	bool AlterStatus (){return  PlacedOre;}
	void PlaceORE ();
};