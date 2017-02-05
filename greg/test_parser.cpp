#include <string>
#include <iostream>
#include "parser.h"
 
int main()
{

	ParsedInput p;
	std::string InputText = "Head North";

	p = parse(InputText);

	if (p.isParsed == true){
		std::cout << "Original: " << InputText << std::endl;
  		std::cout << "Output Command: " << p.command  << std::endl;
		std::cout << "Output Action: " << p.action  << std::endl;
  	}else {
		std::cout << "Parse Error: " << InputText << std::endl;
	}

	return 0;
}