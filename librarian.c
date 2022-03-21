#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book_management.h"
#include "librarian.h"
#include "listManagement.h"

void addNewBook(Book* books, BookList* theBook, unsigned int id, char* title, char* authors, unsigned int year, unsigned int copies){
    tailInsertBooks(books);
    theBook->length++;
    Book* tmp = books;
    for (int i = 0; i < theBook->length; i++){
        tmp = tmp->next;
    }
    tmp->id = id;
    tmp->title = title;
    tmp->authors = authors;
    tmp->year = year;
    tmp->copies = copies;
}

void searchBooksID(Book* books, BookList* theBook, unsigned int id){
    if (theBook->length == 0)
        printf("\nThere is no book in the library now!\n");
    else{
        Book* tmp = books;
        int find = 0;
        int once = 1;
        printf("\n------------------- SEARCHING RESULT --------------------------");
        for(int i = 0; i < theBook->length; i++){
            tmp = tmp->next;
            if (tmp->id == id){
                find++;
                if (once){
                    once = 0;
                    printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                }
                printf("|%3u |%12s       |%13s       |%5u |%7u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
            }
        }
        if (find == 0)
            printf("\nThe search result is none!\n");
        else{
            if (find > 1)
                printf("\n%d results in total.\n", find);
            else
                printf("\n%d result in total.\n", find);
        }
            
    }   
}

void searchBooksTitle(Book* books, BookList* theBook, char* title){
    if (theBook->length == 0)
        printf("\nThere is no book in the library now!\n");
    else{
        Book* tmp = books;
        int find = 0;
        int once = 1;
        printf("\n------------------- SEARCHING RESULT --------------------------");
        for(int i = 0; i < theBook->length; i++){
            tmp = tmp->next;
            if (strcmp(tmp->title, title) == 0){
                find++;
                if (once){
                    once = 0;
                    printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                }
                printf("|%3u |%12s       |%13s       |%5u |%7u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
            }
        }
        if (find == 0)
            printf("\nThe search result is none!\n");
        else{
            if (find > 1)
                printf("\n%d results in total.\n", find);
            else
                printf("\n%d result in total.\n", find);
        }
            
    }
}

void searchBooksAuthors(Book* books, BookList* theBook, char* authors){
    if (theBook->length == 0)
        printf("\nThere is no book in the library now!\n");
    else{
        Book* tmp = books;
        int find = 0;
        int once = 1;
        printf("\n------------------- SEARCHING RESULT --------------------------");
        for(int i = 0; i < theBook->length; i++){
            tmp = tmp->next;
            if (strcmp(tmp->authors, authors) == 0){
                find++;
                if (once){
                    once = 0;
                    printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                }
                printf("|%3u |%12s       |%13s       |%5u |%7u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
            }
        }
        if (find == 0)
            printf("\nThe search result is none!\n");
        else{
            if (find > 1)
                printf("\n%d results in total.\n", find);
            else
                printf("\n%d result in total.\n", find);
        }
            
    }
}

void searchBooksYear(Book* books, BookList* theBook, unsigned int year){
    if (theBook->length == 0)
        printf("\nThere is no book in the library now!\n");
    else{
        Book* tmp = books;
        int find = 0;
        int once = 1;
        printf("\n------------------- SEARCHING RESULT --------------------------");
        for(int i = 0; i < theBook->length; i++){
            tmp = tmp->next;
            if (tmp->year == year){
                find++;
                if (once){
                    once = 0;
                    printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                }
                printf("|%3u |%12s       |%13s       |%5u |%7u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
            }
        }
        if (find == 0)
            printf("\nThe search result is none!\n");
        else{
            if (find > 1)
                printf("\n%d results in total.\n", find);
            else
                printf("\n%d result in total.\n", find);
        }
            
    }   
}

void searchBooksCopies(Book* books, BookList* theBook, unsigned int copies){
    if (theBook->length == 0)
        printf("\nThere is no book in the library now!\n");
    else{
        Book* tmp = books;
        int find = 0;
        int once = 1;
        printf("\n------------------- SEARCHING RESULT --------------------------");
        for(int i = 0; i < theBook->length; i++){
            tmp = tmp->next;
            if (tmp->copies == copies){
                find++;
                if (once){
                    once = 0;
                    printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                }
                printf("|%3u |%12s       |%13s       |%5u |%7u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
            }
        }
        if (find == 0)
            printf("\nThe search result is none!\n");
        else{
            if (find > 1)
                printf("\n%d results in total.\n", find);
            else
                printf("\n%d result in total.\n", find);
        }
            
    }   
}

void librarianMenu(BookList* theBook, StudentList* theStudent){
    int librarianLogin = 1;
    int chances = 3;
    char* inputUsername = (char*)malloc(sizeof(char));
    char* inputPassword = (char*)malloc(sizeof(char));
    printf("\nPlease enter your account: \n->");
    scanf("%s", inputUsername);
    printf("Please enter your password: \n->");
    scanf("%s", inputPassword);
    while (chances){
        if (strcmp(inputUsername, librarianUsername) != 0 || strcmp(inputPassword, librarianPassword) != 0){
            chances--;
            printf("Login failed! You have %d left chances!\n", chances);
            if (chances == 0)
                return;
            printf("\nPlease enter your account: \n->");
            scanf("%s", inputUsername);
            printf("Please enter your password: \n->");
            scanf("%s", inputPassword);
        }else{
            printf("\nLogin successfully!\n");
            break;
        }
    }

    while (librarianLogin) {
        int option;

        printf("\n");
        printf("\n |------------- LIBRARIAN MENU ---------------|\n");
        printf(" ----------------------------------------------\n");
        printf(" | | [1] ADD BOOKS TO THE LIBRARY           | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [2] REMOVE BOOKS FROM THE LIBRARY      | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [3] CHANGE INFORMATION OF BOOKS        | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [4] SEARCH FOR A BOOK                  | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [5] DISPLAY ALL BOOKS                  | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [6] DISPLAY ALL READERS                | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [7] SEARCH SOME READER                 | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [8] DISPLAY BORROWED BOOKS             | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [9] DELETE SOME USER                   | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [10] LOG OUT                           | |\n");
        printf(" ----------------------------------------------\n");

        printf("\nChoose one option(1-10): \n->");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            char searchChoice[6];
            printf("\nWhich one do you want to search by, id, title, author, year or copies?\n->");
            scanf("%s", searchChoice);
            if (strcmp(searchChoice, "id") == 0){
                unsigned int id;
                printf("Which id?\n->");
                scanf("%u", &id);
                searchBooksID(theBook->list, theBook, id);
            }else if (strcmp(searchChoice, "title") == 0){
                char* title = (char*)malloc(sizeof(char));
                printf("Which title?\n->");
                scanf("%s", title);
                searchBooksTitle(theBook->list, theBook, title);
            }else if (strcmp(searchChoice, "author") == 0){
                char* authors = (char*)malloc(sizeof(char));
                printf("Which author?\n->");
                scanf("%s", authors);
                searchBooksAuthors(theBook->list, theBook, authors);
            }else if (strcmp(searchChoice, "year") == 0){
                unsigned int year;
                printf("Which year?\n->");
                scanf("%u", &year);
                searchBooksYear(theBook->list, theBook, year);
            }else if (strcmp(searchChoice, "copies") == 0){
                unsigned int copies;
                printf("How many copies?\n->");
                scanf("%u", &copies);
                searchBooksCopies(theBook->list, theBook, copies);
            }
            
            break;
        case 5:
            showListBooks(theBook->list, theBook->length);
            break;
        case 6:
            showListStudents(theStudent->list, theStudent->length);
            break;
        case 7:
            break;
        case 8:
            break; 
        case 9:
            break;
        case 10:
            return;
        default:
            printf("Unknown option!\n");
            break;
        }
    }
}