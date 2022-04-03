#ifndef READER_GUARD__H 
#define READER_GUARD__H

// the main menu after a reader logging in
void readerMenu(BookList* theBook, StudentList* theStudent, BorrowInformation* borrows);

// to change personal information
// the username and password can be changed, but the length of the password should not less than 6
// students is the pointer pointing to the head node of the student list
// theStudent is the pointer pointing to the StudentList
// id is the student's id who want to change the information, also the student who is logging in
void changePersonalInformation(Student* students, StudentList* theStudent, unsigned int id);

// to borrow a book
// one student can only borrow at most 5 books
// books is the pointer pointing to the head node of the book list
// length is the number of nodes in the book list except the head node
// borrows is the pointer pointing the first node of the borrowing information list
// stuID is the student ID who want to borrow a book, also the student who is logging in
void borrowABook(Book* books, unsigned int length, Student* students, BorrowInformation* borrows, unsigned int stuID);

// to display books the student whose ID is stuID has borrowed
// books is the pointer pointing to the first node of the book list
// borrows is the pointer pointing to the first node of the borrowing information list
void displayMyBooksOnLoan(Book* books, BorrowInformation* borrows, unsigned int currentID);

// to return a book to the library
// books is the pointer pointing to the head node of the book list
// length is the number of nodes in the book list except the head node
// borrows is the pointer pointing the first node of the borrowing information list
// students is the pointer pointing to the head node of the student list
// stuID is the student ID who want to return a book, also the student who is logging in
void returnABook(Book* books, unsigned int length, Student* students, BorrowInformation* borrows, unsigned int stuID);

#endif