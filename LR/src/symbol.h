
#ifndef __SYMBOL_H
#define __SYMBOL_H
#include <ostream>
#include <stdlib.h>
#include <string.h>

class Symbol
{
public:
  bool empty;
  bool terminal;
  char *str;
public:
  Symbol ();
  Symbol (bool empty);
  Symbol (char *str);
  Symbol (char *str, bool terminal);
  ~Symbol ();
};

class DollarSymbol : public Symbol
{
public:
  DollarSymbol ();
};

std::ostream &operator<< (std::ostream &output, const Symbol &symbol);
bool operator== (const Symbol &s1, const Symbol &s2);

#endif
