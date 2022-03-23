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

BookList find_book_by_id (Book* books, BookList* theBook, unsigned int id){
    Book* tmp = books;
    BookList searchBookList;
    searchBookList.length = 0;
    searchBookList.list = (Book*)malloc(sizeof(Book));
    searchBookList.list->next = NULL;
    for (int i = 0; i < theBook->length; i++){
        tmp = tmp->next;
        if (tmp->id == id){
            tailInsertBooks(searchBookList.list);
            searchBookList.length++;
            Book* tmpp = searchBookList.list;
            for (int i = 0; i < searchBookList.length; i ++){
                tmpp = tmpp->next;
            }
            tmpp->id = tmp->id;
            tmpp->title = tmp->title;
            tmpp->authors = tmp->authors;
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->next = NULL;
        }
    }

    return searchBookList;
}

BookList find_book_by_title (Book* books, BookList* theBook, const char *title){
    Book* tmp = books;
    BookList searchBookList;
    searchBookList.length = 0;
    searchBookList.list = (Book*)malloc(sizeof(Book));
    searchBookList.list->next = NULL;
    for (int i = 0; i < theBook->length; i++){
        tmp = tmp->next;
        if (strcmp(tmp->title, title) == 0){
            tailInsertBooks(searchBookList.list);
            searchBookList.length++;
            Book* tmpp = searchBookList.list;
            for (int i = 0; i < searchBookList.length; i ++){
                tmpp = tmpp->next;
            }
            tmpp->id = tmp->id;
            tmpp->title = tmp->title;
            tmpp->authors = tmp->authors;
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->next = NULL;
        }
    }

    return searchBookList;
}

BookList find_book_by_author (Book* books, BookList* theBook, const char *authors){
    Book* tmp = books;
    BookList searchBookList;
    searchBookList.length = 0;
    searchBookList.list = (Book*)malloc(sizeof(Book));
    searchBookList.list->next = NULL;
    for (int i = 0; i < theBook->length; i++){
        tmp = tmp->next;
        if (strcmp(tmp->authors, authors) == 0){
            tailInsertBooks(searchBookList.list);
            searchBookList.length++;
            Book* tmpp = searchBookList.list;
            for (int i = 0; i < searchBookList.length; i ++){
                tmpp = tmpp->next;
            }
            tmpp->id = tmp->id;
            tmpp->title = tmp->title;
            tmpp->authors = tmp->authors;
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->next = NULL;
        }
    }

    return searchBookList;
}

BookList find_book_by_year (Book* books, BookList* theBook, unsigned int year){
    Book* tmp = books;
    BookList searchBookList;
    searchBookList.length = 0;
    searchBookList.list = (Book*)malloc(sizeof(Book));
    searchBookList.list->next = NULL;
    for (int i = 0; i < theBook->length; i++){
        tmp = tmp->next;
        if (tmp->year == year){
            tailInsertBooks(searchBookList.list);
            searchBookList.length++;
            Book* tmpp = searchBookList.list;
            for (int i = 0; i < searchBookList.length; i ++){
                tmpp = tmpp->next;
            }
            tmpp->id = tmp->id;
            tmpp->title = tmp->title;
            tmpp->authors = tmp->authors;
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->next = NULL;
        }
    }

    return searchBookList;
}

BookList find_book_by_copies (Book* books, BookList* theBook, unsigned int copies){
    Book* tmp = books;
    BookList searchBookList;
    searchBookList.length = 0;
    searchBookList.list = (Book*)malloc(sizeof(Book));
    searchBookList.list->next = NULL;
    for (int i = 0; i < theBook->length; i++){
        tmp = tmp->next;
        if (tmp->copies == copies){
            tailInsertBooks(searchBookList.list);
            searchBookList.length++;
            Book* tmpp = searchBookList.list;
            for (int i = 0; i < searchBookList.length; i ++){
                tmpp = tmpp->next;
            }
            tmpp->id = tmp->id;
            tmpp->title = tmp->title;
            tmpp->authors = tmp->authors;
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->next = NULL;
        }
    }

    return searchBookList;
}

