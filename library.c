#include <stdio.h>
#include <stdlib.h>

#include "book_management.h"
#include "library.h"

//initialize the library
//read books from txt
void initLibrary(BookList theBook){
	FILE* fp;

	fp = fopen("books.txt", "r");
	if (!fp){
		printf("error");
		exit(1);
	}else{
		load_books(fp, theBook);
	}
	fclose(fp);
}
//
////create a file to store the database of books
//void store_books(FILE* file){
//	
//}
//
////load books from txt if the book file "books.txt" exist and store them to the book list
int load_books(FILE* fp, BookList theBook){
	Book* tmp;

	while(!feof(fp)){
		tmp = tailInsert(theBook);
		fscanf(fp, "%u %s %s %u %u", &(tmp->id), (tmp->title), (tmp->authors), &(tmp->year), &(tmp->copies));
		fgetc(fp);
	}

	return 0;
}

//delete a node from the tail of the book list
//void tailDelete(BookList* theBook){
//	Book* pre = theBook->list;
//	Book* L = theBook->list;
//    for (int i = 0; i < theBook->length; i ++){
//     	pre = pre->next;
//    }
//    Book* tmp = L;
//    if (theBook->length>1){
//        for (int i = 0; i < theBook->length-1; i++){
//            tmp = tmp->next;
//        }
//    }
//    tmp->next = NULL;
//    free(pre);
//    pre = NULL;
//    theBook->length --;
//}

////exit the library
//void exitLibrary(BookList* theBook){
//	while(theBook->length > 0){
//		tailDelete(theBook);
//	}
//	free(theBook->list);
//	theBook->list = NULL; 
//}

//insert a node at the tail of the book list and return the pointer pointing the last node
Book* tailInsert(BookList theBook){
	Book* tmp = theBook.list;
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	Book* new = (Book*)malloc(sizeof(Book));
	new->next = NULL;
	tmp->next = new;
	theBook.length ++;

	return new;
}

//遍历链表 用于测试
void showList(Book* book, BookList theBook){
	Book* tmp = book->next;
	while(tmp != NULL){
		printf("%u %s %s %u %u", (tmp->id), (tmp->title), (tmp->authors), (tmp->year), (tmp->copies));
        tmp = tmp->next;
    }
    printf("The number of books is %u", theBook.length);	
}

////the library main menu
void libraryMenu(void){
	int libraryOpen = 1;
	BookList theBook;
	theBook.list = (Book*)malloc(sizeof(Book));
	theBook.list->next = NULL;
	initLibrary(theBook);
	showList(theBook.list, theBook);

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

		//exitLibrary(theBook);
		//free(theBook);
		return;
	}
}

      
