
#include "main.h"

Grammar *grammar = NULL;

int main (int argc, char **argv)
{
  grammar = new Grammar();
  Parser* parser;

  int ret = yyparse();

  parser = new LALR1(grammar);
  
  std::cout << *grammar << std::endl;
  parser->print_first_sets();
  parser->print_follow_sets();
  
  parser->print_item_set();
  parser->print_automata();
  parser->generateDotFile("LALR1.dot");

  delete parser;
  delete grammar;
  grammar = NULL;
  return ret;
}
