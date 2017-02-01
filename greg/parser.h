#ifndef PARSER_H
#define PARSER_H
#include <string>

struct ParsedInput{
  std::string command;
  std::string action;
};

ParsedInput parse(std::string ); 
 
#endif