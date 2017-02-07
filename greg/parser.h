#ifndef PARSER_H
#define PARSER_H


struct ParsedInput{
  bool isParsed;
  bool hasPreposition;
  std::string command;
  std::string action;
  std::string secondAction;
};

ParsedInput parse(std::string ); 
 
#endif