#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "testScanner.h"

int main(int argc, char* argv[]){
	// File pointer
	FILE *filePointer = NULL;
	
	static const char *EXTENSION = ".fs18";
	
	 if(argc == 1){
		// input file pointer 
		filePointer = stdin;

	
		if (filePointer == NULL){
			fprintf(stderr, "Unable To Start stdin: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
		}

		// Prompt user for input
		if (isatty(0)){
			printf("\nFile Not Found. \nEnter Input: ");
		}
		if(!feof(filePointer)){
			testScanner(filePointer);
		}
		fclose(filePointer);
	}
	else {
		
		char *fileName = malloc(sizeof(argv[1]) + sizeof(EXTENSION));
		strncat(fileName, argv[1], strlen(argv[1]));
		strncat(fileName, EXTENSION, strlen(EXTENSION));
		filePointer = fopen(fileName, "r");

		//  input file failure 
		if (filePointer == NULL){
			fprintf(stderr, "Unable To Open '%s': %s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
		}

		// read token 
		if(!feof(filePointer)){
			testScanner(filePointer);
		}
		if (feof(filePointer)){
			printf("\nScanner Complete.\n");
			fclose(filePointer);
		}
	}
 //------------
 
 	// error if more than 2 arguments
	if (argc > 2){
		printf("Exceeded Argument limit.\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}