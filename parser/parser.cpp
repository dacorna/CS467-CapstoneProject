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
	boost::trim(input);
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
	p.hasPreposition = false;

	const char *filterList[] = {
	                "THE ", 
	                " THE",
	                "'S",
		".",
		"!",
	 0};
	int x = 0;
	while (filterList[x] != '\0'){
		std::string temp (filterList[x]);
		std::string::size_type r = input.find(temp);
   		while (r!= std::string::npos) {
   			  input.erase(r,temp.length());
   			  r = input.find(temp, r);
  		 }
		x++;
	}

	int nwords = std::count(input.begin(), input.end(), ' ')+1;
	 std::string words[nwords];
   	 int i = 0;
    	std::stringstream ssin(input);
    	while (ssin.good() && i < nwords){
        		ssin >> words[i];
        		++i;
   	 }


	std::map<std::string, std::string> m;

	m["CHEAT"] = "CHEAT";
	m["UNCHEAT"] = "UNCHEAT";
	m["PUSH"] = "PUSH";
	m["USE"] = "USE";
	m["EXPLORE"] =  "EXPLORE";
	m["OPEN"] =  "OPEN";

	m["GO"]="GO";
	m["GO IN"]="GO";
	m["GO TO"]="GO";
	m["HEAD"]="GO";
	m["HEAD TO"]="GO";
	m["TRAVEL"]="GO";
	m["TRAVEL TO"]="GO";
	m["MOVE"]="GO";
	m["MOVE TO"]="GO";
	m["WALK"]="GO";

	m["NORTH"] = "quickGO";
	m["SOUTH"] = "quickGO";
	m["EAST"] = "quickGO";
	m["WEST"] = "quickGO";

	m["LOOK"]="LOOK";
	
	m["LOOK AT"]="LOOK AT";
                     m["LOOK UP"]="LOOK AT";
	m["LOOK INTO"]="LOOK AT";
	m["LOOK INSIDE"]="LOOK AT";
	m["INSPECT"]="LOOK AT";
	m["SEARCH"]="LOOK AT";

	m["CONSUME"]="CONSUME";
	m["EAT"]="CONSUME";
	m["DRINK"]="CONSUME";
	m["SIP"]="CONSUME";

	m["ATTACK"]="ATTACK";
	m["STRIKE"]="ATTACK";
	m["SWING"]="ATTACK";

	m["TALK"]="TALK";
	m["TALK TO"]="TALK";
	m["SPEAK"]="TALK";
	m["SPEAK TO"]="TALK";

	m["SET"] = "PLACE";
	m["PLACE"] = "PLACE";

	m["TAKE"] = "TAKE";
	m["GRAB"] = "TAKE";
	m["PICK UP"] = "TAKE";
	m["PICKUP"] = "TAKE";
	m["GET"] = "TAKE";

	m["DROP"] = "DROP";
	m["LEAVE"] = "DROP";

	m["SAVE"] = "SAVE";
	m["STORE"] = "SAVE";
	m["SAVE GAME"] = "SAVE";
	m["SAVEGAME"] = "SAVE";

	m["LOAD"] = "LOAD";
	m["LOAD GAME"] = "LOAD";
	m["LOADGAME"] = "LOAD";
	m["RESTORE"] = "LOAD";

	m["INVENTORY"] =  "INVENTORY"	;
	m["BAG"] =  "INVENTORY";

	m["HELP"] =  "HELP";
	m["?"] =  "HELP";

	std::string command;
	int endCommand;


	 for(i = 0; i <nwords; i++){
		command.append(words[i]);  
		if ( m.find(command) != m.end() ) {
  			p.command = m[command];
			p.isParsed = true;
			endCommand = i;
		}
		command.append(" ");
	}
	if(p.isParsed == false){
		p.error = "Could not parse command: command not found!" ;
		return p;
	}  

	if(nwords == endCommand+1){

		if (p.command == "quickGO"){
			p.command = "GO";
			p.firstObject = words[0];
			p.isParsed = true;
			return p;

		}
		if (p.command != "SAVE" && p.command != "LOAD"
			 && p.command != "INVENTORY"  && p.command != "HELP"
                                                                && p.command != "CHEAT"){
			p.isParsed = false;
			p.error = "Could not parse command: no objects!" ;
			return p;
		}
		
	}

	int objectOneStart = endCommand+1;
	const char *GamePrepositions[] = {
	                "ABOUT", 
	                "WITH", 
	                 "INTO",
	                 "IN",
	                  "ON",
		"AT",
	 0};
	int s=0;
	int t = 0;
	int objectOneEnd = endCommand+1;
	for(s =objectOneStart ; s <nwords; s++){
        		 for (t=0;GamePrepositions[t] != '\0';t++){
			if(std::strcmp (words[s].c_str(),GamePrepositions[t] ) == 0){
				p.hasPreposition = true;
				p.preposition = words[s];
				objectOneEnd = s-1;
				break;
			}  
			
		}
	}

	std::map<std::string, std::string> n;;
	n["TREASURE CHEST"] = "TREASURECHEST";
	n["TREASURE"] = "TREASURECHEST";

	n["INK POT"] = "INKPOT";
	n["INK"] = "INKPOT";

	if (p.hasPreposition == false){
		int w;
		for(w=objectOneStart ;w<nwords;w++){
			p.firstObject.append(words[w]);
			if (w<nwords-1){
				p.firstObject.append(" ");
			}
		}
		

		if ( n.find(p.firstObject) != n.end() ) {
  			p.firstObject= n[p.firstObject];
		}
		return p;
	}

	int y;
	for(y=objectOneStart ;y<=objectOneEnd;y++){
		p.firstObject.append(words[y]);
		if (y<objectOneEnd-1){
                                         		p.firstObject.append(" ");
		}
	}
	

	int z;
	for(z=objectOneEnd+2 ;z<nwords;z++){
		p.secondObject.append(words[z]);
		if (z<nwords-1){
                                         		 p.secondObject.append(" ");
		}
	}
	

	if ( n.find(p.firstObject) != n.end() ) {
  			p.firstObject= n[p.firstObject];
		}

	if ( n.find(p.secondObject) != n.end() ) {
  			p.secondObject= n[p.secondObject];
		}


	return p;

}

std::string Capitalize (std::string str){
	boost::to_upper(str);
	return str;
}