#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>


struct ParsedInput{
	bool valid;
	std::string command;
	std::string action;
};

ParsedInput parse(std::string);

#endif