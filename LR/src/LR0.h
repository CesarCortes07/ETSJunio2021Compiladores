
#ifndef __LR0_H
#define __LR0_H
#include <algorithm>
#include "grammar.h"
#include "item.h"
#include "state.h"
#include "parser.h"

class LR0 : public Parser
{

public:
  LR0();
  LR0(Grammar* grammar);
  ~LR0();

public:
  void create_item_set(void);
  std::set<Item*> getProductionOfItem(Item* item);
  Item* getNextItem(Item* i);
};

#endif