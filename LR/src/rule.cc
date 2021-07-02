
#include "rule.h"

Rule::Rule()
{
  head = NULL;
  body.clear();
}

Rule::Rule(Symbol *head)
{
  this->head = head;
  body.clear();
}

Rule::Rule(Symbol *head, std::vector<Symbol*> body)
{
  this->head = head;
  this->body = body;
  this->body_size = body.size();
}

Rule::~Rule()
{
  body.clear();
}

void Rule::addHead(Symbol *head)
{
  this->head = head;
}

void Rule::addBody(std::vector<Symbol*> body)
{
  this->body = body;
  this->body_size = body.size();
}

void Rule::addToBody(Symbol *symbol)
{
  body.push_back(symbol);
  this->body_size = body.size();
}

std::ostream &operator<< (std::ostream &output, const Rule &rule)
{
  output << *(rule.head) << " \u21d2 ";
  std::vector<Symbol*>::iterator it;
  std::vector<Symbol*> r = rule.body;
  for (it = r.begin(); it != r.end(); it++) {
      output << *(*it) << " ";
  }
  return output;
}

bool operator== (const Rule &r1, const Rule &r2)
{
  if(r1.body.size() != r2.body.size())
    return false;

  if(!(r1.head == r2.head)) {
    return false;
  }

  for(int i=0; i<r1.body.size(); i++) {
    if(r1.body.at(i) != r2.body.at(i)) {
      return false; 
      break;
    }
  }
  return true;
}