
#ifndef __GRAMAR_H
#define __GRAMAR_H
#include <map>
#include <set>
#include <iostream>
#include <ostream>
#include <vector>
#include "symbol.h"
#include "rule.h"

class Grammar
{
private:
  Symbol *empty;
  Symbol *dollar;
  
public:
  std::vector<Rule*> rules;
  std::map<std::string, Symbol*> symbols;
  
public:
  Grammar();
  ~Grammar();
  void addRule(Rule *rule);
  void addRule(Rule *rule, bool front);
  Symbol *getSymbol(char *str);
  Symbol *getEmptySymbol ();
  Symbol *getDollarSymbol ();
  std::map<Symbol*,std::set<Symbol*> > first (void);
  std::map<Symbol*,std::set<Symbol*> > follow (void);
  void print_first_sets (void);
  void print_follow_sets (void);
  void expand_grammar(void);

private:
  std::vector<Rule*> rulesForNonterminal(Symbol*);
  bool deriveToEmpty(Symbol*);
  std::vector<Symbol*> terminals (void);
  std::vector<Symbol*> nonterminals (void);
  void print_set (std::map<Symbol*,std::set<Symbol*> > map);
};

std::ostream &operator<< (std::ostream &output, const Grammar &grammar);

#endif
