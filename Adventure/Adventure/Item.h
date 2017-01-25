#pragma once

#include <string>
using std::string;

class Item
{
private:
	string name;
	string description;
	// more to come
public:
	Item();
	~Item();
	string getName() { return name; }
	string getDescription() { return description; }
};