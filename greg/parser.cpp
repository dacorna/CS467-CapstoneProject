#include <string>
#include <boost/algorithm/string.hpp>
#include<map>
#include <vector>
#include <sstream>
#include <algorithm>
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
	
	//p = ValidateInput(p);
	
	return p;
}

 ParsedInput  Separate(std::string input)
{
	ParsedInput p;
	//bool preposition;
	int n = std::count(input.begin(), input.end(), ' ');
	 std::string words[n+1];
	
   	 int i = 0;
    	std::stringstream ssin(input);
    	while (ssin.good() && i <= n){
        		ssin >> words[i];
        		++i;
   	 }
   	
	 for(i = 0; i <=n; i++){
        		std::cout << words[i] << std::endl;
   	}

	//preposition = FindPreposition(input);
	//p.hasPreposition = preposition;

	

	//std::string delimiter = " ";
	//p.command = input.substr(0, input.find(delimiter));
	//input.erase(0,  p.command.length());
	//p.action = input;
	
	std::map<std::string, std::string> m;
	m["GO"]="GO";
	m["HEAD"]="GO";
	m["TRAVEL"]="GO";
	m["HEAD TO"]="GO";
	m["HEAD"]="GO";
	
	m["LOOK"]="LOOK";
	m["LOOK UP"]="LOOK";
	m["LOOK INSIDE"]="LOOK";


	std::string command;
	command = words[0];
	int endCommand;
	 for(i = 0; i <n; i++){
		if ( m.find(command) == m.end() ) {
  			//p.isParsed = false;
		} else {
  			p.command = m[command];
			p.isParsed = true;
			endCommand = i;
		}
		command.append(" ");
		command.append(words[i+1]);  
	}

	
	//std::map<std::string, std::string> p;
	//p["INTO"]="INTO";
	
	const char *GamePrepositions[] = {
	                "ABOUT", 
	                "WITH", 
	                 "INTO",
		"IN",
		"THE"
	 0};
	std::string preposition;

	p.action = words[endCommand+1];
	
	preposition =  words[endCommand+2];

	 while (GamePrepositions[i] != '\0'){
		if(std::strcmp (preposition.c_str(),GamePrepositions[i] ) == 0){
			p.hasPreposition = 1;
			p.preposition = preposition;
			break;
		}  

		 i++;
	}

	p.secondAction = words[endCommand+3];



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
	m["TRAVEL"]="GO";
	m["HEAD TO"]="GO";


	if ( m.find(p.command) == m.end() ) {
  		p.isParsed = false;
	} else {
  		p.command = m[p.command];
		p.isParsed = true;
	}

	return p;

}