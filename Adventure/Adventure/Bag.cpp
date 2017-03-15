#include "Bag.h"

Bag::Bag()
{
	maxSize = 7;		// evaluate this number later 
}

Bag::~Bag()
{}

bool Bag::hasItem(string itemName)
{
	for (unsigned i = 0; i < items.size(); i++) {
		if (items.at(i)->getName() == itemName)
			return true;
	}

	return false;	
}

int Bag::getItemIndex(string itemName)
{
	for(unsigned i = 0; i < items.size(); i++) {
		if (items.at(i)->getName() == itemName)
			return i;
	}
	// item not found
	return -1;
}

Item* Bag::getItemAtIndex(int index)
{
	if(index >= 0 && items.size() > index) 
		return items.at(index);

	else return NULL; // bad index given
}

Item* Bag::getItem(string itemName)
{
	for(unsigned i = 0; i < items.size(); i++) {
		if (items.at(i)->getName() == itemName)
			return items.at(i);
	}
	// item not found
	//Item noItem("noItem");
	//return &noItem;
	return NULL;		 
}

bool Bag::add(Item* item)
{
	if (hasItem(item->getName())) {
		std::cout << "Item already in bag" << std::endl;
		return false;
	}
	if(items.size() >= maxSize) {
		std::cout << "Your bag is full! You'll have to drop an item first" << std::endl;
		return false;
	}
		
	items.push_back(item);
	
	return true;
}

void Bag::displayBag()
{
	
	if(items.size() == 0)
	{
		std::cout << "You have nothing in your bag!" << std::endl; 
		return;
	}
	std::cout << "Player inventory: " << std::endl; 
	for (unsigned i = 0; i < items.size(); i++) {
		std::cout << "\nItem " << i + 1 << ": " << items.at(i)->getName() << std::endl;
	}
}

void Bag::dropItem(string itemName)
{
	int index = getItemIndex(itemName);
	if(index >= 0) 
		items.erase(items.begin() + index);
	
	else
		std::cout << "That item is not in your bag!" << std::endl;
}
