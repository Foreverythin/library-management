#ifndef READER_GUARD__H 
#define READER_GUARD__H

void readerMenu(BookList* theBook, StudentList* theStudent, BorrowInformation* borrows);

void changePersonalInformation(Student* students, StudentList* theStudent, unsigned int id);

void borrowABook(Book* books, unsigned int length, Student* students, BorrowInformation* borrows, unsigned int stuID);

void displayMyBooksOnLoan(Book* books, BorrowInformation* borrows, unsigned int currentID);

#endif