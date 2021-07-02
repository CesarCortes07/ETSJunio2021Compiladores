
#ifndef __LALR1_H
#define __LALR1_H
#include <algorithm>
#include "grammar.h"
#include "item.h"
#include "state.h"
#include "parser.h"
#include "LR1.h"

class LALR1 : public LR1
{

public:
  LALR1();
  LALR1(Grammar* grammar);
  ~LALR1();

public: 
  State* createState(State* newState);
  void createTransitionStates(State* state);
  void create_automata(void);
  std::set<Item*> getProductionOfItem(Item* item);
  void print_automata(void);
};

#endif