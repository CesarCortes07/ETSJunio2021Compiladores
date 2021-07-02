%{
  #include "symbol.h"
  #include "rule.h"
  #include "parser.hh"

  extern "C" int yylex(void);
%}

%option yylineno

SPACE  [\ \t\r]
LETTER [^\ \t\r\n;]
DIGIT  [0-9]

%%

"=>"             return TK_FLECHA;
"|"              return TK_DIVISOR;
";"              return TK_SEP;

{LETTER}*        return TK_LIT_STRING;
\'[^']\'         return TK_LIT_STRING;
\"[^"]*\"        return TK_LIT_STRING;

\n
.


%%
