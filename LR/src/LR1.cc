
#include "LR1.h"

LR1::LR1()
{
  this->type = "LR1"; 
}

LR1::LR1(Grammar* grammar)
{
  this->type = "LR1";
  this->grammar = grammar;
  this->grammar->expand_grammar();
  this->follow = this->grammar->follow();
  this->first = this->grammar->first();
  create_item_set();
  Parser::create_automata();
}

LR1::~LR1()
{
}

void LR1::create_item_set(void) 
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
  std::set<Item*> items_lookahead;

  for(Item *i:  this->items) {
 
    for (auto& entry : this->follow) {
    
      if(*(entry.first) == *i->rule->head) {
        if(i->rule->body.size() > 0) {
        
          for (Symbol *s : entry.second) {
            std::vector<Symbol*> l{s};
            items_lookahead.insert(new Item(i->rule, i->dot, l)); 
          }   
      
        } else {
          for (Symbol *s: Parser::getFollowOf(i->rule->head)) {
            std::vector<Symbol*> l{s};
            if(Parser::isLookaheadInFollow(i->rule->head, s))
              items_lookahead.insert(new Item(i->rule, i->dot, l));
          }
        }     
      } 
    }
  }

  this->clearItems();
  setItems(items_lookahead);
}

std::set<Item*> LR1::getProductionOfItem(Item* item)
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

Item* LR1::getNextItem(Item* i)
{
  for(Item* it : this->items) {
    if( it->rule == i->rule && 
        std::get<0>(i->dot)+1 == std::get<0>(it->dot) && 
        std::get<1>(i->dot) && 
        it->lookahead[0] == i->lookahead[0])
      return it;
  }

  return NULL;
}