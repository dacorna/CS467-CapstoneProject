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
std::string Capitalize(std::string str);
bool FindPreposition(std::string input);

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
	p.isParsed = false;


	std::string pattern = "THE ";
	const char *filterList[] = {
		"THE ",
		" THE",
		"'S",
		0 };
	int x = 0;
	while (filterList[x] != '\0'){
		std::string temp(filterList[x]);
		std::string::size_type r = input.find(temp);
		while (r != std::string::npos) {
			input.erase(r, temp.length());
			r = input.find(temp, r);
		}
		x++;
	}




	int nwords = std::count(input.begin(), input.end(), ' ') + 1;
	std::string words[nwords];
	int i = 0;
	std::stringstream ssin(input);
	while (ssin.good() && i < nwords){
		ssin >> words[i];
		++i;
	}
	for (i = 0; i <nwords; i++){
		std::cout << words[i] << std::endl;
	}




	std::map<std::string, std::string> m;
	m["GO"] = "GO";
	m["GO IN"] = "GO";
	m["GO TO"] = "GO";
	m["HEAD"] = "GO";
	m["TRAVEL"] = "GO";
	m["HEAD TO"] = "GO";
	m["HEAD"] = "GO";
	m["MOVE"] = "GO";

	m["LOOK"] = "LOOK";
	m["LOOK UP"] = "LOOK";
	m["LOOK INTO"] = "LOOK";
	m["LOOK AT"] = "LOOK";
	m["LOOK INSIDE"] = "LOOK";
	m["INSPECT"] = "LOOK";
	m["SEARCH"] = "LOOK";

	m["CONSUME"]="CONSUME";
	m["EAT"]="CONSUME";
	m["DRINK"]="CONSUME";
	m["SIP"]="CONSUME";

	m["ATTACK"]="ATTACK";
	m["STRIKE"]="ATTACK";
	m["SWING"]="ATTACK";
	m["PUNCH"]="ATTACK";

	m["TALK"]="TALK";
	m["TALK TO"]="TALK";
	m["SPEAK"]="TALK";
	m["SPEAK TO"]="TALK";

	m["SET"] = "SET";
	m["PLACE"] = "SET";

	m["SAVE"] = "SAVE";
	m["STORE"] = "SAVE";
	m["LOAD"] = "LOAD";
	m["RESTORE"] = "LOAD";
	
	
	std::string command;
	int endCommand;

	if (nwords == 2){
		p.hasPreposition = false;
		if (m.find(words[0]) != m.end()) {
			p.command = m[words[0]];
			p.isParsed = true;
		}
		else {

			p.isParsed = false;
			p.error = "Could not parse command. ";
		}
		p.firstObject = words[1];

		std::string vObject;
		vObject.append(words[0]);
		vObject.append(" ");
		vObject.append(words[1]);
		if (m.find(vObject) != m.end()) {
			p.isParsed = false;
			p.error = "Could not parse object. ";
		}

		return p;

	}
	else {

		for (i = 0; i <nwords - 1; i++){
			command.append(words[i]);
			if (m.find(command) != m.end()) {
				p.command = m[command];
				p.isParsed = true;
				endCommand = i;
			}
			command.append(" ");
		}
	}

	if (p.isParsed == false){
		p.error = "Could not parse command. ";
		return p;
	}

	int objectOneStart = endCommand + 1;
	const char *GamePrepositions[] = {
		"ABOUT",
		"WITH",
		"INTO",
		"IN",
		"ON",
		0 };
	int s = 0;
	int t = 0;
	int objectOneEnd = endCommand + 1;
	for (s = objectOneStart; s <nwords; s++){
		for (t = 0; GamePrepositions[t] != '\0'; t++){
			if (std::strcmp(words[s].c_str(), GamePrepositions[t]) == 0){
				p.hasPreposition = true;
				p.preposition = words[s];
				objectOneEnd = s - 1;
				break;
			}

		}
	}

	int y;
	for (y = objectOneStart; y <= objectOneEnd; y++){
		p.firstObject.append(words[y]);
		p.firstObject.append(" ");
	}

	if (p.hasPreposition == false){

		return p;
	}


	int z;
	for (z = objectOneEnd + 2; z<nwords; z++){
		p.secondObject.append(words[z]);
		p.secondObject.append(" ");
	}

	return p;

}

bool FindPreposition(std::string input){

	int prepositions = 0;
	const char *GamePrepositions[] = {
		"ABOUT",
		"WITH",
		"ON",
		"TO",
		0 };
	int i = 0;

	while (GamePrepositions[i] != '\0'){
		std::size_t found = input.find(GamePrepositions[i]);
		if (found != std::string::npos){
			prepositions++;
		}
		i++;
	}

	if (prepositions == 1){
		return 1;
	}
	else {
		return 0;
	}


}

std::string Capitalize(std::string str){
	boost::to_upper(str);
	return str;
}

ParsedInput  ValidateInput(ParsedInput p)
{

	std::map<std::string, std::string> m;
	m["HEAD"] = "GO";
	m["TRAVEL"] = "GO";
	m["HEAD TO"] = "GO";


	if (m.find(p.command) == m.end()) {
		p.isParsed = false;
	}
	else {
		p.command = m[p.command];
		p.isParsed = true;
	}

	return p;

}