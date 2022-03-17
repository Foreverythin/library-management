#include <stdio.h>
#include <stdlib.h>

typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
		struct _Book *next; //pointer to the next book element
}Book;

typedef struct _BookList {
	 Book* list; // pointer to a list of struct Book.
	 unsigned int length; // number of elements in the (Book*) List 
}BookList;

// int load_books(FILE* books, BookList* theBook);
// void tailDelete(BookList* theBook);
// void exitLibrary(BookList* theBook);
//void tailInsert(BookList* theBook, unsigned int a);
// void showList(BookList* theBook);

void tailInsert(Book* booklist, unsigned int a, BookList theBook){
	Book* tmp = booklist;
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	Book* new = (Book*)malloc(sizeof(Book));
    new->copies = a;
	new->next = NULL;
	tmp->next = new;
    theBook.length ++;
}

// void showList(BookList* theBook){
// 	Book* tmp = theBook->list->next;
// 	while(tmp != NULL){
// 		printf("%u", (tmp->copies));
//         tmp = tmp->next;
//     }
//     printf("The number of books is %u", theBook->length);	
// }

int main(void){
    BookList theBook;// = (BookList*)malloc(sizeof(BookList));
    theBook.list = (Book*)malloc(sizeof(Book));
    theBook.list->next = NULL;

    tailInsert(theBook.list, 1, theBook);
    tailInsert(theBook.list, 2, theBook);

    // showList(theBook);
    // FILE* file = fopen("books.txt", "r");
    // if (file != NULL){
	// 	theBook->length = load_books(file, theBook);
	// }
	// fclose(file);
}
