
#include "grammar.h"

Grammar::Grammar()
{
  empty = new Symbol(true);
  dollar = new DollarSymbol();
}

Grammar::~Grammar()
{

  while (rules.size() != 0){
    Rule *r = rules.back();
    rules.pop_back();
    delete r;
  }


  while (symbols.size() != 0){
    Symbol *s = (symbols.begin())->second;
    symbols.erase(symbols.begin());
    delete s;
  }

  delete empty;
  delete dollar;
}

void Grammar::addRule(Rule *rule)
{
  rule->head->terminal = false;
  rules.push_back(rule);
}

void Grammar::addRule(Rule *rule, bool front)
{
  rule->head->terminal = false;
  if(front)
    rules.insert(rules.begin(), rule);
  else
    rules.push_back(rule);
}

Symbol *Grammar::getSymbol(char *str)
{
  std::map<std::string,Symbol*>::iterator it = symbols.find(std::string(str));
  if (it != symbols.end()){
    return (*it).second;
  }else{
    Symbol *newSymbol = new Symbol(str, true);
    symbols[str] = newSymbol;
    return newSymbol;
  }
}

Symbol *Grammar::getEmptySymbol ()
{
  return empty;  
}

Symbol *Grammar::getDollarSymbol ()
{
  return dollar;
}

std::vector<Symbol*> Grammar::terminals (void)
{

  std::vector<Symbol*> terminals;
  std::map<std::string,Symbol*>::iterator itmap;
  for (itmap = symbols.begin(); itmap != symbols.end(); itmap++){
    if ((*itmap).second->terminal == true){
      terminals.push_back ((*itmap).second);
    }
  }
  return terminals;
}

std::vector<Symbol*> Grammar::nonterminals (void)
{
  std::vector<Symbol*> nonterminals;
  std::map<std::string,Symbol*>::iterator itmap;
  for (itmap = symbols.begin(); itmap != symbols.end(); itmap++){
    if ((*itmap).second->terminal == false){
      nonterminals.push_back ((*itmap).second);
    }
  }
  return nonterminals;
}

bool Grammar::deriveToEmpty (Symbol *symbol)
{
  if (symbol->terminal) return false;

}

std::vector<Rule*> Grammar::rulesForNonterminal (Symbol *symbol)
{ 
  std::vector<Rule*> ret;
  if (symbol->terminal){
    throw "Error";
  }
  
  for (Rule *r : rules){
    if (r->head == symbol){
      ret.push_back (r);
    }
  }
  return ret;
}

static int count_map (std::map<Symbol*,std::set<Symbol*> > map)
{
  int ret = map.size();
  for (auto &entry : map){
    ret += entry.second.size();
  }
  return ret;
}

