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
void tailDeleteBooks(Book* books, unsigned int length){
	Book* pre = books;
	Book* L = books;
   for (int i = 0; i < length; i ++){
    	pre = pre->next;
   }
   Book* tmp = L;
   if (length>1){
       for (int i = 0; i < length-1; i++){
           tmp = tmp->next;
       }
   }
   tmp->next = NULL;
   free(pre->authors);
   pre->authors = NULL;
   free(pre->title);
   pre->title = NULL;
   free(pre);
   pre = NULL;
}

// delete a node from the tail of the list
void tailDeleteStudents(Student* students, unsigned int length){
    Student* pre = students;
    Student* L = students;
    for (int i = 0; i < length; i++){
        pre = pre->next;
    }
    Student* tmp = L;
    if (length>1){
        for (int i = 0; i < length-1; i++){
            tmp = tmp->next;
        }
    }
    tmp->next = NULL;
    free(pre->name);
    pre->name = NULL;
    free(pre->password);
    pre->password = NULL;
    free(pre->username);
    pre->username = NULL;
    free(pre);
    pre = NULL;
}

//delete a node in the middle of the book list
void middleDeleteBooks(Book* books, BookList* theBook, int index){
    Book* tmp = books;
    for (int i = 0; i < index-1; i++){
        tmp = tmp->next;
    }
    Book* pre = tmp->next;
    tmp->next = pre->next;
    free(pre);
    pre = NULL;
}

//delete a node in the middle of the student list
void middleDeleteStudents(Student* students, StudentList* theStudent, int index){
    Student* tmp = students;
    for (int i = 0; i < index-1; i++){
        tmp = tmp->next;
    }
    Student* pre = tmp->next;
    tmp->next = pre->next;
    free(pre);
    pre = NULL;
}

// display the book list
void showListBooks(Book* books, unsigned int length){
    if (length == 0){
        printf("\nThere is no book in the library!\n");
    }else{
        printf("\n------------------- DISPLAY ALL BOOKS -------------------------");
        printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
        printf("---------------------------------------------------------------\n");
        Book* tmp = books->next;
        while(tmp != NULL){
            printf("|%3u |%12s       |%13s       |%5u |%7u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
            tmp = tmp->next;
        }
        if (length > 1)
            printf("\nThere are %u kinds of books in total.\n", length);
        else
            printf("\nThere are %u kind of books in total.\n", length);
    }
}

//display the student list
void showListStudents(Student* students, unsigned int length){
    if (length == 0){
        printf("\nThere is no reader registered in the library!\n");
    }
    else{
        printf("\n-------------- DISPLAY ALL READERS ------------------");
        printf("\n| ID |     NAME     |    USERNAME    |   PASSWORD   |\n");
        printf("-----------------------------------------------------\n");
        Student* tmp = students->next;
        while (tmp != NULL){
            printf("|%3u |%9s     |%12s    |%11s   |\n", tmp->id, tmp->name, tmp->username, tmp->password);
            tmp = tmp->next;
        }
        if (length > 1)
            printf("\nThere are %u readers registered.\n", length);
        else
            printf("\nThere are %u reader registered.\n", length);
    }
}

void distroyBook(Book* books, unsigned int length){
    while(length){
        tailDeleteBooks(books, length);
        length--;
    }
}

void distroyStudent(Student* students, unsigned int length){
    while(length){
        tailDeleteStudents(students, length);        
        length--;
    }
}