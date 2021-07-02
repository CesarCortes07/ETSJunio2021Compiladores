
#include "LR0.h"

LR0::LR0()
{
  this->type = "LR0"; 
}

LR0::LR0(Grammar* grammar)
{
  this->type = "LR0";
  this->grammar = grammar;
  create_item_set();
  Parser::create_automata();
}

LR0::~LR0()
{
}

void LR0::create_item_set(void) 
{
  std::vector<Rule*> r = this->grammar->rules; 
  std::vector<Rule*>::iterator it_r;
  std::vector<Symbol*> body;
  std::vector<Symbol*>::iterator it_b;
  int dot;
  bool hasNext;

  for (it_r = r.begin(); it_r != r.end(); it_r++) {
    hasNext = true;
    body = (*it_r)->body;
    dot = 0;

    if(body.size() == 1 && body[0]->empty) {
      hasNext = false;
      Rule *r = new Rule((*it_r)->head);
      Item *i = new Item(r, std::make_tuple(0, hasNext, body[0]));
      addItem(i);
    } else {

      for (it_b = body.begin(); it_b != body.end(); it_b++) {
        Item *i = new Item((*it_r), std::make_tuple(dot, hasNext, (*it_b)));
        addItem(i);
        dot++;
      }

      hasNext = false;
      it_b--; 
      Item *i = new Item((*it_r), std::make_tuple(dot, hasNext, (*it_b)));
      addItem(i);
    }
  }
}

std::set<Item*> LR0::getProductionOfItem(Item* item)
{
  std::set<Item*> items_set;
  std::tuple<int, bool, Symbol*> dot = item->dot;
  Symbol* s = std::get<2>(dot);

  for(Item* it: this->items) {
    
    if(std::get<1>(item->dot)) {
  
      if(std::get<0>(it->dot) == 0 && s == it->rule->head) {
        int last_size = items_set.size();
        items_set.insert(it);
      }
    }
  }
  return items_set;
}

Item* LR0::getNextItem(Item* i)
{
  for(Item* it : this->items) {
    
    if(it->rule == i->rule && std::get<0>(i->dot)+1 == std::get<0>(it->dot) && std::get<1>(i->dot))
      return it;
  }

  return NULL;
}