#ifndef LIBRARIAN_GUARD__H 
#define LIBRARIAN_GUARD__H

void librarianMenu(BookList* theBook, StudentList* theStudent);

void addNewBook(Book* books, BookList* theBook, unsigned int id, char* title, char* authors, unsigned int year, unsigned int copies);

void searchBooksMain(Book* books, BookList* theBook);
void searchReadersMain(StudentList* theStudent);

void addBooksMain(Book* books, BookList* theBook);
void removeBooksMain(Book* books, BookList* theBook);
void removeBooksID(Book* books, BookList* theBook, unsigned int id);

void changeInformationBooks(Book* books);

void displayAvailableBooks(Book* books, unsigned int length);

void displayAvailableBooks(Book* books, unsigned int length);

void displayBorrowedBooks(Book* books, unsigned int length);

#endif