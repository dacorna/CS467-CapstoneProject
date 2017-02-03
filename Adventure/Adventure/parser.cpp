#include "parser.h"

ParsedInput  parse(std::string input)
{
	ParsedInput p;

	std::string delimiter = " ";
	p.command = input.substr(0, input.find(delimiter));
	input.erase(0, p.command.length());
	p.action = input;
	p.valid = true;			// add logic to determine this 
	return p;
}