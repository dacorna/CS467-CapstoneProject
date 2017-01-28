#include "Item.h"

Item::Item()
{}

Item::Item(string itemName)
{
	name = itemName;
}

Item::Item(string itemName, string itemDescription)
{
	name = itemName;
	description = itemDescription;
}

Item::~Item()
{}

void Item::setName(string newName)
{
	name = newName;
}

void Item::setDescription(string newDescription)
{
	description = newDescription;
}

