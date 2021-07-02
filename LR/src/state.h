#ifndef __STATE_H
#define __STATE_H
#include "rule.h"
#include "item.h"
#include <set>
#include <string>
#include <vector>
#include <algorithm>

class State
{

public:
  int id;
  std::set<Item*> kernel;
  std::set<Item*> item_set;
  std::set<Item*> all_items;
  std::set<std::pair<Symbol*, State* >> transitions;

public:
  State();
  State(std::set<Item*> kernel);
  State(int id, std::set<Item*> kernel, std::set<Item*> item_set);
  ~State();
  void setId(int id);
  void setItemSet(std::set<Item*> item_set);
  void setKernel(std::set<Item*> kernel);
  bool haveSameKernel(State* s2);
  bool haveSameKernelItems(State* s2);
  void updateAllItems();
  void addItemToKernel(Item* i);
  void addItemToItemsSet(Item* i); 
  void printTransitions(void);
};

std::ostream &operator<< (std::ostream &output, const State &state);

#endif