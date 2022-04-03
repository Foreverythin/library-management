#ifndef LISTMANAGEMENT_GUARD__H 
#define LISTMANAGEMENT_GUARD__H

#include "book_management.h"

// insert a new node to the book list at the tail
// books is the pointer pointing to the head node of the book list
void tailInsertBooks(Book* books);

// insert a new node to the student list at the tail
// students is the pointer pointing to the head node of the student list
void tailInsertStudents(Student* students);

// insert a new node to the borrowing informaion list at the tail
// borrows is the pointer pointing to the head node of the borrowing information list
void tailInsertBorrowInformation(BorrowInformation* borrows);

// display the book list
void showListBooks(Book* books, unsigned int length);

//display the student list
void showListStudents(Student* Student, unsigned int length);

// delete a node from the tail of the list
// books is the pointer pointing to the head node of the book list
// length is the number of nodes before deleting except the head node
void tailDeleteBooks(Book* books, unsigned int length);

// delete a node from the tail of the list
// students is the pointer pointing to the head node of the student list
// length is the number of nodes before deleting except the head node
void tailDeleteStudents(Student* students, unsigned int length);

// delete a node from the tail of the list
// borrows is the pointer pointing to the head node of the borrowing information list
// length is the number of nodes before deleting except the head node
void tailDeleteBorrowInformation(BorrowInformation* borrows);

// delete a node in the middle of the book list
// index is the position of node you want to delete
void middleDeleteBooks(Book* books, BookList* theBook, int index);

//delete a node in the middle of the student list
// index is the position of node you want to delete
void middleDeleteStudents(Student* students, StudentList* theStudent, int index);

//delete a node in the middle of the borrow information list
// index is the position of node you want to delete
void middleDeleteBorrows(BorrowInformation* borrows, int index);

// free the space of book list in the heap
void destroyBook(Book* books, unsigned int length);

// free the space of student list in the heap
void destroyStudent(Student* students, unsigned int length);

// free the space of borrowing information list in the heap
void destroyBorrowInformation(BorrowInformation* borrows);

#endif