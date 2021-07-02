
#ifndef __ITEM_H
#define __ITEM_H
#include <vector>
#include <tuple>
#include <iostream>
#include "symbol.h"
#include "rule.h"

class Item
{
public:
  Rule* rule;
  std::vector<Symbol*> lookahead;
  std::tuple<int, bool, Symbol*> dot; 

public:
  Item();
  Item(Rule* rule, std::tuple<int, bool, Symbol*> dot);
  Item(Rule* rule, std::tuple<int, bool, Symbol*> dot, std::vector<Symbol*> lookahead);
  ~Item();
  bool isBodyEqual(Item* i2);
  void printItemWithoutLookahead(void);
};

std::ostream &operator<< (std::ostream &output, const Item &item);
bool operator== (const Item &i1, const Item &i2);

#endif