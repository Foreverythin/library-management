#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book_management.h"
#include "listManagement.h"
#include "librarian.h"
#include "utility.h"

void changePersonalInformation(Student* students, StudentList* theStudent, unsigned int id){
    Student* tmp = students;
    char* username = (char*)malloc(sizeof(char));
    char* password = (char*)malloc(sizeof(char));
    int numChanges = 0;
    for (int i = 0; i < theStudent->length; i++){
        tmp = tmp->next;
        if (tmp->id == id){
            printf("\n-----------------------------------------------------\n");
            printf("| ID |     NAME     |    USERNAME    |   PASSWORD   |\n");
            printf("|%3u |%9s     |%12s    |%11s   |\n", tmp->id, tmp->name, tmp->username, tmp->password);
            printf("-----------------------------------------------------\n");
            char* yes_no = (char*)malloc(sizeof(char));
            while (1){
                printf("Do you want to change your username?(yes/no)\n->");
                scanf("%s", yes_no);
                if (strcmp(yes_no, "yes") == 0){
                    printf("What username do you want to change to?\n->");
                    scanf("%s", username);
                    strcpy(tmp->username, username);
                    numChanges ++;
                    break;
                }else if (strcmp(yes_no, "no") == 0){
                    break;
                }else
                    printf("Unknown option!\n");
            }
            while (1){
                printf("Do you want to change your password?(yes/no)\n->");
                scanf("%s", yes_no);
                if (strcmp(yes_no, "yes") == 0){
                    printf("What password do you want to change to?\n->");
                    scanf("%s", password);
                    strcpy(tmp->password, password);
                    numChanges ++;
                    break;
                }else if (strcmp(yes_no, "no") == 0){
                    break;
                }else
                    printf("Unknown option!\n");
            }
            free(yes_no);
            yes_no = NULL;
            break;
        }
    }
    if (numChanges)
        printf("Successfully change your personal information!\n");
    free(username);
    username = NULL;
    free(password);
    password = NULL;
}

