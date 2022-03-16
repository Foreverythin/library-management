//the function of the library menu
void libraryMenu(void);
//initialize the library
void initLibrary(BookList* theBook);
//exit the library
//void exitLibrary(BookList* theBook);
//load books from "books.txt" if exists and store them into the book list
int load_books(FILE* books, BookList* theBook);
//insert a node at the tail of the book list and return the pointer pointing the last node
BookList* tailInsert(BookList* theBook);
