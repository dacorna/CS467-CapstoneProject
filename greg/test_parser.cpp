#include <string>
#include <iostream>
#include "parser.h"
 
void Check(std::string input);

int main()
{

	std::string text;

	text = "look up the";
	Check(text);

	std::cout << "****************************************************" << std::endl;


	text = "look up the [TEXT] in's the [something's]";
	Check(text);

	std::cout << "****************************************************" << std::endl;


	 text = "look at bird ";
	Check(text);

	std::cout << "****************************************************" << std::endl;

	
	text = "look look at bird ";
	Check(text);

	std::cout << "****************************************************" << std::endl;

	 text = "fook up [TEXT] in [something]";
	Check(text);


	std::cout << std::endl;


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