# /*****************************************************************
# //
# //  NAME:		Ehsan Kourkchi
# //
# //  HOMEWORK:		2
# //
# //  CLASS:		ICS 212
# //
# //  INSTRUCTOR:	Ravi Narayan
# //
# //  DATE:		September 12, 2013           
# //
# //  FILE:		Makefile        
# //
# //  DESCRIPTION:	Makefile for "program01.c"
# //
# //****************************************************************/


all: program01.o strappend.o find_index_of_max.o
	cc -o program01.x program01.o strappend.o find_index_of_max.o 

program01.o: program01.c
	cc -c program01.c

strappend.o: strappend.c
	cc -c strappend.c

find_index_of_max.o: find_index_of_max.c
	cc -c find_index_of_max.c

.PHONY: clean

clean:
	rm -f *.o