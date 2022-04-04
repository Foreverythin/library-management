#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book_management.h"
#include "listManagement.h"
#include "library.h"
#include "librarian.h"
#include "reader.h"
#include "utility.h"

char* librarianUsername;
char* librarianPassword;

// initialize the library, load data to the data structure
// theBook is the pointer pointing to the BookList
// theStudent is also the pointer pointing to the StudentList
// borrows is also the pointer pointing to the first node of the borrowing information list
void initLibrary(BookList* theBook, StudentList* theStudent, BorrowInformation* borrows) {
    theBook->length = 0;
    theBook->list = (Book*)malloc(sizeof(Book));
    Book* books = theBook->list;
    books->next = NULL;
    theStudent->length = 0;
    theStudent->list = (Student*)malloc(sizeof(Student));
    Student* students = theStudent->list;
    students->next = NULL;
    borrows->next = NULL;

    FILE* fp_b = fopen("books.txt", "r");
    if (!fp_b) {
        printf("\n");
    }
    else {
        load_books(fp_b, books, theBook);
        fclose(fp_b);
    }
    
    FILE* fp_l = fopen("librarian.txt", "r");
    if (!fp_l){
        printf("error opening of librarian.txt\n");
    }else{
        librarianUsername = (char*)malloc(sizeof(char));
        librarianPassword = (char*)malloc(sizeof(char));
        fscanf(fp_l, "%s %s", librarianUsername, librarianPassword);
        fclose(fp_l);    
    }

    FILE* fp_r = fopen("readers.txt", "r");
    if (!fp_r){
        printf("Error opening of readers.txt\n");
    }else{
        load_students(fp_r, students, theStudent);
        fclose(fp_r);
    }

    FILE* fp_bo = fopen("borrowInformation.txt", "r");
    if (!fp_bo){
        printf("Error opening of borrowInformation.txt\n");
    }else{
        load_borrowInformation(fp_bo, borrows);
        fclose(fp_bo);
    }
}

// load the books from the txt to the book list
// the file is what you want to read
// theBook is a pointer pointing to BookList
// books is a pointer pointing to the first node of the book list
// return 0 if loaded successfully
int load_books(FILE* file, Book* books, BookList* theBook){
    Book* tmp;

    while (1)
    {
        tmp = books;
        tailInsertBooks(books);
        while (tmp->next != NULL){
		    tmp = tmp->next;
	    }
        if(fscanf(file, "%u %s %s %u %u %u", &tmp->id, tmp->title, tmp->authors, &tmp->year, &tmp->copies, &tmp->lend) == EOF){
            break;
        }else{
            theBook->length ++;
        }
    }
    theBook->length ++;
    tailDeleteBooks(books, theBook->length);
    theBook->length --;

    return 0;
}

//load the information of students from the students.txt
// the file is what you want to read
// theStudent is a pointer pointing to StudentList
// students is a pointer pointing to the first node of the student list
// return 0 if loaded successfully
int load_students(FILE* file, Student* students, StudentList* theStudent){
    Student* tmp;

    while (1){
        tmp = students;
        tailInsertStudents(students);
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        if (fscanf(file, "%u %s %s %s %u", &tmp->id, tmp->name, tmp->username, tmp->password, &tmp->borrow) == EOF){
            break;
        }else{
            theStudent->length ++;
        }
    }
    theStudent->length++;
    tailDeleteStudents(students, theStudent->length);
    theStudent->length--;

    return 0;
}

// load the books' information on loan from the borrowInformation.txt
// the file is what you want to read
// borrows is the pointer pointing to the borrowing information list
// return 0 if loaded successfully
int load_borrowInformation(FILE* file, BorrowInformation* borrows){
    BorrowInformation* tmp;

    while(1){
        tmp = borrows;
        tailInsertBorrowInformation(borrows);
        while (tmp->next != NULL)
            tmp = tmp->next;
        if (fscanf(file, "%u %u", &tmp->stuID, &tmp->bookID) == EOF)
            break;
    }
    tailDeleteBorrowInformation(borrows);

    return 0;
}


