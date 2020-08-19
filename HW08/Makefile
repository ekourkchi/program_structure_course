# /*****************************************************************
# //
# //  NAME:		Ehsan Kourkchi
# //
# //  HOMEWORK:		8
# //
# //  CLASS:		ICS 212
# //
# //  INSTRUCTOR:	Ravi Narayan
# //
# //  DATE:		November 2, 2013           
# //
# //  FILE:		Makefile        
# //
# //
# //****************************************************************/


all: HW08.java HW08.h libMyCppLibrary.so
	javac HW08.java

HW08.class : HW08.java
	javac HW08.java


HW08.h: HW08.class
	javah HW08

libMyCppLibrary.so: libMyCppLibrary.cpp HW08.h
	gcc -shared  libMyCppLibrary.cpp -o libMyCppLibrary.so -m32




.PHONY: clean

clean:
	rm -f *.so *class HW08.h