%{
#include "token.h"
%}

BACKSLASH [\\]
OPERATOR [\|\+\.\*\(\)\[\]\"\'\?\^\\]
SPECIAL [abfnrtv]
NORMAL_WORD [^\|\+\.\*\(\)\[\]\"\'\?\^\n\r]
ENTER [\n\r]

%%

{ENTER} { yyterminate(); }

%%

int yywrap()
{
	return 1;
}
