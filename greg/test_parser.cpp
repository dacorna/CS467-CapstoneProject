#include <string>
#include <iostream>
#include "parser.h"
 
int main()
{

	ParsedInput p;
	std::string InputText = "look up [TEXT] in [something]";

	p = parse(InputText);

	if (p.isParsed == true){
		std::cout << "Original: " << InputText << std::endl;
  		std::cout << "Output Command: " << p.command  << std::endl;
		std::cout << "Output Action: " << p.action  << std::endl;
		std::cout << "Has Preposition: " << p.hasPreposition << std::endl;
		std::cout << "Preposition: " << p.preposition << std::endl;
		std::cout << "Second Action: " << p.secondAction << std::endl;
  	}else {
		std::cout << "Parse Error: " << InputText << std::endl;
	}

	return 0;
}