
#ifndef __LR1_H
#define __LR1_H
#include <algorithm>
#include "grammar.h"
#include "item.h"
#include "state.h"
#include "parser.h"

class LR1 : public Parser
{

public:
  LR1();
  LR1(Grammar* grammar);
  ~LR1();

public:
  void create_item_set(void);
  std::set<Item*> getProductionOfItem(Item* item);
  Item* getNextItem(Item* i);
};

#endif