#include <string>
#include <boost/algorithm/string.hpp>
#include<map>
#include "parser.h"

//define all basic commands
//define all aliases

 ParsedInput  parse(std::string input)
{
	
	std::string cInput;
	cInput = Capitalize(input);

	ParsedInput p;
	p = Separate(cInput);
	
	p = ValidateInput(p);
	
	return p;
}

 ParsedInput  Separate(std::string input)
{
	ParsedInput p;
	std::string delimiter = " ";
	p.command = input.substr(0, input.find(delimiter));
	input.erase(0,  p.command.length());
	p.action = input;
	return p;
}

std::string Capitalize (std::string str){
	boost::to_upper(str);
	return str;
}

ParsedInput  ValidateInput(ParsedInput p)
{
	
	std::map<std::string, std::string> m;
	m["HEAD"]="GO";

	if ( m.find(p.command) == m.end() ) {
  		p.isParsed = false;
	} else {
  		p.command = m[p.command];
		p.isParsed = true;
	}

	return p;

}