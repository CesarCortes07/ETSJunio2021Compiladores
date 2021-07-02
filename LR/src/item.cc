#include "item.h"
#include "symbol.h"

Item::Item()
{
}

Item::Item(Rule* rule, std::tuple<int, bool, Symbol*> dot)
{
    this->rule = rule;
    this->dot = dot;
}

Item::Item(Rule* rule, std::tuple<int, bool, Symbol*> dot, std::vector<Symbol*> lookahead)
{
    this->dot = dot;
    this->rule = rule;
    this->lookahead = lookahead;
}

Item::~Item()
{
  lookahead.clear();
}

std::ostream &operator<< (std::ostream &output, const Item &item)
{
  int dot = 0;
  output << *(item.rule->head) << " \u21d2 "; 
  
  if (item.rule->body.size() > 0) {

    for (auto& symbol : item.rule->body) {

      if(dot == std::get<0>(item.dot)) {
        output << "• "; 
      } 
      output << *symbol << " ";
      dot++;
    }

    if (dot == std::get<0>(item.dot)){
      output << "• "; 
    } 

    if (item.lookahead.size() > 0) {
      for (auto& symbol : item.lookahead) {
        output << ", " << *symbol;
      }
    }

    output << std::endl;
  } else {
    output << "• "; 
    if (item.lookahead.size() > 0) {
      for (auto& symbol : item.lookahead) {
        output << ", " << *symbol;
      }
    }
    output << std::endl;
  }
  return output;
}

bool operator==(const Item &i1, const Item &i2)
{

  if(!(i1.rule == i2.rule))
    return false;

  for(int i=0; i < i1.lookahead.size(); i++) {
    if(!(i1.lookahead[i] == i2.lookahead[i]))
      return false;
  }

  if(std::get<0>(i1.dot) != std::get<0>(i2.dot))
    return false;

  return true;
}

bool Item::isBodyEqual(Item* i2)
{

  if(!(this->rule == i2->rule))
    return false;

  if(std::get<0>(this->dot) != std::get<0>(i2->dot))
    return false;

  return true;
}

void Item::printItemWithoutLookahead(void)
{
  int dot = 0;
  std::cout << *this->rule->head << " \u21d2 "; 
  
  if (this->rule->body.size() > 0) {

    for (auto& symbol : this->rule->body) {

      if(dot == std::get<0>(this->dot)) {
        std::cout << "• "; 
      } 
      std::cout << *symbol << " ";
      dot++;
    }

    if (dot == std::get<0>(this->dot)){
      std::cout << "• "; 
    } 
  } else {
    std::cout << "• ";
  }
}