static void debug_print_set (std::set<Symbol*> set)
{
  std::cout << "IMPRESIÓN SET " << std::endl;
  for (Symbol *s : set){
    std::cout << *s << std::endl;
  }
  std::cout << "FIN IMPRESIÓN " << std::endl;

std::map<Symbol*,std::set<Symbol*> > Grammar::first (void)
{
  std::map<Symbol*,std::set<Symbol*> > firsts;
 
  bool keep_going = true;

  bool DEBUG = false;
  
  while (keep_going){
    if (DEBUG){
      std::cout << "====================" << std::endl;
    }
  
    int count = count_map (firsts);
 
    for (Rule *rule : rules){

      if (DEBUG){
        std::cout << "=> CABEZA" << *(rule->head) << std::endl;
      }

      bool body_derives_empty = true;
      for (Symbol *s : rule->body){
        
      	if (s->terminal){
                
                firsts[rule->head].insert (s);
                body_derives_empty = false;
      	  break;
      	}else{
              
                
                if(DEBUG){
                  std::cout << "==> ANALIZA" << *s << std::endl;
                }

      	  std::set<Symbol*> nts = firsts[s];

                std::set<Symbol*> copy = nts;

                if(DEBUG){ 
                  debug_print_set (copy);
                  std::set<Symbol*>::iterator emptyPresent = nts.find(getEmptySymbol());
                  std::cout << "==> ES " << (emptyPresent != nts.end()) << std::endl;
                }

                copy.erase (getEmptySymbol());

                if(DEBUG){ 
                  std::cout << "==> AÑADE" << std::endl;
                  debug_print_set (copy);
                }

      	  firsts[rule->head].insert (copy.begin(), copy.end());

                bool deriveToEmpty = nts.find(getEmptySymbol()) != nts.end();

                if(DEBUG){ 
                  if (deriveToEmpty == true){
                    std::cout << "==> MIEMBRO " << *s << "CONTINUA" << std::endl;
                  }else{
                    std::cout << "==> MIEBRO " << *s << " NO CONTINUA" << std::endl;
                  }
                }
                
                if (deriveToEmpty == false){
              
                  body_derives_empty = false;
                  break; 
                }
      	}
      }

      if (body_derives_empty == true){
        firsts[rule->head].insert (getEmptySymbol());
      }
    }

    if ((count_map (firsts) - count) == 0){
      keep_going = false;
    }
    
  }
  return firsts;
}

std::map<Symbol*,std::set<Symbol*> > Grammar::follow (void)
{
  std::map<Symbol*,std::set<Symbol*> > follows;
  std::map<Symbol*,std::set<Symbol*> > firsts = this->first();
  
  bool keep_going = true;

  bool DEBUG = false;

  Rule *first_rule = rules[0];
  follows[first_rule->head].insert (getDollarSymbol());
  
  while (keep_going){
    if (DEBUG){
      std::cout << "INICIA ITERACIÓN" << std::endl;
    }

    int count = count_map (follows);
  

    for (Rule *rule : rules){

      if (DEBUG){
        std::cout << "=> CABEZA " << *(rule->head) << std::endl;
      }

      std::vector<Symbol*>::iterator it;
      for (it = rule->body.begin(); it != rule->body.end(); it++){
	Symbol *s = *it;

	if (s->terminal) continue;

	if (DEBUG){
	  std::cout << "==> ENCONTRADO " << *s << " to analyze." << std::endl;
	}

	std::vector<Symbol*>::iterator it_next;
	it_next = it+1;

	if (it_next == (rule->body).end()){
	  if (DEBUG) std::cout << "==> NO SIGUIENTE " << *(rule->head) << "." << std::endl;
	  std::set<Symbol*> copy = follows[rule->head];
	  if (DEBUG) std::cout << "TAMAÑO SIGUIENTE "<< copy.size() << std::endl;
	  if (DEBUG) debug_print_set (copy);
	  if (DEBUG) std::cout << "s ES " << *(s) << std::endl;
	  if (DEBUG) debug_print_set (follows[s]);
	  follows[s].insert(copy.begin(), copy.end());
	  continue;
	}

	if (it_next != (rule->body).end()){
	  if (DEBUG) std::cout << "==> SIGUIENTE " << *(*it_next) << "." << std::endl;
	  
	  while (it_next != rule->body.end()){

	    if (DEBUG) std::cout << "==> SIGUIENTE" << *(*it_next) << "..." << std::endl;
	    if ((*it_next)->terminal){
	      follows[s].insert (*it_next);
	      break;
	    }
	    std::set<Symbol*>::iterator emptyPresent = f.find(getEmptySymbol());
	    bool emptyIsPresent = !(emptyPresent == f.end());
	    f.erase (getEmptySymbol());
	    follows[s].insert (f.begin(), f.end()); 

	    if (!emptyIsPresent){
	      break;
	    }else{

	      if ((it_next+1) == rule->body.end()){
		std::set<Symbol*> copy = follows[rule->head];
		follows[s].insert(copy.begin(), copy.end());
	      }
	    }

	    it_next++;
	  }
	}
      }
    }

    
    if ((count_map (follows) - count) == 0){
      
      if (DEBUG) std::cout << "TAMAÑO ESTRUCTURA" << std::endl;
      keep_going = false;
    }
  }

  return follows;
}

void Grammar::print_first_sets (void)
{
  this->print_set(this->first());
}

void Grammar::print_follow_sets (void)
{
  this->print_set(this->follow());
}

void Grammar::print_set (std::map<Symbol*,std::set<Symbol*> > map)
{
  std::map<Symbol*,std::set<Symbol*> > follows = map;
  for (auto& entry : follows){
    std::cout << *(entry.first) << " -- ";
    for (Symbol *s : entry.second){
      std::cout << *s << " ";
    }
    std::cout << std::endl;
  }
}

void Grammar::expand_grammar (void)
{
  Rule* start = (Rule*) this->rules[0];
  char* new_head = (char*) malloc((strlen(start->head->str)+2) * sizeof(char));
  strcpy(new_head, start->head->str);
  strcat(new_head, "'");
  
  Symbol* Start2 = new Symbol(new_head , false);
  std::vector<Symbol*> Start2_body;

  Start2_body.push_back(start->head);

  Rule* new_start = new Rule(Start2, Start2_body);
  addRule(new_start, true);
  free(new_head);
}

std::ostream &operator<< (std::ostream &output, const Grammar &grammar)
{

  int ntc = 0;
  std::map<std::string,Symbol*>::iterator itmap;
  std::map<std::string,Symbol*> map = grammar.symbols;
  for (itmap = map.begin(); itmap != map.end(); itmap++){
    if (!((*itmap).second)->terminal){
      ntc++;
    }
  }

  output << "GRAMATICA " << grammar.rules.size() << " REGLAS " << grammar.symbols.size() << " Y SIMBOLOS (" << ntc << " non-terminals):" << std::endl;
  std::vector<Rule*>::iterator it;
  std::vector<Rule*> r = grammar.rules;
  for (it = r.begin(); it != r.end(); it++){
    output << *(*it);
    if ((it+1) != r.end()){
      output << std::endl;
    }
  }
  return output;
}
