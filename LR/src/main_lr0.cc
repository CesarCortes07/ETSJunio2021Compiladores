
#include "main.h"

Grammar *grammar = NULL;

int main (int argc, char **argv)
{
  grammar = new Grammar();
  Parser* parser;

  int ret = yyparse();

  grammar->expand_grammar();
  parser = new LR0(grammar);
  
  std::cout << *grammar << std::endl;
  parser->print_item_set();
  parser->print_automata();
  parser->generateDotFile("LR0.dot");

  delete grammar;
  delete parser;
  grammar = NULL;
  parser = NULL;
  return ret;
}
