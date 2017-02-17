#include "Room.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Outside : public Room
{
public:
	Outside();
	~Outside();
};