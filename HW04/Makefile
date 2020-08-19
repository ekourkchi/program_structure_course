# /*****************************************************************
# //
# //  NAME:		Ehsan Kourkchi
# //
# //  HOMEWORK:		4
# //
# //  CLASS:		ICS 212
# //
# //  INSTRUCTOR:	Ravi Narayan
# //
# //  DATE:		September 21, 2013           
# //
# //  FILE:		Makefile        
# //
# //  DESCRIPTION:	Makefile for "hw04.c"
# //
# //****************************************************************/


all: hw04.o databaseio.o
	cc -o hw04  hw04.o databaseio.o



database_functions.o: hw04.c account.h
	cc -c hw04.c

databaseio.o:  databaseio.c databaseio.h account.h
	cc -c databaseio.c


.PHONY: clean

clean:
	rm -f *.o