# File: Makefile
# Name: Shivansh Rustagi
# Class: CMPS 12B
# CruzID: shrustag
# Description: Makefile for Assignment 3

ADT = BST
FLAGS = -std=c99 -Wall
TESTING = $(ADT)Client
SOURCES = $(ADT).c $(ADT)Client.c
OBJECTS = $(ADT).o $(ADT)Client.o
HEADERS = $(ADT).h
EXEBIN = $(ADT)Client

all : $(EXEBIN)
	
$(EXEBIN) : $(OBJECTS) $(HEADERS)
	gcc -o $(EXEBIN) $(OBJECTS)
$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)
clean :
	rm -f $(EXEBIN) $(OBJECTS)
check :
	valgrind --leak-check=full $(EXEBIN)
run :
	./$(EXEBIN)
