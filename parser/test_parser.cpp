#include <string>
#include <iostream>
#include "parser.h"
 
ParsedInput Check(std::string input);

int main()
{

	std::string text;
	ParsedInput r;

	std::cout << "****************************************************" << std::endl;
	text = "attack troll";
	r = Check(text);
	if (r.command == "ATTACK" && r.firstObject == "TROLL"){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

 	std::cout << "****************************************************" << std::endl;
	text = "grab treasure";
	r =  Check(text);
	if (r.command == "TAKE" && r.firstObject == "TREASURECHEST"){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

 	std::cout << "****************************************************" << std::endl;
                     text = "strike treasure chest with ink";
	r = Check(text);
	if (r.command == "ATTACK" && r.firstObject == "TREASURECHEST"
	         && r.preposition == "WITH" && r.secondObject == "INKPOT" ){				
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}
                    
   	std::cout << "****************************************************" << std::endl;
	text = "sip the ink";
	r = Check(text);
	if (r.command == "CONSUME" && r.firstObject == "INKPOT"){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}
                    
                     std::cout << "****************************************************" << std::endl;
	text = "strike troll with sword";
	r = Check(text);
	if (r.command == "ATTACK" && r.firstObject == "TROLL" 
		&& r.preposition == "WITH" && r.secondObject == "SWORD" ){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	 text = "look at bird";
	r = Check(text);
	if (r.command == "LOOK AT" && r.firstObject == "BIRD"){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	text = "look up the [TEXT] in's the [something's]";
	r = Check(text);
	if (r.command == "LOOK AT" && r.firstObject == "[TEXT]"
		&& r.preposition == "IN" && r.secondObject == "[SOMETHING]" ){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	 text = "Eat the yellow jelly bean with great bizantine fork.";
	r = Check(text);
	if (r.command == "CONSUME" && r.firstObject == "YELLOW JELLYBEAN"
                             && r.preposition == "WITH" && r.secondObject == "GREAT BIZANTINE FORK" ){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	 text = "Speak to the affable Ogre.";
	r = Check(text);
	if (r.command == "TALK" && r.firstObject == "AFFABLE OGRE" ){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	 text = "Drink oily Potion";
	r = Check(text);
	if (r.command == "CONSUME" && r.firstObject == "OILY POTION"){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	text = "load Game";
	r = Check(text);
	if (r.command == "LOAD"){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	text = "save";
	r = Check(text);
	if (r.command == "SAVE"){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	text = "save game";
	r = Check(text);
	if (r.command == "SAVE" ){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	text = "attack";
	r = Check(text);
	if (r.isParsed == false){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	text = "Speak to";
	r = Check(text);
	if (r.isParsed == false){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	text = "";
	r = Check(text);
	if (r.isParsed == false){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	text = " ";
	r = Check(text);
	if (r.isParsed == false){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

	std::cout << "****************************************************" << std::endl;
	text = " Go West ";
	r = Check(text);
	if (r.command == "GO" && r.firstObject == "WEST"){
	      std::cout << "PASS! PASS! PASS! PASS! PASS! PASS! PASS!" << std::endl;
	}else {
	       std::cout << "FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL! FAIL!" << std::endl;
                            return 0;
	}

}

ParsedInput Check(std::string input){

	ParsedInput p;
	p = parse(input);


	if (p.isParsed == true){
		std::cout << input << std::endl;
  		std::cout << "Command: " << p.command  << "\t";
		std::cout << "First Object: " << p.firstObject  << std::endl;
		if (p.hasPreposition == true){
			std::cout << "Preposition: " << p.preposition  << "\t";
			std::cout << "Second Object: " << p.secondObject << std::endl;
		}
  	}else {
		std::cout << "Original: " << input << std::endl;
		std::cout << "Parse Error: " << p.error << std::endl;
	}

	return p;

}