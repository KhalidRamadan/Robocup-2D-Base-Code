%option reentrant
%option bison-bridge
%option noyywrap
%option nounistd

%{
	#include "parser.hpp"
	#include<sstream>
	#include<io.h>
	#include<stdio.h>

%}

 
%%

\(													{ return TOKEN_LB; }
\)													{ return TOKEN_RB; }
init												{ return TOKEN_INIT; }
l|r													{														
														char *charval = new char;
														*charval = yytext[0];
														*yylval = charval;
														//andomy
														return TOKEN_SIDE; 
													}
[0-9]+												{
														std::stringstream str;
														str << yytext;
														int temp;
														str >> temp;
														int *intval = new int;
														*intval = temp;
														*yylval = intval;
														return TOKEN_NUMBER;
													}
[a-zA-Z0-9\_\-]+									{ return TOKEN_TEAMNAME; /*TODO: FIX*/ }












%%

