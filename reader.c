#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book_management.h"
#include "listManagement.h"
#include "librarian.h"

void readerMenu(BookList* theBook, StudentList* theStudent){
    int readerLogin = 0;
    char* option = (char*)malloc(sizeof(char));

    int chances = 3;
    char* inputUsername = (char*)malloc(sizeof(char));
    char* inputPassword = (char*)malloc(sizeof(char));
    printf("\nPlease enter your username: \n->");
    scanf("%s", inputUsername);
    Student* tmp = theStudent->list;
    Student* usernameEqual = (Student*)malloc(sizeof(Student));
    usernameEqual->next = NULL;
    int usernameEqualLength = 0;
    Student* tmpp;
    for (int i = 0; i < theStudent->length; i++){
        tmp = tmp->next;
        tmpp = usernameEqual;
        if (strcmp(tmp->username, inputUsername) == 0){
            tailInsertStudents(usernameEqual);
            usernameEqualLength ++;
            for (int i = 0; i < usernameEqualLength; i++){
                tmpp = tmpp->next;
            }
            strcpy(tmpp->username, inputUsername);
            strcpy(tmpp->password, tmp->password);
            strcpy(tmpp->name, tmp->name);
        }
    }
    if (usernameEqualLength){
        while (chances){
            printf("Please enter your password: \n->");
            scanf("%s", inputPassword);
            tmpp = usernameEqual;
            for (int i = 0; i < usernameEqualLength; i++){
                tmpp = tmpp->next;
                if (strcmp(tmpp->password, inputPassword) == 0){
                    printf("\nLogin successfully, %s!\n", tmpp->name);
                    readerLogin = 1;
                    break;
                }
            }
            if (readerLogin){
                break;
            }else{
                chances--;
                printf("Login failed! You have %d left chances!\n", chances);
            }
        }
    }else{
        printf("This username has not been registered!\n");
    }


    while (readerLogin) {

        printf("\n");
        printf("\n |-------------- READER MENU -----------------|\n");
        printf(" ----------------------------------------------\n");
        printf(" | | [1] DISPLAY ALL BOOKS                  | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [2] SEARCH FOR A BOOK                  | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [3] DISPLAY BOOKS THAR CAN BE BORROWED | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [4] BORROW A BOOK                      | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [5] RETURN A BOOK                      | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [6] CHANGE PERSONAL INFORMATION        | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [7] LOG OUT                            | |\n");
        printf(" ----------------------------------------------\n");

        printf("\nChoose one option(1-7): \n->");
        scanf("%s", option);

        if (strcmp(option, "1") == 0)
            showListBooks(theBook->list, theBook->length);
        else if (strcmp(option, "2") == 0)
            searchBooksMain(theBook->list, theBook);
        else if (strcmp(option, "7") == 0)
            readerLogin = 0;
        else
            printf("Unknown option!\n");
    }


    distroyStudent(usernameEqual, usernameEqualLength);
    free(usernameEqual);
    free(option);
}