
#include "state.h"

State::State()
{
}

State::State(std::set<Item*> kernel)
{
  this->kernel = kernel;
  updateAllItems();
}

State::State(int id,
             std::set<Item*> kernel, 
             std::set<Item*> item_set)
{
  this->id = id;
  this->kernel = kernel;
  this->item_set = item_set;
  updateAllItems();
}

State::~State()
{
  this->kernel.clear();
  this->item_set.clear();
  this->transitions.clear();
  this->all_items.clear();
}
 
void State::setId(int id)
{
  this->id = id;
}

void State::setItemSet(std::set<Item*> item_set)
{
  this->item_set.clear();
  this->item_set = item_set;
  updateAllItems();
}

void State::setKernel(std::set<Item*> kernel)
{
  this->kernel = kernel;
  updateAllItems();
}

bool State::haveSameKernel(State* s2)
{
  std::set<Item*>::iterator it;
  if(this->kernel.size() != s2->kernel.size())
    return false;
  
  for (it = this->kernel.begin(); it != this->kernel.end(); it++){
    if (s2->kernel.find((*it)) == s2->kernel.end())
      return false;
  }
  return true;
}

bool State::haveSameKernelItems(State* s2)
{
 
  for (Item* i: this->kernel) {
    bool isIn = false;
    
    for(Item* i2: s2->kernel) {
      if(i->isBodyEqual(i2))
        isIn = true;
    }
    if(!isIn)
      return false;
  }
  return true;
}



std::ostream &operator<< (std::ostream &output, const State &state)
{ 
  output << "Estado " << state.id << ":" << std::endl;
  for(auto& i : state.kernel)
    output << *i;
  
  output << "---------------" << std::endl;

  for(auto& i : state.item_set)
    output << *i;

  if(state.transitions.size() > 0) {
    output << "Transición: " << std::endl;
    for(auto& t : state.transitions)
      output << *t.first << " ---> " << t.second->id << std::endl;
  }
  output << std::endl;
  return output;
}

void State::updateAllItems()
{
  set_union(this->kernel.begin(), this->kernel.end(), 
            this->item_set.begin(), this->item_set.end(), 
            std::inserter(this->all_items, this->all_items.begin()));
}

void State::addItemToKernel(Item* i)
{ 
  this->kernel.insert(i);
  this->updateAllItems();
}

void State::addItemToItemsSet(Item* i)
{
  this->item_set.insert(i);
  this->updateAllItems();
}

void State::printTransitions(void)
{
  if(this->transitions.size() > 0) {
    std::cout << "Transición: " << std::endl;
    for(auto& t : this->transitions)
      std::cout << *t.first << " ---> " << t.second->id << std::endl;
  }
  std::cout << std::endl;
}