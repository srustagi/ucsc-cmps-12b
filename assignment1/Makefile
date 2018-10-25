# File: Makefile
# Name: Shivansh Rustagi
# CruzID: 1651034
# Class: CMPS 12B
# Description: Makefile for Assignment 1

# Macros
FLAGS = -std=c99 -Wall
TESTING = main
FUNCTIONS = list_funcs
EXEBIN = $(TESTING)
OBJECTS = $(TESTING).o $(FUNCTIONS).o
SOURCES = $(TESTING).c $(FUNCTIONS).c

all : $(EXEBIN)

# create executable file
$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

# create object file
$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

# clean utility
clean :
	rm -f $(EXEBIN) $(OBJECTS)

run :
	./main