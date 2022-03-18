//the function of the library menu
void libraryMenu(void);

//initialize the library
void initLibrary(BookList* theBook);

//exit the library
//void exitLibrary(BookList* theBook);

//insert a node at the tail of the book list and return the pointer pointing the last node
void tailInsert(Book* books);

void showList(Book* books, unsigned int length);
//
void tailDelete(Book* books, BookList* theBook);

//
//void exitLibrary(BookList theBook);
