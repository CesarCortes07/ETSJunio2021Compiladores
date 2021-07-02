
#include "symbol.h"

Symbol::Symbol()
{
}

Symbol::Symbol(bool empty)
{
  this->str = strdup("\u03B5");
  this->empty = empty;
  terminal = true;
}

Symbol::Symbol(char *str)
{
  this->str = strdup(str);
  empty = false;
}

Symbol::Symbol(char *str, bool terminal)
{
  this->str = strdup(str);
  this->terminal = terminal;
  empty = false;
}

Symbol::~Symbol()
{
  free(str);
}

DollarSymbol::DollarSymbol ()
{
  this->str = strdup("$");
  empty = false;
  terminal = true;
}

std::ostream &operator<< (std::ostream &output, const Symbol &symbol)
{
  output << "{"<<symbol.str << "," << symbol.terminal<<"}";
  output << symbol.str;
  return output;
}

bool operator== (const Symbol &s1, const Symbol &s2)
{
  if(strcmp(s1.str, s2.str) == 0)
    return true;
  else
    return false;
}
