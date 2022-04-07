#ifndef LIBRARY_GUARD__H 
#define LIBRARY_GUARD__H

// the library main menu
// initialize the information reading at first and store them at last
// initialize the book list, student list and borrowing information at first and destroy them at last
void libraryMenu(char* bookFile);

// initialize the library, load data to the data structure
// theBook is the pointer pointing to the BookList
// theStudent is also the pointer pointing to the StudentList
// borrows is also the pointer pointing to the first node of the borrowing information list
void initLibrary(char* bookFile, BookList* theBook, StudentList* thstudent, BorrowInformation* borrows);

// the main entrance to register an account for a reader
void registerAccountsMain(StudentList* theStudent);

// register an account for a reader
// the id should not be same to id registered and the length of password should not less than 6
// students is a pointer pointing to the head node of students of the student list
// theStudent is a pointer pointing to the StudentList
void registerAccounts(Student* students, StudentList* theStudent, unsigned int id, char* name, char* username, char* password);

#endif