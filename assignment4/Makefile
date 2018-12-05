# File: Makefile
# Name: Shivansh Rustagi
# Class: CMPS 12B
# CruzID: shrustag
# ID Number: 1651034
# Description: Makefile for Assignment 3

ADT = BST
FLAGS = -std=c99 -Wall
TESTING = $(ADT)Client
SOURCES = $(ADT).c $(TESTING).c
OBJECTS = $(ADT).o $(TESTING).o
HEADERS = $(ADT).h
EXEBIN = $(TESTING)

all : $(EXEBIN)

$(EXEBIN) : $(OBJECTS) $(HEADERS)
	gcc -o $(EXEBIN) $(OBJECTS)
$(OBJECTS) : $(SOURCES) $(HEADERS)
	gcc -c $(FLAGS) $(SOURCES)
clean :
	rm -f $(EXEBIN) $(OBJECTS)
check :
	valgrind --leak-check=full $(EXEBIN)
run :
	./$(EXEBIN)
