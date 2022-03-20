#include <stdio.h>
#include <stdlib.h>

#include "book_management.h"
#include "librarian.h"

void librarianMenu(BookList* theBook, StudentList* theStudent){
    int librarianLogin = 1;
    int chances = 3;
    char* inputUsername = (char*)malloc(sizeof(char));
    char* inputPassword = (char*)malloc(sizeof(char));
    printf("%s", librarianPassword);
    printf("%s", librarianUsername);
    printf("\nPlease enter your account: \n");
    scanf("%s", inputUsername);
    printf("Please enter your password: \n");
    scanf("%s", inputPassword);
    while (chances){
        if (inputUsername != librarianUsername || inputPassword != librarianPassword){
            chances--;
            printf("Login failed! You have %d left chances!\n", chances);
            if (chances == 0)
                return;
            printf("\nPlease enter your account: \n");
            scanf("%s", inputUsername);
            printf("Please enter your password: \n");
            scanf("%s", inputPassword);
        }else{
            printf("Login successfully!\n");
            break;
        }
    }

    while (librarianLogin) {
        // int option;

        printf("\n");
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
        printf(" | | [6] DISPLAY ALL USERS                  | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [5] SEARCH SOME USER                   | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [5] DISPLAY BORROWED BOOKS             | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [5] DELETE SOME USER                   | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [6] LOG OUT                            | |\n");
        printf(" ----------------------------------------------\n");

        librarianLogin = 0;
    }
}