// store books to txt
// the file is what you want to write
// theBook is a pointer pointing to BookList
// books is a pointer pointing to the first node of the book list
// return 0 if store successfully
int store_books(FILE* file, Book* books, BookList* theBook){
    Book* tmp = books;
    for (int i = 0; i < theBook->length; i ++){
        tmp = tmp->next;
        fprintf(file, "%u %s %s %u %u %u\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies, tmp->lend);
    }

    return 0;
}

// store readers to txt
// the file is what you want to write
// theStudent is a pointer pointing to StudentList
// students is a pointer pointing to the first node of the student list
// return 0 if store successfully
int store_readers(FILE* file, Student* students, StudentList* theStudent){
    Student* tmp = students;
    for (int i = 0; i < theStudent->length; i ++){
        tmp = tmp->next;
        fprintf(file, "%u %s %s %s %u\n", tmp->id, tmp->name, tmp->username, tmp->password, tmp->borrow);
    }

    return 0;
}

// store borrowing informaiton to txt
// the file is what you want to write
// borrows is the pointer pointing to the borrowing information list
// return 0 if store successfully
int store_borrowInformation(FILE* file, BorrowInformation* borrows){
    BorrowInformation* tmp = borrows;
    tmp = tmp->next;
    while(tmp){
        fprintf(file, "%u %u\n", tmp->stuID, tmp->bookID);
        tmp = tmp->next;
    }
    
    return 0;
}

// register an account for a reader
// the id should not be same to id registered and the length of password should not less than 6
// students is a pointer pointing to the head node of students of the student list
// theStudent is a pointer pointing to the StudentList
void registerAccounts(Student* students, StudentList* theStudent, unsigned int id, char* name, char* username, char* password){
    tailInsertStudents(students);
    theStudent->length ++;
    Student* tmp = students;
    for (int i = 0; i < theStudent->length; i++){
        tmp = tmp->next;
    }
    tmp->id = id;
    strcpy(tmp->name, name);
    strcpy(tmp->username, username);
    strcpy(tmp->password, password);
}

// the main entrance to register an account for a reader
void registerAccountsMain(StudentList* theStudent){
    char* s_id = (char*)malloc(sizeof(char));
    char* name = (char*)malloc(sizeof(char));
    char* username = (char*)malloc(sizeof(char));
    char* password = (char*)malloc(sizeof(char));
    char* passwordAgain = (char*)malloc(sizeof(char));
    printf("\nPlease enter your student ID: \n->");
    scanf("%s", s_id);
    if (!isNumber(s_id)){
        printf("Invalid ID!\n");
        free(name);
        name = NULL;
        free(username);
        username = NULL;
        free(password);
        password = NULL;
        free(passwordAgain);
        password = NULL;
        free(s_id);
        s_id = NULL;
        return;
    }
    unsigned int id = (unsigned)atoi(s_id);
    if (id<=0 || id>999){
        printf("The ID number must be in [1, 999]!\n");
        free(name);
        name = NULL;
        free(username);
        username = NULL;
        free(password);
        password = NULL;
        free(passwordAgain);
        password = NULL;
        free(s_id);
        s_id = NULL;
        return;
    }
    Student* tmp = theStudent->list;
    for (int i = 0; i < theStudent->length; i++){
        tmp = tmp->next;
        if (id == tmp->id){
            printf("The ID may not be correct, because it is the same to others'!\n");
            free(name);
            name = NULL;
            free(username);
            username = NULL;
            free(password);
            password = NULL;
            free(passwordAgain);
            password = NULL;
            free(s_id);
            s_id = NULL;
            return;
        }
    }
    printf("Please enter your name: \n->");
    scanf("%s", name);
    printf("Please enter your username: \n->");
    scanf("%s", username);
    int jump;
    while(1){
        jump = 1;
        tmp = theStudent->list;
        for (int i = 0; i < theStudent->length; i++){
            tmp = tmp->next;
            if (strcmp(tmp->username, username) == 0){
                jump = 0;
                printf("The username has been registered!\n");
                printf("Please enter a username which has not been registered: \n->");
                scanf("%s", username);
                break;
            }
        }
        if (jump)
            break;
    }
    printf("Please enter your password: \n->");
    scanf("%s", password);
    while (strlen(password) < 6){
        printf("The password's length should be at least 6!\n");
        printf("Please enter your password: \n->");
        scanf("%s", password);
    }
    printf("Please repeat your password again: \n->");
    scanf("%s", passwordAgain);
    if (strcmp(password, passwordAgain) != 0)
        printf("The two passwords you entered did not match!\n");
    else{
        registerAccounts(theStudent->list, theStudent, id, name, username, password);
        printf("\nRegistered successfully!\n");
    }
        
    free(name);
    name = NULL;
    free(username);
    username = NULL;
    free(password);
    password = NULL;
    free(passwordAgain);
    password = NULL;
    free(s_id);
    s_id = NULL;
}

// the library main menu
// initialize the information reading at first and store them at last
// initialize the book list, student list and borrowing information at first and destroy them at last
void libraryMenu(void){
    int libraryOpen = 1;
    char* option = (char*)malloc(sizeof(char));
    BookList* theBook = (BookList*)malloc(sizeof(BookList));
    StudentList* theStudent = (StudentList*)malloc(sizeof(StudentList)); 
    BorrowInformation* borrows = (BorrowInformation*)malloc(sizeof(BorrowInformation));
    initLibrary(theBook, theStudent, borrows);
    
    while (libraryOpen) {
        printf("\n");
        printf(" *============================================*\n");
        printf(" | * - * - * THE LIBRARY MAIN MENU  * - * - * |\n");
        printf(" | *                                        * |\n");
        printf(" | | [1] LOG IN FOR LIBRARIANS              | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [2] LOG IN FOR READERS                 | |\n");
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

        printf("\nChoose one option(1-6):\n->");
        scanf("%s", option);
        getchar();
        if (strcmp(option, "1") == 0){
            printf("\n     | * - * - * Librarian login * - * - * |\n");
            librarianMenu(theBook, theStudent); // go to the main menu of librarians
        } 
        else if (strcmp(option, "2") == 0){
            printf("\n     | * - * - * Reader login * - * - * |\n");
            readerMenu(theBook, theStudent, borrows); // go to the main menu of readers
        }
        else if (strcmp(option, "3") == 0){
            printf("\n| * - * - * Register an account * - * - * |\n");
            registerAccountsMain(theStudent); // register an account for a reader
        }     
        else if (strcmp(option, "4") == 0){
            printf("\n   | * - * - * Search for a book * - * - * |\n");
            searchBooksMain(theBook->list, theBook); // search books
        }
        else if (strcmp(option, "5") == 0){
            printf("\n   | * - * - * Display all books * - * - * |\n");
            showListBooks(theBook->list, theBook->length); // show all books
        }
        else if (strcmp(option, "6") == 0){
            printf("Bye~\n");
            break;
        }   
        else{
            printf("Unknown option!\n");
        }

    }

    // store the book list to txt
    FILE* fp_b = fopen("books.txt", "w");
    if (!fp_b){
        printf("wrong to store books!\n");
    }else{
        if (!store_books(fp_b, theBook->list, theBook))
            printf("\nSuccessfully store the books' information!\n");
        else
            printf("\nStoring books'information failed!\n");
        fclose(fp_b);
    }

    // store the reader list to txt
    FILE* fp_r = fopen("readers.txt", "w");
    if (!fp_r){
        printf("wrong to store readers!\n");
    }else{
        if (!store_readers(fp_r, theStudent->list, theStudent))
            printf("Successfully store the readers' information!\n");
        else
            printf("Storing readers'information failed!\n");
        fclose(fp_r);
    }

    // store the borrowing information list to txt
    FILE* fp_bo = fopen("borrowInformation.txt", "w");
    if (!fp_bo){
        printf("Storing borrowing information failed!\n");
    }else{
        if (!store_borrowInformation(fp_bo, borrows))
            printf("Successfully store the borrowing information!\n");
        else
            printf("Storing borrowing information failed!\n");
        fclose(fp_bo);
    }

    // store the librarian information to txt
    FILE* fp_l = fopen("librarian.txt", "w");
    if (!fp_l){
        printf("Wrong to store librarian information!\n");
    }else{
        if (fprintf(fp_l, "%s %s", librarianUsername, librarianPassword) == (strlen(librarianUsername)+strlen(librarianPassword)+1))
            printf("Successfully store the librarian's information!\n");
        else
            printf("Storing the librarian's information failed!\n");
        fclose(fp_l);
    }

    // free space in heap
    free(option);
    option = NULL;

    free(librarianUsername);
    librarianUsername = NULL;
    free(librarianPassword);
    librarianPassword = NULL;

    destroyBook(theBook->list, theBook->length);
    destroyStudent(theStudent->list, theStudent->length);
    destroyBorrowInformation(borrows);
    free(theBook->list);
    theBook->list = NULL;
    free(theStudent->list);
    theStudent->list = NULL;
    free(theBook);
    theBook = NULL;
    free(theStudent);
    theStudent = NULL;
    free(borrows);
    borrows = NULL;
    
    return;
}
