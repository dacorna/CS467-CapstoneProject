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