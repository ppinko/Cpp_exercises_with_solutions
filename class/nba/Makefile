#declare variables
CC=g++

CFLAGS=-c -Wall

all: file

file: main.o NBA.o AllStar.o
	$(CC) main.o NBA.o AllStar.o -o executable

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

AllStar.o: AllStar.cpp
	$(CC) $(CFLAGS) AllStar.cpp

NBA.o: NBA.cpp
	$(CC) $(CFLAGS) NBA.cpp

clean:
	rm -rf *o executable