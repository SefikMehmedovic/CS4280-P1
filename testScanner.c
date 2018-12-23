#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "scanner.h"
#include "testScanner.h"

// Token name array to print to terminal 
char *tokenNames[38] = {
	"End of File", 
	"Error", 
	"Identifier", 
	"Integer", 
	"Equal Sign",
	"Less Then", 
	"Less Equal", 
	"Greater Then", 
	"Greater Equal", 
	"Not Equal",
	"Equal Equal",
	"Colon",
	"Plus Sign", 
	"Minus Sign", 
	"Asterisk", 
	"Slash", 
	"Percent Sign", 
	"Period", 
	"Open Parenthesis", 
	"Close Parenthesis", 
	"Comma",
	"Open Brace", 
	"Close Brace", 
	"Semicolon", 
	"Open Bracket", 
	"Close Bracket",
	"Begin Keyword", 
	"End Keyword", 
	"Iter Keyword", 
	"Void Keyword",
	"Var Keyword", 
	"Return keyword", 
	"Read Keyword", 
	"Print Keyword", 
	"Program Keyword",
	"Cond Keyword",
	"Then Keyword",
	"Let Keyword"
};

// function calls testScanner
void testScanner (FILE *infile){
	token_t tempToken;
	int lineNum = 1;
	do{
		tempToken = scanner(infile, &lineNum);
		if(strcmp(tokenNames[tempToken.tkIdentifier], "Error") == 0){
		printf("Scanner Error: %s Not Allowed At Line: %i.\n", tempToken.tkString, tempToken.lineNum);
			printf("Exiting\n");
			exit(EXIT_FAILURE);
		}
		else{
		printf("TokenID: %s Instance: %s Line#: %i\n", tokenNames[tempToken.tkIdentifier], tempToken.tkString, tempToken.lineNum);
		}
	} while(!feof(infile));
}