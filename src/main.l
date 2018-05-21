

%{
#include <stdio.h>
#include <string.h>

#include "ccc_lib.h"
#define MAX 100

char final[MAX];

%}


LETRA [a-zA-Z]
PALAVRA {LETRA}+

%%
[a-zA-Z0-9]+ {
	camelcase_to_underline(yytext,final);
	printf("%s", final);
	for(int i=0; i < strlen(final);i++){
		final[i] = ' ';
	}
}

[a-zA-Z0-9\_]+ {
	underline_to_camelcase(yytext, final);
	printf("%s", final);
	for(int i=0; i < strlen(final);i++){
		final[i] = ' ';
	}
}


[.\n]* {printf("\n");};
[[:space:]]{1} {printf(" ");};
[[:^space:]]{1} {printf(" ");}  ;



%%

int main() {
  yylex();
  return 0;
}
