#include <string>
#include <iostream>
#include "parser.h"
 
void Check(std::string input);

int main()
{

	std::string text;

	text = "attack troll";
	Check(text);

	text = "strike troll with sword";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	 text = "look at bird ";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	text = "look up the [TEXT] in's the [something's]";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	 text = "Eat the yellow jelly bean with great bizantine fork.";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	 text = "Speak to the affable Ogre.";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	 text = "Drink oily Potion";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	text = "load Game";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	text = "save";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	text = "save game";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	text = "attack";
	Check(text);

	std::cout << "****************************************************" << std::endl;
	text = "Speak to";
	Check(text);



}

void Check(std::string input){

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

}