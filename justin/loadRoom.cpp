/*  loadRoom.cpp

    This file will have my working version of the function for loading a room.
    Work-in-progress

*/

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void loadRoom(string filename)
{
    string roomName, longDesc, shortDesc;
    bool isVisited, northLocked, southLock, westLocked, eastLocked;
    //Have to figure out items, because there can be a variable amount

    string buffer;

    std::ifstream roomFile (filename);
    if(roomFile.is_open())
    {
        getline(roomFile, buffer);
        roomName = buffer;

        getline(roomFile, buffer);
        longDesc = buffer;

        getline(roomFile, buffer);
        shortDesc = buffer;

        getline(roomFile, buffer);
        isVisited = std::stoi(buffer, nullptr);
    }
    cout << roomName << endl << longDesc << endl << shortDesc << endl;
}

int main()
{
    string name = "testroom.txt";
    loadRoom(name);


}
