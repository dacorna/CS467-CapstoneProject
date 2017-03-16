#include "Room.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Earth : public Room {

private: 
	bool PlacedOre;
	bool FurnanceLit ;


public:
	Earth();
	~Earth();
	void useItem(Bag, string);
	void LightFurnace(Bag);
	bool AlterStatus ();
	void PlaceORE ();
	void MeltLock ();

};