#ifndef LISTMANAGEMENT_GUARD__H 
#define LISTMANAGEMENT_GUARD__H

#include "book_management.h"

//insert a node at the tail of the book list and return the pointer pointing the last node
void tailInsertBooks(Book* books);

//insert a node at the tail of the student list and return the pointer pointing the last node
void tailInsertStudents(Student* students);

//
void showListBooks(Book* books, unsigned int length);

//
void showListStudents(Student* Student, unsigned int length);

//
void tailDeleteBooks(Book* books, BookList* theBook);

//
void tailDeleteStudents(Student* students, StudentList* theStudent);

#endif