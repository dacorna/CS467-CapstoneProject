#include "Library.h"


Library::Library()
{
	name = "Library";
	longDescription = "A wondrous library. Books are scattered everywhere. Just ahead, a table sits with an open book.";// An inkpot lies next to it.";
	shortDescription = "Libary. A book lies on a table ahead.";
	exploreStory = "Walking around the library...such a beautiful creation. Interestingly, the book on the table doesn't seem to be ON the table, but IN the table. Either someone really didn't want the book to leave this room, or they wanted to ensure a certain page was read.";
}

void Library::useItem(Bag bag, string item)
{
	if (item == "BOOK") {
		// read book -- aka reveal the "word of opening" 
	}
}