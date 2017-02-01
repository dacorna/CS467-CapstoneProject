#include <string>
#include "parser.h"

 ParsedInput  parse(std::string input)
{
	ParsedInput p;

	std::string delimiter = " ";
	p.command = input.substr(0, input.find(delimiter));
	input.erase(0,  p.command.length());
	p.action = input;
	return p;
}