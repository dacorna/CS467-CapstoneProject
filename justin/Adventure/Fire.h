#include "Room.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Fire : public Room{

public:
	Fire();
	~Fire();
	bool pushSwitch();
	void extinguishFire();
	bool FireExtinguished();
};