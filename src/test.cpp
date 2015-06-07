/*
 * test.cpp
 *
 *  Created on: 2015. 3. 30.
 *      Author: 근홍
 */

#include "token.h"
#include "hangul_lex.hpp"

#include <iostream>
#include <cstdio>

int main()
{
	yyFlexLexer lexer;
	lexer.yyrestart(&std::cin);

	bool running = true;
	while(running)
	{
		switch(lexer.yylex())
		{
		case 0:
		{
			printf("End of file.\n");
			running = false;
			break;
		}
		case WITH_BATCHIM:
		{
			printf("With batchim: %s\n", lexer.YYText());
			break;
		}
		case WITHOUT_BATCHIM:
		{
			printf("Without batchim: %s\n", lexer.YYText());
			break;
		}
		case INCOMPLETE_CHOSUNG:
		{
			printf("With batchim: %s\n", lexer.YYText());
			break;
		}
		case FLUSH:
		{
			printf("Flush.\n");
			running = false;
			break;
		}
		case END_OF_FILE:
		{
			printf("EOF.\n");
			running = false;
			break;
		}
		default:
		{
			printf("Unknown: %s\n", lexer.YYText());
			running = false;
			break;
		}
		}
	}
	return 0;
}
