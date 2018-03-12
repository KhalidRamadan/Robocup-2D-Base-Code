
%define api.pure full
%lex-param { void *scanner }
%parse-param { void *scanner }

%{
#define YYSTYPE	void*
void yyerror(void* yyscanner, const char *e);
int yylex (YYSTYPE * yylval_param , void* yyscanner);
%}

%token		TOKEN_LB
%token		TOKEN_RB
%token		TOKEN_INIT
%token		TOKEN_SIDE
%token		TOKEN_NUMBER
%token		TOKEN_TEAMNAME





%%

command: command_init;
command_init: TOKEN_LB TOKEN_INIT TOKEN_SIDE TOKEN_NUMBER TOKEN_TEAMNAME;

%%

void yyerror(void* yyscanner, const char *e)
{
}

