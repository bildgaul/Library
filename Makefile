# Author: Billy Gauldin
# File: Makefile
# Makefile for Book Inventory

CC=g++

DEBUG=-g

TARGET=library

CFLAGS=-c -Wall $(DEBUG)

all: $(TARGET)

$(TARGET): main.o library.o
	$(CC) main.o library.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

library.o: library.cpp library.h
	$(CC) $(CFLAGS) library.cpp

clean:
	rm *~ *.o $(TARGET)
