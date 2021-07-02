
#ifndef __RULE_H
#define __RULE_H
#include <cstddef>
#include <ostream>
#include <vector>
#include "symbol.h"

class Rule
{
public:
  Symbol *head;
  std::vector<Symbol*> body;
  int body_size;
  
public:
  Rule();
  Rule(Symbol *head);
  Rule(Symbol *head, std::vector<Symbol*> body);
  ~Rule();

  void addHead(Symbol *head);
  void addBody(std::vector<Symbol*> body);
  void addToBody(Symbol *symbol);
};

std::ostream &operator<< (std::ostream &output, const Rule &rule);
bool operator== (const Rule &r1, const Rule &r2);

#endif
