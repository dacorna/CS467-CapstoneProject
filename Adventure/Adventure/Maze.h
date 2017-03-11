#pragma once

#include "Room.h"
#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>

/*#include <ncurses.h>
#define kb_up 259
#define kb_down 258
#define kb_left 260
#define kb_right 261
#define kb_esc 27
*/
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;


struct Node {
	int position;
	Node *north, *east, *south, *west;
	string clue;
};


class Maze 
{
private:
	Node *start, *end;
	Node *one, *two, *three, *four, *five, *six, *seven, *eight;
	Node* currentNode;
	int xLoc;
	int yLoc;
	bool isFinished;
	bool mazeReversed;
public:
	Maze();
	~Maze();
	void setClues();
	void reverseMaze();
	void displayMaze(bool);
	int enterMaze(Room*);
	void go(int);
	bool getIsFinished() { return isFinished; }
	void setIsFinished(bool finished) { isFinished = finished; }
	bool getMazeReversed() { return mazeReversed; }
};
