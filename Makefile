# code details

EXE = ./bin/library
SRC = main.c library.c librarian.c listManagement.c

# generic build details

CC = gcc
CFLAGS = -std=c99 -Wall
CLINK=

# compile to object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE)

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c library.h
library.o: library.c book_management.h listManagement.h library.h librarian.h
librarian.o: librarian.c book_management.h librarian.h listManagement.h
listManagement.o: listManagement.c book_management.h listManagement.h