void borrowABook(Book* books, unsigned int length, Student* students, BorrowInformation* borrows, unsigned int stuID){
    Student* tmp = students;
    tmp = tmp->next;
    while(tmp){
        if (tmp->id == stuID)
            break;
        tmp = tmp->next;
    }
    if (tmp->borrow == 5){
        printf("You are able to borrow at most 5 books! And you have already borrowed 5 books!\n");
        return;
    }
    displayAvailableBooks(books, length);
    printf("\n");
    char* s_bookID = (char*)malloc(sizeof(char));
    printf("Which book do you want to borrow?(Enter the book ID)\n->");
    scanf("%s", s_bookID);
    if (!isNumber(s_bookID)){
        printf("Invalid ID!\n");
        free(s_bookID);
        s_bookID = NULL;
        return;
    }else{
        unsigned int bookID = (unsigned)atoi(s_bookID);

        BorrowInformation* tmp_borrows = borrows;
        tmp_borrows = tmp_borrows->next;
        while (tmp_borrows)
        {
            if (tmp_borrows->stuID == stuID && tmp_borrows->bookID == bookID){
                printf("You have borrowed this book for one copy!\n");
                free(s_bookID);
                s_bookID = NULL;
                return;
            }
            tmp_borrows = tmp_borrows->next;
        }

        Book* tmpp = books;
        tmpp = tmpp->next;
        int judge = 0;
        while(tmpp){
            if (tmpp->id == bookID){
                judge = 1;
                break;
            }
            tmpp = tmpp->next;
        }
        if (judge == 0){
            printf("No book has the ID %u", bookID);
            free(s_bookID);
            s_bookID = NULL;
            return;
        }else{
            if (tmpp->lend == tmpp->copies){
                printf("This book is not available!\n");
                free(s_bookID);
                s_bookID = NULL;
                return;
            }
        }
        printf("---------------------------------------------------------------\n");
        printf("| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
        printf("---------------------------------------------------------------\n");
        printf("|%3u |%12s       |%13s       |%5u |%7u |\n", tmpp->id, tmpp->title, tmpp->authors, tmpp->year, tmpp->copies);
        printf("---------------------------------------------------------------\n");
        char* yes_no = (char*)malloc(sizeof(char));
        printf("Are you sure to borrow this book?(yes/no)\n->");
        scanf("%s", yes_no);
        while(strcmp(yes_no, "yes")!=0 && strcmp(yes_no, "no")!=0){
            printf("Unknown choice!\n");
            printf("Are you sure to borrow this book?(yes/no)\n->");
            scanf("%s", yes_no);
        }
        if (strcmp(yes_no, "yes") == 0){
            tmpp->lend ++;
            tmp->borrow ++;
            tailInsertBorrowInformation(borrows);
            BorrowInformation* tmpBorrows = borrows;
            while(tmpBorrows->next)
                tmpBorrows = tmpBorrows->next;
            tmpBorrows->stuID = stuID;
            tmpBorrows->bookID = tmpp->id;
            printf("Successfully borrow one book!\n");
        }else
            printf("Borrow failed!\n");
        free(yes_no);
        yes_no = NULL;
    }
    free(s_bookID);
    s_bookID = NULL;
}

void displayMyBooksOnLoan(Book* books, BorrowInformation* borrows, unsigned int stuID){
    BorrowInformation* tmp_borrows = borrows;
    tmp_borrows = tmp_borrows->next;
    int once = 1;
    int in = 0;
    Book* tmp_books = books;
    while(tmp_borrows){
        if (tmp_borrows->stuID == stuID){
            if (once){
                printf("\n-------------- DISPLAY BOOKS I BORROWED --------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR |\n");
                printf("------------------------------------------------------\n");
                once = 0;
            }
            in ++;
            tmp_books=books->next;
            while(tmp_books){
                if(tmp_books->id == tmp_borrows->bookID){
                    printf("|%3u |%12s       |%13s       |%5u |\n", tmp_books->id, tmp_books->title, tmp_books->authors, tmp_books->year);
                }
                tmp_books = tmp_books->next;
            }
        }
        tmp_borrows = tmp_borrows->next;
    }
    if (in == 0){
        printf("You have not borrowed one book!\n");
        return;
    }else{
        printf("------------------------------------------------------\n");
        printf("You have borrowed %d books in total.\n", in);
    }
}

void readerMenu(BookList* theBook, StudentList* theStudent, BorrowInformation* borrows){
    int readerLogin = 0;
    char* option = (char*)malloc(sizeof(char));
    int currentID;

    int chances = 3;
    char* inputUsername = (char*)malloc(sizeof(char));
    char* inputPassword = (char*)malloc(sizeof(char));
    printf("\nPlease enter your username: \n->");
    scanf("%s", inputUsername);
    Student* tmp = theStudent->list;
    Student userEqual;
    userEqual.next = NULL;
    userEqual.name = (char*)malloc(sizeof(char));
    userEqual.username = (char*)malloc(sizeof(char));
    userEqual.password = (char*)malloc(sizeof(char));
    userEqual.id = 0;
    for (int i = 0; i < theStudent->length; i++){
        tmp = tmp->next;
        if (strcmp(tmp->username, inputUsername) == 0){
            userEqual.id = tmp->id;
            strcpy(userEqual.username, inputUsername);
            strcpy(userEqual.password, tmp->password);
            strcpy(userEqual.name, tmp->name);
            break;
        }
    }
    if (userEqual.id){
        while (chances){
            printf("Please enter your password: \n->");
            scanf("%s", inputPassword);
            if (strcmp(userEqual.password, inputPassword) == 0){
                printf("\nLogin successfully, %s!\n", userEqual.name);
                currentID = userEqual.id;
                readerLogin = 1;
                break;
            }else{
                chances--;
                printf("Login failed! You have %d left chances!\n", chances);
            }
        }
    }else{
        printf("This username has not been registered!\n");
    }
    free(inputUsername);
    inputUsername = NULL;
    free(inputPassword);
    inputPassword = NULL;
    free(userEqual.name);
    userEqual.name = NULL;
    free(userEqual.username);
    userEqual.username = NULL;
    free(userEqual.password);
    userEqual.password = NULL;

    while (readerLogin) {

        printf("\n");
        printf("\n |-------------- READER MENU -----------------|\n");
        printf(" ----------------------------------------------\n");
        printf(" | | [1] DISPLAY ALL BOOKS                  | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [2] SEARCH FOR A BOOK                  | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [3] DISPLAY AVAILABLE BOOKS            | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [4] BORROW A BOOK                      | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [5] RETURN A BOOK                      | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [6] DISPLAY MY BOOKS ON LOAN           | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [7] CHANGE PERSONAL INFORMATION        | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [8] LOG OUT                            | |\n");
        printf(" ----------------------------------------------\n");

        printf("\nChoose one option(1-8): \n->");
        scanf("%s", option);

        if (strcmp(option, "1") == 0)
            showListBooks(theBook->list, theBook->length);
        else if (strcmp(option, "2") == 0)
            searchBooksMain(theBook->list, theBook);
        else if (strcmp(option, "3") == 0)
            displayAvailableBooks(theBook->list, theBook->length);
        else if (strcmp(option, "4") == 0)
            borrowABook(theBook->list, theBook->length, theStudent->list, borrows, currentID);
        else if (strcmp(option, "6") == 0)
            displayMyBooksOnLoan(theBook->list, borrows, currentID);
        else if (strcmp(option, "7") == 0)
            changePersonalInformation(theStudent->list, theStudent, currentID);
        else if (strcmp(option, "8") == 0)
            readerLogin = 0;
        else
            printf("Unknown option!\n");
    }

    free(option);
    option = NULL;
}