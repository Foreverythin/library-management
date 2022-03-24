#ifndef LIBRARIAN_GUARD__H 
#define LIBRARIAN_GUARD__H

void librarianMenu(BookList* theBook, StudentList* theStudent);

void addNewBook(Book* books, BookList* theBook, unsigned int id, char* title, char* authors, unsigned int year, unsigned int copies);

// void searchBooksID(Book* books, BookList* theBook, unsigned int id);
// void searchBooksTitle(Book* books, BookList* theBook, char* title);
// void searchBooksAuthors(Book* books, BookList* theBook, char* authors);
// void searchBooksYear(Book* books, BookList* theBook, unsigned int year);
// void searchBooksCopies(Book* books, BookList* theBook, unsigned int copies);

void searchBooksMain(Book* books, BookList* theBook);
void searchReadersMain(StudentList* theStudent);

void addBooksMain(Book* books, BookList* theBook);
#endif