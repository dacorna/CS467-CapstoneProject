#include <string>
#include <iostream>
#include "parser.h"
 
void Check(std::string input);

int main()
{

	std::string user_input;

	do {
		std::cout << "> ";
		 std::getline (std::cin,user_input);
		Check(user_input);
	}while(1);
}

void Check(std::string input){

	ParsedInput p;
	p = parse(input);

	if (p.isParsed == true){
  		std::cout << "Command: " << p.command  << "\t";
		std::cout << "First Object: " << p.firstObject  << std::endl;
		if (p.hasPreposition == true){
			std::cout << "Preposition: " << p.preposition  << "\t";
			std::cout << "Second Object: " << p.secondObject << std::endl;
		}
  	}else {
		std::cout << "Parse Error: " << p.error << std::endl;
	}

}