// Command to compile : make all
// Command to clean : make clean
// To run : ./proj2 input.txt
// input.txt is the file which has the details of the songs

all: lab7

lab7:	Pandora.o	Time.o	Song.o	Library.o	
	g++	-g Pandora.o	Time.o	Song.o	Library.o		-o proj2

Pandora:	Pandora.cpp
	g++	-g -c	Pandora.cpp	-o Pandora.o
	
Time:	Time.cpp	Time.h
	g++	-g -c	Time.cpp	-o Time.o
	
Song:	Song.cpp	Song.h
	g++	-g -c	Song.cpp	-o Song.o
	
Library:	Library.cpp	Library.h
	g++	-g -c	Library.cpp	-o Library.o
		
clean: 
	rm -f *.o proj2
	
	
