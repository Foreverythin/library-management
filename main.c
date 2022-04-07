#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "book_management.h"
#include "library.h"

int main(int argc, char** argv){
	char* bookFile = (char*)malloc(sizeof(char));
	if (argc != 2){
		printf("Error\nExpected use: ./library <books.txt>\n");
	}else{
		strcpy(bookFile, argv[1]);
		FILE* fp = fopen(bookFile, "r");
		if (!fp) {
			printf("No such file: %s!\n", bookFile);
		}else {
			fclose(fp);
			printf("\n  Welcome to our library~\n");
			libraryMenu(bookFile); // go to the main menu of the library
		}
	}
	free(bookFile);
	return 0;
}