void searchReadersName(Student* students, StudentList* theStudent, char* name){
    if (theStudent->length == 0)
        printf("\nThere is no book in the library now!\n");
    else{
        Student* tmp = students;
        int find = 0;
        int once = 1;
        printf("\n------------------- SEARCHING RESULT --------------------------");
        for(int i = 0; i < theStudent->length; i++){
            tmp = tmp->next;
            if (strcmp(tmp->name, name) == 0){
                find++;
                if (once){
                    once = 0;
                    printf("\n| ID |     NAME     |    USERNAME    |   PASSWORD   |\n");
                }
                printf("|%3u |%9s     |%12s    |%11s   |\n", tmp->id, tmp->name, tmp->username, tmp->password);
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

void searchReadersID(Student* students, StudentList* theStudent, unsigned int id){
    if (theStudent->length == 0)
        printf("\nThere is no reader registered in the library now!\n");
    else{
        Student* tmp = students;
        int find = 0;
        int once = 1;
        printf("\n------------------- SEARCHING RESULT --------------------------");
        for(int i = 0; i < theStudent->length; i++){
            tmp = tmp->next;
            if (tmp->id == id){
                find++;
                if (once){
                    once = 0;
                    printf("\n| ID |     NAME     |    USERNAME    |   PASSWORD   |\n");
                }
                printf("|%3u |%9s     |%12s    |%11s   |\n", tmp->id, tmp->name, tmp->username, tmp->password);
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

void searchBooksMain(Book* books, BookList* theBook){
    if (theBook->length == 0)
        printf("\nThere is no book in the library!\n");
    else{
        char searchChoice4[6];
        printf("\nWhich one do you want to search by, id, title, author, year or copies?\n->");
        scanf("%s", searchChoice4);
        if (strcmp(searchChoice4, "id") == 0){
            unsigned int id;
            printf("Which id?\n->");
            scanf("%u", &id);
            BookList tmp;
            tmp = find_book_by_id(theBook->list, theBook, id);
            if (tmp.length != 0){
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                Book* indexTmp = tmp.list->next;
                while(indexTmp != NULL){
                    printf("|%3u |%12s       |%13s       |%5u |%7u |\n", indexTmp->id, indexTmp->title, indexTmp->authors, indexTmp->year, indexTmp->copies);
                    indexTmp = indexTmp->next;
                }
                if (tmp.length == 1)
                    printf("\n%d result in total.\n", tmp.length);
                else
                    printf("\n%d results in total.\n", tmp.length);
            }else{
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\nThe search result is none!\n");
            } 
            distroyBook(tmp.list, tmp.length);
            free(tmp.list);
        }else if (strcmp(searchChoice4, "title") == 0){
            char* title = (char*)malloc(sizeof(char));
            printf("Which title?\n->");
            scanf("%s", title);
            BookList tmp;
            tmp = find_book_by_title(theBook->list, theBook, title);
            if (tmp.length != 0){
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                Book* indexTmp = tmp.list->next;
                while(indexTmp != NULL){
                    printf("|%3u |%12s       |%13s       |%5u |%7u |\n", indexTmp->id, indexTmp->title, indexTmp->authors, indexTmp->year, indexTmp->copies);
                    indexTmp = indexTmp->next;
                }
                if (tmp.length == 1)
                    printf("\n%d result in total.\n", tmp.length);
                else
                    printf("\n%d results in total.\n", tmp.length);
            }else{
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\nThe search result is none!\n");
            }
            free(title);
            distroyBook(tmp.list, tmp.length);
            free(tmp.list);
        }else if (strcmp(searchChoice4, "author") == 0){
            char* authors = (char*)malloc(sizeof(char));
            printf("Which author?\n->");
            scanf("%s", authors);
            BookList tmp;
            tmp = find_book_by_author(theBook->list, theBook, authors);
            if (tmp.length != 0){
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                Book* indexTmp = tmp.list->next;
                while(indexTmp != NULL){
                    printf("|%3u |%12s       |%13s       |%5u |%7u |\n", indexTmp->id, indexTmp->title, indexTmp->authors, indexTmp->year, indexTmp->copies);
                    indexTmp = indexTmp->next;
                }
                if (tmp.length == 1)
                    printf("\n%d result in total.\n", tmp.length);
                else
                    printf("\n%d results in total.\n", tmp.length);
            }else{
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\nThe search result is none!\n");
            }
            free(authors);
            distroyBook(tmp.list, tmp.length);
            free(tmp.list);
        }else if (strcmp(searchChoice4, "year") == 0){
            unsigned int year;
            printf("Which year?\n->");
            scanf("%u", &year);
            BookList tmp;
            tmp = find_book_by_year(theBook->list, theBook, year);
            if (tmp.length != 0){
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                Book* indexTmp = tmp.list->next;
                while(indexTmp != NULL){
                    printf("|%3u |%12s       |%13s       |%5u |%7u |\n", indexTmp->id, indexTmp->title, indexTmp->authors, indexTmp->year, indexTmp->copies);
                    indexTmp = indexTmp->next;
                }
                if (tmp.length == 1)
                    printf("\n%d result in total.\n", tmp.length);
                else
                    printf("\n%d results in total.\n", tmp.length);
            }else{
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\nThe search result is none!\n");
            }
            distroyBook(tmp.list, tmp.length);
            free(tmp.list);
        }else if (strcmp(searchChoice4, "copies") == 0){
            unsigned int copies;
            printf("How many copies?\n->");
            scanf("%u", &copies);
            BookList tmp;
            tmp = find_book_by_copies(theBook->list, theBook, copies);
            if (tmp.length != 0){
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                Book* indexTmp = tmp.list->next;
                while(indexTmp != NULL){
                    printf("|%3u |%12s       |%13s       |%5u |%7u |\n", indexTmp->id, indexTmp->title, indexTmp->authors, indexTmp->year, indexTmp->copies);
                    indexTmp = indexTmp->next;
                }
                if (tmp.length == 1)
                    printf("\n%d result in total.\n", tmp.length);
                else
                    printf("\n%d results in total.\n", tmp.length);
            }else{
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\nThe search result is none!\n");
            }
            distroyBook(tmp.list, tmp.length);
            free(tmp.list);
        }else{
            printf("Unknown choice!\n");
        }
    }
    
}

void searchReadersMain(StudentList* theStudent){
    if (theStudent->length == 0){
        printf("\nThere is no reader registered in the library!\n");
    }
    else{
        char searchChoice7[4];
        printf("\nWhich one do you want to search by, id or name?\n->");
        scanf("%s", searchChoice7);
        if (strcmp(searchChoice7, "id") == 0){
            unsigned int id;
            printf("Which id?\n->");
            scanf("%u", &id);
            searchReadersID(theStudent->list, theStudent, id);
        }else if(strcmp(searchChoice7, "name") == 0){
            char* name = (char*)malloc(sizeof(char));
            printf("Which name?\n->");
            scanf("%s", name);
            searchReadersName(theStudent->list, theStudent, name);
            free(name);
        }else{
            printf("Unknown choice!\n");
        }
    }
    
}

void librarianMenu(BookList* theBook, StudentList* theStudent){
    int librarianLogin = 1;
    char* option = (char*)malloc(sizeof(char));

    int chances = 3;
    char* inputUsername = (char*)malloc(sizeof(char));
    char* inputPassword = (char*)malloc(sizeof(char));
    printf("\nPlease enter your username: \n->");
    scanf("%s", inputUsername);
    printf("Please enter your password: \n->");
    scanf("%s", inputPassword);
    while (chances){
        if (strcmp(inputUsername, librarianUsername) != 0 || strcmp(inputPassword, librarianPassword) != 0){
            chances--;
            printf("Login failed! You have %d left chances!\n", chances);
            if (chances == 0)
                return;
            printf("\nPlease enter your username: \n->");
            scanf("%s", inputUsername);
            printf("Please enter your password: \n->");
            scanf("%s", inputPassword);
        }else{
            printf("\nLogin successfully!\n");
            break;
        }
    }
    free(inputUsername);
    free(inputPassword);

    while (librarianLogin) {

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
        scanf("%s", option);

        if (strcmp(option, "4") == 0)
            searchBooksMain(theBook->list, theBook);
        else if (strcmp(option, "5") == 0)
            showListBooks(theBook->list, theBook->length);
        else if (strcmp(option, "6") == 0)
            showListStudents(theStudent->list, theStudent->length);
        else if (strcmp(option, "7") == 0)
            searchReadersMain(theStudent);
        else if (strcmp(option, "10") == 0)
            librarianLogin = 0;
        else
            printf("Unknown option!\n");
    }

    free(option);
}