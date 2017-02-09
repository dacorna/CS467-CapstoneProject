#include "Bag.h"

Bag::Bag()
{
	maxSize = 10;		// evaluate this number later 
}

Bag::~Bag()
{}

bool Bag::hasItem(string itemName)
{
	for (unsigned i = 0; i < items.size(); i++) {
		if (items.at(i).getName() == itemName)
			return true;
}

	return false;	
}

int Bag::getItemIndex(string itemName)
{
	for(unsigned i = 0; i < items.size(); i++) {
		if (items.at(i).getName() == itemName)
			return i;
	}
	// item not found
	return -1;
}

Item Bag::getItem(string itemName)
{
	for(unsigned i = 0; i < items.size(); i++) {
		if (items.at(i).getName() == itemName)
			return items.at(i);
	}
	// item not found
	Item noItem("noItem");
	return noItem;	 
}

bool Bag::add(Item item)
{
	if (hasItem(item.getName())) {
		std::cout << "Item already in bag" << std::endl;
		return false;
	}
	items.push_back(item);
	return true;
}

void Bag::displayBag()
{
	for (unsigned i = 0; i < items.size(); i++) {
		std::cout << "\nItem " << i + 1 << ": " << items.at(i).getName() << std::endl;
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
