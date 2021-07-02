
#include "main.h"

Grammar *grammar = NULL;

int main (int argc, char **argv)
{
  grammar = new Grammar();

  int ret = yyparse();

  std::cout << *grammar << std::endl;

  std::cout << std::endl << "PRIMER SET:" << std::endl;
  grammar->print_first_sets();

  std::cout << std::endl << "SIGUIENTES SET:" << std::endl;
  grammar->print_follow_sets();
  
  delete grammar;
  grammar = NULL;
  return ret;
}
