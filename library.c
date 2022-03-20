#include <stdio.h>
#include <stdlib.h>

#include "book_management.h"
#include "listManagement.h"
#include "library.h"
#include "librarian.h"

char* librarianUsername;
char* librarianPassword;

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
    
    FILE* fp_l = fopen("librarian.txt", "r");
    if (!fp_l){
        printf("error opening of librarian.txt\n");
    }else{
        librarianUsername = (char*)malloc(sizeof(char));
        librarianPassword = (char*)malloc(sizeof(char));
        fscanf(fp_l, "%s %s", librarianUsername, librarianPassword);
        printf("%s %s\n", librarianUsername, librarianPassword);
        fclose(fp_l);    
    }

    FILE* fp_s = fopen("students.txt", "r");
    if (!fp_s){
        printf("error opening of students.txt\n");
    }else{
        load_students(fp_s, students, theStudent);
        showListStudents(theStudent->list, theStudent->length);
        fclose(fp_s);
    }
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


// store books to txt
int store_books(FILE* file, Book* books, BookList* theBook){
    Book* tmp = books;
    for (int i = 0; i < theBook->length; i ++){
        tmp = tmp->next;
        fprintf(file, "%u %s %s %u %u\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
    }

    return 0;
}

// the library main menu
void libraryMenu(void){
    int libraryOpen = 1;
    BookList* theBook = (BookList*)malloc(sizeof(BookList));
    StudentList* theStudent = (StudentList*)malloc(sizeof(StudentList)); 
    initLibrary(theBook, theStudent);
    
    while (libraryOpen) {
        int option ;

        printf("\n");
        printf(" *============================================*\n");
        printf(" | * - * - * THE LIBRARY MAIN MENU  * - * - * |\n");
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

        printf("\nChoose one option(1-6):\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n    | * - * - * Librarian login * - * - * |\n");
            librarianMenu(theBook, theStudent);
            break;
        case 2:
            printf("\n| * - * - * Students login * - * - * |\n");
            break;
        case 3:
            printf("\n| * - * - * Register an account * - * - * |\n");
            break;
        case 4:
            printf("\n| * - * - * Search for a book * - * - * |\n");
            break;
        case 5:
            printf("\n          | * - * - * Display all books * - * - * |\n");
            showListBooks(theBook->list, theBook->length);
            break;
        case 6:
            printf("Bye~\n");
            return;
        default:
            printf("Unknown option");
            break;
        }

        // FILE* fp_b = fopen("books.txt", "w");
        // if (!fp_b){
        //     printf("wrong to store!\n");
        // }else{
        //     store_books(fp_b, theBook->list, theBook);
        //     fclose(fp_b);
        // }

        // exitLibrary(theBook);
        // free(theBook);
    }
    
    return;
}
