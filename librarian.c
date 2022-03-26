#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book_management.h"
#include "librarian.h"
#include "listManagement.h"
#include "utility.h"

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
            strcpy(tmpp->title, tmp->title);
            strcpy(tmpp->authors, tmp->authors);
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->lend = tmp->lend;
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
            strcpy(tmpp->title, tmp->title);
            strcpy(tmpp->authors, tmp->authors);
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->lend = tmp->lend;
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
            strcpy(tmpp->title, tmp->title);
            strcpy(tmpp->authors, tmp->authors);
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->lend = tmp->lend;
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
            strcpy(tmpp->title, tmp->title);
            strcpy(tmpp->authors, tmp->authors);
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->lend = tmp->lend;
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
            strcpy(tmpp->title, tmp->title);
            strcpy(tmpp->authors, tmp->authors);
            tmpp->year = tmp->year;
            tmpp->copies = tmp->copies;
            tmpp->lend = tmp->lend;
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
        printf("\n----------------- SEARCHING RESULT ------------------");
        for(int i = 0; i < theStudent->length; i++){
            tmp = tmp->next;
            if (strcmp(tmp->name, name) == 0){
                find++;
                if (once){
                    once = 0;
                    printf("\n| ID |     NAME     |    USERNAME    |   PASSWORD   |\n");
                    printf("-----------------------------------------------------\n");
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
        printf("\n----------------- SEARCHING RESULT ------------------");
        for(int i = 0; i < theStudent->length; i++){
            tmp = tmp->next;
            if (tmp->id == id){
                find++;
                if (once){
                    once = 0;
                    printf("\n| ID |     NAME     |    USERNAME    |   PASSWORD   |\n");
                    printf("-----------------------------------------------------\n");
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
                printf("---------------------------------------------------------------\n");
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
                printf("\n------------------ SEARCHING RESULT -----------------");
                printf("\nThe search result is none!\n");
            } 
            destroyBook(tmp.list, tmp.length);
            free(tmp.list);
            tmp.list = NULL;
        }else if (strcmp(searchChoice4, "title") == 0){
            char* title = (char*)malloc(sizeof(char));
            printf("Which title?\n->");
            scanf("%s", title);
            BookList tmp;
            tmp = find_book_by_title(theBook->list, theBook, title);
            if (tmp.length != 0){
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                printf("---------------------------------------------------------------\n");
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
            title = NULL;
            destroyBook(tmp.list, tmp.length);
            free(tmp.list);
            tmp.list = NULL;
        }else if (strcmp(searchChoice4, "author") == 0){
            char* authors = (char*)malloc(sizeof(char));
            printf("Which author?\n->");
            scanf("%s", authors);
            BookList tmp;
            tmp = find_book_by_author(theBook->list, theBook, authors);
            if (tmp.length != 0){
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                printf("---------------------------------------------------------------\n");
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
            authors = NULL;
            destroyBook(tmp.list, tmp.length);
            free(tmp.list);
            tmp.list = NULL;
        }else if (strcmp(searchChoice4, "year") == 0){
            unsigned int year;
            printf("Which year?\n->");
            scanf("%u", &year);
            BookList tmp;
            tmp = find_book_by_year(theBook->list, theBook, year);
            if (tmp.length != 0){
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                printf("---------------------------------------------------------------\n");
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
            destroyBook(tmp.list, tmp.length);
            free(tmp.list);
            tmp.list = NULL;
        }else if (strcmp(searchChoice4, "copies") == 0){
            unsigned int copies;
            printf("How many copies?\n->");
            scanf("%u", &copies);
            BookList tmp;
            tmp = find_book_by_copies(theBook->list, theBook, copies);
            if (tmp.length != 0){
                printf("\n------------------- SEARCHING RESULT --------------------------");
                printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
                printf("---------------------------------------------------------------\n");
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
            destroyBook(tmp.list, tmp.length);
            free(tmp.list);
            tmp.list = NULL;
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

void addBooksMain(Book* books, BookList* theBook){
    unsigned int id;
    char* title = (char*)malloc(sizeof(char));
    char* authors = (char*)malloc(sizeof(char));
    unsigned int year;
    unsigned int copies;
    printf("The book's ID you want to add to the library: \n->");
    scanf("%d", &id);
    if (id<0 || id>999){
        printf("The Book ID must be in (0, 1000)!\n");
        free(title);
        title = NULL;
        free(authors);
        authors = NULL;
        return;
    }
    Book* tmp = books;
    tmp = tmp->next;
    while(tmp){
        if (tmp->id == id){
            printf("The book whose ID is %d has already been collected in the library.\n", id);
            printf("So how many copies of this book do you want to add: \n->");
            scanf("%u", &copies);
            tmp->copies += copies;
            printf("Successfully add books!\n");
            break;
        }
        tmp = tmp->next;
    }
    if (!tmp){
        tailInsertBooks(books);
        theBook->length ++;
        Book* t = books;
        for (int i = 0; i < theBook->length; i++){
            t = t->next;
        }
        printf("The book's title: \n->");
        scanf("%s", t->title);
        printf("The book's authors: \n->");
        scanf("%s", t->authors);
        printf("The year of publication of this book: \n->");
        scanf("%u", &year);
        while (year <= 0 || year > 2022){
            printf("Invalid year!\n");
            printf("The year of publication of this book: \n->");
            scanf("%u", &year);
        }
        t->year = year;
        printf("The book's copies: \n->");
        scanf("%u", &t->copies);
        t->id = id;
        printf("Successfully add books!\n");
    }

    free(title);
    title = NULL;
    free(authors);
    authors = NULL;
}

void removeBooksID(Book* books, BookList* theBook, unsigned int id){
    BookList tmp;
    tmp = find_book_by_id(theBook->list, theBook, id);
    if (tmp.length != 0){
        printf("\n-------------------------- SEARCHING RESULT -----------------------------");
        printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES | ON LOAN |\n");
        printf("-------------------------------------------------------------------------\n");
        Book* indexTmp = tmp.list->next;
        int lendtmp;
        while(indexTmp != NULL){
            printf("|%3u |%12s       |%13s       |%5u |%7u |%8u |\n", indexTmp->id, indexTmp->title, indexTmp->authors, indexTmp->year, indexTmp->copies, indexTmp->lend);
            printf("-------------------------------------------------------------------------\n");
            lendtmp = indexTmp->lend;
            indexTmp = indexTmp->next;
        }
        if (tmp.length == 1)
            printf("\n%d result in total.\n", tmp.length);
        else
            printf("\n%d results in total.\n", tmp.length);
        if (lendtmp > 0){
            printf("This book can not be removed because it is on loan now!\n");
            destroyBook(tmp.list, tmp.length);
            free(tmp.list);
            tmp.list = NULL;
            return;
        }
        printf("Are you sure to remove it?\n->");
        char* yes_no = (char*)malloc(sizeof(char));
        scanf("%s", yes_no);
        while (strcmp(yes_no, "yes") != 0 && strcmp(yes_no, "no") != 0){
            printf("Unknown option!\n");
            printf("Are you sure to remove it?(yes/no)\n->");
            scanf("%s", yes_no);
        }
        if (strcmp(yes_no, "yes") == 0){
            int index = 0;
            Book* indexBooks = books->next;
            while(indexBooks){
                index ++;
                if(indexBooks->id == id)
                    break;
                indexBooks = indexBooks->next;
            }
            middleDeleteBooks(books, theBook, index);
            theBook->length --;
            printf("Successfully remove the book!\n");
        }else
            printf("Remove books failed!\n");
        free(yes_no);
        yes_no = NULL;
    }else{
        printf("\n------------------ SEARCHING RESULT -----------------");
        printf("\nNo book to remove!\n");
    } 
    destroyBook(tmp.list, tmp.length);
    free(tmp.list);
    tmp.list = NULL;
}

void removeBooksMain(Book* books, BookList* theBook){
    displayBorrowedBooks(books, theBook->length);
    char* s_id = (char*)malloc(sizeof(char));
    printf("Which book do you want to remove?(Enter the book ID)\n->");
    scanf("%s", s_id);
    if (!isNumber(s_id)){
        printf("Invalid ID!\n");
        free(s_id);
        s_id = NULL;
        return;
    }else{
        unsigned int id = (unsigned)atoi(s_id);
        removeBooksID(books, theBook, id);
        free(s_id);
        s_id = NULL;
    }
}

void changeInformationBooks(Book* books){
    char* s_id = (char*)malloc(sizeof(char));
    int numChanges = 0;
    printf("What is the book's ID whose information you want to change?\n->");
    scanf("%s", s_id);

    if (isNumber(s_id)){
        unsigned int id = (unsigned)atoi(s_id);
        Book* tmp = books;
        tmp = tmp->next;
        while(tmp->id != id){
            tmp = tmp->next;
            if (tmp == NULL){
                printf("No books in the library have this ID!\n");
                return;
            }
        }
        char* yes_no = (char*)malloc(sizeof(char));
        char* title = (char*)malloc(sizeof(char));
        char* authors = (char*)malloc(sizeof(char));
        char* s_year = (char*)malloc(sizeof(char));
        printf("\n---------------------------------------------------------------");
        printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES |\n");
        printf("|%3u |%12s       |%13s       |%5u |%7u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies);
        printf("---------------------------------------------------------------\n");
        while (1){
            printf("Do you want to change the title?(yes/no)\n->");
            scanf("%s", yes_no);
            if (strcmp(yes_no, "yes") == 0){
                printf("What title do you want to change to?\n->");
                scanf("%s", title);
                strcpy(tmp->title, title);
                numChanges ++;
                break;
            }else if (strcmp(yes_no, "no") == 0){
                break;
            }else
                printf("Unknown option!\n");
        }
        while (1){
            printf("Do you want to change the authors?(yes/no)\n->");
            scanf("%s", yes_no);
            if (strcmp(yes_no, "yes") == 0){
                printf("What authors do you want to change to?\n->");
                scanf("%s", authors);
                strcpy(tmp->authors, authors);
                numChanges ++;
                break;
            }else if (strcmp(yes_no, "no") == 0){
                break;
            }else
                printf("Unknown option!\n");
        }
        while (1){
            printf("Do you want to change the year of publication?(yes/no)\n->");
            scanf("%s", yes_no);
            if (strcmp(yes_no, "yes") == 0){
                printf("Which year do you want to change to?\n->");
                scanf("%s", s_year);
                while (isNumber(s_year) == 0){
                    printf("Invalid year!\n");
                    printf("Which year do you want to change to?\n->");
                    scanf("%s", s_year);
                }
                unsigned int year = (unsigned)atoi(s_year);
                tmp->year = year;
                numChanges ++;
                break;
            }else if (strcmp(yes_no, "no") == 0){
                break;
            }else
                printf("Unknown option!\n");
        }
        free(yes_no);
        yes_no = NULL;
        free(title);
        title = NULL;
        free(authors);
        authors = NULL;
        free(s_year);
        s_year = NULL;
        free(s_id);
        s_id = NULL;
        if (numChanges)
            printf("Successfully change the information of books!\n");
    }else{
        printf("Invalid ID!\n");
        free(s_id);
        s_id = NULL;
    }
}

// void deleteUser(Student* students, StudentList* theStudent){
//     char* s_id = (char*)malloc(sizeof(char));
//     printf("What is the ID of the user you want to delete?\n->");
//     scanf("%s", s_id);
//     int in = 0;
//     if (isNumber(s_id)){
//         unsigned int id = (unsigned)atoi(s_id);
//         Student* tmp = students;
//         for (int i = 1; i < theStudent->length+1; i++){
//             tmp = tmp->next;
//             if (tmp->id == id){
//                 in = 1;
//                 printf("\n-----------------------------------------------------");
//                 printf("\n| ID |     NAME     |    USERNAME    |   PASSWORD   |\n");
//                 printf("-----------------------------------------------------\n");
//                 printf("|%3u |%9s     |%12s    |%11s   |\n", tmp->id, tmp->name, tmp->username, tmp->password);
//                 printf("-----------------------------------------------------\n");
//                 char* sure = (char*)malloc(sizeof(char));
//                 printf("Are you sure to delete this user?(yes/no)\n->");
//                 scanf("%s", sure);
//                 while (strcmp(sure, "yes") != 0 && strcmp(sure, "no") != 0){
//                     printf("Unknown option!\n");
//                     printf("Are you sure to delete this user?(yes/no)\n->");
//                     scanf("%s", sure);
//                 }
//                 if (strcmp(sure, "yes")==0){
//                     if (i == theStudent->length){
//                         tailDeleteStudents(students, theStudent->length);
//                         theStudent->length --;
//                     }else{
//                         middleDeleteStudents(students, theStudent, i);
//                         theStudent->length --;
//                     }
//                     printf("Successfully delete the reader!\n");
//                 }else
//                     printf("Delete failed!\n");
//                 free(sure);
//                 sure=NULL;
//                 break;
//             }
//         }
//         if (in == 0){
//             printf("No such reader whose ID is %u", id);
//         }
//     }else{
//         printf("Invalid ID!\n");
//     }
//     free(s_id);
//     s_id = NULL;
// }

void changePassword(void){
    char* password = (char*)malloc(sizeof(char));
    printf("What is the new password?\n->");
    scanf("%s", password);
    strcpy(librarianPassword, password);
    free(password);
    password=NULL;

    printf("Successfully Update the password!\n");
}

void displayAvailableBooks(Book* books, unsigned int length){
    if (length == 0){
        printf("\nThere is no book in the library!\n");
    }else{
        int numAvailable = 0;
        printf("\n----------------------- DISPLAY AVAILABLE BOOKS ---------------------------");
        printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES | AVAILABLE |\n");
        printf("---------------------------------------------------------------------------\n");
        Book* tmp = books->next;
        while(tmp != NULL){
            if ((tmp->lend) < (tmp->copies)){
                numAvailable ++;
                printf("|%3u |%12s       |%13s       |%5u |%7u |%10u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies, (tmp->copies)-(tmp->lend));
            }
            tmp = tmp->next;
        }
        if (numAvailable > 1)
            printf("\nThere are %d kinds of available books in total.\n", numAvailable);
        else if (numAvailable == 1)
            printf("\nThere are %d kind of available book in total.\n", numAvailable);
        else
            printf("\nNo available books now!\n");
    }
}

void displayBorrowedBooks(Book* books, unsigned int length){
    if (length == 0){
        printf("\nThere is no book in the library!\n");
    }else{
        int numLent = 0;
        printf("\n------------------------ DISPLAY BOOKS ON LOAN --------------------------");
        printf("\n| ID |       TITLE       |       AUTHOR       | YEAR | COPIES | ON LOAN |\n");
        printf("-------------------------------------------------------------------------\n");
        Book* tmp = books->next;
        while(tmp != NULL){
            if ((tmp->lend) > 0){
                numLent ++;
                printf("|%3u |%12s       |%13s       |%5u |%7u |%8u |\n", tmp->id, tmp->title, tmp->authors, tmp->year, tmp->copies, tmp->lend);
            }
            tmp = tmp->next;
        }
        if (numLent > 1)
            printf("\nThere are %d kinds of books on loan in total.\n", numLent);
        else if (numLent == 1)
            printf("\nThere are %d kind of book on loan in total.\n", numLent);
        else
            printf("\nNo books on loan now!\n");
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
    inputUsername = NULL;
    free(inputPassword);
    inputPassword = NULL;

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
        printf(" | | [8] DISPLAY BOOKS ON LOAN              | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [9] DISPLAY AVAILABLE BOOKS            | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [10] CHANGE THE PASSWORD               | |\n");
        printf(" | *                                        * |\n");
        printf(" | | [11] LOG OUT                           | |\n");
        printf(" ----------------------------------------------\n");

        printf("\nChoose one option(1-11): \n->");
        scanf("%s", option);

        if (strcmp(option, "1") == 0)
            addBooksMain(theBook->list, theBook);
        else if (strcmp(option, "2") == 0)
            removeBooksMain(theBook->list, theBook);
        else if (strcmp(option, "3") == 0)
            changeInformationBooks(theBook->list);
        else if (strcmp(option, "4") == 0)
            searchBooksMain(theBook->list, theBook);
        else if (strcmp(option, "5") == 0)
            showListBooks(theBook->list, theBook->length);
        else if (strcmp(option, "6") == 0)
            showListStudents(theStudent->list, theStudent->length);
        else if (strcmp(option, "7") == 0)
            searchReadersMain(theStudent);
        else if (strcmp(option, "8") == 0)
            displayBorrowedBooks(theBook->list, theBook->length);
        else if (strcmp(option, "9") == 0)
            displayAvailableBooks(theBook->list, theBook->length);
        else if (strcmp(option, "10") == 0)
            changePassword();
        else if (strcmp(option, "11") == 0)
            librarianLogin = 0;
        else
            printf("Unknown option!\n");
    }

    free(option);
    option = NULL;
}