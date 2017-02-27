#pragma once

#include <string>
using std::string;

class Item
{
private:
	string name;
	string description;
	bool canPickup;
	bool objectiveCompleted;
	
public:
	Item();
	Item(string);
	Item(string, string);
	~Item();
	string getName() { return name; }
	string getDescription() { return description; }
	void setName(string);
	void setDescription(string);
	bool canPickupItem() { return canPickup; }
	void setCanPickUp(bool);
	bool isObjectiveCompleted() { return objectiveCompleted; }
	void completeObjective() { objectiveCompleted = true; }
};
