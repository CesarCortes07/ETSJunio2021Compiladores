
#ifndef __MAIN_H
#define __MAIN_H
#include <iostream>
#include <vector>
#include "symbol.h"
#include "rule.h"
#include "grammar.h"
#include "parser.h"
#include "LR0.h"
#include "LR1.h"
#include "LALR1.h"

extern int yyparse(void);
extern Grammar *grammar;

#endif
