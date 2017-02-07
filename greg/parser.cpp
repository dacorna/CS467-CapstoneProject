#include <string>
#include <boost/algorithm/string.hpp>
#include<map>
#include <vector>
#include "parser.h"

//define all basic commands
//define all aliases

ParsedInput  Separate(std::string input);
ParsedInput ValidateInput(ParsedInput p);
std::string Capitalize (std::string str);
bool FindPreposition (std::string input);

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
	bool preposition;


	preposition = FindPreposition(input);
	p.hasPreposition = preposition;

	std::string delimiter = " ";
	p.command = input.substr(0, input.find(delimiter));
	input.erase(0,  p.command.length());
	p.action = input;
	return p;
}

bool FindPreposition (std::string input){

	int prepositions = 0;
	

	const char *GamePrepositions[] = {
	                "ABOUT", 
	                "WITH", 
	                 "ON",
	                 "TO",
	 0};
	 int i =0;

	 while (GamePrepositions[i] != '\0'){
		std::size_t found = input.find(GamePrepositions[i]);
		if(found!=std::string::npos){
			std::cout << "Hi ";
			prepositions++;	
		}        		
       		 i++;
   	 }

	if (prepositions == 1){
		return 1;
	} else {
		return 0;
	}
		

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