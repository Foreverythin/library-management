#include <stdio.h>
#include <stdlib.h>

#include "book_management.h"
#include "library.h"

// initialize the library, load data to the data structure
void initLibrary(BookList* theBook) {
    theBook->length = 0;
    theBook->list = (Book*)malloc(sizeof(Book));
    Book* books = theBook->list;
    books->next = NULL;
    FILE* fp = fopen("books.txt", "r");
    if (!fp) {
        printf("error open\n");
    }
    else {
        load_books(fp, books, theBook);
        showList(theBook->list, theBook->length);
    }
}

// insert a new node to the list
void tailInsert(Book* books){
    Book* tmp = books;
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	Book* new = (Book*)malloc(sizeof(Book));
    new->title = (char*)malloc(sizeof(char));
    new->authors = (char*)malloc(sizeof(char));
	new->next = NULL;
	tmp->next = new;
}

// delete a node from the tail of the list
void tailDelete(Book* books, BookList* theBook){
	Book* pre = books;
	Book* L = books;
   for (int i = 0; i < theBook->length; i ++){
    	pre = pre->next;
   }
   Book* tmp = L;
   if (theBook->length>1){
       for (int i = 0; i < theBook->length-1; i++){
           tmp = tmp->next;
       }
   }
   tmp->next = NULL;
   free(pre);
   pre = NULL;
   theBook->length --;
}

// load the books from the txt to the book list
int load_books(FILE* fp, Book* books, BookList* theBook){
    Book* tmp;

    while (1)
    {
        tmp = books;
        tailInsert(books);
        while (tmp->next != NULL){
		    tmp = tmp->next;
	    }
        if(fscanf(fp, "%u %s %s %u %u", &tmp->id, tmp->title, tmp->authors, &tmp->year, &tmp->copies) == EOF){
            break;
        }else{
            theBook->length ++;
        }
    }
    theBook->length ++;
    tailDelete(books, theBook);

    return 0;
}

// display the book list
void showList(Book* books, unsigned int length){
	Book* tmp = books->next;
	while(tmp != NULL){
		printf("%u %s %s %u %u\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
        tmp = tmp->next;
    }
    printf("The number of books is %u\n", length);	
}

// the library main menu
void libraryMenu(void){
    int libraryOpen = 1;
    BookList* theBook = (BookList*)malloc(sizeof(BookList));
    initLibrary(theBook);
    
    while (libraryOpen) {
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

        // exitLibrary(theBook);
        // free(theBook);
        return;
    }

    return;
}
