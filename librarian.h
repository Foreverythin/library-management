#ifndef LIBRARIAN_GUARD__H 
#define LIBRARIAN_GUARD__H

// the main menu of the librarian
// theBook is the pointer pointing to the BookList
// theStudent is the pointer pointing to the StudentList
void librarianMenu(BookList* theBook, StudentList* theStudent);

// add new books to the library
// all information of the books will be completed
// books is the pointer pointing to the first node of the book list
// theBook is the pointer pointing to BookList 
void addNewBook(Book* books, BookList* theBook, unsigned int id, char* title, char* authors, unsigned int year, unsigned int copies);

// the main entrance to find books
// books can by searched by id, title, name of authors, year, number of copies
// books is the pointer pointing to the first node of the book list
// theBook is the pointer pointing to BookList 
void searchBooksMain(Book* books, BookList* theBook);

// the main entrance to search readers
// readers can be searched by id, name
// theStudent is the pointer pointing to the StudentList
void searchReadersMain(StudentList* theStudent);

// the main entrance to add books
// when the books to be added have already in the library, then the number of copies will only be provided to be entered
// otherwise, all information will be provided to entered---add a new kind of books to the library
// books is the pointer pointing to the first node of the book list
// theBook is the pointer pointing to BookList 
void addBooksMain(Book* books, BookList* theBook);

// the main entrance to remove books
// books is the pointer pointing to the first node of the book list
// theBook is the pointer pointing to BookList
void removeBooksMain(Book* books, BookList* theBook);

// remove books by ID
// books is the pointer pointing to the first node of the book list
// theBook is the pointer pointing to BookList 
// when the book is lent out, then this kind of books can not be removed
void removeBooksID(Book* books, BookList* theBook, unsigned int id);

// change the book's information
// books is the pointer pointing to the first node of the book list
// the title, authors and year can be changed
void changeInformationBooks(Book* books);

// display books which can be lent
// books is the pointer pointing to the first node of the book list
// length is the number of nodes of the book list except the head node
void displayAvailableBooks(Book* books, unsigned int length);

// display books which can be lent
// books is the pointer pointing to the first node of the book list
// length is the number of nodes of the book list except the head node
void displayAvailableBooks(Book* books, unsigned int length);

// display books which are lent
// books is the pointer pointing to the first node of the book list
// length is the number of nodes of the book list except the head node
void displayBorrowedBooks(Book* books, unsigned int length);

#endif