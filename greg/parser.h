#ifndef PARSER_H
#define PARSER_H


struct ParsedInput{
  bool isParsed;
  std::string command;
  std::string action;
};

ParsedInput parse(std::string ); 
ParsedInput  Separate(std::string input);
ParsedInput ValidateInput(ParsedInput p);
std::string Capitalize (std::string str);
 
#endif