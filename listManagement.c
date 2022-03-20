#include <stdio.h>
#include <stdlib.h>

#include "book_management.h"
#include "listManagement.h"

// insert a new node to the book list
void tailInsertBooks(Book* books){
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

// insert a new node to the student list
void tailInsertStudents(Student* students){
    Student* tmp = students;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    Student* new = (Student*)malloc(sizeof(Student));
    new->name = (char*)malloc(sizeof(char));
    new->username = (char*)malloc(sizeof(char));
    new->password = (char*)malloc(sizeof(char));
    new->next = NULL;
    tmp->next = new;
}

// delete a node from the tail of the list
void tailDeleteBooks(Book* books, BookList* theBook){
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

// delete a node from the tail of the list
void tailDeleteStudents(Student* students, StudentList* theStudent){
    Student* pre = students;
    Student* L = students;
    for (int i = 0; i < theStudent->length; i++){
        pre = pre->next;
    }
    Student* tmp = L;
    if (theStudent->length>1){
        for (int i = 0; i < theStudent->length-1; i++){
            tmp = tmp->next;
        }
    }
    tmp->next = NULL;
    free(pre);
    pre = NULL;
    theStudent->length --;
}

// display the book list
void showListBooks(Book* books, unsigned int length){
    if (length == 0){
        printf("\nThere is no books in the library!\n");
    }else{
        printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
        printf("---------------------------------------------------------------\n");
        Book* tmp = books->next;
        while(tmp != NULL){
            printf("|%3u |%12s       |%13s       |%5u |%7u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
            tmp = tmp->next;
        }
        printf("\nThere are %u kinds of books in total.\n", length);
    }
}

//display the student list
void showListStudents(Student* students, unsigned int length){
    Student* tmp = students->next;
    while (tmp != NULL){
        printf("%u %s %s %s\n", tmp->id, tmp->name, tmp->username, tmp->password);
        tmp = tmp->next;
    }
    printf("The number of students is %u\n", length);
}