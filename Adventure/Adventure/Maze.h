#pragma once

#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>
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
	Node *one, *two, *three, *four, *five, *six;
	Node* currentNode;
	bool isFinished;

public:
	Maze();
	~Maze();
	void enterMaze();
	void go(int);
	bool getIsFinished() { return isFinished; }
	void setIsFinished(bool finished) { isFinished = finished; }
};
