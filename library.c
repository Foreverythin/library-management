#include <stdio.h>
#include <stdlib.h>

#include "book_management.h"
#include "library.h"

// initialize the library, load data to the data structure
void initLibrary(BookList* theBook, StudentList* theStudent) {
    theBook->length = 0;
    theBook->list = (Book*)malloc(sizeof(Book));
    Book* books = theBook->list;
    books->next = NULL;
    theStudent->length = 0;
    theStudent->list = (Student*)malloc(sizeof(Student));
    Student* students = theStudent->list;
    students->next = NULL;
    FILE* fp_b = fopen("books.txt", "r");
    if (!fp_b) {
        printf("error open\n");
    }
    else {
        load_books(fp_b, books, theBook);
        showListBooks(theBook->list, theBook->length);
        fclose(fp_b);
    }
    
    // FILE* fp_l = fopen("librarian.txt", "r");
    // if (!fp_l){
    //     printf("error opening of librarian.txt\n");
    // }else{
    //     librarianUsername = (char*)malloc(sizeof(char));
    //     librarianPassword = (char*)malloc(sizeof(char));
    //     fscanf(fp_l, "%s %s", librarianUsername, librarianPassword);
    //     printf("%s %s\n", librarianUsername, librarianPassword);
    // }
    // fclose(fp_l);

    FILE* fp_s = fopen("students.txt", "r");
    if (!fp_s){
        printf("error opening of students.txt\n");
    }else{
        load_students(fp_s, students, theStudent);
        showListStudents(theStudent->list, theStudent->length);
        fclose(fp_s);
    }
}

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

// load the books from the txt to the book list
int load_books(FILE* file, Book* books, BookList* theBook){
    Book* tmp;

    while (1)
    {
        tmp = books;
        tailInsertBooks(books);
        while (tmp->next != NULL){
		    tmp = tmp->next;
	    }
        if(fscanf(file, "%u %s %s %u %u", &tmp->id, tmp->title, tmp->authors, &tmp->year, &tmp->copies) == EOF){
            break;
        }else{
            theBook->length ++;
        }
    }
    theBook->length ++;
    tailDeleteBooks(books, theBook);

    return 0;
}

//load the information of students from the students.txt
void load_students(FILE* file, Student* students, StudentList* theStudent){
    Student* tmp;

    while (1){
        tmp = students;
        tailInsertStudents(students);
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        if (fscanf(file, "%u %s %s %s", &tmp->id, tmp->name, tmp->username, tmp->password) == EOF){
            break;
        }else{
            theStudent->length ++;
        }
    }
    theStudent->length++;
    tailDeleteStudents(students, theStudent);
}

// display the book list
void showListBooks(Book* books, unsigned int length){
	Book* tmp = books->next;
	while(tmp != NULL){
		printf("%u %s %s %u %u\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
        tmp = tmp->next;
    }
    printf("The number of books is %u\n", length);	
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

// the library main menu
void libraryMenu(void){
    int libraryOpen = 1;
    BookList* theBook = (BookList*)malloc(sizeof(BookList));
    StudentList* theStudent = (StudentList*)malloc(sizeof(StudentList)); 
    initLibrary(theBook, theStudent);
    
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
