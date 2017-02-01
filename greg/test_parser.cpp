#include <string>
#include <iostream>
#include "parser.h"
 
int main()
{

	ParsedInput p;
	std::string InputText = "Hello There";

	p = parse(InputText);
	std::cout << "Original: " << InputText << std::endl;
  	std::cout << "Output Command: " << p.command  << std::endl;
	std::cout << "Output Action: " << p.action  << std::endl;
  	return 0;
}