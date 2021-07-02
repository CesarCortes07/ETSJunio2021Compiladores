
%{
  #include<stdio.h>
  #include "symbol.h"
  #include "rule.h"
  #include "main.h"

  extern "C" int yylex (void);
  extern int yylineno;
  extern char *yytext;
  void yyerror (char const *msg);

  Symbol *current_head;
  std::vector<Symbol*> current_corpo;
%}

%token TK_LIT_STRING
%token TK_LIT_LETTER
%token TK_FLECHA
%token TK_BREAK
%token TK_SEP
%token TK_DIVISOR
%define parse.error verbose
%start gr
%%

gr: regras | ;

regras: lista_regras;
lista_regras: regra | lista_regras regra;
regra: cabeca TK_FLECHA lista_corpos TK_SEP { current_head = NULL; };
cabeca: TK_LIT_STRING {
                       current_head = grammar->getSymbol(yytext);
                       current_corpo.clear();
                      };
lista_corpos: corpo;
lista_corpos: lista_corpos TK_DIVISOR corpo;
corpo: /*empty*/ {
                   current_corpo.push_back(grammar->getEmptySymbol());
                   Rule *rule = new Rule(current_head, current_corpo);
                   grammar->addRule (rule);
                   rule = NULL;
                   current_corpo.clear();
                 };
corpo: lista_palavras {
                       Rule *rule = new Rule(current_head, current_corpo);
                       grammar->addRule(rule);
                       rule = NULL;
                       current_corpo.clear();
                      };
lista_palavras: palavra | lista_palavras palavra;
palavra: TK_LIT_STRING { current_corpo.push_back(grammar->getSymbol(yytext)); };

%%

void yyerror (char const *msg)
{
  fprintf (stderr, "%s on line %d\n", msg, yylineno);
}
