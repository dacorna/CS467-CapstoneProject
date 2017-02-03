/*  loadRoom.cpp

    This file will have my working version of the function for loading a room.
    Work-in-progress

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void loadRoom(string filename)
{
    bool isVisited, northLocked, southLocked, westLocked, eastLocked;
    //Have to figure out items, because there can be a variable amount -- Vector, duh
	vector<string> items;
	int i = 0;

    string buffer;

    std::ifstream roomFile (filename);
    if(roomFile.is_open())
    {
		//These first calls to getline are standard, they will always be in every room file.
        getline(roomFile, buffer);
        isVisited = std::stoi(buffer);
		
		getline(roomFile, buffer);
        northLocked = std::stoi(buffer);
		
		getline(roomFile, buffer);
        southLocked = std::stoi(buffer);
		
		getline(roomFile, buffer);
        westLocked = std::stoi(buffer);
		
		getline(roomFile, buffer);
        eastLocked = std::stoi(buffer);
		
		//Now, we get to the items, which can vary in number so we loop
		while(getline(roomFile, buffer))
		{
			items.push_back(buffer);
			i++;
		}
		
		
    }
	
	cout << isVisited << ',' << northLocked << ',' << southLocked << ',' << westLocked << ',' << eastLocked << endl;
	
	for(int j = 0; j < i; j++)
	{
		cout << items[j] << endl;		
	}
}

int main()
{
    string name = "testroom.txt";
    loadRoom(name);


}
