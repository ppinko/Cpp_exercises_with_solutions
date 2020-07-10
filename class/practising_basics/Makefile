#declare variables
CC=g++

CFLAGS=-c -Wall

all: file

file: main.o Dog.o
	$(CC) main.o Dog.o -o executable

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Dog.o: Dog.cpp
	$(CC) $(CFLAGS) Dog.cpp