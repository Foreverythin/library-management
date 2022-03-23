#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book_management.h"
#include "listManagement.h"
#include "librarian.h"

void readerMenu(BookList* theBook, StudentList* theStudent){
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
    // Student* usernameEqual = (Student*)malloc(sizeof(Student));
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
    free(inputPassword);
    free(userEqual.name);
    free(userEqual.username);
    free(userEqual.password);

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

    free(option);
}