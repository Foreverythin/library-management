#include <stdio.h>
#include <stdlib.h>

#include "library.h"
#include "book_management.h"

#define bookFile "books.txt"

//initialize the library
//read books from txt
void initLibrary(char* bookFile, BookList* theBook){
	FILE* file;
	file = fopen(bookFile, "r");
	if (file != NULL){
		theBook.length = boad_books(file);
	}
	fclose(file);
}
//
////create a file to store the database of books
//void store_books(FILE* file){
//	
//}
//
////load books from txt if the book file "books.txt" exist and store them to the book list
int load_books(FILE* books, BookList* theBook){
	int numbooks = 0;
	BookList* tmp;

	while(!feof(books)){
		tmp = tailInsert(theBook);
		fscanf(books, "%d %s %s %d %d", &(tmp->id), &(tmp->title), &(tmp->authors), &(tmp->year), &(tmp->copies));
		numbooks ++;
	}

	return numbooks;
}
//
////exit the library
//void exitLibrary(BookList* theBook){
//	//
//}
//

//insert a node at the tail of the book list and return the pointer pointing the last node
BookList* tailInsert(BookList* theBook){
	BookList* tmp = (BookList*)malloc(sizeof(BookList));
	tmp = theBook;
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	BookList* new = (BookList*)malloc(sizeof(BookList));
	new->next = NULL;
	tmp->next = new;

	return tmp;
}

////the library main menu
void libraryMenu(void){
	int libraryOpen = 1;
	BookList* theBook = (BookList*)malloc(sizeof(BookList));
	theBook->next = NULL;	
	initLibrary(bookFile, theBook);

	while (libraryOpen){
		printf(" *============================================*\n");
		printf(" | * - * - * Welcome to Our Library * - * - * |\n");
		printf(" | *                                        * |\n");
		printf(" | | [1] LOG IN FOR LIBRARIANS              | |\n");
		printf(" | *                                        * |\n");
		printf(" | | [2] LOG IN FOR STUDENTS                | |\n");	
		printf(" | *                                        * |\n");
		printf(" | | [3] REGISTER AN ACCOUNT                | |\n");
		printf(" | *                                        * |\n");
		printf(" | | [4] SEARCH FOR A BOOK                  | |\n");
		printf(" | *                                        * |\n");
		printf(" | | [5] DISPLAY ALL BOOKS                  | |\n");
		printf(" | *                                        * |\n");
		printf(" | | [6] QUIT                               | |\n");
		printf(" | *                                        * |\n");
		printf(" | * - * - * - * - * - * - * - * - * - * -  * |\n");
		printf(" *============================================*\n");

		return;
	}
}

