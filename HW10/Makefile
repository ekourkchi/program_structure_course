# /*****************************************************************
# //
# //  NAME:		Ehsan Kourkchi
# //
# //  HOMEWORK:		10
# //
# //  CLASS:		ICS 212
# //
# //  INSTRUCTOR:	Ravi Narayan
# //
# //  DATE:		December 11, 2013           
# //
# //  FILE:		Makefile        
# //
# //  DESCRIPTION:	Makefile for hw10.cpp
# //
# //****************************************************************/


all: hw10.o animal.o cow.o bird.o animal.h cow.h bird.h 
	c++ -o hw10  hw10.o animal.o cow.o bird.o

hw10.o: hw10.cpp animal.h
	c++ -c hw10.cpp

animal.o: animal.cpp animal.h
	c++ -c animal.cpp


cow.o: cow.cpp cow.h
	c++ -c cow.cpp

bird.o: bird.cpp bird.h
	c++ -c bird.cpp


.PHONY: clean

clean:
	rm -f *.o


