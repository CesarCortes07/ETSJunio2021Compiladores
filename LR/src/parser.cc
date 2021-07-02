
#include "parser.h"

Parser::Parser()
{
}

Parser::Parser(Grammar* grammar)
{
  this->grammar = grammar;
}
  
Parser::~Parser()
{
  clearItems();
  clearStates();
}

void Parser::setType(std::string type)
{
  this->type = type;
}

void Parser::clearItems()
{
  this->items.clear();
}

void Parser::setItems(std::set<Item*> items)
{
  this->items = items;
}

void Parser::clearStates()
{
  this->states.clear();
}

int Parser::getNextStateId(void)
{
  int maxid = 0;
  for(State *s: this->states)
    if(s->id > maxid)
      maxid = s->id;

  return maxid+1;
}

void Parser::addItem(Item *item)
{
  this->items.insert(item);
}

void Parser::print_item_set (void)
{
  std::cout << std::endl << this->type << " ITEM:" << std::endl;
  for(auto& item : this->items){
    std::cout << *item;
  }
}
    
void Parser::print_automata(void)
{
  std::cout << std::endl << this->type << " AUTOMATA:" << std::endl;
  for(State* s : this->states)
    std::cout << *s;
}

void Parser::print_first_sets(void)
{
  std::cout << std::endl << "SET 1: " << std::endl;
  this->grammar->print_first_sets();
}

void Parser::print_follow_sets(void)
{
  std::cout << std::endl << "SIGUIENTE SET: " << std::endl;
  this->grammar->print_follow_sets();
}

void Parser::createTransitionStates(State* state)
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
    new_state = createState(new_state);
    new_state->setItemSet(closure(new_state->kernel));
    std::pair<Symbol*, State*> transition = std::make_pair(s, new_state);
    state->transitions.insert(transition);
  }
}

std::set<Symbol*> Parser::getFollowOf(Symbol* s)
{
  return this->follow[s];
}

State* Parser::createState(State* newState)
{

  for(State* s : this->states) { 
    if (newState->haveSameKernel(s)) {
      return s;
    }
  }

  int id = getNextStateId();
  newState->setId(id);
  newState->setItemSet(closure(newState->all_items));
  this->states.insert(newState);
  return newState;
}

std::set<Item*> Parser::closure(std::set<Item*> kernel)
{
  std::set<Item*> items_set;
  std::set<Item*> new_set;
  std::tuple<int, bool, Symbol*> dot;
  Symbol* s;
  bool change = true;
  int last_size;

  for(Item* item : kernel) {
      new_set = getProductionOfItem(item);
      set_union(items_set.begin(), items_set.end(), 
                new_set.begin(), new_set.end(), 
                std::inserter(items_set, items_set.begin()));
  }

  while(change) {
    change = false;
    last_size = items_set.size(); 

    for (Item* i: items_set) { 
      new_set = getProductionOfItem(i);
      set_union(items_set.begin(), items_set.end(), 
                new_set.begin(), new_set.end(), 
                std::inserter(items_set, items_set.begin()));          
    }

    if(last_size != items_set.size())
      change = true;
  }
  
  return items_set;
}

bool Parser::isLookaheadInFirst(Symbol* head, Symbol* lookahead)
{
  for(Symbol* s: this->first[head]) {
    if(lookahead == s)
      return true;
  }
  return false;
}

bool Parser::isLookaheadInFollow(Symbol* head, Symbol* lookahead)
{
  for(Symbol* s: this->follow[head]) {
    if(lookahead == s)
      return true;
  }
  return false;
}

bool Parser::isEmptyInFirst(Symbol* head)
{
    for(Symbol* s: this->first[head]) {
    if(s->empty){
      return true;
    }
  }
  return false;
}

void Parser::create_automata(void)
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
}

void Parser::expandStates(void)
{
  for(State* s: this->states) {
    s->setItemSet(closure(s->kernel));
    s->updateAllItems();
  }
}

void Parser::generateDotFile(std::string outFile)
{
  int port = 0;
  std::ofstream dotFile;
  dotFile.open (outFile);
  dotFile << "digraph g { graph [fontsize=30 labelloc=\"t\" label=\"\" splines=true overlap=false rankdir = \"LR\"]; ratio = auto;\n\n";

  for(State *s: this->states){
    port = 0;
  
    if(s->id == 1){
      dotFile << "\t\"state" << s->id << "\" [ style = \"filled\" penwidth = 1 fillcolor = \"#D3D3D3\" fontname = \"Courier New\" shape = \"Mrecord\" label = <<table border=\"0\" cellborder=\"0\" cellpadding=\"3\" bgcolor=\"#D3D3D3\">\n";
    }
    else{
      dotFile << "\t\"state" << s->id << "\" [ style = \"filled\" penwidth = 1 fillcolor = \"white\" fontname = \"Courier New\" shape = \"Mrecord\" label = <<table border=\"0\" cellborder=\"0\" cellpadding=\"3\" bgcolor=\"white\">\n";
    }
  
    dotFile << "\t\t<tr><td bgcolor=\"black\" align=\"center\" colspan=\"2\"><font color=\"white\">State #" << s->id << "</font></td></tr>\n";

    for(Item* i : s->kernel) {
      dotFile << "\t\t<tr><td align=\"left\" port=\"r" << port << "\"><font face=\"bold\">" << *i << "</font></td></tr>\n";
      port++;
    }
  
    for(Item* i : s->item_set) {
      dotFile << "\t\t<tr><td align=\"left\" port=\"r" << port << "\"><font color=\"gray25\" face=\"bold\">" << *i << "</font></td></tr>\n";
      dotFile << "\t\t<tr><td align=\"left\" port=\"r" << port << "\">" << *i << "</td></tr>\n";
      port++;
    }
    dotFile << "\t</table>>];\n\n";
  }


  std::set<State*>::iterator it = this->states.begin();


  dotFile << "nowhere [style=invis,shape=point]\n";
  dotFile << "nowhere -> state" << (*it)->id << "[ penwidth = 3 fontsize = 22 fontcolor = \"black\"];\n";

  for(; it != this->states.end(); it++){
    for(std::pair<Symbol*, State* > t : (*it)->transitions){
    
      dotFile << "ESTADO" << (*it)->id << " -> ESTADO" << t.second->id << "[ penwidth = 3 fontsize = 22 fontcolor = \"black\" label = \"" << t.first->str << "\" ];\n";
    }
  }

  dotFile << "}";
  dotFile.close();
}