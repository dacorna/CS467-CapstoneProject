#include "Room.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class TrollBridge : public Room {

public:
	TrollBridge();
	~TrollBridge();
	void useItem(Bag, string);
};