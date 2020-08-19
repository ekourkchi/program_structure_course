# /*****************************************************************
# //
# //  NAME:		Ehsan Kourkchi
# //
# //  HOMEWORK:		3
# //
# //  CLASS:		ICS 212
# //
# //  INSTRUCTOR:	Ravi Narayan
# //
# //  DATE:		September 21, 2013           
# //
# //  FILE:		Makefile        
# //
# //  DESCRIPTION:	Makefile for "database.c"
# //
# //****************************************************************/


all: database.o database_functions.o
	cc -o database  database.o database_functions.o

database.o: database.c record.h
	cc -c database.c

database_functions.o: database_functions.c record.h
	cc -c database_functions.c


.PHONY: clean

clean:
	rm -f *.o