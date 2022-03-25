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
void tailDeleteBooks(Book* books, unsigned int length);

//
void tailDeleteStudents(Student* students, unsigned int length);

void middleDeleteBooks(Book* books, BookList* theBook, int index);

void middleDeleteStudents(Student* students, StudentList* theStudent, int index);

void distroyBook(Book* books, unsigned int length);

void distroyStudent(Student* students, unsigned int length);

#endif