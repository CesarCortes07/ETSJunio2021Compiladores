#include "LALR1.h"

LALR1::LALR1()
{
  this->type = "LALR1"; 
}
LALR1::LALR1(Grammar* grammar)
{
  this->type = "LALR1";
  this->grammar = grammar;
  this->grammar->expand_grammar();
  this->follow = this->grammar->follow();
  this->first = this->grammar->first();
  LR1::create_item_set();
  create_automata();
}

LALR1::~LALR1()
{
}

void LALR1::create_automata(void)
{ 
 
  std::vector<State*> states;
  bool change = true;
  int last_size = 0;
  Item* start = *this->items.begin(); 
  std::set<Item*> kernel = {start}; 
  std::set<Item*> items_set = closure(kernel);

  State* starting_state = new State(0, kernel, items_set);
  createTransitionStates(starting_state);
  this->states.insert(starting_state);

  while(change) {
    change = false;
    last_size = this->states.size();
    for(State* s : this->states) {
      createTransitionStates(s);
      this->states.insert(s);

      for(auto& ts : s->transitions) {
        createTransitionStates(ts.second);
        this->states.insert(ts.second);
      }
    }
    if(last_size != this->states.size())
      change = true;
  }

  Parser::expandStates();
}

State* LALR1::createState(State* newState)
{
 
  for(State* s : this->states) { 
    if (newState->haveSameKernelItems(s)) {
      
      for(Item* i: newState->kernel)
        s->addItemToKernel(i);  
      for(Item* i: newState->item_set)
        s->addItemToItemsSet(i);  
      return s;
    }
  }

  int id = Parser::getNextStateId();
  newState->setId(id);
  newState->setItemSet(Parser::closure(newState->all_items));
  this->states.insert(newState);
  return newState;
}

void LALR1::createTransitionStates(State* state)
{
  std::set<Symbol*> symbols;

  for(auto& i : state->all_items) {
    if(std::get<1>(i->dot))
      symbols.insert(std::get<2>(i->dot));
  }

  for(auto& s : symbols) {
    std::set<Item*> kernel;

    for(auto& i : state->all_items) {
 
      if(std::get<1>(i->dot) && std::get<2>(i->dot) == s) {

        Item* nextItem = getNextItem(i);
        if(nextItem != NULL)
          kernel.insert(nextItem);
      }   
    }
    State* new_state = new State(kernel);
    new_state = LALR1::createState(new_state);
    new_state->setItemSet(closure(new_state->kernel));
    std::pair<Symbol*, State*> transition = std::make_pair(s, new_state);
    state->transitions.insert(transition);
  }
}

std::set<Item*> LALR1::getProductionOfItem(Item* item)
{
  std::set<Item*> items_set;
  std::tuple<int, bool, Symbol*> dot = item->dot;
  Symbol* s = std::get<2>(dot);

  if(!(std::get<1>(dot)) || s->terminal)
    return items_set;    

  for(Item* it: this->items) {

      if(std::get<0>(it->dot) == 0 && s == it->rule->head) {

        if(item->rule->body_size - std::get<0>(dot) == 1) {
          if(it->lookahead[0] == item->lookahead[0])
            items_set.insert(it);

        } else {

          if(!(item->rule->body[std::get<0>(dot)+1]->terminal)) {
       
            if(Parser::isLookaheadInFirst(item->rule->body[std::get<0>(dot)+1], it->lookahead[0]))
              items_set.insert(it);

            if(Parser::isEmptyInFirst(item->rule->body[std::get<0>(dot)+1])){

              if(Parser::isLookaheadInFollow(item->rule->body[std::get<0>(dot)+1], it->lookahead[0]))
                items_set.insert(it);
            }

          } else {
            if(it->lookahead[0] == item->rule->body[std::get<0>(dot)+1])
              items_set.insert(it);
          }
        }  
      }
    }

  return items_set;
} 


void LALR1::print_automata(void)
{
  std::cout << std::endl << this->type << " automata:" << std::endl;

  std::vector< std::pair<Item*, std::vector<Symbol*> > >item_map;
  std::vector< std::pair<Item*, std::vector<Symbol*> > >::iterator itmap;
  bool found;

  for(State* s : this->states) {
    item_map.clear();
    std::cout << "State " << s->id << ":" << std::endl;

    for (Item* item: s->kernel) {
  
      found = false;
      for (itmap = item_map.begin(); itmap != item_map.end(); itmap++){
        if ((*itmap).first->isBodyEqual(item)) {
          (*itmap).second.push_back(item->lookahead[0]);
          found = true;
          break;
        }
      }
    
      if(!found){
        item_map.push_back(std::make_pair( item, item->lookahead));
      }
    } 


    for (itmap = item_map.begin(); itmap != item_map.end(); itmap++) {
      (*itmap).first->printItemWithoutLookahead();

      std::cout << ", ";
      for(Symbol* symbol : (*itmap).second) 
        std::cout << *symbol << " ";
    }
    std::cout << std::endl << "---------------" << std::endl;

    item_map.clear();

    for (Item* item: s->item_set) {

      found = false;
      for (itmap = item_map.begin(); itmap != item_map.end(); itmap++){
        if ((*itmap).first->isBodyEqual(item)) {
          (*itmap).second.push_back(item->lookahead[0]);
          found = true;
          break;
        }
      }
  
      if(!found){
        item_map.push_back(std::make_pair( item, item->lookahead));
      }
    }


    for (itmap = item_map.begin(); itmap != item_map.end(); itmap++) {
      (*itmap).first->printItemWithoutLookahead();

      std::cout << ", ";
      for(Symbol* symbol : (*itmap).second) 
        std::cout << *symbol << " ";
      std::cout << std::endl;  
    }
    s->printTransitions();
  }
}