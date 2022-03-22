#ifndef LIBRARY_GUARD__H 
#define LIBRARY_GUARD__H

//the function of the library menu
void libraryMenu(void);

//initialize the library
void initLibrary(BookList* theBook, StudentList* thstudent);


void registerAccountsMain(StudentList* theStudent);
void registerAccounts(Student* students, StudentList* theStudent, unsigned int id, char* name, char* username, char* password);

//exit the library
//void exitLibrary(BookList* theBook);

//
//void exitLibrary(BookList theBook);

#endif